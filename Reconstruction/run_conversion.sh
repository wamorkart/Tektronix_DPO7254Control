#!/bin/bash

FNAL_SCOPE_DIR=/eos/cms/store/group/phys_susy/razor/FNAL_TB_1811/Scope_standalone

done_runs=($(ls -d ${FNAL_SCOPE_DIR}/ROOT/*.root))
# for run in ${done_runs}
for (( run_i=0; run_i<${#done_runs[@]}; run_i++ ));
do
  echo ${done_runs[$run_i]}
done
echo Selected:
new_runs=($(ls -dt ${FNAL_SCOPE_DIR}/RAW/* | head -${#done_runs[@]}))
tLen=${#new_runs[@]}
echo $tLen

for (( run_i=0; run_i<$tLen; run_i++ ));
do
  python conversion.py ${new_runs[$run_i]}
done
