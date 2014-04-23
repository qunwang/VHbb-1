#!/bin/bash
theDir=$1
condorDir=$PWD

source /uscmst1/prod/sw/cms/shrc prod

cd $theDir
eval `scramv1 runtime -sh`

python doPostProc.py $condorDir
