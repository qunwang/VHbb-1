cuts={}

cuts['mjj']='hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt>100 && naJets==0 && nalep==0 && METtype1corr.et>45 && (hJet_csv[0]>0.898 || hJet_csv[1]>0.898) && (hJet_csv[0]>0.5 && hJet_csv[1]>0.5) && HVdPhi>2.95 && abs(lMETdPhi)<TMath::Pi()/2'

cuts['bdt']='hJet_ptCorr[0]>30 && hJet_ptCorr[1]>30 && H.pt>100 && H.mass<250 && METtype1corr.et>45 && (hJet_csv[0]>0.4 && hJet_csv[1]>0.4) && nalep==0 && abs(lMETdPhi)<TMath::Pi()/2'

#FIXME

cuts['WLF']=''

cuts['WHF']=''

cuts['ttbar']=''
