#!/bin/bash

if [ -z $BIGASSNUMBER]; then
	BIGASSNUMBER=10000000	
fi

if [ -z $1 ]; then
	RUNNUMBER=10
else
	RUNNUMBER=$1
fi

if [ -z $2 ]; then
        SLEEPLENGTH=1
else    
        SLEEPLENGTH=$2
fi

if [ ! -z $3 ]; then
        PRIMESTOFIND=$3
fi
echo $BIGASSNUMBER
BIGASSNUMBER=$RUNNUMBER
echo $BIGASSNUMBER

COUNTER=0
while [ $COUNTER -lt $BIGASSNUMBER ]; do
	echo The counter is $COUNTER of $BIGASSNUMBER
	Prime $PRIMESTOFIND
	let COUNTER=$COUNTER+1
	sleep $SLEEPLENGTH
done

BIGASSNUMBER=10000000
