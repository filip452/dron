#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

class plaszczyzna
{
protected:
  int id;
  double wym[4];  //wym[0] - x maks wym[1] - x min
                  //wym[2] - y maks wym[3] - y min
public:
  void ustaw_wym(double tab[4])
  {
    for(int i=0;i<4;i++)
      wym[i]=tab[i];
  }
};

#endif
