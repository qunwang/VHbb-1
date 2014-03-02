from ROOT import *

from Sample import *
samples=samplesForPlotting
from cuts import *
from doPostProc import *
from scaleFactors import *

from array import array

PUWeight='PUweight'
trigWeightEl='weightTrig2012SingleEle'
trigWeightMu='weightTrig2012SingleMuon'

if not os.path.isdir(outputDir): os.system("mkdir -p "+outputDir)
output=TFile(outputDir+'/plots.root',"RECREATE")

TH1.SetDefaultSumw2(True)

class Plot:

    def __init__(self,name,distribution,bins=None,nBins=100,xMin=0,xMax=100,xTitle='',yLog=True,cuts="1",channel=4):
        self.name=name; self.distribution=distribution; self.bins=bins; self.nBins=nBins; self.xMin=xMin; self.xMax=xMax; self.xTitle=xTitle; self.yLog=yLog; self.cuts=cuts; self.channel=channel

        if self.bins:
            self.nBins=len(self.bins)-1
            self.xMin=self.bins[0]
            self.xMax=self.bins[-1]
        else:
            self.bins=[]
            for n in range(self.nBins+1):
                self.bins.append(self.xMin+n*(float(self.xMax-self.xMin)/self.nBins))
        self.bins=array('f',self.bins)

        #make name unique
        self.name+='_'+self.cuts+'_Vtype'+str(self.channel)
        
        if (self.channel==0 or self.channel==2):
            self.lumi=muLumi
            self.trigWeight=trigWeightMu
        elif (self.channel==1 or self.channel==3):
            self.lumi=elLumi
            self.trigWeight=trigWeightEl

    #---------------------------------------------------------------------------------------------------------------------------------------------------------
    
    def Prepare(self):
        yields={}
        
        #get histograms with proper normalization
        for sample in samples:

            #skip electron (muon) data for muon (electron) channel
            if self.channel==0 or self.channel==2:
                if sample.channel=='el': continue
            if self.channel==1 or self.channel==3:
                if sample.channel=='mu': continue

            sample.setInputList(inputDir)
            sample.makeTChain(treeName)
                        
            hName=self.name+'__'+sample.name
            sample.h=TH1F(hName,";"+self.xTitle,self.nBins,self.bins)
            sample.h.Sumw2()

            theCuts=cuts[self.cuts]+' && Vtype=='+str(self.channel)

            weight='1'
            if sample.isMC:
                weight+=' * '+PUWeight 
                weight+=' * '+self.trigWeight

                if sample.isSignal:
                    weight+=' * weightSignalEWK'
                    weight+=' * weightSignalQCD'

                weight+=' / effectiveLumi'

            if sample.type=='WJets'.lower():
                self.Wlight=sample.h.Clone(self.name+'_light'); self.Wlight.Sumw2()
                self.Wb=sample.h.Clone(self.name+'_b'); self.Wb.Sumw2()
                self.Wbb=sample.h.Clone(self.name+'_bb'); self.Wbb.Sumw2()

                #FIXME - shouldn't have hardcoded 0
                sample.chain.Draw(self.distribution+'>>'+hName+'_light',weight+' * '+str(scaleFactors[0]['Wlight'])+' * ('+theCuts+' && ((abs(hJet_flavour[0])==5)+(abs(hJet_flavour[1])==5))==0)','GOFF')
                sample.chain.Draw(self.distribution+'>>'+hName+'_b'    ,weight+' * '+str(scaleFactors[0]['Wb'])    +' * ('+theCuts+' && ((abs(hJet_flavour[0])==5)+(abs(hJet_flavour[1])==5))==1)','GOFF')
                sample.chain.Draw(self.distribution+'>>'+hName+'_bb'   ,weight+' * '+str(scaleFactors[0]['Wbb'])   +' * ('+theCuts+' && ((abs(hJet_flavour[0])==5)+(abs(hJet_flavour[1])==5))==2)','GOFF')

                sample.h.Add(self.Wlight)
                sample.h.Add(self.Wb)
                sample.h.Add(self.Wbb)
                
                self.Wlight.Scale(self.lumi)
                self.Wb.Scale(self.lumi)
                self.Wbb.Scale(self.lumi)

                yields['Wlight']=self.Wlight.Integral(0,self.nBins+1)
                yields['Wb']=self.Wb.Integral(0,self.nBins+1)
                yields['Wbb']=self.Wbb.Integral(0,self.nBins+1)
                                                                
            else:
                #FIXME - shouldn't have hardcoded 0
                if sample.type=='ttbar': scaleFactor=str(scaleFactors[0]['ttbar'])
                else: scaleFactor='1'

                sample.chain.Draw(self.distribution+">>"+hName,weight+' * '+scaleFactor+' * ('+theCuts+')','GOFF')

            if sample.isMC: sample.h.Scale(self.lumi)
            yields[sample.name]=sample.h.Integral(0,self.nBins+1) #for cutflow table

        output.cd()
        self.signals=[]
        self.backgroundStack=THStack()
        
        self.ewk=TH1F(self.name+'__ewk',';'+self.xTitle,self.nBins,self.bins); self.ewk.Sumw2()
        self.top=TH1F(self.name+'__top',';'+self.xTitle,self.nBins,self.bins); self.top.Sumw2()
        self.other=TH1F(self.name+'__other',';'+self.xTitle,self.nBins,self.bins); self.other.Sumw2()
        self.data=TH1F(self.name+'__DATA',';'+self.xTitle,self.nBins,self.bins);

        for sample in samples:
            if self.channel==0 or self.channel==2:
                if sample.channel=='el': continue
            if self.channel==1 or self.channel==3:
                if sample.channel=='mu': continue
            
            if sample.isSignal:
                sample.h.Scale(signalMagFrac)
                sample.h.SetLineColor(1)
                sample.h.SetLineStyle(2+len(self.signals))
                self.signals.append(sample)
            elif sample.isBackground:
                if sample.type=='ttbar' or sample.type=='singleTop'.lower(): self.top.Add(sample.h)
                elif sample.type=='WJets'.lower() or sample.type=='ZJets'.lower(): self.ewk.Add(sample.h)
                else: self.other.Add(sample.h)
            elif sample.isData:
                self.data.Add(sample.h)
            sample.h.SetLineWidth(4)
                        
        self.ewk.SetFillColor(ROOT.kGreen-3)
        self.ewk.SetLineColor(ROOT.kGreen-2)
        self.top.SetFillColor(ROOT.kRed-7)
        self.top.SetLineColor(ROOT.kRed-4)
        self.other.SetFillColor(ROOT.kBlue)
        self.other.SetLineColor(ROOT.kBlue)
        self.data.SetMarkerStyle(20)
        
        self.backgroundStack.Add(self.other)
        self.backgroundStack.Add(self.ewk)
        self.backgroundStack.Add(self.top)

        self.background=self.backgroundStack.GetStack().Last().Clone(self.name+'_background'); self.background.Sumw2()
        yields['Total Background']=self.background.Integral(0,self.nBins+1)
        yields['Data']=self.data.Integral(0,self.nBins+1)

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
                
        self.data.SetMaximum(2*self.data.GetMaximum())
        self.data.SetMinimum(0.025)

        binWidth=round(self.data.GetBinWidth(1),5)
        if binWidth-round(binWidth)<.001*binWidth: binWidth=int(round(binWidth))
        yTitle="Events"
        if '[' in self.xTitle and ']' in self.xTitle: #get units from x axis title
            begin=self.xTitle.find('[')+1
            end=self.xTitle.find(']')
            yTitle+=' / '+str(binWidth)+' '+self.xTitle[begin:end]
        self.data.GetYaxis().SetTitle(yTitle)
            
        self.formatUpperHist(self.data)

        self.uPad.cd()
        self.data.Draw("E1 X0") #draw data first because its easier to format a TH1 than a THStack
        self.backgroundStack.Draw("SAME HIST")
        for signal in self.signals:
            signal.h.Draw("SAME HIST")
        self.data.Draw("SAME E1 X0") #redraw data so its not hidden
        self.uPad.RedrawAxis()

        #calculate stat+sys uncertainty
        self.uncBand=self.background.Clone("unc")
        for binNo in range(0,self.nBins+1):
            lumiUnc=0
            statUnc=0
            for hist in [self.ewk, self.top, self.other]:
                lumiUnc+=(hist.GetBinContent(binNo)*lumiFracUnc)**2
                statUnc+=hist.GetBinError(binNo)**2
            sigmaUnc=(self.ewk.GetBinContent(binNo)*ewkFracUnc)**2+(self.top.GetBinContent(binNo)*topFracUnc)**2+(self.other.GetBinContent(binNo)*otherFracUnc)**2

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
        legend.AddEntry(self.data,"Data")
        legend.AddEntry(self.top,"t#bar{t} + Single-Top","f")
        legend.AddEntry(self.ewk,"V + jets","f")
        legend.AddEntry(self.other,"VV","f")
        
        for signal in self.signals:
            legend.AddEntry(signal.h, signal.altName, "l")

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
        if self.channel==0: text='Z #rightarrow #mu#mu'
        elif self.channel==1: text='Z #rightarrow ee'
        elif self.channel==2: text='W #rightarrow #mu#nu'
        else: text='W #rightarrow e#nu'
        channelTex.DrawLatex(0.5, 0.83, text);

        self.lPad.cd()
        self.pull=self.data.Clone("pull")
        for binNo in range(0,self.nBins+1):
            if self.background.GetBinError(binNo)!=0:
                self.pull.SetBinContent(binNo,(self.data.GetBinContent(binNo)-self.background.GetBinContent(binNo))/sqrt(self.background.GetBinError(binNo)**2+self.data.GetBinError(binNo)**2))
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
                if doLimitSetting:
                    #FIXME - not sure what to do here for Combine tool
                    print "not implemented yet"
                    exit(1)

        if not doLimitSetting:
            try:
                self.Wlight.Write()
                self.Wb.Write()
                self.Wbb.Write()
            except: pass
        
        self.data.Write()
        self.ewk.Write()
        self.top.Write()
        self.other.Write()
        
        for sample in samples:
            if sample.isSignal or not doLimitSetting:
                try: sample.h.Write()
                except: pass
                
        #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        if doShapeComparison:
            if self.ewk.Integral(0,self.nBins+1)>0: self.ewk.Scale(1./self.ewk.Integral(0,self.nBins+1))
            self.ewk.SetFillColor(kWhite)
            if self.top.Integral(0,self.nBins+1)>0: self.top.Scale(1./self.top.Integral(0,self.nBins+1))
            self.top.SetFillColor(kWhite)
            for signal in self.signals:
                if signal.Integral(0,self.nBins+1)>0: signal.Scale(1./signal.Integral(0,self.nBins+1))
                signal.SetFillColor(kWhite)
            
            max=0
            for hist in [self.ewk,self.top]+self.signals:
                if hist.GetMaximum()>max: max=hist.GetMaximum()
            self.ewk.SetMaximum(1.1*max)
                        
            #self.formatUpperHist(self.ewk);
            self.ewk.GetYaxis().SetTitle('Shape')
            
            ewkEff=self.ewk.Clone('ewkEff')
            #self.formatLowerHist(ewkEff)
            ewkEff.GetYaxis().SetTitle('1-Integral')
            ewkEff.SetMinimum(.8)
            ewkEff.SetMaximum(1)
            
            topEff=self.top.Clone('topEff')
            signalEffs=[]
            for signal in self.signals: signalEffs.append(signal.Clone('signalEff'+str(len(signalEffs)))); 

            for binNo in range(1,self.nBins+1):
                ewkEff.SetBinContent(binNo,1-self.ewk.Integral(0,binNo))
                topEff.SetBinContent(binNo,1-self.top.Integral(0,binNo))
                for signal,signalEff in zip(self.signals,signalEffs): signalEff.SetBinContent(binNo,1-signal.Integral(0,binNo))

            self.canvas=TCanvas('shape_'+self.name,"",1000,800)
            #self.uPad.cd()
            self.ewk.Draw()
            self.top.Draw("SAME")
            for signal in self.signals: signal.Draw("SAME")

            legend.Clear()
            legend.AddEntry(self.top,"t#bar{t} + Single-Top", "l")
            legend.AddEntry(self.ewk,"W#rightarrowl#nu + Z/#gamma*#rightarrowl^{+}l^{-} + VV" , "l")
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
