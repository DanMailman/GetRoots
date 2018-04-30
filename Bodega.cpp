  /*
  bool bPrevTerm(false);
  bool bAllZeros(true);
  for (size_t iCoeff(0) ; iCoeff < COEFF.size() ; iCoeff++){
	if (COEFF[iCoeff] != 0){
	  bAllZeros = false;
	  break;
	}
  }
  if (bAllZeros){
	ret+="0)";
	return ret;
  }
  for (size_t iCoeff(0) ; iCoeff < Coeff.size() ; iCoeff++){
	size_t Degree = Coeff.size()-iCoeff-1;
	if (Coeff[iCoeff] != 0){
	  if (bPrevTerm) { ret+= " + " ; }
	  if (Coeff[iCoeff] != 1){ ret+=  to_string(Coeff[iCoeff]) ; }
	  if (Degree == 1){
		ret += "x";
	  } else if (Degree > 1){
		ret += ("x^" + to_string(Degree));
	  }
	  bPrevTerm = true;
	}
  }
  ret+= ")";
  return ret;
  
  }
bool bAllZeros(true);
  for (size_t iCoeff(0) ; iCoeff < FUN.COEFF.size() ; iCoeff++){
	if (FUN.COEFF[iCoeff] != 0){
	  bAllZeros = false;
	  break;
	}
  }
  if (bAllZeros){
	return cout << 0 << ")";
  }
  vector<double> Coeff = FUN.COEFF ;
  
  bool bPrevTerm(false);
  reverse (Coeff.begin(),Coeff.end());
  for (size_t iCoeff(0) ; iCoeff < Coeff.size() ; iCoeff++){
	size_t Degree = Coeff.size()-iCoeff-1;
	if (Coeff[iCoeff] != 0){
	  if (bPrevTerm) { cout << " + " ; }
	  cout << Coeff[iCoeff] << "*" << "X" << "^" << Degree ;
	  bPrevTerm = true;
	}
  }
  cout << ")";
  
  
