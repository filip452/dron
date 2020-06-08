#ifndef KOLIZJE_HH
#define KOLIZJE_HH
#include "wek.hh"

class kolizje
{
public:
  virtual bool czy_kolizja(wektor<double,3> d)
  {
    return false;
  }
};

#endif
