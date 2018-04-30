/* POLY_t: Polynomial Type */
#include <iostream>
#include <vector>    // vector
#include <set>
#define MAX_DEGREE   5
#define MIN_COEFF (-10)
#define MAX_COEFF   10
#define MIN_X     (-12)
#define MAX_X       12
#define EPSILON  (0.001)
using namespace std; // vector
struct POLY_t {
  vector<double> COEFF; // Coefficients: Index is Exponent of X 
  set   <double> ROOTS;
  bool bZero;
  friend ostream& operator<<(ostream& OUT, const POLY_t& POLY);  
  static void test(POLY_t &P);
  double EVAL(double x);
  string STRING();
  void FindRoots();
  string Roots();
  void Plot();
  void PlotRoots();
  ~POLY_t();
  POLY_t(vector<double> pvUsrCoeff);
  POLY_t();
  double operator()(double pfX);
};
