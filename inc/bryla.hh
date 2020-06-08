#ifndef BRYLA_HH
#define BRYLA_HH
#include "wek.hh"
#include <iostream>

using std::cerr;
using std::endl;

class bryla
{
protected:
  wektor<double,3> tab;
  double orientacja;
public:
  double & operator[] (int index)
  {
  if (index < 0 || index >= 3)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab[index];
}
};

#endif
