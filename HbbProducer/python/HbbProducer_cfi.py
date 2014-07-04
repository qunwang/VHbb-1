import FWCore.ParameterSet.Config as cms

HbbProducer = cms.EDProducer('HbbProducer',
                             rhoSource=cms.InputTag('fixedGridRhoFastjetAll'),

                             ak4Source =cms.InputTag('patJetsAK4PFCHS'),
                             ak8Source =cms.InputTag('patJetsAK8PFCHS'),
                             ak10Source=cms.InputTag('patJetsAK10PFCHS'),
                             ak12Source=cms.InputTag('patJetsAK12PFCHS'),
                             ak15Source=cms.InputTag('patJetsAK15PFCHS'),
)
