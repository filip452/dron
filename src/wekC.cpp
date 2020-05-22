#include "wek.cpp"


template class wektor<double,3>;
template std::istream & operator>>(std::istream & strm, wektor<double,3> & W);
template std::ostream & operator<<(std::ostream & strm, const wektor<double,3> & W);
template wektor<double,3> operator*(double l1, const wektor<double,3> & W2);




