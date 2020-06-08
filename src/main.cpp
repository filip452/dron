#include <iostream>
#include <string>
#include "wek.hh"
#include "macierz.hh"
#include "dron.hh"
#include "dno.hh"
#include "tafla.hh"
#include "Dr3D_gnuplot_api.hh"
#include "przesz.hh"

using std::cout;
using std::endl;
using std::cin;

using std::string;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

int main()
{
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-25,25,-25,25,0,25,0));
  
  double wym_plasz[4];
  dno dno;
  tafla t;

  wym_plasz[0]=25; wym_plasz[1]=-25; wym_plasz[2]=25; wym_plasz[3]=-25;
  dno.ustaw_wym(wym_plasz);
  t.ustaw_wym(wym_plasz);
  
  dno.rysuj(api);
  t.rysuj(api);
  
  wektor<double,3> poz;

  przesz l_przeszkod[3];
  dron l_dronow[3];
  
  dron d1;
  poz[2]=10;
  d1.ustaw(poz);
  d1.zmien_kolor("red");
  d1.rysuj(api);
  l_dronow[0]=d1;

  dron d2;
  poz[0]=-10;
  poz[1]=-10;
  poz[2]=10;
  d2.ustaw(poz);
  d2.zmien_kolor("purple");
  d2.rysuj(api);
  l_dronow[1]=d2;

  dron d3;
  poz[0]=-5;
  poz[1]=15;
  poz[2]=10;
  d3.ustaw(poz);
  d3.zmien_kolor("orange");
  d3.rysuj(api);
  l_dronow[2]=d3;

  wektor<double,3> wym;
  wym[0]=4;
  wym[1]=4;
  wym[2]=10;

  przesz p1,p2,p3;
  
  p1[0]=10;
  p1[1]=4;
  p1[2]=5;

  p1.zmien_wymiary(wym);

  l_przeszkod[0]=p1;

  wym[0]=2;
  wym[1]=6;
  wym[2]=8;

  p2[0]=12;
  p2[1]=-6;
  p2[2]=8;

  p2.zmien_wymiary(wym);

  l_przeszkod[1]=p2;
  
  wym[0]=6;
  wym[1]=2;
  wym[2]=5;

  p3[0]=-4;
  p3[1]=9;
  p3[2]=8;

  p3.zmien_wymiary(wym);

  l_przeszkod[2]=p3;
  
  int IND[3];
  for(int i=0;i<3;i++)
    {
      l_przeszkod[i].rysuj(api,IND[i],"black");
    }

  int wybor;
  char kolor;
  bool koniec=false;
  while(!koniec)
    {
      cout<<"Prosze wybrac drona:\n";
      cout<<"c - czerwony\n";
      cout<<"p - pomaranczowy\n";
      cout<<"f - fioletowy\n";
      cin>>kolor;
      switch(kolor)
	{
	case 'c':
	  wybor=0;
	  cout<<endl;
	  koniec=true;
	  break;
	case 'p':
	  wybor=2;
	  cout<<endl;
	  koniec=true;
	  break;
	case 'f':
	  wybor=1;
	  cout<<endl;
	  koniec=true;
	  break;
	default:
	  cout<<"Nie ma takiej opcji.\n";
    }
    }
  
  char opcja='a';
  while(opcja!='k')
    {
      cout<<"Prosze wybrac opcje:\n";
      cout<<"r - ruch do przodu,\n";
      cout<<"o - obrot woko; osi z,\n";
      cout<<"m - menu\n";
      cout<<"k - koniec.\n";
      cin>>opcja;
      switch(opcja)
	{
	case 'r':
	  double odl,kat_w;
	  cout<<"Podaj wartosc przemieszczenia drona:\n";
	  cin>>odl;
	  cout<<"Podaj kat wznoszenia:\n";
	  cin>>kat_w;
	  l_dronow[wybor].plyn(api,odl,kat_w,l_przeszkod,l_dronow,t,dno);
	  break;
	case 'o':
	  double kat;
	  cout<<"Podaj kat obrotu:\n";
	  cin>>kat;

	  float ile;
	  int znak;
	  if(kat<0) znak=-1;
	  ile=abs(kat/5);
	  for(int i=0;i<ile;i++)
	    {
	      l_dronow[wybor].prost::obroc(znak*5);
	      l_dronow[wybor].usun(api);
	      l_dronow[wybor].rysuj(api);
	    }
	  break;
	case 'm':
	  
	  break;
	}
      }

  delete &api;
  
  return 0;
}
