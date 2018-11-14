#!/bin/bash
. /cvmfs/sft.cern.ch/lcg/releases/LCG_88/ROOT/6.08.06/x86_64-slc6-gcc62-opt/ROOT-env.sh

FNAL_SCOPE_DIR=/eos/cms/store/group/phys_susy/razor/FNAL_TB_1811/Scope_standalone/
CODE_DIR=/afs/cern.ch/user/n/nminafra/Work/TimingKU/FNAL_Nov18/Tektronix_DPO7254Control/TimingAnalysis/
# runs=($(ls -d ${FNAL_SCOPE_DIR}/ROOT/*.root))

run_i=$(( $1 + 0 ))

runs=(W5_1_lp_195V_ch1, W5_1_lp_185V_ch1, W5_1_lp_175V_ch1)
channels=(1 1 1)
thresholds=(-0.012 -0.012 -0.012)


echo run_scope${run_i}.root

${CODE_DIR}/analyzeDataVsMCP -f ${channels[$run_i]} -t ${thresholds[$run_i]} -c 0.5 -s 0.088 --lowpass 00e6 --MCPsaturation 0.4 --MCPthreshold -0.05 -i ${FNAL_SCOPE_DIR}/Analyzed/merged/runs[${run_i}].root -o ${FNAL_SCOPE_DIR}/Analyzed/results/
