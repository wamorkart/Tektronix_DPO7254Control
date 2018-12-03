# TimingAnalysis

Code for timing analysis. Author: **Nicola Minafra**

* source ../includes.CMSTimingSetup.sh
* Usage:
```
$> make
$> ./example_analyzeData --help
  Allowed options:
  -h [ --help ]                         produce help message
  -f [ --firstchannel ] arg (=0)        Channel under analysis (the other channel is set to MCP by default)
  -s [ --saturation ] arg (=1)          Saturation channel under analysis
  -c [ --cfd_threshold ] arg (=0.4)     CFD fraction
  -t [ --threshold_ch1 ] arg (=-0.1)    Threshold for ch under analysis, negative for negative signals (V)
  -p [ --lowpass ] arg (=0)             Lowpass filter frequency (Hz)
  -j [ --hysteresis ] arg (=0.001)      Hysteresis for the discriminator (V)
  -t [ --treename ] arg (=pulse)        Name of the TTree
  --MCPthreshold                        Offline threshold MCP
  --MCPsaturation                       Cut saturation MCP
  -o [ --outputdir ] arg                output directory (=~/Work/public/Fermilab/Results)
  -i [ --filename ] arg                 input file

```

For Fermilab analysis:
```
$> ./example_analyzeData -i /afs/cern.ch/work/n/nminafra/public/Fermilab/  -f 1 -t -0.03 -s 0/6 -c 0.5 --lowpass 700e6[...]
```

The output root file is saved in **Results/** with the same name of the input file, plus **_result_ch0_ch1.root**
Important plots:
- evN: graph of waveforms
- h_deltat_Smart: time difference between the two channels with the method ComputeExactTimeCFD in  `/TimingAnalysis/include/timingAlgorithm.h`
- h_max_selected_DetN: amplitude of only events selected for timing analysis
- h_SNR_DetN: SNR computed event by event


NOTE: Root required, <br />
on lxplus:
```
$> . /cvmfs/sft.cern.ch/lcg/releases/LCG_88/ROOT/6.08.06/x86_64-slc6-gcc62-opt/ROOT-env.sh
$> make

To run the analysis like it is:
$> . run_withLowpass.sh N

with N:0..26 to choose the input file:
0  : W5_LP_165V
1  : W5_LP_175V
2  : W5_LP_185V
3  : W5_LP_195V
4  : W5_LP_200V
5  : W5_LP_205V
6  : W5_LP8e14_315V
7  : W5_LP8e14_335V
8  : W5_LP8e14_355V
9  : W5_LP8e14_365V
10 : W5_LP8e14_375V
11 : W5_LP8e14_380V
12 : W5_LP8e14_390V
13 : W5_LP8e14_395V
14 : W5_LP8e14_400V
15 : W5_LP1p5e15_350V
16 : W5_LP1p5e15_370V
17 : W5_LP1p5e15_390V
18 : W5_LP1p5e15_400V
19 : W5_LP1p5e15_410V
20 : W5_LP1p5e15_415V
21 : W5_LP1p5e15_425V
22 : W5_LP1p5e15_435V
23 : W5_LP1p5e15_445V
24 : W5_LP1p5e15_455V
25 : W5_LP1p5e15_465V
26 : W5_LP1p5e15_485V

```
