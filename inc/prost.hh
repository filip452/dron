#ifndef PROST_HH
#define PROST_HH
#include "bryla.hh"
#include "interfejs_rys.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class prost: public bryla
{
protected:
  wektor<double,3> w;
public:
  void zmien_wymiary(wektor<double,3> wym);
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api,int & p);
  void ruch(std::shared_ptr<drawNS::Draw3DAPI> api,wektor<double,3> r,int & p);
};

#endif