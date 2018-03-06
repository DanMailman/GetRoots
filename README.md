GetRoots: Input: Vector of Real Coefficients for Polynomial
          Output: Complex Roots and Plot of Associated Polynomial
          NOTE:  Currently limited to Degree 2
FILES:
 - POLY_MAKE.sh - Shell Script to Compile POLY_TEST
 - POLY_TEST: Driver for POLY_t::test()
 - POLY_t.h: Interface for POLY_t Type
 - POLY_t.cpp: Implementation for POLY_t Type
 - Utilities.h: Interface for Utility Functions
 - Utilities.cpp: Implementation for Utility Functions
 - gnuplot-iostream.h - Interface for popen() to gnuplot
 
NEXT STEPS:
 - (1.) Boundary Conditions: Handle f(x) = 5
 - (2a) Increase Degree Max/Generate Black Box Polynomials
 - (2b) Use Bracketing to Find Real Roots, if any
Fundamental theorem of algebra: every non-zero, single-variable, degree n>0 polynomial with real coefficients has, 
                                counted with multiplicity, exactly n complex roots.
