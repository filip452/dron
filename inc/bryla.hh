#ifndef BRYLA_HH
#define BRYLA_HH
#include "wek.hh"
#include <iostream>

using std::cerr;
using std::endl;

class bryla: public wektor<double,3>
{
protected:
  double orientacja;
};

#endif
