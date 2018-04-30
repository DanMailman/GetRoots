/* POLY_TEST: Driver for POLY_t.test() */
#include <signal.h>
#include <iostream>     // cout
#include "POLY_t.h"
#include "Utilities.h" // vector<double> output operator

void SigHandler(int s){
  printf("Caught signal %d\n",s);
  system("pkill -x gnuplot_qt");
  exit(1); 
}
int main(int argc, char *argv[]){
  struct sigaction sigIntHandler;
  
  sigIntHandler.sa_handler = SigHandler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;

   sigaction(SIGINT, &sigIntHandler, NULL);
   vector < vector<double> >  vvTestData= {
	 //{0},     // f(x) = 0; No Roots
	 //{1},     // f(x) = 1; No Roots
	 //{1,0},   // f(x) = x; Root 0
	 //{1,1},   // f(x) = x+1; Root -1
	 //{1,0,0}, // f(x) = x²: Roots 0
	 //{1,0,1}, // roots 1±i  
	 //{1,1,0}, // roots 0,-1 
	 //{1,1,1},  // roots -0.5 ± (√3/2)i
	 //{0,0},   // f(x) = 0; No Roots
	 //{0,1},   // f(x) = 1; No Roots
	 // {0,0,0}, // f(x) = 0; No Roots
	 // {0,0,1}, // f(x) = 1; No Roots 
	 // {0,1,0}, // f(x) = x; Root 0
	 // {0,1,1}, // f(x) = x+1; Root -1
	 {-1,2,4,7,6,6} // Caught By Epsilon 0.5, Missed By 0.01
   };
   //Test Known Data
   for  (vector < vector<double> >::iterator iV = vvTestData.begin() ; iV != vvTestData.end(); ++iV){
	 cout << "TestData" << "(" <<  *iV << ")" << endl;
	 POLY_t P(*iV);
	 POLY_t::test(P);  
   }
   //Test Randomly Generated Data   
   // do { 
   // 	 POLY_t P; 
   // 	 POLY_t::test(P);  
   // 	 if (PromptContinue((char*)"<ret>Another RANDOM POLY?",(char*)"END POLIES")){ continue ; } else { break ; }	
   //} while(true);
   //system("pkill -x gnuplot_qt");
}
