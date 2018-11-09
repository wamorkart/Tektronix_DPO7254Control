#!/bin/bash
source /afs/cern.ch/sw/lcg/app/releases/ROOT/6.06.08/x86_64-slc6-gcc49-opt/root/bin/thisroot.sh
source /afs/cern.ch/sw/lcg/external/gcc/4.9.3o3/x86_64-slc6-gcc49-opt/setup.sh

runs=(1251 1276 1276)
thresholds=(-0.1 -0.01 -0.04)
saturations=(0.24 0.085 0.17)
channels=(2 1 2)
MCPchannels=(1 0 0)
# runs=($(ls -d /afs/cern.ch/user/n/nminafra/Work/TimingKU/data/*.root))
# channel     0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15
# thresholds=(0.01 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 \
#             0.01 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 -0.02 \
#             )
run_i=$1
echo DataNetScope_Run${runs[$run_i]}.root
# /afs/cern.ch/user/n/nminafra/Work/TimingKU/TimingAnalysisDRS/analyzeDataVsMCP -i  /afs/cern.ch/work/m/malazaro/public/FNAL_dataDRS/Run${runs[$run_i]}.root -o /afs/cern.ch/user/n/nminafra/Work/TimingKU/TimingAnalysisDRS/Condor/Results/ -f ${channel} -c 0.5 -t -0.019 --lowpass 0 -s 0.4
/afs/cern.ch/user/n/nminafra/Work/TimingKU/TimingAnalysisOscApril/analyzeDataVsMCP -i  /afs/cern.ch/user/n/nminafra/Work/TimingKU/dataApril/DataNetScope_Run${runs[$run_i]}.root -o /afs/cern.ch/user/n/nminafra/Work/TimingKU/TimingAnalysisOscApril/Condor/Results/ -f ${channels[$run_i]} -c -0.1 -t ${thresholds[$run_i]} --lowpass -0.2e9 -s ${saturations[$run_i]} --MCPchannel ${MCPchannels[$run_i]} --MCPthreshold -0.09 --MCPsaturation 0.16
