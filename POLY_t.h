/* POLY_t: Polynomial Type
 */
#include <vector>    // vector
#include <complex>   // complex
using namespace std; // vector
using namespace std::complex_literals;
struct POLY_t {
vector<double> COEFF; // Coefficients: Index is Power of 10 
vector< complex<double> > ROOTS;
vector< complex<double> >  GetRoots();
friend ostream& operator<<(ostream& OUT, const POLY_t& POLY);  
static void test(POLY_t &P);
  double EVAL(double x);
  void Plot();
  ~POLY_t();
  POLY_t(vector<double> pvUsrCoeff);
  POLY_t();
  double operator()(double pfX);
};
