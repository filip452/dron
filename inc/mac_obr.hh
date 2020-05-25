#ifndef MAC_OBR_HH
#define MAC_OBR_HH
#include "macierz.hh"
#include <cmath>

class m_obr: public macierz<double,3>
{
public:
  m_obr(double sigma)
  {
    tab[0][0]=cos(sigma); tab[0][1]=-sin(sigma); tab[0][2]=0;
    tab[1][0]=sin(sigma); tab[1][1]=cos(sigma); tab[1][2]=0;
    tab[2][0]=0; tab[2][1]=0; tab[2][2]=1;
  }
};

#endif
