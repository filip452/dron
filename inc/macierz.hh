#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "wek.hh"

template<class TYP, int ROZMIAR>
class macierz
{
protected:
  wektor<TYP,ROZMIAR> tab[ROZMIAR];
public:
  macierz();
  macierz(int jednostkowa);

  //wektory - wiersze
  const wektor<TYP,ROZMIAR> & operator[] (int index) const;
  wektor<TYP,ROZMIAR> & operator[] (int index);
  //wektory kolumny
  const wektor<TYP,ROZMIAR> operator() (int index) const;
  wektor<TYP,ROZMIAR> operator() (int index);
  
  wektor<TYP,ROZMIAR> operator *(const wektor<TYP,ROZMIAR> & w);
  macierz<TYP,ROZMIAR> operator +(const macierz<TYP,ROZMIAR> & M);
  macierz<TYP,ROZMIAR> operator -(const macierz<TYP,ROZMIAR> & M);
  macierz<TYP,ROZMIAR> operator *(const macierz<TYP,ROZMIAR> & M);
  macierz<TYP,ROZMIAR> operator *(const TYP l2);

  bool operator== (const macierz<TYP,ROZMIAR> & M) const;
  bool operator!= (const macierz<TYP,ROZMIAR> & M) const;

  macierz<TYP,ROZMIAR> transponuj() const;
  void transponuj();
  TYP wyznacznik();
};

template<class TYP, int ROZMIAR>
macierz<TYP,ROZMIAR> operator *(TYP l2,const macierz<TYP,ROZMIAR> & M);

template<class TYP, int ROZMIAR>
std::istream & operator>>(std::istream & strm, macierz<TYP,ROZMIAR> & M);

template<class TYP, int ROZMIAR>
std::ostream & operator<< (std::ostream & strm, const macierz<TYP,ROZMIAR> & M);

#endif
