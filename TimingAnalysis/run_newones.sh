#!/bin/bash

FNAL_SCOPE_DIR=/eos/cms/store/group/phys_susy/razor/FNAL_TB_1811/Scope_standalone
make

done_runs=($(ls -d ${FNAL_SCOPE_DIR}/Analyzed/*.root))
new_runs=($(ls -dt ${FNAL_SCOPE_DIR}/ROOT/*))
# for (( run_i=0; run_i<${#new_runs[@]}; run_i++ ));
# do
#   echo ${new_runs[$run_i]}
# done

lenDone=${#done_runs[@]}
lenNew=${#new_runs[@]}
let lenToDo=$lenNew-$lenDone
echo Processing $lenToDo new files

for (( run_i=0; run_i<$lenToDo; run_i++ ));
do
  ./analyzeDataVsMCP -i ${new_runs[$run_i]} -f 1 -t -0.015 -c 0.5 --lowpass 00e6 --MCPsaturation 0.085 --MCPthreshold -0.02 -o /eos/cms/store/group/phys_susy/razor/FNAL_TB_1811/Scope_standalone/Analyzed/
done
