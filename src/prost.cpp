#include "prost.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void prost::zmien_wymiary(wektor<double,3> wym)
{
  for(int i=0;i<3;i++)
    w[i]=w[i]+wym[i]/2;
}
void prost::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api,int & p)
{
  p=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(tab[0]+w[0],tab[1]+w[1],tab[2]+w[2]),
	  drawNS::Point3D(tab[0]+w[0],tab[1]-w[1],tab[2]+w[2]),
	  drawNS::Point3D(tab[0]-w[0],tab[1]-w[1],tab[2]+w[2]),
	  drawNS::Point3D(tab[0]-w[0],tab[1]+w[1],tab[2]+w[2])  
	  },{
	drawNS::Point3D(tab[0]+w[0],tab[1]+w[1],tab[2]-w[2]),
	  drawNS::Point3D(tab[0]+w[0],tab[1]-w[1],tab[2]-w[2]),
	  drawNS::Point3D(tab[0]-w[0],tab[1]-w[1],tab[2]-w[2]),
	  drawNS::Point3D(tab[0]-w[0],tab[1]+w[1],tab[2]-w[2])
	  }});
}

void prost::ruch(std::shared_ptr<drawNS::Draw3DAPI> api,wektor<double,3> r,int & p)
{
  for(int i=0;i<3;i++)
    tab[i]=tab[i]+r[i];
  api->erase_shape(p);
  rysuj(api,p);
}
