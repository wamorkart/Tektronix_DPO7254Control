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
```
