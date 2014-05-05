#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "RooRealVar.h"

#include "ScalarPdfFactoryPPWH.cc"

using namespace std;

class KDcalcPPWH {

public:

  RooRealVar* costheta1;
  RooRealVar* costheta2;
  RooRealVar* phi;
  RooRealVar* m;
  RooRealVar* Y;

  RooRealVar* mH;
  
  ScalarPdfFactoryPPWH* SMHiggs;
  ScalarPdfFactoryPPWH* pseudoScalar;
  ScalarPdfFactoryPPWH* higherOrder;

  KDcalcPPWH(double sqrtsVal, double mX){

    costheta1 = new RooRealVar("costheta1","costheta1",-1.,1.);
    costheta2 = new RooRealVar("costheta2","costheta2",-1.,1.);
    phi       = new RooRealVar("phi","phi",-TMath::Pi(),TMath::Pi());
    m         = new RooRealVar("m","m",150,1000.);
    Y         = new RooRealVar("Y","Y",-4,4);
    mH        = new RooRealVar("mH","mH",100.,1000.);
    mH->setVal(mX);

    SMHiggs   = new ScalarPdfFactoryPPWH(costheta1,
					 costheta2,
					 phi,
					 m,
					 Y,
					 mH,
					 2,
					 false);
    
    SMHiggs->fa2->setVal(0.0);
    SMHiggs->fa3->setVal(0.0);
    SMHiggs->phia2->setVal(0.0);
    SMHiggs->phia3->setVal(0.0);
    SMHiggs->sqrts->setVal(sqrtsVal);
    
    pseudoScalar = new ScalarPdfFactoryPPWH(costheta1,
					    costheta2,
					    phi,
					    m,
					    Y,
					    mH,
					    2,
					    false);

    pseudoScalar->fa2->setVal(0.0);
    pseudoScalar->fa3->setVal(0.999999);
    pseudoScalar->phia2->setVal(0.0);
    pseudoScalar->phia3->setVal(0.0);
    pseudoScalar->sqrts->setVal(sqrtsVal);

    higherOrder = new ScalarPdfFactoryPPWH(costheta1,
					   costheta2,
					   phi,
					   m,
					   Y,
					   mH,
					   2,
					   false);

    higherOrder->fa2->setVal(0.999999);
    higherOrder->fa3->setVal(0.0);
    higherOrder->phia2->setVal(0.0);
    higherOrder->phia3->setVal(0.0);
    higherOrder->sqrts->setVal(sqrtsVal);

    SMHiggs->makeParamsConst(true);
    pseudoScalar->makeParamsConst(true);
    higherOrder->makeParamsConst(true);
  };


  double getLikelihood(float mH_,
		       float costheta1_,
		       float costheta2_,
		       float phi_,
		       float m_,
		       float Y_,
		       bool withAcc = false,
		       int signal=0){
    
    mH->setVal(mH_);
    costheta1->setVal(costheta1_);
    costheta2->setVal(costheta2_);
    phi->setVal(phi_);
    m->setVal(m_);
    Y->setVal(Y_);
    
    double mW = 80.399;
    if ( withAcc ) {
      vector<TLorentzVector> lep_4vecs = Calculate4Momentum(m_,mW,mH_,acos(costheta1_),acos(costheta2_),acos(0),phi_,0);
      // have to calculate this before the boost
      // now boost the 4leptons to the original frame
      TLorentzVector pZstar_new;
      // calculate pz and E based on m and Y                                                                                                                                                                
      double E_Zstar_new =  m_*(exp(2*Y_)+1)/(2*exp(Y_));
      double pz_Zstar_new = (exp(2*Y_)-1)/(exp(2*Y_)+1)*E_Zstar_new;
      pZstar_new.SetPxPyPzE(0, 0, pz_Zstar_new, E_Zstar_new);
      TVector3 boost_pZstar = pZstar_new.BoostVector();

      for (int i = 0 ; i < 4 ; i++ )
        lep_4vecs[i].Boost(boost_pZstar);

      double pt_plus_sq = pow(lep_4vecs[1].Px(),2) + pow(lep_4vecs[1].Py(),2);
      double pt_minus_sq = pow(lep_4vecs[0].Px(),2) + pow(lep_4vecs[0].Py(),2);

      double sinh2_eta_plus = pow(lep_4vecs[1].Pz(),2)/pt_plus_sq;
      double sinh2_eta_minus = pow(lep_4vecs[0].Pz(),2)/pt_minus_sq;

      double higgsPtSq = pow((lep_4vecs[2]+lep_4vecs[3]).Pt(),2);

      if( pt_minus_sq<400.0
          || pt_plus_sq<400.0
          || sinh2_eta_minus>pow(sinh(2.4),2)
          || sinh2_eta_plus>pow(sinh(2.4),2)
          || higgsPtSq < (200.*200)
          ) return 0;
    }

    switch(signal){
    case 0: return SMHiggs->PDF->getVal();
    case 1: return pseudoScalar->PDF->getVal();
    case 2: return higherOrder->PDF->getVal();
    default: return -1;
    }
  }

