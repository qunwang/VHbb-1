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
    outputDir=argv[1]
else:
    outputDir='plots'

if len(argv)>2:
    inputDir=argv[2]
else:
    inputDir='/eos/uscms/store/user/jstupak/Vh/step4/2014_3_12' #Step 4
    #inputDir='/eos/uscms/store/user/sethzenz/fromdcache/' #Step 3

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

DEBUG=False

doCutTable=True
doLimitSetting=False

doCuts=[
        'bdt',
        #'mjj',
        #'WLF',
        #'WHF',
        #'ttbar'
        ]

doVtypes=[
          2,
          3
          ]

doBoosts=[
          'low',
          'med',
          'high'
          ]

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

overflowBin=False   #FIXME - not implemented

doShapeComparison=False   #FIXME - not updated

#FIXME - these are not correct for ReReco
elLumi=19040
muLumi=19040

ewkFracUnc=.2
topFracUnc=.15
otherFracUnc=.15
lumiFracUnc=.022   #FIXME?

signalMagFrac=25

treeName='tree'
                
#---------------------------------------------------------------------------------------------------------------------------------------------

if doLimitSetting:
    doVtypes=[2,3]
    doBoosts=['low','med','high']
    doCutTable=False
    
if doCutTable:
    doLimitSetting=False

##################################################################################################################################################################
                                    
if __name__=='__main__':
    
    print 'Welcome to doPostProc!'
    logFile = open(outputDir + '/log.txt','w')
    logFile.close()

    yields={}
    plots=[]
    for cuts in doCuts:
        yields[cuts]={}
    
    for Vtype in doVtypes:
        for cuts in doCuts:
            yields[cuts][Vtype]={}
            for boost in doBoosts:
                yields[cuts][Vtype][boost]={}
        
                if doCutTable:
                    plots+=[Plot(name='dummy',distribution='H.pt',nBins=1,xMin=0,xMax=500000,cuts=cuts,Vtype=Vtype,boost=boost)]
                    
                else:
                    plots+=[
                            #Plot(name='h_pT',distribution='H.pt',nBins=25,xMin=0,xMax=500,xTitle='p_{T}(h) [GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='h_mass',distribution='H.mass',nBins=25,xMin=0,xMax=500,xTitle='m(h) [GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='h_eta',distribution='H.eta',nBins=20,xMin=-4,xMax=4,xTitle='#eta(h)',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='h_dRjj',distribution='H.dR',nBins=20,xMin=0,xMax=10,xTitle='#deltaR(j_{1},j_{2})',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            Plot(name='hJet1_ptCorr',distribution='hJet_ptCorr[0]',nBins=25,xMin=0,xMax=500,xTitle='p_{T}(j_{1}) [GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='hJet2_ptCorr',distribution='hJet_ptCorr[1]',nBins=25,xMin=0,xMax=500,xTitle='p_{T}(j_{2}) [GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='hJet1_csv',distribution='hJet_csv[0]',nBins=25,xMin=0,xMax=1,xTitle='csv(j_{1}) [GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='hJet2_csv',distribution='hJet_csv[1]',nBins=25,xMin=0,xMax=1,xTitle='csv(j_{2}) [GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='V_pT',distribution='V.pt',nBins=25,xMin=0,xMax=500,xTitle='p_{T}(V) [GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='METtype1corr_et',distribution='METtype1corr.et',nBins=25,xMin=0,xMax=500,xTitle='E_{T}^{miss} [GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='METtype1corr_sig',distribution='METtype1corr.sig',nBins=25,xMin=0,xMax=10,xTitle='E_{T}^{miss} significance',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='naJets',distribution='naJets',nBins=20,xMin=0,xMax=30,xTitle='N_{aj}',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='nalep',distribution='nalep',nBins=20,xMin=0,xMax=20,xTitle='N_{al}',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='HVdPhi',distribution='HVdPhi',nBins=20,xMin=0,xMax=3.3,xTitle='#Delta#phi(V,H)',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='lMETdPhi',distribution='lMETdPhi',nBins=20,xMin=-3.3,xMax=3.3,xTitle='#Delta#phi(E_{T}^{miss},l)',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='x_costheta1',distribution='x_costheta1',nBins=20,xMin=-1,xMax=1,xTitle='Cos(#theta_{1})',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='x_costheta2',distribution='x_costheta2',nBins=20,xMin=-1,xMax=1,xTitle='Cos(#theta_{2})',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='x_phi',distribution='x_phi',nBins=20,xMin=-3.3,xMax=3.3,xTitle='#phi',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='x_costhetastar',distribution='x_costhetastar',nBins=20,xMin=0,xMax=1,xTitle='Cos(#theta*)',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='x_phi1',distribution='x_phi1',nBins=20,xMin=-3.3,xMax=3.3,xTitle='#phi_{1}',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='x_mVH',distribution='x_mVH',nBins=25,xMin=0,xMax=1000,xTitle='m(VH)[GeV]',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                            #Plot(name='x_rapidityVH',distribution='x_rapidityVH',nBins=20,xMin=-3,xMax=3,xTitle='y(VH)',yLog=False,cuts=cuts,Vtype=Vtype,boost=boost),
                        ]
    
    for plot in plots:
        y=plot.Prepare()
        try: yields[plot.cuts][plot.Vtype][plot.boost]=y
        except: pass
        plot.Draw()

    cWidth=15; nameWidth=30
    for Vtype in doVtypes:
        for cuts in doCuts:
            print ("VTYPE: "+str(Vtype)).ljust(nameWidth+(2*cWidth+1))
            print ("CUTS: "+cuts).ljust(nameWidth+(2*cWidth+1))
            print "".ljust(nameWidth),
            for boost in doBoosts: print boost.ljust(cWidth),
            print
            for sample in ['Wlight','Wb','Wbb','EWK','top','other']:
                print sample.ljust(nameWidth),
                try:
                    for boost in doBoosts:
                        print str(int(round(yields[cuts][Vtype][boost][sample]))).ljust(cWidth),
                except: pass
                print
            for sample in samples:
                #if sample.isData: continue
                print sample.name.ljust(nameWidth),
                try:
                    for boost in doBoosts:
                        print str(int(round(yields[cuts][Vtype][boost][sample.name]))).ljust(cWidth),
                except: pass
                print
            for sample in ['Total Background','Data']:
                print sample.ljust(nameWidth),
                for boost in doBoosts:
                    print str(int(round(yields[cuts][Vtype][boost][sample]))).ljust(cWidth),
                print
            print 'Background/Data'.ljust(nameWidth),
            for boost in doBoosts:
                try: print str(round(yields[cuts][Vtype][boost]['Total Background']/yields[cuts][Vtype][boost]['Data'],3)).ljust(cWidth),
                except: pass
            print 3*'\n'


