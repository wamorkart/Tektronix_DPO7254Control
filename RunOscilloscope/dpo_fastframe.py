"""
VISA Control: FastFrame Acquisition
Tektronix DPO7254 Control
FNAL November 2018
CMS MTD ETL Test beam
"""

import numpy as np
import matplotlib.pyplot as plt
import sys
import optparse
import argparse
import signal
import os
import shutil
import datetime
from shutil import copy

stop_asap = False

import visa

def copytree(src, dst, symlinks=False, ignore=None):
    for item in os.listdir(src):
        s = os.path.join(src, item)
        d = os.path.join(dst, item)
        shutil.copytree(item, d, symlinks, ignore)
def copynew(source,destination):
    for files in source:
        shutil.copy(files,destination)

"""#################SEARCH/CONNECT#################"""
# establish communication with dpo
rm = visa.ResourceManager()
dpo = rm.open_resource('TCPIP::192.168.133.161::INSTR')
dpo.timeout = 3000000
dpo.encoding = 'latin_1'
print(dpo.query('*idn?'))

parser = argparse.ArgumentParser(description='Run info.')

parser.add_argument('--totalNumber', metavar='tot', type=int,help='totalNumber of data point',required=True)
parser.add_argument('--numFrames',metavar='Frames', type=str,default = 500, help='numFrames (default 500)',required=False)
parser.add_argument('--trigCh',metavar='trigCh', type=str, default='AUX',help='trigger Channel (default Aux (-0.1V))',required=False)
parser.add_argument('--trig',metavar='trig', type=float, default= -0.05, help='trigger value in V (default Aux (-0.05V))',required=False)
parser.add_argument('--trigSlope',metavar='trigSlope', type=str, default= 'NEGative', help='trigger slope; positive(rise) or negative(fall)',required=False)

args = parser.parse_args()
trigCh = (args.trigCh) # string with trigger channel number [CH1..CH4]
trigLevel = float(args.trig)
triggerSlope = args.trigSlope

date = datetime.datetime.now()

"""#################CONFIGURE INSTRUMENT#################"""
# variables for individual settings
hScale = 100e-9 # horizontal scale in seconds
numFrames = int(args.numFrames) # number of frames for each file

totalNumber = int(args.totalNumber) # total number of frames

#vertical scale
vScale_ch1 = 0.05 # in Volts for division
vScale_ch2 = 0.01 # in Volts for division
vScale_ch3 = 0.01 # in Volts for division
vScale_ch4 = 1 # in Volts for division

#vertical position
vPos_ch1 = 4  # in Divisions
vPos_ch2 = 4  # in Divisions
vPos_ch3 = 4  # in Divisions
vPos_ch4 = 4  # in Divisions

date = datetime.datetime.now()

if totalNumber < numFrames:
    raise Exception("total number of frames < number of frames for each file")

if numFrames > 2000:
    ("WARNING: numFrames > 2000 --> the DUT might need more than one spill to fill a waveform file.\n")


"""#################CONFIGURE RUN NUMBER#################"""
# increment the last runNumber by 1
with open('runNumber.txt') as file:
    runNumber = int(file.read())
print('######## Starting RUN {} ########\n'.format(runNumber))
print('---------------------\n')
print(date)
print('---------------------\n')

with open('runNumber.txt','w') as file:
    file.write(str(runNumber+1))

"""#################SET THE OUTPUT FOLDER#################"""
# The scope save runs localy on a shared folder with
path = "C:\Users\Public\Documents\Infiniium\Test_Feb18"
dpo.write(':DISK:MDIRectory "{}"'.format(path))
log_path = "Logbook.txt"

#Write in the log file
logf = open(log_path,"a+")
logf.write("\n\n#### SCOPE LOGBOOK -- RUN NUMBER {} ####\n\n".format(runNumber))
logf.write("Date:\t{}\n".format(date))
logf.write("---------------------------------------------------------\n")
logf.write("Total number of triggers acquired: {} \n".format(totalNumber))
logf.write("Number of triggers per file: {} \n".format(numFrames))
logf.write("---------------------------------------------------------\n\n")

"""#################SCOPE HORIZONTAL SETUP#################"""
# dpo setup

