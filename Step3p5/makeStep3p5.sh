#!/bin/bash

macroDir=${1}
inputDir=${2}
inputDirNom=${3}

scratch=${PWD}
scramv1 project CMSSW CMSSW_5_3_6
cd CMSSW_5_3_6/src
eval `scramv1 runtime -sh`

cp -p $macroDir/*.cc .
cp -p $macroDir/*.so .
cp -p $macroDir/*.d .
export PATH=$PATH:$macroDir

for file in `ls $inputDir`; do
    if [[ $file == *root ]]; then
    XRDpath=root://cmsxrootd-site.fnal.gov//store/${inputDir##/eos/uscms/store/}
    XRDpathNom=root://cmsxrootd-site.fnal.gov///store/${inputDirNom##/eos/uscms/store/}
	root -l -b -q $macroDir/makeStep3p5.C\(\"$macroDir\",\"$XRDpath/$file\",\"$XRDpathNom/$file\",\"$scratch/$file\"\)
    fi
done
