from ROOT import *

from Sample import *
#samples=samplesForPlotting
samples=allSamples
from cuts import *
from doPostProc import *
from scaleFactors import *
from utils import *

import os,sys

from array import array

PUWeight='PUweight'
#trigWeightEl='weightTrig2012SingleEle'
#trigWeightMu='weightTrig2012SingleMuon'
trigWeightEl='weightTrig2012A'
trigWeightMu='weightTrig2012A'

if not os.path.isdir(outputDir): os.system("mkdir -p "+outputDir)
output=TFile(outputDir+'/plots.root',"RECREATE")

TH1.SetDefaultSumw2(True)

class Plot:

    def __init__(self,name,distribution,bins=None,nBins=100,xMin=0,xMax=100,xTitle='',yLog=True,cuts="bdt",Vtype=3,boost='low'):
        self.name=name; self.distribution=distribution; self.bins=bins; self.nBins=nBins; self.xMin=xMin; self.xMax=xMax; self.xTitle=xTitle; self.yLog=yLog; self.cuts=cuts; self.Vtype=Vtype; self.boost=boost
        if self.bins:
            self.nBins=len(self.bins)-1
            self.xMin=self.bins[0]
            self.xMax=self.bins[-1]
        else:
            self.bins=[]
            for n in range(self.nBins+1):
                self.bins.append(self.xMin+n*(float(self.xMax-self.xMin)/self.nBins))
        self.bins=array('f',self.bins)

        self.extraHists={}

        #make name unique
        self.name+='_'+self.cuts+'_Vtype'+str(self.Vtype)+'_'+self.boost+'Boost'
        
        if (self.Vtype==0 or self.Vtype==2):
            self.lumi=muLumi
            self.trigWeight=trigWeightMu
        elif (self.Vtype==1 or self.Vtype==3):
            self.lumi=elLumi
            self.trigWeight=trigWeightEl

        for sample in reversed(samples):

            if (((sample.systematic=='JECDown' or sample.systematic=='JECUp') and not (doAllSys or doJECSys)) or 
                ((sample.systematic=='JERDown' or sample.systematic=='JERUp') and not (doAllSys or doJERSys)) or 
                ((sample.systematic=='btagDown' or sample.systematic=='btagUp') and not (doAllSys or doBTagSys)) or 
                ((sample.systematic=='mistagDown' or sample.systematic=='mistagUp') and not (doAllSys or doMisTagSys))): samples.remove(sample)

    #---------------------------------------------------------------------------------------------------------------------------------------------------------            

    def newHist(self, name, Sumw2=True):
        result=TH1F(self.name+'__'+name,";"+self.xTitle,self.nBins,self.bins)
        if Sumw2: result.Sumw2()
        return result

    #---------------------------------------------------------------------------------------------------------------------------------------------------------

    def skip(self, sample):
        if (self.Vtype==0 or self.Vtype==2) and sample.channel=='el': return True
        if (self.Vtype==1 or self.Vtype==3) and sample.channel=='mu': return True
        if (not doWJetsShapeSys and not doAllSys) and isEqual(sample.type,'WJets') and 'shape' in sample.name: return True
        if (not doTTbarShapeSys and not doAllSys) and isEqual(sample.type,'ttbar') and 'shape' in sample.name: return True
        else: return False
                    
    #---------------------------------------------------------------------------------------------------------------------------------------------------------
    
    def Prepare(self):
        yields={}
        
        #get histograms with proper normalization
        for sample in samples:
            print sample.name
            
            if self.skip(sample): continue
        
            sample.setInputList(inputDir)
            sample.makeTChain(treeName)
                        
            #hName=self.name+'__'+sample.name
            sample.h=self.newHist(sample.name)

            theCuts=cuts[self.Vtype][self.cuts]+' && Vtype=='+str(self.Vtype)
            if self.boost=='low': theCuts+=' && 100<V.pt && V.pt<130 && vLepton_pfCorrIso[0] < 0.075'
            if self.boost=='med': theCuts+=' && 130<V.pt && V.pt<180'
            if self.boost=='high': theCuts+=' && 180<V.pt'
            

            weight='1'
            if sample.isMC:
                theCuts = theCuts.replace('((EVENT.run<193834 && (triggerFlags[22]>0 || triggerFlags[23]>0)) || (EVENT.run>=193834 && (triggerFlags[14]>0 ||triggerFlags[21]>0)))','1')
                theCuts = theCuts.replace('(triggerFlags[44]>0)','1')
                theCuts = theCuts.replace('(!(207883<=EVENT.run && EVENT.run<=208307))','1')
                weight+=' * '+PUWeight 
                weight+=' * '+self.trigWeight
                if isEqual(sample.type,'WJets'): weight+=' * weightWpt_WJets'
                if isEqual(sample.type,'ttbar'): weight+=' * weightWpt_TTbar'
                weight+=' * weightEleTrigger'

                if sample.isSignal:
                    #weight+=' * weightSignalEWK'
                    #weight+=' * weightSignalQCD'
                    weight+=' * 1'

                weight+=' / effectiveLumi'

            if isEqual(sample.type,'WJets'):
                W_light='W_light'
                W_b='W_b'
                W_bb='W_bb'
                if sample.systematic:
                    W_light+='_'+sample.systematic
                    W_b+='_'+sample.systematic
                    W_bb+='_'+sample.systematic

                self.extraHists[W_light]=self.newHist(W_light)
                self.extraHists[W_b]=self.newHist(W_b)
                self.extraHists[W_bb]=self.newHist(W_bb)

                if not applyNormSFs:
                    scaleFactors[self.boost]['W_light'] = 1
                    scaleFactors[self.boost]['W_b'] = 1
                    scaleFactors[self.boost]['W_bb'] = 1
                
                sample.chain.Draw(self.distribution+'>>'+self.extraHists[W_light].GetName(),weight+' * '+str(scaleFactors[self.boost]['W_light'])+' * ('+theCuts+' && ((abs(hJet_flavour[0])==5)+(abs(hJet_flavour[1])==5))==0)','GOFF')
                sample.chain.Draw(self.distribution+'>>'+self.extraHists[W_b].GetName(),weight+' * '+str(scaleFactors[self.boost]['W_b'])    +' * ('+theCuts+' && ((abs(hJet_flavour[0])==5)+(abs(hJet_flavour[1])==5))==1)','GOFF')
                sample.chain.Draw(self.distribution+'>>'+self.extraHists[W_bb].GetName(),weight+' * '+str(scaleFactors[self.boost]['W_bb'])   +' * ('+theCuts+' && ((abs(hJet_flavour[0])==5)+(abs(hJet_flavour[1])==5))==2)','GOFF')

                sample.h.Add(self.extraHists[W_light])
                sample.h.Add(self.extraHists[W_b])
                sample.h.Add(self.extraHists[W_bb])
                
                self.extraHists[W_light].Scale(self.lumi)
                self.extraHists[W_b].Scale(self.lumi)
                self.extraHists[W_bb].Scale(self.lumi)

                yields[W_light]=self.extraHists[W_light].Integral(0,self.nBins+1)
                yields[W_b]=self.extraHists[W_b].Integral(0,self.nBins+1)
                yields[W_bb]=self.extraHists[W_bb].Integral(0,self.nBins+1)
                                                                
            else:
                if isEqual(sample.type,'ttbar') and applyNormSFs: scaleFactor=str(scaleFactors[self.boost]['ttbar'])
                else: scaleFactor='1'

                if DEBUG:
                    print '=============================='
                    print weight+' * '+scaleFactor
                    print '=============================='
                    print theCuts
                    print '=============================='

                val = sample.chain.Draw(self.distribution+">>"+sample.h.GetName(),weight+' * '+scaleFactor+' * ('+theCuts+')','GOFF')
                
                stdout_old = sys.stdout
                logFile = open(outputDir + '/log.txt','a')
                sys.stdout = logFile
                if DEBUG: print sample.name, self.Vtype, self.cuts, self.boost, sample.h.Integral()
                sys.stdout = stdout_old
                logFile.close()
                if DEBUG: print sample.h.Integral()
            
            if showOverflow:
                content=sample.h.GetBinContent(self.nBins)+sample.h.GetBinContent(self.nBins+1)
                error=sqrt(sample.h.GetBinError(self.nBins)**2+sample.h.GetBinError(self.nBins+1)**2)
                sample.h.SetBinContent(self.nBins,content)
                sample.h.SetBinError(self.nBins,error)
                sample.h.SetBinContent(self.nBins+1,0)
                sample.h.SetBinError(self.nBins+1,0)

            if sample.isMC: sample.h.Scale(self.lumi)
            yields[sample.name]=sample.h.Integral(0,self.nBins+1) #for cutflow table

        for sample in samples:
            if self.skip(sample) or isEqual(sample.type,'signal'): continue

            name=sample.type
            if sample.systematic: name+='_'+sample.systematic
            if not name in self.extraHists.keys():
                self.extraHists[name]=self.newHist(name)
                yields[name]=0
            self.extraHists[name].Add(sample.h)
            yields[name]+=sample.h.Integral(0,self.nBins+1)

        output.cd()
        self.signals=[]
        self.backgroundStack=THStack()
        
        for sample in samples:
            if self.skip(sample): continue
            
            if sample.isSignal:
                sample.h.Scale(signalMagFrac)
                sample.h.SetLineColor(1)
                sample.h.SetLineStyle(2+len(self.signals))
                self.signals.append(sample)
            elif sample.isBackground:
                pass
                #if isEqual(sample.type,'ttbar') or isEqual(sample.type,'singleTop'): self.extraHists['top'].Add(sample.h)
                #elif isEqual(sample.type,'WJets') or isEqual(sample.type,'ZJets'): self.extraHists['ewk'].Add(sample.h)
                #else: self.extraHists['other'].Add(sample.h)
            elif sample.isData:
                pass
                #self.extraHists['data'].Add(sample.h)
            sample.h.SetLineWidth(4)

        try:
            self.extraHists['VZ'].SetFillColor(ROOT.kRed-7)
            self.extraHists['VZ'].SetLineColor(ROOT.kRed-4)
        except: pass
        try:
            self.extraHists['VV'].SetFillColor(ROOT.kGray+2)
            self.extraHists['VV'].SetLineColor(ROOT.kGray+3)
        except:pass
        try:
            self.extraHists['WJets'].SetFillColor(ROOT.kGreen-3)
            self.extraHists['WJets'].SetLineColor(ROOT.kGreen-2)
        except:pass
        try:
            self.extraHists['ZJets'].SetFillColor(ROOT.kYellow-7)
            self.extraHists['ZJets'].SetLineColor(ROOT.kYellow-4)
        except:pass
        try:
            self.extraHists['ttbar'].SetFillColor(ROOT.kBlue-7)
            self.extraHists['ttbar'].SetLineColor(ROOT.kBlue-3)
        except:pass
        try:
            self.extraHists['singleTop'].SetFillColor(ROOT.kCyan-7)
            self.extraHists['singleTop'].SetLineColor(ROOT.kCyan-3)
        except:pass
        try:
            self.extraHists['QCD'].SetFillColor(ROOT.Magenta)
            self.extraHists['QCD'].SetLineColor(ROOT.Magenta+1)
        except:pass

        """
        self.extraHists['ewk'].SetFillColor(ROOT.kGreen-3)
        self.extraHists['ewk'].SetLineColor(ROOT.kGreen-2)
        self.extraHists['top'].SetFillColor(ROOT.kRed-7)
        self.extraHists['top'].SetLineColor(ROOT.kRed-4)
        self.extraHists['other'].SetFillColor(ROOT.kBlue-7)
        self.extraHists['other'].SetLineColor(ROOT.kBlue-3)
        self.extraHists['data'].SetMarkerStyle(20)
        """

        for b in ['QCD','ZJets','WJets','singleTop','ttbar','VV','VZ']:
            try: self.backgroundStack.Add(self.extraHists[b])
            except: pass

        self.background=self.backgroundStack.GetStack().Last().Clone(self.name+'_background'); self.background.Sumw2()
        yields['Total Background']=self.background.Integral(0,self.nBins+1)
        for key in self.extraHists.keys():
            yields[key]=self.extraHists[key].Integral(0,self.nBins+1)

        return yields

    #---------------------------------------------------------------------------------------------------------------------------------------------------------
    
    def Draw(self):
        gStyle.SetErrorX(0.5)

        self.canvas=TCanvas(self.name,"",1000,800)

        yDiv=0.35
        self.uPad=TPad("uPad","",0,yDiv,1,1) #for actual plots
        self.uPad.SetTopMargin(0.07)
        self.uPad.SetBottomMargin(0)
        self.uPad.SetRightMargin(.05)
        self.uPad.SetLeftMargin(.18)
        self.uPad.Draw()
                                    
        self.lPad=TPad("lPad","",0,0,1,yDiv) #for sigma runner
        self.lPad.SetTopMargin(0)
        self.lPad.SetBottomMargin(.4)
        self.lPad.SetRightMargin(.05)
        self.lPad.SetLeftMargin(.18)
        self.lPad.SetGridy()
        self.lPad.Draw()
                
        self.extraHists['Data'].SetMaximum(2*self.extraHists['Data'].GetMaximum())
        self.extraHists['Data'].SetMinimum(0.025)

        binWidth=round(self.extraHists['Data'].GetBinWidth(1),5)
        if binWidth-round(binWidth)<.001*binWidth: binWidth=int(round(binWidth))
        yTitle="Events"
        if '[' in self.xTitle and ']' in self.xTitle: #get units from x axis title
            begin=self.xTitle.find('[')+1
            end=self.xTitle.find(']')
            yTitle+=' / '+str(binWidth)+' '+self.xTitle[begin:end]
        self.extraHists['Data'].GetYaxis().SetTitle(yTitle)
            
        self.formatUpperHist(self.extraHists['Data'])

        self.uPad.cd()
        self.extraHists['Data'].Draw("E1 X0") #draw data first because its easier to format a TH1 than a THStack
        self.backgroundStack.Draw("SAME HIST")
        for signal in self.signals:
            if signal in samplesForPlotting:
                signal.h.Draw("SAME HIST")
        self.extraHists['Data'].Draw("SAME E1 X0") #redraw data so its not hidden
        self.uPad.RedrawAxis()

        #calculate stat+sys uncertainty
        self.uncBand=self.background.Clone("unc")
        for binNo in range(0,self.nBins+2):
            lumiUnc=0
            statUnc=0
            sigmaUnc=0
            for sample in samples:
                if sample.systematic or (not sample.isBackground) or self.skip(sample): continue
                lumiUnc+=(sample.h.GetBinContent(binNo)*lumiFracUnc)**2
                sigmaUnc+=(sample.h.GetBinContent(binNo)*sigmaFracUnc[sample.type])**2
                statUnc+=sample.h.GetBinError(binNo)**2
            totalUnc=sqrt(lumiUnc+sigmaUnc+statUnc)
            self.uncBand.SetBinError(binNo,totalUnc)
            self.background.SetBinError(binNo,totalUnc)
        self.uncBand.SetFillStyle(3344)
        self.uncBand.SetFillColor(1)
        self.uncBand.SetLineColor(1)
        self.uncBand.SetMarkerSize(0)
        gStyle.SetHatchesLineWidth(1)
        self.uncBand.Draw("SAME E2")
        
        legend=TLegend(0.55,0.55,0.90,0.90)
        legend.SetShadowColor(0);
        legend.SetFillColor(0);
        legend.SetLineColor(0);
        legend.AddEntry(self.extraHists['Data'],"Data")
        for bName,bLabel in zip(reversed(['QCD','ZJets','WJets','singleTop','ttbar','VV','VZ']),reversed(['QCD','Z+jets','W+jets','single top','ttbar','VV','VZ'])):
            try: legend.AddEntry(self.extraHists[bName],bLabel,"f")
            except: pass

        for signal in self.signals:
            if signal in samplesForPlotting:
                legend.AddEntry(signal.h, signal.altName + " x" + str(signalMagFrac), "l")

        legend.AddEntry(self.uncBand , "Uncertainty" , "f")
        legend.Draw("SAME")
        
        prelimTex=TLatex()
        prelimTex.SetNDC()
        prelimTex.SetTextSize(0.04)
        prelimTex.SetTextAlign(31) # align right
        lumi=self.lumi/1000.
        lumi=round(lumi,2)
        prelimTex.DrawLatex(0.9, 0.95, "CMS Preliminary, "+str(lumi)+" fb^{-1} at #sqrt{s} = 8 TeV");
            
        channelTex = TLatex()
        channelTex.SetNDC()
        channelTex.SetTextSize(0.08)
        channelTex.SetTextAlign(31)
        if self.Vtype==0: text='Z #rightarrow #mu#mu'
        elif self.Vtype==1: text='Z #rightarrow ee'
        elif self.Vtype==2: text='W #rightarrow #mu#nu'
        else: text='W #rightarrow e#nu'
        channelTex.DrawLatex(0.5, 0.83, text);

        self.lPad.cd()
        self.pull=self.extraHists['Data'].Clone("pull")
        for binNo in range(0,self.nBins+2):
            if self.background.GetBinError(binNo)!=0:
                self.pull.SetBinContent(binNo,(self.extraHists['Data'].GetBinContent(binNo)-self.background.GetBinContent(binNo))/sqrt(self.background.GetBinError(binNo)**2+self.extraHists['Data'].GetBinError(binNo)**2))
        self.pull.SetMaximum(3)
        self.pull.SetMinimum(-3)
        self.pull.SetFillColor(2)
        self.pull.SetLineColor(2)
        self.formatLowerHist(self.pull)
        self.pull.GetYaxis().SetTitle('Pull')
        self.pull.Draw("HIST")

        output.cd()
        self.canvas.Write()
        self.canvas.SaveAs(outputDir+'/'+self.name+'.pdf')
        self.canvas.SaveAs(outputDir+'/'+self.name+'.eps')
        self.canvas.SaveAs(outputDir+'/'+self.name+'.png')

        for sample in samples:
            if sample.isSignal:
                sample.h.Scale(1./signalMagFrac)

        for histName in self.extraHists.keys():
            try:
                if contains(histName,'W_light_'):
                    self.extraHists[histName].Scale(self.extraHists['W_light'].Integral(0,self.nBins+1)/self.extraHists[histName].Integral(0,self.nBins+1))
                elif contains(histName,'W_b_'):
                    self.extraHists[histName].Scale(self.extraHists['W_b'].Integral(0,self.nBins+1)/self.extraHists[histName].Integral(0,self.nBins+1))
                elif contains(histName,'W_bb_'):
                    self.extraHists[histName].Scale(self.extraHists['W_bb'].Integral(0,self.nBins+1)/self.extraHists[histName].Integral(0,self.nBins+1))
                elif contains(histName,'ttbar_'):
                    self.extraHists[histName].Scale(self.extraHists['ttbar'].Integral(0,self.nBins+1)/self.extraHists[histName].Integral(0,self.nBins+1))
            except: pass
                                                         
        #Write histograms
        for sample in samples:
            if self.skip(sample): continue
            sample.h.Write()
                        
        for histName in self.extraHists.keys():
            try: self.extraHists[histName].Write()
            except: pass

        #Stat systematic
        if (doStatSys or doAllSys):
            for sample in samples:
                if self.skip(sample): continue
                if sample.systematic: continue
                if not sample.isSignal: continue
                name=sample.name.split('_')[-1]
                statUp=sample.h.Clone(sample.h.GetName()+'_stat_'+name+'Up')
                statDown=sample.h.Clone(sample.h.GetName()+'_stat_'+name+'Down')
                for binNo in range(0,self.nBins+2):
                    statUp.SetBinContent(binNo,sample.h.GetBinContent(binNo)+sample.h.GetBinError(binNo))
                    statDown.SetBinContent(binNo,sample.h.GetBinContent(binNo)-sample.h.GetBinError(binNo))
                    if statDown.GetBinContent(binNo)<0: statDown.SetBinContent(binNo,0)
                statUp.Write()
                statDown.Write()

            for histName in self.extraHists.keys():
                if 'Up' in histName or 'Down' in histName or 'Shape' in histName or 'Data' in histName: continue
                #try:
                statUp=self.extraHists[histName].Clone(self.extraHists[histName].GetName()+'_stat_'+histName+'Up')
                statDown=self.extraHists[histName].Clone(self.extraHists[histName].GetName()+'_stat_'+histName+'Down')
                for binNo in range(0,self.nBins+2):
                    statUp.SetBinContent(binNo,self.extraHists[histName].GetBinContent(binNo)+self.extraHists[histName].GetBinError(binNo))
                    statDown.SetBinContent(binNo,self.extraHists[histName].GetBinContent(binNo)-self.extraHists[histName].GetBinError(binNo))
                    if statDown.GetBinContent(binNo)<0: statDown.SetBinContent(binNo,0)
                if isEqual(sample.type,'ttbar') or isEqual(sample.type,'WJets'):
                    statUp.Scale(self.extraHists[histName].Integral(0,self.nBins+1)/statUp.Integral(0,self.nBins+1))
                    statDown.Scale(self.extraHists[histName].Integral(0,self.nBins+1)/statDown.Integral(0,self.nBins+1))
                statUp.Write()
                statDown.Write()
                #except: pass

            #Shape sys
            if doWJetsShapeSys or doAllSys:
                for sampleName in ['W_light','W_b','W_bb']:
                        #try: 
                        nominal=self.extraHists[sampleName]
                        up=self.extraHists[sampleName+'_WJetsShapeUp']
                        down=up.Clone(up.GetName().replace('Up','Down'))
                        for binNo in range(0,self.nBins+2):
                            down.SetBinContent(binNo,nominal.GetBinContent(binNo)-(up.GetBinContent(binNo)-nominal.GetBinContent(binNo)))
                            if down.GetBinContent(binNo)<0: down.SetBinContent(binNo,0)
                        down.Scale(nominal.Integral(0,self.nBins+1)/down.Integral(0,self.nBins+1))
                        down.Write()
                        #except: pass
                
            if doTTbarShapeSys or doAllSys:
                    #try:
                    nominal=self.extraHists['ttbar']
                    up=self.extraHists['ttbar_ttbarShapeUp']
                    down=up.Clone(up.GetName().replace('Up','Down'))
                    for binNo in range(0,self.nBins+2):
                        down.SetBinContent(binNo,nominal.GetBinContent(binNo)-(up.GetBinContent(binNo)-nominal.GetBinContent(binNo)))
                        if down.GetBinContent(binNo)<0: down.SetBinContent(binNo,0)
                    down.Scale(nominal.Integral(0,self.nBins+1)/down.Integral(0,self.nBins+1))
                    down.Write()
                    #except: pass
                
        #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        if doShapeComparison:
            if self.extraHists['ewk'].Integral(0,self.nBins+1)>0: self.extraHists['ewk'].Scale(1./self.extraHists['ewk'].Integral(0,self.nBins+1))
            self.extraHists['ewk'].SetFillColor(kWhite)
            if self.extraHists['top'].Integral(0,self.nBins+1)>0: self.extraHists['top'].Scale(1./self.extraHists['top'].Integral(0,self.nBins+1))
            self.extraHists['top'].SetFillColor(kWhite)
            for signal in self.signals:
                if signal.Integral(0,self.nBins+1)>0: signal.Scale(1./signal.Integral(0,self.nBins+1))
                signal.SetFillColor(kWhite)
            
            max=0
            for hist in [self.extraHists['ewk'],self.extraHists['top']]+self.signals:
                if hist.GetMaximum()>max: max=hist.GetMaximum()
            self.extraHists['ewk'].SetMaximum(1.1*max)
                        
            #self.formatUpperHist(self.extraHists['ewk']);
            self.extraHists['ewk'].GetYaxis().SetTitle('Shape')
            
            ewkEff=self.extraHists['ewk'].Clone('ewkEff')
            #self.formatLowerHist(ewkEff)
            ewkEff.GetYaxis().SetTitle('1-Integral')
            ewkEff.SetMinimum(.8)
            ewkEff.SetMaximum(1)
            
            topEff=self.extraHists['top'].Clone('topEff')
            signalEffs=[]
            for signal in self.signals: signalEffs.append(signal.Clone('signalEff'+str(len(signalEffs)))); 

            for binNo in range(1,self.nBins+2):
                ewkEff.SetBinContent(binNo,1-self.extraHists['ewk'].Integral(0,binNo))
                topEff.SetBinContent(binNo,1-self.extraHists['top'].Integral(0,binNo))
                for signal,signalEff in zip(self.signals,signalEffs): signalEff.SetBinContent(binNo,1-signal.Integral(0,binNo))

            self.canvas=TCanvas('shape_'+self.name,"",1000,800)
            #self.uPad.cd()
            self.extraHists['ewk'].Draw()
            self.extraHists['top'].Draw("SAME")
            for signal in self.signals: signal.Draw("SAME")

            legend.Clear()
            legend.AddEntry(self.extraHists['top'],"t#bar{t} + Single-Top", "l")
            legend.AddEntry(self.extraHists['ewk'],"W#rightarrowl#nu + Z/#gamma*#rightarrowl^{+}l^{-} + VV" , "l")
            for signal in self.signals:
                mass=signal.GetName()[-3:]
                for s in signalsForPlotting:
                    if s.name in signal.GetName(): legend.AddEntry(signal, "H^{#pm} (m="+mass+" GeV)", "l")
            legend.Draw("SAME")

            #self.lPad.cd()
            #ewkEff.Draw("C")
            #topEff.Draw("SAME C")
            #for signalEff in signalEffs: signalEff.Draw("SAME C")
            
            self.canvas.SaveAs(outputDir+'/shape_'+self.name+'.pdf')
            self.canvas.SaveAs(outputDir+'/shape_'+self.name+'.eps')
            self.canvas.SaveAs(outputDir+'/shape_'+self.name+'.png')

    #---------------------------------------------------------------------------------------------------------------------------------------------------------
 
    def formatUpperHist(self,histogram):
        histogram.GetXaxis().SetLabelSize(0)

        histogram.GetYaxis().CenterTitle()
        histogram.GetYaxis().SetLabelSize(0.08)
        histogram.GetYaxis().SetTitleSize(0.12)
        histogram.GetYaxis().SetTitleOffset(.75)
                
        if self.yLog:
            self.uPad.SetLogy()
            histogram.SetMaximum(500*histogram.GetMaximum())
            
    #---------------------------------------------------------------------------------------------------------------------------------------------------------

    def formatLowerHist(self,histogram):
        histogram.GetXaxis().SetLabelSize(.15)
        histogram.GetXaxis().SetTitleSize(0.18)
        histogram.GetXaxis().SetTitleOffset(0.95)
        histogram.GetXaxis().SetTitle(self.xTitle)

        histogram.GetYaxis().SetLabelSize(0.125)
        histogram.GetYaxis().SetTitleSize(0.1)
        histogram.GetYaxis().SetTitleOffset(.55)
        histogram.GetYaxis().SetNdivisions(5);
