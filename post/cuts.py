cuts=[{} for i in range(10)]

jetPt_cut   = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30' #PAS
jetEta_cut  = 'abs(hJet_eta[0]) < 2.5 && abs(hJet_eta[1])<2.5' #PAS
jetID_cut   = 'hJet_id[0]==1 && hJet_id[1]==1' #DAS/Jia Fu
jetpuID_cut = 'hJet_puJetIdL[0]>0 && hJet_puJetIdL[1]>0' #DAS/Jia Fu
jetCsv_cut  = 'hJet_csvReshapedNew[0] > 0 && hJet_csvReshapedNew[1] > 0'

#PAS
dPhi_cut = '(acos(cos(METtype1corr.phi-vLepton_phi[0])) < TMath::Pi()/2)'
METet_cut   = 'METtype1corr.et>45' #PAS

Hpt_cut     = 'H.ptCorr > 100' #PAS
Hmass_cut   = 'H.massCorr < 250' #PAS

#PAS, AN
#el_cut      = 'vLepton_wp80[0] == 1 && vLepton_pfCorrIso[0] < 0.1 && vLepton_pt[0]>30 && abs(vLepton_eta[0])<2.5 && (abs(vLepton_eta[0])<1.44 || abs(vLepton_eta[0])>1.57)'
el_cut      = 'vLepton_wp80[0] == 1 && vLepton_pt[0]>30 && abs(vLepton_eta[0])<2.5 && (abs(vLepton_eta[0])<1.44 || abs(vLepton_eta[0])>1.57)'
mu_cut      = 'vLepton_pt[0]>20 && abs(vLepton_eta[0])<2.4'

#Seth, DAS
#num_aJets   = 'Sum$(aJet_pt>20 && abs(aJet_eta)<4.5 && aJet_id==1 && aJet_puJetIdL>0)'
num_aJets   = 'Sum$(aJet_pt>20 && abs(aJet_eta)<4.5 && aJet_puJetIdL>0)'
num_aLeps   = 'Sum$(aLepton_pt > 15 && abs(aLepton_eta) < 2.5 && (aLepton_pfCorrIso < 0.10) )'
#num_aLeps   = 'Sum$(aLepton_pt > 15 && abs(aLepton_eta) < 2.5)'

#DAS
hbhe_cut    = 'hbhe'

bad_pixels = '(!(207883<=EVENT.run && EVENT.run<=208307))'

#CR_CommCuts =  jetPt_cut + ' && ' + jetEta_cut + ' && ' + jetID_cut + ' && ' + jetpuID_cut + ' && ' +  Hpt_cut + ' && ' + Hmass_cut + ' && ' + METet_cut + ' && ' + dPhi_cut + ' && ' + hbhe_cut + ' && ' + bad_pixels
CR_CommCuts =  jetPt_cut + ' && ' + jetCsv_cut + ' && ' + jetEta_cut + ' && ' + jetpuID_cut + ' && ' +  Hpt_cut + ' && ' + Hmass_cut + ' && ' + METet_cut + ' && ' + dPhi_cut + ' && ' + hbhe_cut + ' && ' + bad_pixels

TriggerFlags_old_mu = '(triggerFlags[14]>0 || triggerFlags[21]>0 || triggerFlags[22]>0 || triggerFlags[23]>0)'
TriggerFlags_new_mu = '((EVENT.run<193834 && (triggerFlags[22]>0 || triggerFlags[23]>0)) || (EVENT.run>=193834 && (triggerFlags[14]>0 ||triggerFlags[21]>0)))'

TriggerFlags_new_el = '(triggerFlags[44]>0)'

TriggerFlags_mu = TriggerFlags_new_mu
TriggerFlags_el = TriggerFlags_new_el

cuts[2]['WLF']     =  CR_CommCuts + ' && ' + mu_cut + ' && ' + TriggerFlags_mu + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.244 && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) < 0.898 && ' + num_aJets + ' < 2 && ' + num_aLeps + ' == 0 && (METtype1corr.et /TMath::Sqrt(METtype1corr.sumet)) > 2'
cuts[3]['WLF']     =  CR_CommCuts + ' && ' + el_cut + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.244 && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) < 0.898 && ' + num_aJets + ' < 2 && ' + num_aLeps + ' == 0 && (METtype1corr.et /TMath::Sqrt(METtype1corr.sumet)) > 3 && (triggerFlags[44]>0)'

