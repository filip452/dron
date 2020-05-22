#ifndef GRAN_HH
#define GRAN_HH
#include "bryla.hh"
#include "interfejs_rys.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"

class gran: public bryla
{
protected:
  double w[2];
public:
  void zmien_wymiary(double wym[2]);
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api,int & p);
  void ruch(std::shared_ptr<drawNS::Draw3DAPI> api,wektor<double,3> r,int & p);
};

#endif