dpo.write(':TIMebase:RANGe {}'.format(hScale)) ## Sets the full-scale horizontal time in s. Range value is ten times the time-per division value.
# # TIMebase:SCALe
dpo.write(':TIMebase:POSition 25E-9') ## offset
dpo.write(':ACQuire:MODE SEGMented') ## fast frame/segmented acquisition mode
dpo.write(':ACQuire:SEGMented:COUNt 100') ##number of segments to acquire

print("# SCOPE HORIZONTAL SETUP #")
print('Horizontal scale set to {} for division\n'.format(hScale))

logf.write("HORIZONTAL SETUP\n")
logf.write('- Horizontal scale set to {} s for division\n\n'.format(hScale))

"""#################SCOPE CHANNELS BANDWIDTH#################"""
#'full' set the bandwidth to 2.5GHz(HW) IMPORTANT: the vertical scale has to be at least 10mV/division to use this feature!
dpo.write(':ACQuire:BANDwidth MAX') ## set the bandwidth to maximum
# dpo.write('CHANnel1:ISIM:BANDwidth 4.00E+09')
# dpo.write('CHANnel2:ISIM:BANDwidth 4.00E+09')
# dpo.write('CHANnel3:ISIM:BANDwidth 3.50E+09')
# dpo.write('CHANnel4:ISIM:BANDwidth 4.00E+09')
"""#################SCOPE VERTICAL SETUP#################"""
#vScale expressed in Volts
dpo.write('CHANnel1:SCALe {}'.format(vScale_ch1))
dpo.write('CHANnel2:SCALe {}'.format(vScale_ch2))
dpo.write('CHANnel3:SCALe {}'.format(vScale_ch3))
dpo.write('CHANnel4:SCALe {}'.format(vScale_ch4))
#
# # dpo.write('MARKer1:Y:POSition {}'.format(vPos_ch1))
# # # dpo.write('ch2:position {}'.format(vPos_ch2))
# # # dpo.write('ch3:position {}'.format(vPos_ch3))
# # # dpo.write('ch4:position {}'.format(vPos_ch4))
#
logf.write("VERTICAL SETUP\n")
logf.write('- CH1: vertical scale set to {} V for division\n'.format(vScale_ch1))
logf.write('- CH2: vertical scale set to {} V for division\n'.format(vScale_ch2))
logf.write('- CH3: vertical scale set to {} V for division\n'.format(vScale_ch3))
logf.write('- CH4: vertical scale set to {} V for division\n\n'.format(vScale_ch4))
#
#
# """#################TRIGGER SETUP#################"""
dpo.write('TRIGger:MODE EDGE; :TRIGger:EDGE:SOURce %s; :TRIGger:LEVel %s, %f'%(trigCh, trigCh, trigLevel))
dpo.write(':TRIGger:EDGE:SLOPe %s;' %(triggerSlope))
# # # # dpo.write(':TRIGGER:A:EDGE:SOURCE LINE') #TO trigger on the line (60Hz)
#
trigprint='%.3f'%(trigLevel)
print("# TRIGGER SETUP #")
print('Trigger scale set to %s V\n'%(trigprint))

logf.write("TRIGGER SETUP\n")
logf.write('- Trigger Channel set to %s\n'%(trigCh))
logf.write('- Trigger scale set to %s V\n\n\n\n'%(trigprint))



# """#################TERMINATIONS SETUP#################"""
# # # dpo.write(':CH1:TER 50;:CH2:TER 50;:CH3:TER 50;:CH4:TER 50');
# # #
# # # print("# TERMINATIONS SETUP #")
# # # print('All The Terminations set to 50 ohm.\n')
# # #
print('Horizontal, vertical, and trigger settings configured.\n')

