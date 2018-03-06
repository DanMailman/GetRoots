#include <cstddef>             // NULL
#include <string>              // string
#include <iostream>            // cout,cin
#include <cstdlib>             // rand
#include <vector>              // vector
#include <complex>             // complex
using namespace std; // string
long RandInt(long pnLower, long pnUpper){
  return(pnLower + (rand() % static_cast<int>(pnUpper - pnLower + 1)));
}
bool PromptContinue(char *Prompt = NULL, char *sEndMsg = NULL){
  string sIn,sOut((Prompt != NULL) ? Prompt :"(<ret>)Another? ");
  cout << sOut << endl;
  getline(cin,sIn);
  if (sIn == string("")){
	return true;
  } else {
	cout << "Input" << "(" << sIn << ")" << sOut << endl;
	return false;
  }
}
ostream& operator<<(ostream& OUT, const complex<double> &NUM){
  //TODO: Fix -0
  OUT << NUM.real() << "+" << NUM.imag() << "i";
  return OUT;
}
ostream& operator<<(ostream& OUT, const vector< complex<double> >& vRoots){
  //TODO: Fix Trailing Space
  for (auto i = vRoots.begin(); i != vRoots.end(); ++i){
    OUT << (*i) << ' ';
  }
  return OUT;
}
ostream& operator<<(ostream& OUT, const vector<double> &vNums){
  //TODO: Fix Trailing Space
  for (auto i = vNums.begin(); i != vNums.end(); ++i){
	OUT << (*i) << ' ';
  }
  return OUT;
}
