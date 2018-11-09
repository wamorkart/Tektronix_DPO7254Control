#!/bin/bash
source /afs/cern.ch/sw/lcg/app/releases/ROOT/6.06.08/x86_64-slc6-gcc49-opt/root/bin/thisroot.sh
source /afs/cern.ch/sw/lcg/external/gcc/4.9.3o3/x86_64-slc6-gcc49-opt/setup.sh

runs=($(ls -d /afs/cern.ch/work/m/malazaro/public/FNAL_dataDRS/*.root))
# runs2=($(ls -d /eos/user/n/nminafra/FNAL_data/FNAL_dataDRS/*.root))
# runs=(247 249 250 251 252 253 255 256 257 258 261 262 263 264 265 266 268 275 277 279 282 284 285 288 291 292 293 294 345 347 348 349 350 425 426 427 431 432 433 441 442 443 444 445 446 447 448 449 450 451 453 454 456 457 458 459 677 678 689 680)
tLen=${#runs[@]}
run_i=$1
for (( channel=1; channel<4; channel++ ));
do
  echo ${runs[$run_i]} channel ${channel}
  /afs/cern.ch/user/n/nminafra/Work/TimingKU/TimingAnalysisDRS/analyzeDataVsMCP -i  ${runs[$run_i]} -o /afs/cern.ch/user/n/nminafra/Work/TimingKU/TimingAnalysisDRS/Condor/Results/ -f ${channel} -c 0.5 -t -0.02 --lowpass 0 -s 1 | grep SELECTED
done
