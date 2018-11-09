#!/bin/bash
runs=(249 250 251)
tLen=${#runs[@]}
echo ${tLen}
for (( run_i=0; run_i<${tLen}; run_i++ ));
do
  echo ${run_i}
  for (( channel=1; channel<4; channel++ ));
    do
      echo ${channel}
      echo ./analyzeDataVsMCP -i ../data/DataNetScope_Run${runs[$run_i]}.root -f channel -c 0.5 -t -0.02 --lowpass 0 -s 1
    done
done
