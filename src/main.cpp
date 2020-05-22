#include <iostream>
#include "macierz.hh"
#include "prost.hh"
#include "dron.hh"
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
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(0,25,-10,10,0,10,1000));

  api->change_ref_time_ms(0);

  dron d1;

  wektor<double,3> poz;
  poz[0]=5;
  poz[1]=0;
  poz[2]=5;

  d1.ustaw(poz);
  
  d1.rysuj(api);
  
  wait4key();

  d1.plyn(api,8);
  
  wait4key();
  
  return 0;
}
