#!/bin/bash

macroDir=${1}
inputDir=${2}

scratch=${PWD}
scramv1 project CMSSW CMSSW_5_3_6
cd CMSSW_5_3_6/src
eval `scramv1 runtime -sh`

cp $macroDir/makeStep4* .
cp $macroDir/METzCalculator* .

for file in `ls $inputDir`; do
    if [[ $file == *root ]]; then
	root -l -b -q $macroDir/makeStep4.C\(\"$inputDir/$file\",\"$scratch/$file\"\)+
    fi
done
