import FWCore.ParameterSet.Config as cms

HbbProducer = cms.EDProducer('HbbProducer',
                             rhoSource=cms.InputTag('fixedGridRhoFastjetAll'),
                             jetSource=cms.InputTag('slimmedJets'),
)
