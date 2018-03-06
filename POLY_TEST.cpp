/*
POLY_DRIVE: Driver for POLY_t.test()
*/
#include <iostream>     // cout
#include "POLY_t.h"
#include "Utilities.h" // vector<double> output operator
int main(int argc, char *argv[]){
  vector < vector<double> >  vvTestData= {
	{1,0,1}, //roots 1±i
	{0,1,0}, // roots 0
	{0,1,1} // roots 1
  };
  //Test Known Data
  for  (vector < vector<double> >::iterator iV = vvTestData.begin() ; iV != vvTestData.end(); ++iV){
	cout << "TestData" << "(" <<  *iV << ")" << endl;
	POLY_t P(*iV);
	POLY_t::test(P);
  }
  //Test Randomly Generated Data
  do {
	POLY_t P;
	POLY_t::test(P);
	if (PromptContinue("<ret>Another POLY?","END POLIES")){ continue ; } else { break ; }	
  } while(true);
  system("pkill -x gnuplot_qt");
}
