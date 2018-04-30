#include <iostream>
#include <vector>
using namespace std;

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
long RandInt(long pnLower, long pnUpper);
bool PromptContinue(char *Prompt = NULL,char *sEndMsg = NULL);
 
ostream& operator<<(ostream& os, const vector<double>& v) ;
ostream& operator<<(ostream& os, const    set<double>& v) ;