cuts[2]['WHF']     = CR_CommCuts + ' && ' + mu_cut + ' && ' + TriggerFlags_mu + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.898 && (H.massCorr < 95 || H.massCorr > 150) && ' + num_aJets +' == 0 && ' + num_aLeps + ' == 0 && (METtype1corr.et /TMath::Sqrt(METtype1corr.sumet)) > 2'
cuts[3]['WHF']     = CR_CommCuts + ' && ' + el_cut + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.898 && (H.massCorr < 95 || H.massCorr > 150) && ' + num_aJets +'== 0 && ' + num_aLeps + ' == 0 && (triggerFlags[44]>0) && (METtype1corr.et /TMath::Sqrt(METtype1corr.sumet)) > 2'

cuts[2]['ttbar']   = CR_CommCuts + ' && ' + mu_cut + ' && ' + TriggerFlags_mu + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.898 && ' + num_aJets + '> 1 && ' + num_aLeps + ' == 0'
cuts[3]['ttbar']   = CR_CommCuts + ' && ' + el_cut + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.898 && ' + num_aJets + '> 1 && ' + num_aLeps + ' == 0 && (triggerFlags[44]>0)'

cuts[2]['bdt']      = mu_cut + ' && ' + jetpuID_cut + ' && ' + jetEta_cut + ' && ' + jetPt_cut + ' && ' + Hpt_cut + ' && ' + Hmass_cut + ' && ' + METet_cut + ' && ' + TriggerFlags_mu + ' && ' + hbhe_cut + ' && ' + bad_pixels + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.40 && min(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.40 && ' + num_aLeps + ' ==0 && ' + dPhi_cut
cuts[3]['bdt']      = el_cut + ' && ' + jetpuID_cut + ' && ' + jetEta_cut + ' && ' + jetPt_cut + ' && ' + Hpt_cut + ' && ' + Hmass_cut + ' && ' + METet_cut + ' && ' + TriggerFlags_el + ' && ' + hbhe_cut + ' && ' + bad_pixels + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.40 && min(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.40 && ' + num_aLeps + ' ==0 && ' + dPhi_cut

cuts[2]['mjj']      = mu_cut + ' && ' + jetpuID_cut + ' && ' + jetEta_cut + ' && ' + jetPt_cut + ' && ' + Hpt_cut + ' && ' + METet_cut + ' && ' + TriggerFlags_mu + ' && ' + hbhe_cut + ' && ' + bad_pixels + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.898 && min(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.5 && ' + num_aLeps + ' ==0 && ' + num_aJets + ' ==0 && ' + dPhi_cut + ' && HVdPhi > 2.95'
cuts[3]['mjj']      = el_cut + ' && ' + jetpuID_cut + ' && ' + jetEta_cut + ' && ' + jetPt_cut + ' && ' + Hpt_cut + ' && ' + METet_cut + ' && ' + TriggerFlags_el + ' && ' + hbhe_cut + ' && ' + bad_pixels + ' && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.898 && min(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.5 && ' + num_aLeps + ' ==0 && ' + num_aJets + ' ==0 && ' + dPhi_cut + ' && HVdPhi > 2.95'

"""
cuts = {}
for i in ['Wlnu','Wtnu','Zll', 'Znunu']:
    cuts[i] = {}

#H.pt > 100 from v19 of HIG-13-12, > 120 in other versions, Ben?


cuts[3]['WLF']     = jetPt_cut + ' && ' + jetEta_cut + ' && ' + jetID_cut + ' && ' + jetpuID_cut + ' && ' + el_cut + ' && ' +  Hpt_cut + ' && H.mass < 250 && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.244 && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) < 0.898 && ' + num_aJets + ' < 2 && nalep == 0 && METtype1corr.et > 45 && (METtype1corr.et /TMath::Sqrt(METtype1corr.sumet) > 3'

cuts['Wlnu']['mjj']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt>100 && naJets==0 && nalep==0 && METtype1corr.et>45 && (hJet_csvReshapedNew[0]>0.898 || hJet_csvReshapedNew[1]>0.898) && (hJet_csvReshapedNew[0]>0.5 && hJet_csvReshapedNew[1]>0.5) && HVdPhi>2.95 && abs(lMETdPhi)<TMath::Pi()/2'
cuts['Wtnu']['mjj']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt>120 && naJets==0 && nalep==0 && METtype1corr.et>80 && TAU_PT > 40 && TAU_TRACK_PT > 20 && max(hJet_csvReshapedNew[1], hJet_csvReshapedNew[1]) > 0.898 && min(hJet_csvReshapedNew[1], hJet_csvReshapedNew[1]) > 0.4 && HVdPhi>2.95'
cuts['Zll']['mjj']      = 'V.mass > 75 && V.mass < 105 && hJet_ptCorr[0]>20 && hJet_ptCorr[1]>20 && METtype1corr.et<60 && max(hJet_csvReshapedNew[1], hJet_csvReshapedNew[1]) > 0.679 && min(hJet_csvReshapedNew[1], hJet_csvReshapedNew[1]) > 0.5 && ((V.pt < 100) || (V.pt > 100 && V.pt < 150) || (V.pt > 150 && H.dR < 1.6))'
cuts['Znunu']['mjj']    = 'hJet_ptCorr[1] > 30 && naJets==0 && nalep==0 && max(hJet_csvReshapedNew[1], hJet_csvReshapedNew[1]) > 0.898 && min(hJet_csvReshapedNew[1], hJet_csvReshapedNew[1]) > 0.5 && HVdPhi > 2.95 && DPHI_MET_MET_TRACK < 0.5 && ((V.pt < 130 && hJet_ptCorr[0] > 60 && H.pt > 110 && DPHI_MET_JET > 0.7) || (V.pt > 130 && V.pt < 170 && hJet_ptCorr[0] > 60 && H.pt > 140 && DPHI_MET_JET > 0.7) || (V.pt > 170 && hJet_ptCorr[0] > 80 && H.pt > 190 && DPHI_MET_JET > 0.5))'

cuts['Wlnu']['bdt']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt>100 && H.mass<250 && METtype1corr.et>45 && (hJet_csvReshapedNew[0]>0.4 && hJet_csvReshapedNew[1]>0.4) && nalep==0 && abs(lMETdPhi)<TMath::Pi()/2'
cuts['Wtnu']['bdt']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt>120 && H.mass<250 && METtype1corr.et>80 && TAU_PT > 40 && TAU_TRACK_PT > 20 && (hJet_csvReshapedNew[0]>0.4 && hJet_csvReshapedNew[1]>0.4) && nalep==0'
cuts['Zll']['bdt']      = 'V.mass > 75 && V.mass < 105 && hJet_ptCorr[0]>20 && hJet_ptCorr[1]>20 &&  min(hJet_csvReshapedNew[0], hJet_csvReshapedNew[1]) > 0.244 && ((V.pt < 100 && H.mass < 250 && H.mass > 40 && max(hJet_csvReshapedNew[0], hJet_csvReshapedNew[1]) > 0.5) || (V.pt > 100 && H.mass < 250 && max(hJet_csvReshapedNew[0], hJet_csvReshapedNew[1]) > 0.244))'
cuts['Znunu']['bdt']    = 'hJet_ptCorr[0]>60 && hJet_ptCorr[1]>30 && H.mass < 250 && max(hJet_csvReshapedNew[0], hJet_csvReshapedNew[1]) > 0.679 && min(hJet_csvReshapedNew[0], hJet_csvReshapedNew[1]) > 0.244 && nalep==0 && HVdPhi > 2 && DPHI_MET_METTRACKS < .5 && ((V.pt < 130 && H.pt > 100 && METtype1corr.et < 130 && METtype1corr.et > 100 && naJets < 2 && DPHI_MET_JET > 0.7 && METtype1corr.sig > 3) || (V.pt > 130 && V.pt < 170 && H.pt > 130 && METtype1corr.et > 130 && METtype1corr.et < 170 && DPHI_MET_JET < 0.7) || (V.pt > 170 && H.pt > 130 && METtype1corr.et > 170 && DPHI_MET_JET < 0.5))'

cuts['Wlnu']['WLF']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt > 100 && H.mass < 250 && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.244 && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) < 0.898 && naJets < 2 && nalep == 0 && METtype1corr.et > 45 && ((Vtype == 2 && METtype1corr.sig > 2) || (Vtype == 3 && METtype1corr.sig > 3))'
cuts['Wlnu']['WHF']     = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt > 100 && H.mass < 250 && (H.mass < 90 || H.mass > 150) && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.898 && naJets == 0 && nalep == 0 && METtype1corr.et > 45'
cuts['Wlnu']['ttbar']   = 'hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt > 100 && H.mass < 250 && max(hJet_csvReshapedNew[0],hJet_csvReshapedNew[1]) > 0.898 && naJets > 1 && nalep == 0 && METtype1corr.et > 45'

cuts['Zll']['Zjets']    = 'V.mass > 75 && V.mass < 105 && hJet_ptCorr[0] > 20 && hJet_ptCorr[1] > 20 && V.pt > 50 && H.mass < 250 && (H.mass < 80 || H.mass > 150) && hJet_csvReshapedNew[0] > 0.244 && hJet_csvReshapedNew[1] > 0.244'
cuts['Zll']['ttbar']    = '!(V.mass > 75 && V.mass < 105) && hJet_ptCorr[0] > 20 && hJet_ptCorr[1] > 20 && V.pt > 50 && V.pt < 100 && H.mass < 250 && (H.mass < 80 || H.mass > 150) && hJet_csvReshapedNew[0] > 0.244 && hJet_csvReshapedNew[1] > 0.244'
"""

