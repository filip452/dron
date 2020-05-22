#include "macierz.cpp"

template class macierz<double,3>;
template std::istream & operator>>(std::istream & strm,macierz<double,3> & M);
template std::ostream & operator<<(std::ostream & strm, const macierz<double,3> & M);
template macierz<double,3> operator*(double l2,const macierz<double,3> & M);

