Running "make -k" generates 2 Executables:
 * POLY_TEST: - Generates Random Integer Coefficient Polynomials,
   			  - Finds Real Roots, Reports, Plots (using gnuplot).
 * KILL_GPLOT: Removes all Gplots From Display.

These Constants in <POLY_t.h> may be changed for recompilations.

	  MAX_DEGREE   5  // Highest Degree For Randomly Generated Polynomial
	  MIN_COEFF (-10) // Minimum for Randomly Generated Integer Coefficients
	  MAX_COEFF   10  // Mzximum for Randomly Generated Integer Coefficients
	  MIN_X     (-12) // Minimum For Plot/RootFind Interval
	  MAX_X       12  // Maximum For Plot/RootFind Interval
	  EPSILON   (0.1) // Inverval Size for Plotting/RootFinding

the data structure
           vector < vector<double> >  vvTestData
in POLY_TEST.cpp may be modified (by following the examples in the file) to
include coefficients for specific polynomials.              

Left to my own devices, I would add a threaded GUI to
modify Plot Parameters and enter coefficients at run-time.

Although it would be over-kill for learning our course material,
it would sharpen my skills with GUI, IPC, and threading.

Your thoughts are appreciated!
