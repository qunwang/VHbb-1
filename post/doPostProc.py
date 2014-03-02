from ROOT import *

from Sample import *
from Plot import *
from cuts import *

from tdrStyle import *
from sys import argv
from array import array
import os

setTDRStyle()
gStyle.SetOptStat(False)
gROOT.SetBatch(1)

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if len(argv)>1:
    inputDir=argv[1]
else:
    inputDir='/uscms_data/d1/jstupak/Vh/step4/2014_3_1'

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

DEBUG=False

doCutTable=False
doLimitSetting=False

doCuts=['mjj']
#doCuts=['mjj','bdt','WLF','WHF','ttbar']

#0=Z->mumu, 1=Z->ee, 2=W->munu, 3=W->enu
doChannels=[2,3]
#doChannels=[3]
#doChannels=[4]

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

overflowBin=False   #FIXME - not implemented

doShapeComparison=False   #FIXME - not updated

outputDir='plots'

#FIXME - these are not correct for ReReco
elLumi=19624
muLumi=19624

ewkFracUnc=.2
topFracUnc=.15
otherFracUnc=.15
lumiFracUnc=2.2

signalMagFrac=1

treeName='tree'
                
#---------------------------------------------------------------------------------------------------------------------------------------------

if doLimitSetting:
    doChannels=[3,4]
    doCutTable=False
    
if doCutTable:
    doLimitSetting=False

##################################################################################################################################################################
                                    
