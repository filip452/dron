#include "gran.hh"
#include "Dr3D_gnuplot_api.hh"
#include <cmath>
#include "mac_obr.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void gran::zmien_wymiary(double wym[2])
{
  for(int i=0;i<2;i++)
    w[i]=w[i]+wym[i]/2;
}
void gran::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api,int & p)
{
  wektor<double,3> pkt[6];
  pkt[0][0]=tab[0]+w[0]; pkt[0][1]=tab[1]+w[1]/2; pkt[0][2]=tab[2]+w[1]/sqrt(2);
  pkt[1][0]=tab[0]+w[0]; pkt[1][1]=tab[1]-w[1]/2; pkt[1][2]=tab[2]+w[1]/sqrt(2);
  pkt[2][0]=tab[0]+w[0]; pkt[2][1]=tab[1]-w[1]; pkt[2][2]=tab[2];
  pkt[3][0]=tab[0]+w[0]; pkt[3][1]=tab[1]-w[1]/2; pkt[3][2]=tab[2]-w[1]/sqrt(2);
  pkt[4][0]=tab[0]+w[0]; pkt[4][1]=tab[1]+w[1]/2; pkt[4][2]=tab[2]-w[1]/sqrt(2);
  pkt[5][0]=tab[0]+w[0]; pkt[5][1]=tab[1]+w[1]; pkt[5][2]=tab[2];

  wektor<double,3> pkt1[6];
  pkt1[0][0]=tab[0]-w[0]; pkt1[0][1]=tab[1]+w[1]/2; pkt1[0][2]=tab[2]+w[1]/sqrt(2);
  pkt1[1][0]=tab[0]-w[0]; pkt1[1][1]=tab[1]-w[1]/2; pkt1[1][2]=tab[2]+w[1]/sqrt(2);
  pkt1[2][0]=tab[0]-w[0]; pkt1[2][1]=tab[1]-w[1]; pkt1[2][2]=tab[2];
  pkt1[3][0]=tab[0]-w[0]; pkt1[3][1]=tab[1]-w[1]/2; pkt1[3][2]=tab[2]-w[1]/sqrt(2);
  pkt1[4][0]=tab[0]-w[0]; pkt1[4][1]=tab[1]+w[1]/2; pkt1[4][2]=tab[2]-w[1]/sqrt(2);
  pkt1[5][0]=tab[0]-w[0]; pkt1[5][1]=tab[1]+w[1]; pkt1[5][2]=tab[2];

  for(int i=0;i<6;i++)
    pkt[i]=m_obr(orientacja)*pkt[i];

  for(int i=0;i<6;i++)
    pkt1[i]=m_obr(orientacja)*pkt1[i];

  p=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(pkt[0][0],pkt[0][1],pkt[0][2]),
	  drawNS::Point3D(pkt[1][0],pkt[1][1],pkt[1][2]),
	  drawNS::Point3D(pkt[2][0],pkt[2][1],pkt[2][2]),
	  drawNS::Point3D(pkt[3][0],pkt[3][1],pkt[3][2]),
	  drawNS::Point3D(pkt[4][0],pkt[4][1],pkt[4][2]),
	  drawNS::Point3D(pkt[5][0],pkt[5][1],pkt[5][2])
	  },{
        drawNS::Point3D(pkt1[0][0],pkt1[0][1],pkt1[0][2]),
	  drawNS::Point3D(pkt1[1][0],pkt1[1][1],pkt1[1][2]),
	  drawNS::Point3D(pkt1[2][0],pkt1[2][1],pkt1[2][2]),
	  drawNS::Point3D(pkt1[3][0],pkt1[3][1],pkt1[3][2]),
	  drawNS::Point3D(pkt1[4][0],pkt1[4][1],pkt1[4][2]),
	  drawNS::Point3D(pkt1[5][0],pkt1[5][1],pkt1[5][2])
	  }});
}
void gran::ruch(std::shared_ptr<drawNS::Draw3DAPI> api,wektor<double,3> r,int & p)
{
  for(int i=0;i<3;i++)
    tab[i]=tab[i]+r[i];
  api->erase_shape(p);
  rysuj(api,p);
}

void gran::obroc(double kat)
{
  double sigma=(kat/180)*3.1416;
  orientacja=orientacja+sigma;
  while(orientacja>360)
    orientacja=orientacja-360;
}
