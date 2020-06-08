#ifndef DRON_HH
#define DRON_HH
#include "prost.hh"
#include "gran.hh"
#include <iostream>
#include <string>
#include "Dr3D_gnuplot_api.hh"
#include "przesz.hh"
#include "kolizje.hh"
#include "dno.hh"
#include "tafla.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class dron: public prost, public kolizje
{
protected:
  int czesci[3];
  std::string kolor;
public:
  void zmien_kolor (std::string new_c)
  {kolor=new_c;}
  void ustaw(wektor<double,3> poz);
  void usun(std::shared_ptr<drawNS::Draw3DAPI> api);
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
  void plyn(std::shared_ptr<drawNS::Draw3DAPI> api,double r,double kat_w,przesz l_p[3],dron l_d[3],tafla t,dno dno);
  bool czy_kolizja(wektor<double,3> d) override;
};

#endif
