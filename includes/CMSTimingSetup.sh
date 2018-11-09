#!/bin/bash

export KRB5CCNAME=FILE:/tmp/krb5cc_otsdaq_daq;

source /data-08/otsdaq/setup_ots.sh

export USER_DATA=/data-08/TestBeam/Users/cmstiming/2018_11_November_CMSTiming_userdata
export ARTDAQ_DATABASE_URI=filesystemdb:///data-08/TestBeam/Users/cmstiming/2018_11_November_CMSTiming_database
export OTSDAQ_DATA=/data/TestBeam/2018_11_November_CMSTiming


echo "ARTDAQ_DATABASE_URI=$ARTDAQ_DATABASE_URI"
echo "USER_DATA=$USER_DATA"

IS_INTERACTIVE=0
case $- in *i*)  
	IS_INTERACTIVE=1
esac

if [ $IS_INTERACTIVE -eq 0 ] || [[ "x$1" != "x" ]]; then
	StartOTS.sh
	if [[ "$HOSTNAME" == "ftbf-daq-08.fnal.gov" ]]; then
#		ssh ftbf-daq-07 /data-08/otsdaq/setup_fermilabtestbeam.sh &
#		ssh ftbf-daq-06 /data-08/otsdaq/setup_fermilabtestbeam.sh &
		ssh ftbftracker02 /data-08/otsdaq/setup_fermilabtestbeam.sh &
  	fi

	if [[ "x$1" == "xw" ]]; then
	    firefox https://ftbf-daq-08/
        fi
fi
