#include "wek.hh"
#include <iostream>
#include <cmath>

#define EPSILON 0.00001

using std::cerr;
using std::endl;


template<class TYP,int ROZMIAR>
wektor<TYP,ROZMIAR>::wektor()
{
  for(int i=0;i<ROZMIAR;i++)
    tab[i]=0;
}
template<class TYP,int ROZMIAR>
wektor<TYP,ROZMIAR>::wektor(TYP *tab_w)
{
  for(int i=0;i<ROZMIAR;i++)
    tab[i]=tab_w[i];
}

template<class TYP,int ROZMIAR>
const TYP & wektor<TYP,ROZMIAR>::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab[index];
}
template<class TYP,int ROZMIAR>
TYP & wektor<TYP,ROZMIAR>::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab[index];
}

template<class TYP,int ROZMIAR>
wektor<TYP,ROZMIAR> wektor<TYP,ROZMIAR>::operator +(const wektor & W2) const
{
  wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=tab[i]+W2[i];
  return wynik;
}
template<class TYP,int ROZMIAR>
wektor<TYP,ROZMIAR> wektor<TYP,ROZMIAR>::operator -(const wektor & W2) const
{
  wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=tab[i]-W2[i];
  return wynik;
}
template<class TYP,int ROZMIAR>
TYP wektor<TYP,ROZMIAR>::operator *(const wektor & W2) const
{
  TYP wynik;
  wynik=0;
  for(int i=0;i<ROZMIAR;i++)
    wynik+=tab[i]*W2[i]; 
  return wynik;
}
template<class TYP,int ROZMIAR>
wektor<TYP,ROZMIAR> wektor<TYP,ROZMIAR>::operator *(TYP l2) const
{
  wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=tab[i]*l2; 
  return wynik;
}

template<class TYP,int ROZMIAR>
bool wektor<TYP,ROZMIAR>::operator== (const wektor & W2) const
{
  for(int i=0;i<ROZMIAR;i++)
    if(tab[i]==W2[i]) return false;
  return true;
}
template<class TYP,int ROZMIAR>
bool wektor<TYP,ROZMIAR>::operator!= (const wektor & W2) const
{
  for(int i=0;i<ROZMIAR;i++)
    if(tab[i]==W2[i]) return true;
  return false;
}


template<class TYP, int ROZMIAR>
wektor<TYP,ROZMIAR> operator*(TYP l1, const wektor<TYP,ROZMIAR> & W2)
{
  wektor<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=W2[i]*l1; 
  return wynik;
}
  
template<class TYP, int ROZMIAR>
std::istream & operator>>(std::istream & strm, wektor<TYP,ROZMIAR> & W)
{
  char znak;
  strm>>znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);
  for(int i=0;i<ROZMIAR;i++)
    strm>>W[i]>>znak;
  return strm;
}

template<class TYP, int ROZMIAR>
std::ostream & operator<< (std::ostream & strm, const wektor<TYP,ROZMIAR> & W)
{
  strm<<'(';
  for(int i=0;i<ROZMIAR;i++)
    strm<<W[i]<<',';
  strm<<')';
  return strm;
}