if __name__=='__main__':

    plots=[
        Plot(name='H_pT',distribution='H.pt',nBins=50,xMin=0,xMax=500,xTitle='p_{T}(h) [GeV]',yLog=True,cuts='mjj',channel=2),
        Plot(name='H_pT2',distribution='H.pt',nBins=50,xMin=0,xMax=500,xTitle='p_{T}(h) [GeV]',yLog=True,cuts='mjj',channel=3),
        ]

    """
    yields={}
    plots=[]
    for cuts in doCuts:
        yields[cuts]={}
        if doCutTable:
            plots+=[Plot(name='electron0_pt',distribution='elec_1_pt_ChargedHiggsCalc',nBins=100,xMin=0,xMax=7000,xTitle='electron p_{T} [GeV]',yLog=True,cuts=cuts,channel=4),
                    Plot(name='muon0_pt',distribution='muon_1_pt_ChargedHiggsCalc',nBins=100,xMin=0,xMax=7000,xTitle='muon p_{T} [GeV]',yLog=True,cuts=cuts,channel='mu')
                    ]

        elif getWhfCorrections:
            plots+=[Plot(name='muon0_pt',distribution='muon_1_pt_ChargedHiggsCalc',nBins=100,xMin=0,xMax=7000,xTitle='muon p_{T} [GeV]',yLog=True,cuts=cuts,channel='mu')]

        else:
            plots+=[#Plot(name='electron0_pt',distribution='elec_1_pt_ChargedHiggsCalc',nBins=70,xMin=0,xMax=700,xTitle='electron p_{T} [GeV]',yLog=True,cuts=cuts,channel='el'),
                    #Plot(name='electron0_eta',distribution='elec_1_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='electron #eta',yLog=False,cuts=cuts,channel='el'),
                    #Plot(name='electron0_RelIso',distribution='elec_1_RelIso_ChargedHiggsCalc',nBins=30,xMin=0,xMax=0.15,xTitle='electron Rel. Isolation',yLog=True,cuts=cuts,channel='el'),

                    #Plot(name='muon0_pt',distribution='muon_1_pt_ChargedHiggsCalc',nBins=70,xMin=6,xMax=706,xTitle='muon p_{T} [GeV]',yLog=True,cuts=cuts,channel='mu'),
                    #Plot(name='muon0_eta',distribution='muon_1_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='muon #eta',yLog=False,cuts=cuts,channel='mu'),
                    #Plot(name='muon0_RelIso',distribution='muon_1_RelIso_ChargedHiggsCalc',nBins=30,xMin=0,xMax=0.15,xTitle='muon Rel. Isolation',yLog=True,cuts=cuts,channel='mu')
                    ]


            for channel in doChannels:
                plots+=[###Plot(name='BestJetJet2W_M',distribution='BestJetJet2W_M_LjetsTopoCalcNew',nBins=68,xMin=100,xMax=3500,xTitle='M(tb) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        ###Plot(name='Jet1Jet2W_M',distribution='Jet1Jet2W_M_LjetsTopoCalcNew',nBins=68,xMin=100,xMax=3500,xTitle='M(tb) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='corr_met',distribution='corr_met_ChargedHiggsCalc',nBins=70,xMin=0,xMax=700,xTitle='E_{T}^{miss} [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet0_pt',distribution='jet_0_pt_ChargedHiggsCalc',nBins=100,xMin=0,xMax=1000,xTitle='p_{T} (jet1) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet0_eta',distribution='jet_0_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='#eta (jet1)',yLog=False,cuts=cuts,channel=channel),
                        #Plot(name='PFjet1_pt',distribution='jet_1_pt_ChargedHiggsCalc',nBins=80,xMin=0,xMax=800,xTitle='p_{T} (jet2) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet1_eta',distribution='jet_1_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='#eta (jet2)',yLog=False,cuts=cuts,channel=channel),
                        #Plot(name='PFjet2_pt',distribution='jet_2_pt_ChargedHiggsCalc',nBins=80,xMin=0,xMax=800,xTitle='p_{T} (jet3) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet2_eta',distribution='jet_2_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='#eta (jet3)',yLog=False,cuts=cuts,channel=channel),
                        #Plot(name='PFjet3_pt',distribution='jet_3_pt_ChargedHiggsCalc',nBins=80,xMin=0,xMax=800,xTitle='p_{T} (jet4) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet3_eta',distribution='jet_3_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='#eta (jet4)',yLog=False,cuts=cuts,channel=channel),
                        #Plot(name='PFjet4_pt',distribution='jet_4_pt_ChargedHiggsCalc',nBins=80,xMin=0,xMax=800,xTitle='p_{T} (jet5) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet4_eta',distribution='jet_4_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='#eta (jet5)',yLog=False,cuts=cuts,channel=channel),
                        #Plot(name='PFjet5_pt',distribution='jet_5_pt_ChargedHiggsCalc',nBins=80,xMin=0,xMax=800,xTitle='p_{T} (jet6) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet5_eta',distribution='jet_5_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='#eta (jet6)',yLog=False,cuts=cuts,channel=channel),
                        #Plot(name='PFjet6_pt',distribution='jet_6_pt_ChargedHiggsCalc',nBins=80,xMin=0,xMax=800,xTitle='p_{T} (jet7) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet6_eta',distribution='jet_6_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='#eta (jet7)',yLog=False,cuts=cuts,channel=channel),
                        #Plot(name='PFjet7_pt',distribution='jet_7_pt_ChargedHiggsCalc',nBins=80,xMin=0,xMax=800,xTitle='p_{T} (jet8) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='PFjet7_eta',distribution='jet_7_eta_ChargedHiggsCalc',nBins=50,xMin=-2.5,xMax=2.5,xTitle='#eta (jet8)',yLog=False,cuts=cuts,channel=channel),
                        
                        ###Plot(name='TopMass_Best',distribution='BestTop_LjetsTopoCalcNew',nBins=100,xMin=0,xMax=1000,xTitle='M(best jet,W) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        ###Plot(name='TopPt_Best',distribution='BestTop_Pt_LjetsTopoCalcNew',nBins=150,xMin=0,xMax=1500,xTitle='p_{T}(best jet,W) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='Pt_Jet1Jet2',distribution='Jet1Jet2_Pt_LjetsTopoCalcNew',nBins=150,xMin=0,xMax=1500,xTitle='p_{T}(jet1,jet2) [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='HT',distribution='Ht_LjetsTopoCalcNew',nBins=125,xMin=0,xMax=2500,xTitle='H_{T} [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='ST',distribution='jet_0_pt_ChargedHiggsCalc+jet_1_pt_ChargedHiggsCalc+((elec_1_pt_ChargedHiggsCalc>0)*elec_1_pt_ChargedHiggsCalc)+((muon_1_pt_ChargedHiggsCalc>0)*muon_1_pt_ChargedHiggsCalc)+corr_met_ChargedHiggsCalc',nBins=150,xMin=0,xMax=3000,xTitle='S_{T} [GeV]',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='nPV',distribution='nPV_ChargedHiggsCalc',nBins=50,xMin=0,xMax=50,xTitle='# Vertices',yLog=True,cuts=cuts,channel=channel),
                        #Plot(name='Nj',distribution='nSelJets_CommonCalc',nBins=7,xMin=1.5,xMax=8.5,xTitle='N_{jets}',yLog=True,cuts=cuts,channel=channel)
                        ]

    """
    
    for plot in plots:
        y=plot.Prepare()
        try: yields[plot.cuts][str(plot.channel)]=y
        except: pass
        plot.Draw()

    """

    #FIXME
    cWidth=15; nameWidth=30
    for channel in doChannels:
        print ("CHANNEL:"+str(channel)).ljust(nameWidth+(2*cWidth+1)),"N_b"
        print "".ljust(nameWidth),
        for cuts in doCuts: print cuts.ljust(cWidth),
        print
        for sample in ['Data','W+light','W+c','W+b']:
            print sample.ljust(nameWidth),
            for cuts in doCuts:
                print str(int(round(yields[cuts][str(channel)][sample]))).ljust(cWidth),
                #print str(yields[cuts][str(channel)][sample]).ljust(cWidth),
            print
        for sample in samples:
            if (str(channel)=='el' and 'SingleMu' in sample.name) or (str(channel)=='mu' and 'SingleEl' in sample.name): continue
            #if sample.isData: continue
            print sample.name.ljust(nameWidth),
            for cuts in doCuts:
                print str(int(round(yields[cuts][str(channel)][sample.name]))).ljust(cWidth),
                #print str(yields[cuts][str(channel)][sample.name]).ljust(cWidth),
            print
        for sample in ['Total Background']:
            print sample.ljust(nameWidth),
            for cuts in doCuts:
                print str(int(round(yields[cuts][str(channel)][sample]))).ljust(cWidth),
                #print str(yields[cuts][str(channel)][sample]).ljust(cWidth),
            print
        print 'Background/Data'.ljust(nameWidth),
        for cuts in doCuts:
            print str(round(yields[cuts][str(channel)]['Total Background']/yields[cuts][str(channel)]['Data'],3)).ljust(cWidth),
        print 3*'\n'
        
    """
