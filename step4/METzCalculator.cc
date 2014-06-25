#include "METzCalculator.h"
#include "TMath.h"

/// constructor
METzCalculator::METzCalculator() {
	isComplex_ = false;
	otherSol_ = 0.;
	leptonMass_ = 0.105658367;
	newPtneutrino1_ = -1;
	newPtneutrino2_ = -1;
}

/// destructor
METzCalculator::~METzCalculator() {
}

/// member functions
double
METzCalculator::Calculate(int method, int typeR, int typeC) {

	double M_W  = 80.4;
	double M_mu =  leptonMass_;
	double emu = lepton_.E();
	double pxmu = lepton_.Px();
	double pymu = lepton_.Py();
	double pzmu = lepton_.Pz();
	double pxnu = MET_.Px();
	double pynu = MET_.Py();
	double pznu = 0.;
	otherSol_ = 0.;
	
	if (method == 3) {// use Method 3: Scale METet before Pz(nu) calculation if W is off-shell ( Mt(W)<M(W) ), provided by Meenakshi Narain

		double ptnu = MET_.Pt();
		double ptmu = lepton_.Pt();
		double M_t = TMath::Sqrt((ptmu+ptnu)*(ptmu+ptnu)-(pxmu+pxnu)*(pxmu+pxnu)-(pymu+pynu)*(pymu+pynu));
		double A;
		if (M_t < M_W) {A = M_W*M_W/2.;isComplex_= false;}
		else { // assume M_t=M_W, rescale MET accordingly
              isComplex_= true;
		      A = M_t*M_t/2.;
		      double k = ptmu*ptnu-pxmu*pxnu-pymu*pynu;
		      if (k==0.) {k = 0.00001;}
		      double scf = 0.5*M_W*M_W/k;
		      pxnu *= scf;
		      pynu *= scf;
		      ptnu = TMath::Sqrt(pxnu*pxnu+pynu*pynu);
		      }
		double B = pxnu*pxmu + pynu*pymu;
		double C = TMath::Max(1. + pow(ptnu,2) * (pow(pzmu,2)-pow(emu,2)) / pow(A+B,2)  , 0.);
		C = TMath::Sqrt(C);
		double S1= (-(A+B)*pzmu + (A+B)*emu*C) / (pow(pzmu,2)-pow(emu,2));
		double S2= (-(A+B)*pzmu - (A+B)*emu*C) / (pow(pzmu,2)-pow(emu,2));
	   
		if (fabs(S1) < fabs(S2)) {pznu = S1; otherSol_ = S2;}
		else {pznu = S2; otherSol_ = S1;}
		newPtneutrino1_ = ptnu; 
		newPtneutrino2_ = ptnu;
	}

	else if (method == 5){ // use Method 5: provided by Dan Geen
	
        double prmu = TMath::Sqrt( pxmu*pxmu + pymu*pymu + pzmu*pzmu); // lepton direction cosines		
		double dd = M_W*M_W/(2.0*prmu) + pxmu*pxnu/prmu + pymu*pynu/prmu;
		double bb = (2.0*dd*pzmu/prmu)/(pzmu*pzmu/(prmu*prmu) - 1.0);
		double cc = (dd*dd - pxnu*pxnu - pynu*pynu)/(pzmu*pzmu/(prmu*prmu) - 1.0);

		double tmproot = bb*bb - 4.0*cc;

		if (tmproot<0.0) {
		    isComplex_= true;
		    pznu = - bb/2.0; // take real part of complex roots
			otherSol_ = pznu;

			// recalculate the neutrino pT   B = pvp ./pvp(4)
			// solve quadratic eq. discriminator = 0 for pT of nu
			double prnu = TMath::Sqrt(pxnu*pxnu + pynu*pynu + pznu*pznu);
			double a = ((pxnu*pxnu + pynu*pynu)/(prnu*prnu)) *(pzmu*pzmu/(prmu*prmu) - 1.0) + pow(pxmu*pxnu/(prmu*prnu) + pymu*pynu/(prmu*prnu),2);
			double b = (M_W*M_W*((pxmu*pxnu + pymu*pynu)/(prmu*prnu)))/prmu;
			double c = pow((M_W*M_W)/(2.0*prmu),2);
			double ptnu = TMath::Sqrt( pxnu*pxnu + pynu*pynu); // old
		
			double tmpdisc = b*b - 4.0*a*c;
		        //if tmpdisc < 0 {std::cout<<"tmpdisc"<<std::endl;}
			double tmpsolpt1 = (-b + TMath::Sqrt(tmpdisc))/(2.0*a);
			double tmpsolpt2 = (-b - TMath::Sqrt(tmpdisc))/(2.0*a);
			//if (tmpsolpt1 < 0 || tmpsolpt2 < 0) {std::cout<<tmpsolpt1<<"   "<<tmpsolpt1<<std::endl;}
			if ( fabs( tmpsolpt1 - ptnu ) < fabs( tmpsolpt2 - ptnu) ) { newPtneutrino1_ = tmpsolpt1; newPtneutrino2_ = tmpsolpt2;}
			else { newPtneutrino1_ = tmpsolpt2; newPtneutrino2_ = tmpsolpt1; } 
		
		}
		else {
			isComplex_ = false;
			double tmpsol1 = (-bb + TMath::Sqrt(tmproot))/(2.0);
			double tmpsol2 = (-bb - TMath::Sqrt(tmproot))/(2.0);
			//std::cout << " Neutrino Solutions: " << tmpsol1 << ", " << tmpsol2 << std::endl;
			
			if (typeR == 0 ) {
				// two real roots, pick the one closest to pz of muon
			  if (TMath::Abs(tmpsol2-pzmu) < TMath::Abs(tmpsol1-pzmu)) { pznu = tmpsol2; otherSol_ = tmpsol1;}
			  else { pznu = tmpsol1; otherSol_ = tmpsol2; } 
				// if pznu is > 300 pick the most central root
				if ( pznu > 300. ) {
				  if (TMath::Abs(tmpsol1)<TMath::Abs(tmpsol2) ) { pznu = tmpsol1; otherSol_ = tmpsol2; }
				  else { pznu = tmpsol2; otherSol_ = tmpsol1; }
				}
			}
			if (typeR == 1 ) {
				// two real roots, pick the one closest to pz of muon
			  if (TMath::Abs(tmpsol2-pzmu) < TMath::Abs(tmpsol1-pzmu)) { pznu = tmpsol2; otherSol_ = tmpsol1; }
			  else {pznu = tmpsol1; otherSol_ = tmpsol2; }
			}
			if (typeR == 2 ) {
				// pick the most central root.
			  if (TMath::Abs(tmpsol1)<TMath::Abs(tmpsol2) ) { pznu = tmpsol1; otherSol_ = tmpsol2; }
			  else { pznu = tmpsol2; otherSol_ = tmpsol1; }
			}
			if (typeR == 3 ) {
				// pick the largest value of the cosine
				TVector3 p3w, p3mu;
				p3w.SetXYZ(pxmu+pxnu, pymu+pynu, pzmu+ tmpsol1);
				p3mu.SetXYZ(pxmu, pymu, pzmu );
				
				double sinthcm1 = 2.*(p3mu.Perp(p3w))/M_W;
				p3w.SetXYZ(pxmu+pxnu, pymu+pynu, pzmu+ tmpsol2);
				double sinthcm2 = 2.*(p3mu.Perp(p3w))/M_W;

				double costhcm1 = TMath::Sqrt(1. - sinthcm1*sinthcm1);
				double costhcm2 = TMath::Sqrt(1. - sinthcm2*sinthcm2);

				if ( costhcm1 > costhcm2 ) { pznu = tmpsol1; otherSol_ = tmpsol2; }
				else { pznu = tmpsol2;otherSol_ = tmpsol1; }
			}
			
		}
	}
	
	else { // default
	
		double a = M_W*M_W - M_mu*M_mu + 2.0*pxmu*pxnu + 2.0*pymu*pynu;
		double A = 4.0*(emu*emu - pzmu*pzmu);
		double B = -4.0*a*pzmu;
		double C = 4.0*emu*emu*(pxnu*pxnu + pynu*pynu) - a*a;

		double tmproot = B*B - 4.0*A*C;

		if (tmproot<0) {
			isComplex_= true;
		
			if (typeC == 0) {
				pznu = - B/(2*A); // take real part of complex roots
				otherSol_ = pznu;

				// recalculate the neutrino pT
				// solve quadratic eq. discriminator = 0 for pT of nu
				double pnu = MET_.E();
				double Delta = (M_W*M_W - M_mu*M_mu);
				double alpha = (pxmu*pxnu/pnu + pymu*pynu/pnu);
				double ptmu = TMath::Sqrt( pxmu*pxmu + pymu*pymu); ptmu = TMath::Sqrt( pxmu*pxmu + pymu*pymu);
				double ptnu = TMath::Sqrt( pxnu*pxnu + pynu*pynu); // old
				double AA = 4.*pzmu*pzmu - 4*emu*emu + 4*alpha*alpha;
				double BB = 4.*alpha*Delta;
				double CC = Delta*Delta;

				double tmpdisc = BB*BB - 4.0*AA*CC;
				double tmpsolpt1 = (-BB + TMath::Sqrt(tmpdisc))/(2.0*AA);
				double tmpsolpt2 = (-BB - TMath::Sqrt(tmpdisc))/(2.0*AA);

				if ( fabs( tmpsolpt1 - ptnu ) < fabs( tmpsolpt2 - ptnu) ) { newPtneutrino1_ = tmpsolpt1; newPtneutrino2_ = tmpsolpt2;}
				else { newPtneutrino1_ = tmpsolpt2; newPtneutrino2_ = tmpsolpt1; }
			}

			if (typeC == 1) {
				pznu = 0; // set pz to zero
				otherSol_ = pznu;

				// recalculate the neutrino pT
				// solve quadratic eq. discriminator = 0 for pT of nu
				double pnu = MET_.E();
				double Delta = (M_W*M_W - M_mu*M_mu);
				double alpha = (pxmu*pxnu/pnu + pymu*pynu/pnu);
				double ptmu = TMath::Sqrt( pxmu*pxmu + pymu*pymu); ptmu = TMath::Sqrt( pxmu*pxmu + pymu*pymu);
				double ptnu = TMath::Sqrt( pxnu*pxnu + pynu*pynu); // old
				double AA = 4.*pzmu*pzmu - 4*emu*emu + 4*alpha*alpha;
				double BB = 4.*alpha*Delta;
				double CC = Delta*Delta;

				double tmpdisc = BB*BB - 4.0*AA*CC;
				double tmpsolpt1 = (-BB + TMath::Sqrt(tmpdisc))/(2.0*AA);
				double tmpsolpt2 = (-BB - TMath::Sqrt(tmpdisc))/(2.0*AA);

				if ( fabs( tmpsolpt1 - ptnu ) < fabs( tmpsolpt2 - ptnu) ) { newPtneutrino1_ = tmpsolpt1; newPtneutrino2_ = tmpsolpt2;}
				else { newPtneutrino1_ = tmpsolpt2; newPtneutrino2_ = tmpsolpt1; }
			}

		}
		else {
			isComplex_ = false;
			double tmpsol1 = (-B + TMath::Sqrt(tmproot))/(2.0*A);
			double tmpsol2 = (-B - TMath::Sqrt(tmproot))/(2.0*A);

			//std::cout << " Neutrino Solutions: " << tmpsol1 << ", " << tmpsol2 << std::endl;
		
			if (typeR == 0 ) {
				// two real roots, pick the one closest to pz of muon
			  if (TMath::Abs(tmpsol2-pzmu) < TMath::Abs(tmpsol1-pzmu)) { pznu = tmpsol2; otherSol_ = tmpsol1;}
			  else { pznu = tmpsol1; otherSol_ = tmpsol2; } 
				// if pznu is > 300 pick the most central root
				if ( pznu > 300. ) {
				  if (TMath::Abs(tmpsol1)<TMath::Abs(tmpsol2) ) { pznu = tmpsol1; otherSol_ = tmpsol2; }
				  else { pznu = tmpsol2; otherSol_ = tmpsol1; }
				}
			}
			if (typeR == 1 ) {
				// two real roots, pick the one closest to pz of muon
			  if (TMath::Abs(tmpsol2-pzmu) < TMath::Abs(tmpsol1-pzmu)) { pznu = tmpsol2; otherSol_ = tmpsol1; }
			  else {pznu = tmpsol1; otherSol_ = tmpsol2; }
			}
			if (typeR == 2 ) {
				// pick the most central root.
			  if (TMath::Abs(tmpsol1)<TMath::Abs(tmpsol2) ) { pznu = tmpsol1; otherSol_ = tmpsol2; }
			  else { pznu = tmpsol2; otherSol_ = tmpsol1; }
			}
			if (typeR == 3 ) {
				// pick the largest value of the cosine
				TVector3 p3w, p3mu;
				p3w.SetXYZ(pxmu+pxnu, pymu+pynu, pzmu+ tmpsol1);
				p3mu.SetXYZ(pxmu, pymu, pzmu );
			
				double sinthcm1 = 2.*(p3mu.Perp(p3w))/M_W;
				p3w.SetXYZ(pxmu+pxnu, pymu+pynu, pzmu+ tmpsol2);
				double sinthcm2 = 2.*(p3mu.Perp(p3w))/M_W;

				double costhcm1 = TMath::Sqrt(1. - sinthcm1*sinthcm1);
				double costhcm2 = TMath::Sqrt(1. - sinthcm2*sinthcm2);

				if ( costhcm1 > costhcm2 ) { pznu = tmpsol1; otherSol_ = tmpsol2; }
				else { pznu = tmpsol2;otherSol_ = tmpsol1; }
			}
		
		}
	}
	
	//Particle neutrino;
	//neutrino.setP4( LorentzVector(pxnu, pynu, pznu, TMath::Sqrt(pxnu*pxnu + pynu*pynu + pznu*pznu ))) ;

	return pznu;
}
