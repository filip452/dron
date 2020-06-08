#ifndef PRZESZ_HH
#define PRZESZ_HH
#include "kolizje.hh"
#include "prost.hh"
#include "wek.hh"

class przesz: public prost, public kolizje
{
public:
  bool czy_kolizja(wektor<double,3> d) override;
};

#endif
