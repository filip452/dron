#include <iostream>
#include "wek.hh"
#include "macierz.hh"
#include "dron.hh"
#include "dno.hh"
#include "tafla.hh"
#include "Dr3D_gnuplot_api.hh"

using std::cout;
using std::endl;
using std::cin;

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

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

  char opcja;
  cin>>opcja;
  while(opcja!='k')
    {
      cout<<"Prosze wybrac opcje:";
      cout<<"r - ruch do przodu,";
      cout<<"o - obrot woko; osi z,";
      cout<<"m - menu";
      cout<<"k - koniec.";
      switch(opcja)
	{
	case 'r':
	  double odl;
	  cout<<"Podaj wartosc przemieszczenia drona:\n";
		cin>>odl;
	  d.plyn(api,odl);
	  break;
	case 'o':
	  double kat;
	  cout<<"Podaj kat obrotu:\n";
	  cin>>kat;
	  d.prost::obroc(kat);
	  d.usun(api);
	  d.rysuj(api);
	}
      cin>>opcja;
      }

  delete &api;
  
  return 0;
}
