#include <iostream>
#include "macierz.hh"

using std::endl;
using std::cerr;

template<class TYP,int ROZMIAR>
macierz<TYP,ROZMIAR>::macierz()
{
  wektor<TYP,ROZMIAR> zero;
  for(int i=0;i<ROZMIAR;i++)
    tab[i]=zero;
}
template<class TYP,int ROZMIAR>
macierz<TYP,ROZMIAR>::macierz(int jednostkowa)
{
  if(jednostkowa!=1)
    {
      cerr<<"To nie jest wartosc macierzy jednostkowej" << endl;
      exit(1);
    }
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      if(i==j) tab[i][j]=1;
      else tab[i][j]=0;
}


template<class TYP,int ROZMIAR>
const wektor<TYP,ROZMIAR> & macierz<TYP,ROZMIAR>::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab[index];
}
template<class TYP,int ROZMIAR>
wektor<TYP,ROZMIAR> & macierz<TYP,ROZMIAR>::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab[index];
}
template<class TYP,int ROZMIAR>
const wektor<TYP,ROZMIAR> macierz<TYP,ROZMIAR>::operator() (int index) const
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  wektor<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=tab[i][index];
  return wynik;
}
template<class TYP,int ROZMIAR>
wektor<TYP,ROZMIAR> macierz<TYP,ROZMIAR>::operator() (int index)
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  wektor<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    wynik[i]=tab[i][index];
  return wynik;
}


template<class TYP,int ROZMIAR>
wektor<TYP,ROZMIAR> macierz<TYP,ROZMIAR>::operator *(const wektor<TYP,ROZMIAR> & w)
{
  wektor<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      wynik[i]=wynik[i]+tab[i][j]*w[j];
  return wynik;
}
template<class TYP,int ROZMIAR>
macierz<TYP,ROZMIAR> macierz<TYP,ROZMIAR>::operator +(const macierz<TYP,ROZMIAR> & M)
{
  macierz<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      wynik[i][j]=tab[i][j]+M[i][j];
  return wynik;
}
template<class TYP,int ROZMIAR>
macierz<TYP,ROZMIAR> macierz<TYP,ROZMIAR>::operator -(const macierz<TYP,ROZMIAR> & M)
{
  macierz<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      wynik[i][j]=tab[i][j]-M[i][j];
  return wynik;
}
template<class TYP,int ROZMIAR>
macierz<TYP,ROZMIAR> macierz<TYP,ROZMIAR>::operator *(const macierz<TYP,ROZMIAR> & M)
{
  macierz<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      {
	wynik[i][j]=tab[i]*M(j);
      }
  return wynik;
}
template<class TYP,int ROZMIAR>
macierz<TYP,ROZMIAR> macierz<TYP,ROZMIAR>::operator *(const TYP l2)
{
  macierz<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      wynik[i][j]=tab[i][j]*l2;
  return wynik;
}


template<class TYP,int ROZMIAR>
bool macierz<TYP,ROZMIAR>::operator ==(const macierz<TYP,ROZMIAR> & M) const
{
  for(int i=0;i<ROZMIAR;i++)
      if(tab[i]!=M[i]) return false;
  return true;

}
template<class TYP,int ROZMIAR>
bool macierz<TYP,ROZMIAR>::operator !=(const macierz<TYP,ROZMIAR> & M) const
{
  for(int i=0;i<ROZMIAR;i++)
    if(tab[i]!=M[i]) return true;
  return false;
}

template<class TYP,int ROZMIAR>
macierz<TYP,ROZMIAR> macierz<TYP,ROZMIAR>::transponuj() const
{
  macierz<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      wynik[i][j]=tab[j][i];
  return wynik;
}
template<class TYP,int ROZMIAR>
void macierz<TYP,ROZMIAR>::transponuj()
{
  macierz<TYP,ROZMIAR> temp;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      temp[i][j]=tab[j][i];
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      tab[i][j]=temp[i][j];
}

template<class TYP, int ROZMIAR>
macierz<TYP,ROZMIAR> operator *(TYP l2,const macierz<TYP,ROZMIAR> & M)
{
  macierz<TYP,ROZMIAR> wynik;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      wynik[i][j]=M[i][j]*l2;
  return wynik;
}


template<class TYP, int ROZMIAR>
std::istream & operator>>(std::istream & strm, macierz<TYP,ROZMIAR> & M)
{
  for(int i=0;i<ROZMIAR;i++)
    strm>>M[i];
  M.transponuj();
  return strm;
}
template<class TYP, int ROZMIAR>
std::ostream & operator<< (std::ostream & strm, const macierz<TYP,ROZMIAR> & M)
{
  for(int i=0;i<ROZMIAR;i++)
  strm<<M[i]<<endl;
  return strm;
}
