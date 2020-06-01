#include <iostream>
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

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

int main()
{
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-25,25,-25,25,0,20,0));

  double wym_plasz[4];
  dno dno;
  tafla t;

  wym_plasz[0]=25; wym_plasz[1]=-25; wym_plasz[2]=25; wym_plasz[3]=-25;
  dno.ustaw_wym(wym_plasz);
  t.ustaw_wym(wym_plasz);
  
  dno.rysuj(api);
  t.rysuj(api);
  
  wektor<double,3> poz;
  poz[2]=10;
  
  dron d;
  //obroc(45);
  d.ustaw(poz);
  d.rysuj(api);

  przesz p[3];

  wektor<double,3> wym;
  wym[0]=4;
  wym[1]=4;
  wym[2]=10;

  p[0][0]=10;
  p[0][1]=4;
  p[0][2]=5;

  p[0].zmien_wymiary(wym);

  wym[0]=2;
  wym[1]=6;
  wym[2]=8;

  p[1][0]=12;
  p[1][1]=-6;
  p[1][2]=8;

  p[1].zmien_wymiary(wym);

  wym[0]=6;
  wym[1]=2;
  wym[2]=5;

  p[2][0]=-4;
  p[2][1]=9;
  p[2][2]=8;

  p[2].zmien_wymiary(wym);

  int IND[3];
  for(int i=0;i<3;i++)
    p[i].rysuj(api,IND[i]);
  
  char opcja='a';
  while(opcja!='k')
    {
      cout<<"Prosze wybrac opcje:\n";
      cout<<"r - ruch do przodu,\n";
      cout<<"o - obrot woko; osi z,\n";
      cout<<"m - menu";
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
	  d.plyn(api,odl,kat_w,p);
	  break;
	case 'o':
	  double kat;
	  cout<<"Podaj kat obrotu:\n";
	  cin>>kat;
	  d.prost::obroc(kat);
	  d.usun(api);
	  d.rysuj(api);
	case 'm':
	  
	  break;
	}
      }

  delete &api;
  
  return 0;
}