  vector<TLorentzVector> Calculate4Momentum(float Mx,float M1,float M2,float theta,float theta1,float theta2,float _Phi1_,float _Phi_) const 
  {
  
    float phi1,phi2;
    phi1=TMath::Pi()-_Phi1_;
    phi2=_Phi1_+_Phi_;
  
  
    float gamma1,gamma2,beta1,beta2;
  
    gamma1=(Mx*Mx+M1*M1-M2*M2)/(2*Mx*M1);
    gamma2=(Mx*Mx-M1*M1+M2*M2)/(2*Mx*M2);
    beta1=sqrt(1-1/(gamma1*gamma1));
    beta2=sqrt(1-1/(gamma2*gamma2));
  
    //gluon 4 vectors
    TLorentzVector p1CM(0,0,Mx/2,Mx/2);
    TLorentzVector p2CM(0,0,-Mx/2,Mx/2);
  
    //vector boson 4 vectors
    TLorentzVector kZ1(gamma1*M1*sin(theta)*beta1,0, gamma1*M1*cos(theta)*beta1,gamma1*M1*1);   
    TLorentzVector kZ2(-gamma2*M2*sin(theta)*beta2,0, -gamma2*M2*cos(theta)*beta2,gamma2*M2*1);
  
    //Rotation and Boost matrices. Note gamma1*beta1*M1=gamma2*beta2*M2.
  
    TLorentzRotation Z1ToZ,Z2ToZ;
  
    Z1ToZ.Boost(0,0,beta1);
    Z2ToZ.Boost(0,0,beta2);
    Z1ToZ.RotateY(theta);
    Z2ToZ.RotateY(TMath::Pi()+theta);
  
    //fermons 4 vectors in vector boson rest frame
  
    TLorentzVector p3Z1((M1/2)*sin(theta1)*cos(phi1),(M1/2)*sin(theta1)*sin(phi1),(M1/2)*cos(theta1),(M1/2)*1);
  
    TLorentzVector p4Z1(-(M1/2)*sin(theta1)*cos(phi1),-(M1/2)*sin(theta1)*sin(phi1),-(M1/2)*cos(theta1),(M1/2)*1);
  
    TLorentzVector p5Z2((M2/2)*sin(theta2)*cos(phi2),(M2/2)*sin(theta2)*sin(phi2),(M2/2)*cos(theta2),(M2/2)*1);
  
    TLorentzVector p6Z2(-(M2/2)*sin(theta2)*cos(phi2),-(M2/2)*sin(theta2)*sin(phi2),-(M2/2)*cos(theta2),(M2/2)*1);
  
  
    // fermions 4 vectors in CM frame
  
    TLorentzVector p3CM,p4CM,p5CM,p6CM;
  
    p3CM=Z1ToZ*p3Z1;
    p4CM=Z1ToZ*p4Z1;
    p5CM=Z2ToZ*p5Z2;
    p6CM=Z2ToZ*p6Z2;
  
    vector<TLorentzVector> p;
  
    p.push_back(p3CM);
    p.push_back(p4CM);
    p.push_back(p5CM);
    p.push_back(p6CM);
  
    return p;
  }

};


