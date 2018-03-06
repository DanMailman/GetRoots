#include <iostream>     // cout,cin
#include <iomanip>      // setw()
#include "gnuplot-iostream.h" // Gnuplot
#include "POLY_t.h"
#include "Utilities.h"
#define MAX_DEGREE   2
#define MIN_COEFF (-10)
#define MAX_COEFF   10
#define MIN_X     (-12)
#define MAX_X       12
ostream& operator<<(ostream& OUT, const POLY_t& POLY){
  
  for (auto i = POLY.COEFF.begin(); i != POLY.COEFF.end(); ++i){
    cout << *i << ' ';
  }
  cout << endl;
  return OUT;
}
POLY_t::~POLY_t(){
  // cout << "~POLY_t(DESTRUCTOR)" << endl;
}

POLY_t::POLY_t(vector<double> pvUsrCoeff){
  //cout << "ENTER: POLY_t(CONSTRUCTOR)" << endl;
  COEFF = pvUsrCoeff;
  reverse(COEFF.begin(),COEFF.end());
  /*for (size_t iCoeff(0);iCoeff <= MAX_DEGREE;iCoeff++){
	COEFF.insert(COEFF.begin()+iCoeff, RandInt(MIN_COEFF,MAX_COEFF));
	}*/
  //cout << "EXIT: POLY_t(CONSTRUCTOR)" << endl;
}
POLY_t::POLY_t(){
  //cout << "ENTER: POLY_t(CONSTRUCTOR)" << endl;
  for (size_t iCoeff(0);iCoeff <= MAX_DEGREE;iCoeff++){
	COEFF.insert(COEFF.begin()+iCoeff, RandInt(MIN_COEFF,MAX_COEFF));
  }
  //cout << "EXIT: POLY_t(CONSTRUCTOR)" << endl;
}
double POLY_t::EVAL(double pfX){
  double fRetSum;
  for (size_t ExpOf10(0) ; ExpOf10 < COEFF.size() ; ExpOf10++){
	fRetSum += COEFF[ExpOf10] * pow(pfX,ExpOf10);
  }
  return fRetSum;
}
vector< complex<double> > POLY_t::GetRoots(){
  double A(COEFF[2]), B(COEFF[1]), C(COEFF[0]);
  if (A == 0) { return { -C/B + 0i } ;}
  complex<double>
	AxisOfSymmetry(-B/(2*A)),
	Discriminant(pow(B,2)-(4*A*C)),
	AbsDstFrmAxis(sqrt(abs(Discriminant))/(2*A)),
	RootDstFrmAxis(Discriminant.real() == 0
				   ? 0.+0i
				   : Discriminant.real() < 0 ? AbsDstFrmAxis * 1i :AbsDstFrmAxis) ;
  cout << "A" << "(" << A << ")" << " "
	   << "B" << "(" << B << ")" << " "
	   << "C" << "(" << C << ")" << " "
	   << "AxisOfSymmetry" << "(" << AxisOfSymmetry << ")" << " "
	   << "Discriminant"   << "(" << Discriminant   << ")" << " "
	   << "AbsDstFrmAxis"  << "(" << AbsDstFrmAxis  << ")" << " "
	   << "RootDstFrmAxis" << "(" << RootDstFrmAxis << ")" << endl;
	   
  return { AxisOfSymmetry + RootDstFrmAxis ,
	  /**/ AxisOfSymmetry - RootDstFrmAxis } ;
  
}
double POLY_t::operator()(double pfX){ return EVAL (pfX); }
void POLY_t::test(POLY_t &P){
  cout << "F COEFFICIENTS: " << P << endl;
  P.Plot();
  cout << "F ROOTS: " << P.GetRoots() << endl;
  
}
void POLY_t::Plot(){
  Gnuplot gp;
  gp << "set xzeroaxis" << "\n";
  gp << "set yzeroaxis" << "\n";
  gp << "set autoscale" << "\n";
  gp << "set xlabel 'x'" << "\n";
  gp << "set ylabel 'Poly f(x)'"    << "\n";  
  gp << "plot '-' using 1:2 with linespoint lw 2 pt 11 title 'f(x)' \n";
  for (long iX(MIN_X); iX <= MAX_X  ; iX++){
	gp   << iX << " " << (*this)(iX) << "\n" ;
  }
  gp << "e\n";
}
//gp << "set x2tics" << "\n";   // Put Y Vals on top of plot
//cout << "f(" << setw(4) << iX << "): " << setw(10) << right << (*this)(iX) << ")\n" ;	
	  
//gp << "plot '-' using 1:2:xtic(3):x2tic(2) with linespoint lw 2 pt 11 title 'f(x)' \n";
//gp   << iX << " " << (int)(*this)(iX) << " " << (int)(*this)(iX) << "\n" ;
  
/*	
cout << "F(-1): " << P(-1) << endl;
	  cout << " F(0): " << P( 0) << endl;
	  cout << " F(1): " << P( 1) << endl;
	while(true){
	  cout 
	  while(true){
		cout << Poly();
		if (PromptContinue("<ret>Another Eval?","END EVALS")){ continue ; } else { break ; }	
	  }
	*/
//gp << "set xrange " << "[" << MIN_X << ":" << MAX_X << "]" << "\n";
  
/*
 cout << "DISCRIMINANT"    << "(" << fDiscriminant   << ")" << endl
	   << "REAL TERM BASE"  << "(" << fRealTermBase   << ")" << endl
	   << "PossPosCoeffOfI" << "(" << PossPosCoeffOfI << ")" << endl
	   << "fI_OR_1_Factor"  << "(" << fI_OR_1_Factor  << ")" << endl;
*/
