#!/bin/bash

macroDir=${1}
inputDir=${2}

scratch=${PWD}
scramv1 project CMSSW CMSSW_5_3_6
cd CMSSW_5_3_6/src
eval `scramv1 runtime -sh`

cp -p $macroDir/*.cc .
cp -p $macroDir/*.so .
cp -p $macroDir/*.d .
cp $macroDir/EleRecoId.Presel.2012ABCD.root .
export PATH=$PATH:$macroDir

for file in `ls $inputDir`; do
    if [[ $file == *root ]]; then
	XRDpath=root://cmsxrootd-site.fnal.gov//store/${inputDir##/eos/uscms/store/}
	#echo root -l -b -q $macroDir/makeStep4.C\(\"$macroDir\",\"$XRDpath/$file\",\"$scratch/$file\"\)
	root -l -b -q $macroDir/makeStep4.C\(\"$macroDir\",\"$XRDpath/$file\",\"$scratch/$file\"\)
    fi
done
