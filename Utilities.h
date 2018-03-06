#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
long RandInt(long pnLower, long pnUpper);
bool PromptContinue(char *Prompt = NULL,char *sEndMsg = NULL);
ostream& operator<<(ostream& OUT, const vector< complex<double> >& vRoots);
ostream& operator<<(ostream& OUT, const complex<double> &NUM);
ostream& operator<<(ostream& OUT, const vector<double> &vNums);
