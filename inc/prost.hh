#ifndef PROST_HH
#define PROST_HH
#include "bryla.hh"
#include <iostream>
#include <string>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class prost: public bryla
{
protected:
  wektor<double,3> w;
public:
  prost() {orientacja=0;}
  prost(wektor<double,3> wym);
  void zmien_wymiary(wektor<double,3> wym);
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api,int & p,std::string kolor);
  void ruch(std::shared_ptr<drawNS::Draw3DAPI> api,wektor<double,3> r,int & p,std::string kolor);
  void obroc(double sigma);
};

#endif
