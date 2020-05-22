#include "dron.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void dron::ustaw(wektor<double,3> poz)
{
  for(int i=0;i<3;i++)
    prost::tab[i]=poz[i];
}
void dron::usun(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  for(int i=0;i<3;i++)
    api->erase_shape(czesci[i]);
}
void dron::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  gran sr1,sr2;
  prost kad;

  kad[0]=prost::tab[0];
  kad[1]=prost::tab[1];
  kad[2]=prost::tab[2];
  
  wektor<double,3> wym_k;
  wym_k[0]=8;
  wym_k[1]=4;
  wym_k[2]=4;

  double wym_sr[2];
  wym_sr[0]=0.5;
  wym_sr[1]=1.5;
  
  sr1[0]=prost::tab[0]-4.25;
  sr1[1]=prost::tab[1]+1;
  sr1[2]=prost::tab[2];
  
  sr2[0]=prost::tab[0]-4.25;
  sr2[1]=prost::tab[1]-1;
  sr2[2]=prost::tab[2];

  kad.zmien_wymiary(wym_k);
  sr1.zmien_wymiary(wym_sr);
  sr2.zmien_wymiary(wym_sr);
  kad.rysuj(api,czesci[0]);
  sr1.rysuj(api,czesci[1]);
  sr2.rysuj(api,czesci[2]);
}
void dron::plyn(std::shared_ptr<drawNS::Draw3DAPI> api,double r)
{
  double ile=r;
  for(int i=0;i<r*5;i++)
    {
      usun(api);
      prost::tab[0]=prost::tab[0]+0.2;
      rysuj(api);
      
      ile-=0.2;
    }
  if(ile!=0)
    {
      usun(api);
      prost::tab[0]=prost::tab[0]+ile;
      rysuj(api);
    }
}
