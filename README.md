# DPO7254Control
Tektronix DPO7254 Oscilloscope stand-alone and DAQ-integrated control implemented for Test Beam Fermilab (November20018). 

- [Quick start](#quick-start)
  * [Installation](#installation)
  * [Required directories](#required-directories)
- [Standalone-configuration](#standalone-configuration)
  * [Output files](#output_files) 
  * [Files reconstruction](#.root-files-reconstruction) 

  :)
  
  
  
  
  ## Quick start
 The Phyton script to run the acquisition can be found in the machine otsdaq@ftbf-daq-08. You'll need to create the python environment 
 
 - kinit 'username.FNAL.GOV'
 - ssh otsdaq@ftbf-daq-08.FNAL.GOV   (you need to be included in the users list)
 - cd /home/otsdaq/NetScope_standalone/Tektronix_DPO7254Control/RunOscilloscope
 - source /includes/CMSTimingSetup.sh 
  
  ### Installation
  no need to install a new python version. 
  IF NOT ALREADY DONE: Need to locally install pipenv to download needed libraries.
  
  ### Required directories
  
 - Python 2.7 or newer 
 - pyvisa, pyvisa-py, numpy
 - pip install 'library'
 
 
 ## Standalone configuration
 The oscilloscope can run completely independent from the Otsdaq. The number of triggers to acquire is set as script options.
 
  - python dpo_fastframe.py --totalNumber= 'int'  --numFrames='int' 
 
 REMEMBER: 
 * File Number =  # of triggers(totalNumber) / # of trigger for each file(numFrames)
 * numFrames is not striclty required, set to 500 by default
 
 
 ### Output Raw files
 The Raw data files generated are binary waveforms file in the format ".wfm". They can be recalled from the scope to be displayed. 
 The files are saved locally in a shared directory connected to the ftbf-daq-08: 
 /Tektronix
 
 
 IMPORTANT: every time the Oscilloscope is switched off the shared disk need to be mounted (ask Lorenzo)
 
[otsdaq@ftbf-daq-08 Tektronix]
 

### Files reconstruction
To reconstruct root files from the RAW wfm
- cd /home/otsdaq/NetScope_standalone/Tektronix_DPO7254Control/Reconstruction/
- source /includes/CMSTimingSetup.sh 
- conversion.py InputDir RECO/OutputFile

 REMEMBER:
 
 
 
 
