#include "dron.hh"
#include "Dr3D_gnuplot_api.hh"
#include "mac_obr.hh"
#include <cmath>
#include <iostream>
#include "przesz.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void dron::ustaw(wektor<double,3> poz)
{
  for(int i=0;i<3;i++)
    prost::tab[i]=poz[i];
  prost::orientacja=0;
}
void dron::usun(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  for(int i=0;i<3;i++)
    api->erase_shape(czesci[i]);
}
void dron::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  gran sr1,sr2;
  prost kad;

  kad[0]=prost::tab[0];
  kad[1]=prost::tab[1];
  kad[2]=prost::tab[2];
  
  wektor<double,3> wym_k,przes;
  wym_k[0]=8;
  wym_k[1]=4;
  wym_k[2]=4;

  double wym_sr[2];
  wym_sr[0]=0.5;
  wym_sr[1]=1.5;
  
  przes[0]=-4.25; przes[1]=-1; przes[2]=0;

  sr1[0]=prost::tab[0]+przes[0];
  sr1[1]=prost::tab[1]+przes[1];
  sr1[2]=prost::tab[2];
  
  sr2[0]=prost::tab[0]-4.25;
  sr2[1]=prost::tab[1]+1;
  sr2[2]=prost::tab[2];

  kad.zmien_wymiary(wym_k);
  kad.obroc(prost::orientacja*180/3.1416);
  sr1.obroc(prost::orientacja*180/3.1416);
  sr2.obroc(prost::orientacja*180/3.1416);
  sr1.zmien_wymiary(wym_sr);
  sr2.zmien_wymiary(wym_sr);
  kad.rysuj(api,czesci[0]);
  sr1.rysuj(api,czesci[1]);
  sr1[1]=prost::tab[1]-przes[1];
  sr2.rysuj(api,czesci[2]);
}
void dron::plyn(std::shared_ptr<drawNS::Draw3DAPI> api,double r,double kat_w,przesz p[3])
{
  double sr_dron[3];
  double ile=r,h;
  h=tan((kat_w/180)*3.1416)*r;
  h=h/(r*5);
  
  for(int i=0;i<r*5;i++)
    {
      for(int i=0;i<3;i++)
	sr_dron[i]=tab[i];
      for(int i=0;i<3;i++)
	if(p[i].czy_kolizja(sr_dron)==true)
	  {
	    std::cout<<"Kolizja\n";
	    exit(1);
	  }
      
      usun(api);
      prost::tab[0]=prost::tab[0]+0.2;
      prost::tab[2]=prost::tab[2]+h;
      rysuj(api);
      
      ile-=0.2;
    }
  if(ile!=0)
    {
      usun(api);
      prost::tab[0]=prost::tab[0]+ile;
      prost::tab[2]=prost::tab[2]+h;
      rysuj(api);
    }
}
