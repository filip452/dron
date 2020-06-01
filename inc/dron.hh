#ifndef DRON_HH
#define DRON_HH
#include "prost.hh"
#include "gran.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "przesz.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class dron: public prost
{
protected:
  int czesci[3];
public:
  void ustaw(wektor<double,3> poz);
  void usun(std::shared_ptr<drawNS::Draw3DAPI> api);
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
  void plyn(std::shared_ptr<drawNS::Draw3DAPI> api,double r,double kat_w,przesz p[3]);
};

#endif
