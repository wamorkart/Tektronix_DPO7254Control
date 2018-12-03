#!/bin/bash
. /cvmfs/sft.cern.ch/lcg/releases/LCG_88/ROOT/6.08.06/x86_64-slc6-gcc62-opt/ROOT-env.sh

FNAL_SCOPE_DIR=/eos/cms/store/group/phys_susy/razor/FNAL_TB_1811/Scope_standalone/
CODE_DIR=/afs/cern.ch/user/n/nminafra/Work/TimingKU/FNAL_Nov18/Tektronix_DPO7254Control/TimingAnalysis/
OUT_DIR=${CODE_DIR}/Results/
# runs=($(ls -d ${FNAL_SCOPE_DIR}/ROOT/*.root))

run_i=$(( $1 + 0 ))

runs=(W5_1_LP_165V_Ch1        W5_1_LP_175V_Ch1        W5_1_LP_185V_Ch1        W5_1_LP_195V_Ch1        W5_1_LP_200V_Ch1        W5_1_LP_205V_Ch1 \
      W5_1_LP8e14_315V_Ch2    W5_1_LP8e14_335V_Ch2    W5_1_LP8e14_355V_Ch2    W5_1_LP8e14_365V_Ch2    W5_1_LP8e14_375V_Ch2    W5_1_LP8e14_380V_Ch2 \
      W5_1_LP8e14_390V_Ch2    W5_1_LP8e14_395V_Ch2    W5_1_LP8e14_400V_Ch2  \
      W5_1_LP1p5e15_350V_Ch3  W5_1_LP1p5e15_370V_Ch3  W5_1_LP1p5e15_390V_Ch3  W5_1_LP1p5e15_400V_Ch3  W5_1_LP1p5e15_410V_Ch3  W5_1_LP1p5e15_415V_Ch3 \
      W5_1_LP1p5e15_425V_Ch3  W5_1_LP1p5e15_435V_Ch3  W5_1_LP1p5e15_445V_Ch3  W5_1_LP1p5e15_455V_Ch3  W5_1_LP1p5e15_465V_Ch3  W5_1_LP1p5e15_485V_Ch3 )
channels=(1                   1                       1                       1                       1                       1                      \
          2                   2                       2                       2                       2                       2                      \
          2                   2                       2                       \
          3                   3                       3                       3                       3                       3                      \
          3                   3                       3                       3                       3                       3  )
thresholds=(
      -0.016                  -0.018                  -0.018                  -0.02                   -0.02                   -0.022 \
      -0.014                  -0.014                  -0.014                  -0.018                  -0.02                   -0.02  \
      -0.02                   -0.02                   -0.03                   \
      -0.01                   -0.01                   -0.01                   -0.011                  -0.011                  -0.01  \
      -0.01                   -0.011                  -0.011                  -0.011                  -0.011                  -0.011 )

lowpass=(
      700e6                 700e6                  700e6                  700e6                 700e6                  700e6 \
      700e6                 700e6                  700e6                  700e6                 700e6                  700e6 \
      700e6                 700e6                  700e6                  \
      800e6                 800e6                  800e6                  800e6                  800e6                  800e6 \
      800e6                 800e6                  800e6                  800e6                  800e6                  800e6 )

cfd=(
      0.3                     0.3                     0.3                     0.3                     0.3                     0.3    \
      0.3                     0.3                     0.3                     0.3                     0.3                     0.3    \
      0.3                     0.3                     0.3                     \
      0.6                     0.6                     0.6                     0.6                     0.6                     0.6    \
      0.6                     0.6                     0.6                     0.6                     0.6                     0.6    )

echo ${runs[${run_i}]} ${channels[${run_i}]} ${thresholds[${run_i}]}

${CODE_DIR}/analyzeDataVsMCP -f ${channels[$run_i]} -t ${thresholds[$run_i]} -c ${cfd[$run_i]} -s 0.088 --lowpass ${lowpass[$run_i]} --MCPsaturation 0.4 --MCPthreshold -0.05 -i ${FNAL_SCOPE_DIR}/Analyzed/merged/${runs[${run_i}]}.root -o ${OUT_DIR}

# for (( run_i=0; run_i<27; run_i++ ));
# do
#   echo ${CODE_DIR}/analyzeDataVsMCP -f ${channels[$run_i]} -t ${thresholds[$run_i]} -c 0.5 -s 0.088 --lowpass 00e6 --MCPsaturation 0.4 --MCPthreshold -0.05 -i ${FNAL_SCOPE_DIR}/Analyzed/merged/${runs[${run_i}]}.root -o ${FNAL_SCOPE_DIR}/Analyzed/results/
# done
