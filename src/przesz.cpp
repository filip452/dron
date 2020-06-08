#include "przesz.hh"
#include <cmath>
#include "wek.hh"

bool przesz::czy_kolizja(wektor<double,3> d)
{
  if(abs(d[0]-tab[0])>w[0]+4.5)
     return false;
  if(abs(d[1]-tab[1])>w[1]+4.5)
     return false;
  if(abs(d[2]-tab[2])>w[2]+2)
    return false;
  return true;
}
