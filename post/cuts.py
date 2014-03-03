cuts={}

cuts['mjj']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr>100 && naJets==0 && nalep==0 && METtype1corr.et>45 && (hJet_csv[0]>0.898 || hJet_csv[1]>0.898) && (hJet_csv[0]>0.5 && hJet_csv[1]>0.5) && HVdPhi>2.95 && abs(lMETdPhi)<TMath::Pi()/2'
cuts['bdt']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr>100 && H.massCorr<250 && METtype1corr.et>45 && (hJet_csv[0]>0.4 && hJet_csv[1]>0.4) && nalep==0 && abs(lMETdPhi)<TMath::Pi()/2'
cuts['WLF']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr > 100 && H.massCorr < 250 && max(hJet_csv[0],hJet_csv[1]) > 0.244 && max(hJet_csv[0],hJet_csv[1]) < 0.898 && naJets < 2 && nalep == 0 && METtype1corr.et > 45 && ((Vtype == 2 && METtype1corr.sig > 2) || (Vtype == 3 && METtype1corr.sig > 3))'
cuts['WHF']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr > 100 && H.massCorr < 250 && (H.massCorr < 90 || H.massCorr > 150) && max(hJet_csv[0],hJet_csv[1]) > 0.898 && naJets == 0 && nalep == 0 && METtype1corr.et > 45'
cuts['ttbar']   = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr > 100 && H.massCorr < 250 && max(hJet_csv[0],hJet_csv[1]) > 0.898 && naJets > 1 && nalep == 0 && METtype1corr.et > 45'


"""
cuts = {}
for i in ['Wlnu','Wtnu','Zll', 'Znunu']:
    cuts[i] = {}

#H.ptCorr > 100 from v19 of HIG-13-12, > 120 in other versions, Ben?

cuts['Wlnu']['mjj']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr>100 && naJets==0 && nalep==0 && METtype1corr.et>45 && (hJet_csv[0]>0.898 || hJet_csv[1]>0.898) && (hJet_csv[0]>0.5 && hJet_csv[1]>0.5) && HVdPhi>2.95 && abs(lMETdPhi)<TMath::Pi()/2'
cuts['Wtnu']['mjj']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr>120 && naJets==0 && nalep==0 && METtype1corr.et>80 && TAU_PT > 40 && TAU_TRACK_PT > 20 && max(hJet_csv[1], hJet_csv[1]) > 0.898 && min(hJet_csv[1], hJet_csv[1]) > 0.4 && HVdPhi>2.95'
cuts['Zll']['mjj']      = 'V.mass > 75 && V.mass < 105 && hJet_ptCorr[0]>20 && hJet_ptCorr[1]>20 && METtype1corr.et<60 && max(hJet_csv[1], hJet_csv[1]) > 0.679 && min(hJet_csv[1], hJet_csv[1]) > 0.5 && ((V.pt < 100) || (V.pt > 100 && V.pt < 150) || (V.pt > 150 && H.dR < 1.6))'
cuts['Znunu']['mjj']    = 'hJet_ptCorr[1] > 30 && naJets==0 && nalep==0 && max(hJet_csv[1], hJet_csv[1]) > 0.898 && min(hJet_csv[1], hJet_csv[1]) > 0.5 && HVdPhi > 2.95 && DPHI_MET_MET_TRACK < 0.5 && ((V.pt < 130 && hJet_ptCorr[0] > 60 && H.ptCorr > 110 && DPHI_MET_JET > 0.7) || (V.pt > 130 && V.pt < 170 && hJet_ptCorr[0] > 60 && H.ptCorr > 140 && DPHI_MET_JET > 0.7) || (V.pt > 170 && hJet_ptCorr[0] > 80 && H.ptCorr > 190 && DPHI_MET_JET > 0.5))'

cuts['Wlnu']['bdt']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr>100 && H.massCorr<250 && METtype1corr.et>45 && (hJet_csv[0]>0.4 && hJet_csv[1]>0.4) && nalep==0 && abs(lMETdPhi)<TMath::Pi()/2'
cuts['Wtnu']['bdt']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr>120 && H.massCorr<250 && METtype1corr.et>80 && TAU_PT > 40 && TAU_TRACK_PT > 20 && (hJet_csv[0]>0.4 && hJet_csv[1]>0.4) && nalep==0'
cuts['Zll']['bdt']      = 'V.mass > 75 && V.mass < 105 && hJet_ptCorr[0]>20 && hJet_ptCorr[1]>20 &&  min(hJet_csv[0], hJet_csv[1]) > 0.244 && ((V.pt < 100 && H.massCorr < 250 && H.massCorr > 40 && max(hJet_csv[0], hJet_csv[1]) > 0.5) || (V.pt > 100 && H.massCorr < 250 && max(hJet_csv[0], hJet_csv[1]) > 0.244))'
cuts['Znunu']['bdt']    = 'hJet_ptCorr[0]>60 && hJet_ptCorr[1]>30 && H.massCorr < 250 && max(hJet_csv[0], hJet_csv[1]) > 0.679 && min(hJet_csv[0], hJet_csv[1]) > 0.244 && nalep==0 && HVdPhi > 2 && DPHI_MET_METTRACKS < .5 && ((V.pt < 130 && H.ptCorr > 100 && METtype1corr.et < 130 && METtype1corr.et > 100 && naJets < 2 && DPHI_MET_JET > 0.7 && METtype1corr.sig > 3) || (V.pt > 130 && V.pt < 170 && H.ptCorr > 130 && METtype1corr.et > 130 && METtype1corr.et < 170 && DPHI_MET_JET < 0.7) || (V.pt > 170 && H.ptCorr > 130 && METtype1corr.et > 170 && DPHI_MET_JET < 0.5))'

cuts['Wlnu']['WLF']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr > 100 && H.massCorr < 250 && max(hJet_csv[0],hJet_csv[1]) > 0.244 && max(hJet_csv[0],hJet_csv[1]) < 0.898 && naJets < 2 && nalep == 0 && METtype1corr.et > 45 && ((Vtype == 2 && METtype1corr.sig > 2) || (Vtype == 3 && METtype1corr.sig > 3))'
cuts['Wlnu']['WHF']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr > 100 && H.massCorr < 250 && (H.massCorr < 90 || H.massCorr > 150) && max(hJet_csv[0],hJet_csv[1]) > 0.898 && naJets == 0 && nalep == 0 && METtype1corr.et > 45'
cuts['Wlnu']['ttbar']   = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.ptCorr > 100 && H.massCorr < 250 && max(hJet_csv[0],hJet_csv[1]) > 0.898 && naJets > 1 && nalep == 0 && METtype1corr.et > 45'

cuts['Zll']['Zjets']    = 'V.mass > 75 && V.mass < 105 && hJet_ptCorr[0] > 20 && hJet_ptCorr[1] > 20 && V.pt > 50 && H.massCorr < 250 && (H.massCorr < 80 || H.massCorr > 150) && hJet_csv[0] > 0.244 && hJet_csv[1] > 0.244'
cuts['Zll']['ttbar']    = '!(V.mass > 75 && V.mass < 105) && hJet_ptCorr[0] > 20 && hJet_ptCorr[1] > 20 && V.pt > 50 && V.pt < 100 && H.massCorr < 250 && (H.massCorr < 80 || H.massCorr > 150) && hJet_csv[0] > 0.244 && hJet_csv[1] > 0.244'
"""

