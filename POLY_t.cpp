#include <iostream>     // cout,cin
#include <iomanip>      // setw()
#include "gnuplot-iostream.h" // Gnuplot
#include "POLY_t.h"
#include "Utilities.h"
#define DEBUG
string POLY_t::STRING(){
  string ret("F(x)=(");
  vector<double> vCoeff = COEFF ;  
  reverse (vCoeff.begin(),vCoeff.end());
  size_t TermCnt(0);
  for (size_t iCoeff(0) ; iCoeff < vCoeff.size() ; iCoeff++){
	double Coeff(vCoeff[iCoeff]);
	if (Coeff != 0){
	  if (Coeff < 0) { ret+='-'; } else if (TermCnt > 0){ ret+='+'; }
	  float AbsCoeff(fabs(Coeff));
	  if (AbsCoeff != 1){ ret += to_string((size_t)AbsCoeff); }
	  size_t Degree(vCoeff.size()-iCoeff-1);
	  if (Degree == 0){
		;
	  } else {
		ret+='x';
		if ((Degree > 1) or (Degree < 0)){
		  ret+='^';
		  ret+=to_string(Degree);
		}
	  }
	  TermCnt++;
	}
  }
  if (TermCnt == 0){
	ret+="0";
  }
  ret+=")";
  return ret;
}

ostream& operator<<(ostream& OUT, POLY_t& FUN){
  cout << FUN.STRING();
  return cout ;
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

double POLY_t::EVAL(double X){
  double fRetSum(0.0);
  for (size_t Degree(0) ; Degree < COEFF.size() ; Degree++){
#ifdef xDEBUG
	cout <<   "EVAL F(" << X                                       << "): "
		 <<   "Degree(" << Degree                                  << "), "
		 <<    "Coeff(" << COEFF[Degree]                           << "), "
		 <<      "pow(" << pow(X,Degree)                           << "): Adding "
		 <<  "Product(" << COEFF[Degree] * pow(X,Degree)           << ") To"
		 <<      "ACC(" << fRetSum                                 << ")"
		 <<     "--> (" << fRetSum + COEFF[Degree] * pow(X,Degree) << ")" << endl;
#endif
	fRetSum += COEFF[Degree] * pow(X,Degree);
  }
#ifdef xDEBUG
  cout <<   "EVAL():" << "F(" << X << ") --> " <<  fRetSum << endl;
#endif
  return fRetSum;
}

double POLY_t::operator()(double X){ return EVAL (X); }

void POLY_t::test(POLY_t &P){
  P.FindRoots();
  cout << "FUNCTION:"
	   << " " << P.STRING() 
	   << " " << "COEFF: " << P.COEFF
	   << " " << "ROOTS: " << P.Roots() << endl;
  P.Plot();
}
void POLY_t::Plot(){
  Gnuplot gp;
  gp << "set xzeroaxis"  << "\n";
  gp << "set yzeroaxis"  << "\n";
  gp << "set autoscale"  << "\n";
  gp << "set xlabel 'x'" << "\n";
  gp << "set ylabel '" << (*this).STRING() << "'" << "\n";
  gp << "set style line 1"
	 << "linetype 1"             << " "
	 << "linecolor rgb 'orange'" << " "
	 << "pointtype 1"            << " "
	 << "linewidth 2"            << " "
	 << "\n";
  gp << "set style line 2"       << " "
	 << "linecolor rgb 'blue'"    << " "
	 << "pointtype 1"            << " "
	//<< "linewidth 10"           << " "
	 << "pointsize 1" << " "
	 << "\n";
  
  gp << "plot" 
	 << "'-' with lines linestyle 1"
	 << "title '" << "" << "'"
	 << ", "
	 << "'-' with points linestyle 2 title 'Real Roots " << (*this).Roots() << "'" << "\n"
	 << "\n";
  for (long iX(MIN_X-1); iX <= MAX_X  ; iX++){
	gp   << iX << " " << (*this)(iX) << "\n" ;
  }
  gp << "e\n";
  for (set<double>::iterator i(ROOTS.begin()); i!=ROOTS.end();++i){
	gp   << (*i) << " " << 0 << "\n" ;
  }
  gp << "e\n";
}
string POLY_t::Roots(){
  string ret;
  if (bZero){ ret = "<" + STRING() + ">";
  } else {
	ret= "{";
	for (set<double>::iterator i = ROOTS.begin() ;i != ROOTS.end() ; ++i ){
	  if (i==ROOTS.begin()){
		ret += to_string(*i);
	  } else {
		ret += ", " + to_string(*i);
	  }
	}
	ret += "}"; 
  }
  return ret;
}

bool NearEnough(double fVal1, double fVal2, double fEpsilon){
  /* NearEnough(): Return True if two number approximate  */
  bool RET(abs(fVal1-fVal2) < fEpsilon);
  return RET;
}
void POLY_t::FindRoots(){
  bZero=true;
  size_t NumIntervals(MAX_X-MIN_X/EPSILON);
  for (size_t IntervalNum(0); IntervalNum < NumIntervals; IntervalNum++){
	double
	  L(MIN_X + (IntervalNum * EPSILON)),
	  R(L + EPSILON > MAX_X ? MAX_X : L + EPSILON),
	  FL((*this)(L)),
	  FR((*this)(R));
	if (FL*FR > (double)0.0) {
	  bZero=false;
#ifdef xDEBUG
	  cout << "REJECT: SAME SIGN: "
		   << "L: F(" << L << "){" << FL << "}" << " "
		   << "R: F(" << R << "){" << FR << "}" << endl;
#endif
	} else if (FL*FR < (double)0.0) {
#ifdef DEBUG
	  cout << "DIFF SIGN: "
		   << "L: F(" << L << "){" << FL << "}" << " "
		   << "R: F(" << R << "){" << FR << "}"
		   << "Root(" <<  L+R/2 << ")" << endl ;
#endif
	  ROOTS.insert(L+R/2);
	  bZero=false;
	} else {
	  if (FL == double(0.0)) {
#ifdef DEBUG
		cout << "F(L)==0: "
			 << "L: F(" << L << "){" << FL << "}" << " "
			 << "R: F(" << R << "){" << FR << "}"
			 << "Root(" << L << ")" << endl ;
#endif
		ROOTS.insert(L);
	  }
	  if (FR == double(0.0)) {
#ifdef DEBUG
		cout << "F(R)==0: "
			 << "L: F(" << L << "){" << FL << "}" << " "
			 << "R: F(" << R << "){" << FR << "}"
			 << "Root(" << R << ")" << endl ;
#endif
		ROOTS.insert(R);
	  }
	}
	//cout << endl;
  }
}
