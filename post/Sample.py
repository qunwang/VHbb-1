from copy import deepcopy
from glob import glob
from ROOT import *

class Sample:

    def __init__(self,name,sampleType=None,inputDir=None,fileIdentifier='',altName=None,channel=None):
        self.name=name;  self.inputDir=inputDir; self.fileIdentifier=fileIdentifier; self.altName=altName; self.channel=channel

        self.setType(sampleType)
        
    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    def setType(self,sampleType):
        if type(sampleType)!=type(''): return

        self.type=sampleType.lower()

        self.isData=False; self.isMC=False; self.isSignal=False; self.isBackground=False;
        if self.type=='data':
            self.isData=True
        elif self.type=='signal':
            self.isMC=True
            self.isSignal=True
        else:
            self.isMC=True
            self.isBackground=True

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    def setInputList(self,path):
        if not self.inputDir:
            print "No inputDir specified for sample:",self.name
            return

        path+='/'+self.inputDir
        self.inputList=glob(path+'/*'+self.fileIdentifier+'*.root')

        if len(self.inputList)==0:
            print "No input files found for sample:",self.name
            return

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    def makeTChain(self,treeName):
        if not self.inputList:
            print "No inputList specified for sample:",self.name

        self.chain=TChain(treeName)
        for file in self.inputList:
            self.chain.Add(file)

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    def clone(self,name):
        theClone=deepcopy(self)
        theClone.name=name
        return theClone

################################################################################################################################################

#name,sampleType,inputDir,fileIdentifier,altName,channel):

Wh_125p6_0P=Sample('Wh_125p6_0P','signal','nominal','Step2_WHiggs0P_M-125p6','Wh (CP = 0^{+})')
Wh_125p6_0PH=Sample('Wh_125p6_0PH','signal','nominal','Step2_WHiggs0PH_M-125p6')
Wh_125p6_0M=Sample('Wh_125p6_0M','signal','nominal','Step2_WHiggs0M_M-125p6','Wh (CP = 0^{-})')
Wh_125p6_0Mf05ph0=Sample('Wh_125p6_0Mf05ph0','signal','nominal','Step2_WHiggs0Mf05ph0_M-125p6')

signals=[Wh_125p6_0P,Wh_125p6_0PH,Wh_125p6_0M,Wh_125p6_0Mf05ph0]

WZ=Sample('WZ','VZ','nominal/WZ_lumiWeighted')
ZZ=Sample('ZZ','VZ','nominal/ZZ_lumiWeighted')
WW=Sample('WW','VV','nominal/WW_lumiWeighted')

diboson=[WZ,ZZ,WW]

WJets=Sample('WJets','WJets','nominal/WJets_boostedMG_lumiWeighted')

ZJets=Sample('ZJets','ZJets','nominal/ZJets_boostedMG_lumiWeighted')

TTbar_FullLept=Sample('TTbar_FullLept','ttbar','nominal/TTbar_FullLept_lumiWeighted')
TTbar_SemiLept=Sample('TTbar_SemiLept','ttbar','nominal/TTbar_SemiLept_lumiWeighted')
TTbar_Hadronic=Sample('TTbar_Hadronic','ttbar','nominal/TTbar_Hadronic_lumiWeighted')

ttbar=[TTbar_FullLept,TTbar_SemiLept,TTbar_Hadronic]

singleTop_sChannel=Sample('singleTop_sChannel','singleTop','nominal/SingleTop_sChannel_lumiWeighted')
singleTop_tChannel=Sample('singleTop_tChannel','singleTop','nominal/SingleTop_tChannel_lumiWeighted')
singleTop_tW=Sample('singleTop_tW','singleTop','nominal/SingleTop_tW_lumiWeighted')

singleTop=[singleTop_sChannel,singleTop_tChannel,singleTop_tW]

QCD_BCtoE=Sample('QCD_BCtoE','QCD','nominal/QCD_BCtoE_80toInf_lumiWeighted',channel='el')
QCD_Inclusive=Sample('QCD_Inclusive','QCD','nominal/QCD_Inclusive_50toInf_lumiWeighted',channel='el')   #FIXME - Is this correct?
QCD_MuEnriched=Sample('QCD_MuEnriched','QCD','nominal/QCD_MuEnrichedPt5_80toInf_lumiWeighted',channel='mu')

QCD=[QCD_BCtoE,QCD_Inclusive,QCD_MuEnriched]

dataEl=Sample('DataEl','Data','Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_DATA_split_varsBDTsAdded_v19','SingleElectron',channel='el')
dataMu=Sample('DataMu','Data','Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_DATA_split_varsBDTsAdded_v19','SingleMu',channel='mu')

data=[dataEl,dataMu]

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

samplesForPlotting=[Wh_125p6_0P,Wh_125p6_0M]+diboson+[WJets,ZJets]+ttbar+singleTop+QCD+data
allSamples=samplesForPlotting+[Wh_125p6_0PH,Wh_125p6_0Mf05ph0]
