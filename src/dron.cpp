#include "dron.hh"
#include "Dr3D_gnuplot_api.hh"
#include "mac_obr.hh"
#include <cmath>
#include <iostream>
#include "przesz.hh"
#include "mac_obr.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void dron::ustaw(wektor<double,3> poz)
{
  for(int i=0;i<3;i++)
    tab[i]=poz[i];
  orientacja=0;
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

  kad[0]=tab[0];
  kad[1]=tab[1];
  kad[2]=tab[2];
  
  wektor<double,3> wym_k,przes1,przes2;
  wym_k[0]=8;
  wym_k[1]=4;
  wym_k[2]=4;

  double wym_sr[2];
  wym_sr[0]=0.5;
  wym_sr[1]=1.5;
  
  przes1[0]=-4.25; przes1[1]=-1; przes1[2]=0;
  przes1=m_obr(orientacja)*przes1;

  przes2[0]=-4.25; przes2[1]=1; przes2[2]=0;
  przes2=m_obr(orientacja)*przes2;

  sr1[0]=tab[0]+przes1[0];
  sr1[1]=tab[1]+przes1[1];
  sr1[2]=tab[2];
  
  sr2[0]=tab[0]+przes2[0];
  sr2[1]=tab[1]+przes2[1];
  sr2[2]=tab[2];

  kad.zmien_wymiary(wym_k);
  kad.obroc(orientacja*180/3.1416);
  sr1.obroc(orientacja*180/3.1416);
  sr2.obroc(orientacja*180/3.1416);
  sr1.zmien_wymiary(wym_sr);
  sr2.zmien_wymiary(wym_sr);
  kad.rysuj(api,czesci[0],kolor);
  sr1.rysuj(api,czesci[1],kolor);
  sr1[1]=tab[1]+przes2[1];
  sr1[0]=tab[0]+przes2[0];
  sr1.rysuj(api,czesci[2],kolor);
}
void dron::plyn(std::shared_ptr<drawNS::Draw3DAPI> api,double r,double kat_w,przesz l_p[3],dron l_d[3],tafla t,dno dno)
{
  wektor<double,3> sr_dron;
  double ile=r,h;
  h=tan((kat_w/180)*3.1416)*r;
  h=h/(r*5);
  
  for(int i=0;i<r*5;i++)
    {
      
      for(int i=0;i<3;i++)
	sr_dron[i]=tab[i];
      
      for(int i=0;i<3;i++)
	if(l_p[i].czy_kolizja(sr_dron)==true)
	  {
	    std::cout<<"Kolizja \n";
	    delete &api;
	    exit(1);
	  }
      
      for(int i=0;i<3;i++)
	if(l_d[i].czy_kolizja(sr_dron)==true)
	  {
	    std::cout<<"Kolizja \n";
	    delete &api;
	    exit(1);
	  }

      if(t.czy_kolizja(sr_dron)==true)
	  {
	    std::cout<<"Kolizja \n";
	    delete &api;
	    exit(1);
	  }

      if(dno.czy_kolizja(sr_dron)==true)
	  {
	    std::cout<<"Kolizja \n";
	    delete &api;
	    exit(1);
	  }
      
      usun(api);

      wektor<double,3> przes;
      przes[0]=0.2; przes[1]=0; przes[2]=h;
      przes=m_obr(orientacja)*przes;
      
      for(int i=0;i<3;i++)
	tab[i]=tab[i]+przes[i];
      rysuj(api);
      
      ile-=0.2;
    }
}

bool dron::czy_kolizja(wektor<double,3> d)
{
  if(abs(d[0]-tab[0])>9)
     return false;
  if(abs(d[1]-tab[1])>6.5)
     return false;
  if(abs(d[2]-tab[2])>4)
    return false;
  for(int i=0;i<3;i++)
    if(abs(tab[i]-d[i])>0.1)
      return true;
  return false;
}
