#ifndef TAFLA_HH
#define TAFLA_HH
#include "plaszczyzna.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "kolizje.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class tafla: public plaszczyzna, public kolizje
{
public:
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
  bool czy_kolizja(wektor<double,3> d) override;
};

#endif
