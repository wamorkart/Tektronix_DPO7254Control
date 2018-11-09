"""
VISA Control: FastFrame Acquisition
FNAL November 2018
CMS MTD ETL Test beam
"""

import numpy as np
import matplotlib.pyplot as plt
import sys
import optparse
import argparse
import signal
import shutil
from shutil import copy

stop_asap = False

def signal_handler(sig,frame):
    global stop_asap
    stop_asap = True
    print("Emergency stop: Closing")
signal.signal(signal.SIGINT,signal_handler)
signal.signal(signal.SIGTERM,signal_handler)


import visa


def get_waveform_info():
    """Gather waveform transfer information from scope."""
    dpo.write('acquire:stopafter sequence')
    dpo.write('acquire:state on')
    dpo.query('*OPC?')
    binaryFormat = dpo.query('wfmoutpre:bn_fmt?').rstrip()
    print('Binary format: ', binaryFormat)
    numBytes = dpo.query('wfmoutpre:byt_nr?').rstrip()
    print('Number of Bytes: ', numBytes)
    byteOrder = dpo.query('wfmoutpre:byt_or?').rstrip()
    print('Byte order: ', byteOrder)
    encoding = dpo.query('data:encdg?').rstrip()
    print('Encoding: ', encoding)
    if 'RIB' in encoding or 'FAS' in encoding:
        dType = 'b'
        bigEndian = True
    elif encoding.startswith('RPB'):
        dType = 'B'
        bigEndian = True
    elif encoding.startswith('SRI'):
        dType = 'b'
        bigEndian = False
    elif encoding.startswith('SRP'):
        dType = 'B'
        bigEndian = False
    elif encoding.startswith('FP'):
        dType = 'f'
        bigEndian = True
    elif encoding.startswith('SFP'):
        dType = 'f'
        bigEndian = False
    elif encoding.startswith('ASCI'):
        raise visa.InvalidBinaryFormat('ASCII Formatting.')
    else:
        raise visa.InvalidBinaryFormat
    return dType, bigEndian

def copytree(src, dst, symlinks=False, ignore=None):
    for item in os.listdir(src):
        s = os.path.join(src, item)
        d = os.path.join(dst, item)
        if os.path.isdir(s):
            shutil.copytree(s, d, symlinks, ignore)
        else:
            shutil.copy2(s, d)


"""#################SEARCH/CONNECT#################"""
# establish communication with dpo
rm = visa.ResourceManager()
dpo = rm.open_resource('TCPIP::192.168.133.160::INSTR')
dpo.timeout = 60000
dpo.encoding = 'latin_1'
print(dpo.query('*idn?'))
# dpo.write('*rst')


parser = argparse.ArgumentParser(description='Run info.')

parser.add_argument('--totalNumber', metavar='tot', type=int,help='totalNumber of data point',required=True)
parser.add_argument('--numFrames',metavar='Frames', type=str,default = 500, help='numFrames (default 500)',required=False)

args = parser.parse_args()


"""#################CONFIGURE INSTRUMENT#################"""
# variables for individual settings
hScale = 10e-9
numFrames = int(args.numFrames)
totalNumber = int(args.totalNumber)
vScale = 0.5
vPos = -2.5
trigLevel = - 0.03



"""#################CONFIGURE RUN NUMBER#################"""
# increment the last runNumber by 1
with open('runNumber.txt') as file:
    runNumber = int(file.read())
print('######## Starting RUN {} ########'.format(runNumber))
with open('runNumber.txt','w') as file:
    file.write(str(runNumber+1))


"""#################SET THE OUTPUT FOLDER#################"""
# The scope save runs localy on a shared folder with
path = "c:/ETL_Nov2018/test_run{}".format(runNumber)
dpo.write('filesystem:mkdir "{}"'.format(path))

"""#################SCOPE HORIZONTAL SETUP#################"""
# dpo setup
dpo.write('acquire:state off')
dpo.write('horizontal:mode:scale {}'.format(hScale))
dpo.write('horizontal:fastframe:state on')
dpo.write('horizontal:fastframe:count {}'.format(numFrames))

# dpo.write('ch1:scale {}'.format(vScale))
# dpo.write('ch2:scale {}'.format(vScale))
# dpo.write('ch3:scale {}'.format(vScale))
# dpo.write('ch3:scale {}'.format(vScale))

# dpo.write('ch1:position {}'.format(vPos))
# dpo.write('ch2:position {}'.format(vPos))
# dpo.write('ch3:position {}'.format(vPos))
# dpo.write('ch4:position {}'.format(vPos))

"""#################TRIGGER SETUP#################"""
dpo.write('trigger:a:level:ch1 {}'.format(trigLevel))
print('Horizontal, vertical, and trigger settings configured.')

"""#################DATA TRANSFERRING#################"""
# configure data transfer settings
dpo.write('header off')
dpo.write('horizontal:fastframe:sumframe none')
dpo.write('data:encdg fastest')
# dpo.write('data:source ch1')
recordLength = int(dpo.query('horizontal:mode:recordlength?').strip())
dpo.write('data:stop {}'.format(recordLength))
dpo.write('wfmoutpre:byt_n 1')
dpo.write('data:framestart 1')
dpo.write('data:framestop {}'.format(numFrames))
print('Data transfer settings configured.')

dpo.read_termination = '\n'



"""#################ACQUIRE DATA#################"""
i = 0
filename='{}/fastframe'.format(path)
while (i*numFrames<totalNumber) and stop_asap==False:
    i+=1
    print('Acquiring waveform.')
    dpo.write('acquire:stopafter sequence')
    dpo.write('acquire:state on')
    dpo.query('*opc?')
    print('Waveform acquired.\n')
    dpo.write('save:waveform:fileformat INTERNAL')
    dpo.write('save:waveform ch1, "%s_%d_CH1.wfm"'%(filename,i))
    dpo.write('save:waveform ch2, "%s_%d_CH2.wfm"'%(filename,i))
    dpo.write('save:waveform ch3, "%s_%d_CH3.wfm"'%(filename,i))
    dpo.write('save:waveform ch4, "%s_%d_CH4.wfm"'%(filename,i))
                                              
path_ftbf = "/Tektronix/test_run{}".format(runNumber)
path_lxplus = "/lxplus/Scope_standalone/RAW/test_run{}".format(runNumber)
copytree(path_ftbf,path_lxplus)  
     
print('Waveform saved.\n')



# Retrieve vertical and horizontal scaling information
# yOffset = float(dpo.query('wfmoutpre:yoff?'))
# yMult = float(dpo.query('wfmoutpre:ymult?'))
# yZero = float(dpo.query('wfmoutpre:yzero?'))
#
# numPoints = int(dpo.query('wfmoutpre:nr_pt?'))
# xIncr = float(dpo.query('wfmoutpre:xincr?'))
# xZero = float(dpo.query('wfmoutpre:xzero?'))
#
# dType, bigEndian = get_waveform_info()
# data = dpo.query_binary_values(
#     'curve?', datatype=dType, is_big_endian=bigEndian, container=np.array)
#


dpo.close()
