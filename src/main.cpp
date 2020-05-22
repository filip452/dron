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

  wektor<double,3> poz;
  poz[2]=10; 
  
  dron d;
  d.ustaw(poz);
  d.rysuj(api);
  
  char opcja;
  cin>>opcja;
  while(opcja!='k')
    {
      switch(opcja)
	{
	case 'r':
	  double odl;
	  cout<<"Podaj wartosc przemieszczenia drona.\n";
		cin>>odl;
	  d.plyn(api,odl);
	  break;
	}
      cin>>opcja;
    }
  
  return 0;
}
