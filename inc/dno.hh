#ifndef DNO_HH
#define DNO_HH
#include "plaszczyzna.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class dno: public plaszczyzna
{
public:
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
};

#endif