"""#################DATA TRANSFERRING#################"""
# configure data transfer settings
dpo.write(':SYSTem:HEADer OFF')
# # dpo.write(':ACQuire:MODE RTIMe')
# # dpo.write(':ACQuire:POINts 32000')
# # dpo.write(':DIGitize')
# # # dpo.write('horizontal:fastframe:sumframe none')
# # # dpo.write('data:encdg fastest')
# # dpo.write(':MEASure:SOURce CHANnel1')
# # # # dpo.write('data:source ch1')
# # # recordLength = int(dpo.query('horizontal:mode:recordlength?').strip())
# # # dpo.write('data:stop {}'.format(recordLength))
# # # dpo.write('wfmoutpre:byt_n 1')
# # # dpo.write('data:framestart 1')
# # # dpo.write('data:framestop {}'.format(numFrames))
# # # print('Data transfer settings configured.\n')
# # #
# # # dpo.read_termination = '\n'
# # #
# # #
# # #
# # #
# # # """#################ACQUIRE DATA#################"""
i = 0
# # filename='{}/fastframe'.format(path)
filename='{}'.format(path)
for n in range (1, numFrames, 1):
    print "frame # ",n
    dpo.write(':ACQuire:SEGMented:INDex ' + str(n))
    # print(dpo.query(':WAVeform:SEGMented:TTAG?'))
    # print(dpo.query(':MEASure:VMIN? CHANnel1'))
    print(dpo.query(':WAVeform:PREamble?'))
# while (i*numFrames<totalNumber) and stop_asap==False:
#     i+=1
#     print('Acquiring waveform {}'.format(i))
# #     # # dpo.write('acquire:stopafter sequence')
# #     # dpo.write(':ACQuire:COMPlete:STATe 1')
# #     # # dpo.write('acquire:state on')
#     print(dpo.query('*OPC?'))
# #     # print('Waveform {} acquired'.format(i))
# #     # # dpo.write('save:waveform:fileformat INTERNAL')
    dpo.write(':WMEM1:SAVE CHAN1, "%s_%d_CH1.wfm"'%(filename,i))
#     # dpo.write(':WMEMory2:SAVE CHANnel2, "%s_%d_CH2.wfm"'%(filename,i))
#     # dpo.write(':WMEMory3:SAVE CHANnel3, "%s_%d_CH3.wfm"'%(filename,i))
#     # dpo.write(':WMEMory4:SAVE CHANnel4, "%s_%d_CH4.wfm"'%(filename,i))
#     print('Waveform {} saved.\n'.format(i))
#
#
# import time

# #
# #
# # path_ftbf = "/Tektronix/run_scope{}".format(runNumber) #otsdaq path (shared folder with the scope)
# # path_lxplus = ("/lxplus/Scope_standalone/RAW/run_scope%d"%(runNumber)) # lxplus folder mounted on otsdaq
# #
# # while len(os.listdir(path_ftbf)) < 4*i:
# #     time.sleep(1)
# #
# # print('Start copying the file on lxplus....')
# #
# # shutil.copytree(path_ftbf,path_lxplus)
# #
# # print('Waveforms copied.\n')
# # print('Ending Run {}.\n'.format(runNumber))
# #
# # print("\n\n\n ********  DID YOU UPDATE THE LOGBOOK AND SPREADSHEET?? ******** \n\n")
# # print("LogBook: https://docs.google.com/document/d/1PVd6DxdxLFYFbk_dmaxY3c2C5qMCfLAmNJD_r8xbN_4/edit#")
# # print('\n')
# # print("\nSpreadsheet: https://docs.google.com/spreadsheets/d/1w8Xzyr6kfaaHiJRtUg55FBBeXtrGfKv6OfC9XdTYLko/edit?ts=5be4d629#gid=0")
# # print('\n')
# #
# # # Retrieve vertical and horizontal scaling information
# # # yOffset = float(dpo.query('wfmoutpre:yoff?'))
# # # yMult = float(dpo.query('wfmoutpre:ymult?'))
# # # yZero = float(dpo.query('wfmoutpre:yzero?'))
# # #
# # # numPoints = int(dpo.query('wfmoutpre:nr_pt?'))
# # # xIncr = float(dpo.query('wfmoutpre:xincr?'))
# # # xZero = float(dpo.query('wfmoutpre:xzero?'))
# # #
# # # dType, bigEndian = get_waveform_info()
# # # data = dpo.query_binary_values(
# # #     'curve?', datatype=dType, is_big_endian=bigEndian, container=np.array)
# # #
#

dpo.close()
