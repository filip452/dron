#ifndef WEK_HH
#define WEK_HH

#include <iostream>

template<class TYP, int ROZMIAR>
class wektor
{
protected:
  TYP tab[ROZMIAR];
public:
  wektor();
  wektor(TYP *tab_w);

  const TYP & operator[] (int index) const;
  TYP & operator[] (int index);
  
  wektor operator +(const wektor & W2) const;
  wektor operator -(const wektor & W2) const;
  TYP operator *(const wektor & W2) const;
  wektor operator *(TYP l2) const;

  bool operator== (const wektor & W2) const;
  bool operator!= (const wektor & W2) const;
};


template<class TYP, int ROZMIAR>
wektor<TYP,ROZMIAR> operator*(TYP l1, const wektor<TYP,ROZMIAR> & W2);

template<class TYP, int ROZMIAR>
std::istream & operator>>(std::istream & strm, wektor<TYP,ROZMIAR> & W);

template<class TYP, int ROZMIAR>
std::ostream & operator<< (std::ostream & strm, const wektor<TYP,ROZMIAR> & W);

#endif
