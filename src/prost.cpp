#include "prost.hh"
#include "Dr3D_gnuplot_api.hh"
#include "mac_obr.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

prost::prost(wektor<double,3> wym)
{
  w=wym;
  orientacja=0;
}

void prost::zmien_wymiary(wektor<double,3> wym)
{
  for(int i=0;i<3;i++)
    w[i]=w[i]+wym[i]/2;
}
void prost::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api,int & p,std::string kolor)
{ 
  wektor<double,3> pkt[4];
  pkt[0][0]=w[0]; pkt[0][1]=w[1]; pkt[0][2]=w[2];
  pkt[1][0]=w[0]; pkt[1][1]=-w[1]; pkt[1][2]=w[2];
  pkt[2][0]=-w[0]; pkt[2][1]=-w[1]; pkt[2][2]=w[2];
  pkt[3][0]=-w[0]; pkt[3][1]=w[1]; pkt[3][2]=w[2];

  for(int i=0;i<4;i++)
    pkt[i]=m_obr(orientacja)*pkt[i];

  for(int i=0;i<3;i++)
    for(int j=0;j<4;j++)
      pkt[j][i]=pkt[j][i]+tab[i];
  
  p=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(pkt[0][0],pkt[0][1],pkt[0][2]),
	  drawNS::Point3D(pkt[1][0],pkt[1][1],pkt[1][2]),
	  drawNS::Point3D(pkt[2][0],pkt[2][1],pkt[2][2]),
	  drawNS::Point3D(pkt[3][0],pkt[3][1],pkt[3][2])  
	  },{
        drawNS::Point3D(pkt[0][0],pkt[0][1],pkt[0][2]-w[2]*2),
	  drawNS::Point3D(pkt[1][0],pkt[1][1],pkt[1][2]-w[2]*2),
	  drawNS::Point3D(pkt[2][0],pkt[2][1],pkt[2][2]-w[2]*2),
	  drawNS::Point3D(pkt[3][0],pkt[3][1],pkt[3][2]-w[2]*2)  
	  }},kolor);
}

void prost::ruch(std::shared_ptr<drawNS::Draw3DAPI> api,wektor<double,3> r,int & p,std::string kolor)
{
  for(int i=0;i<3;i++)
    tab[i]=tab[i]+r[i];
  api->erase_shape(p);
  rysuj(api,p,kolor);
}

void prost::obroc(double kat)
{
  double sigma=(kat/180)*3.1416;
  orientacja=orientacja+sigma;
  while(orientacja>6.2832)
    orientacja=orientacja-6.2832;
}
