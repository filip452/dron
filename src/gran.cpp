#include "gran.hh"
#include "Dr3D_gnuplot_api.hh"
#include "cmath"

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
  p=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(tab[0]+w[0],tab[1]+w[1]/2,tab[2]+w[1]/sqrt(2)),
	  drawNS::Point3D(tab[0]+w[0],tab[1]-w[1]/2,tab[2]+w[1]/sqrt(2)),
	  drawNS::Point3D(tab[0]+w[0],tab[1]-w[1],tab[2]),
	  drawNS::Point3D(tab[0]+w[0],tab[1]-w[1]/2,tab[2]-w[1]/sqrt(2)),
	  drawNS::Point3D(tab[0]+w[0],tab[1]+w[1]/2,tab[2]-w[1]/sqrt(2)),
	  drawNS::Point3D(tab[0]+w[0],tab[1]+w[1],tab[2])
	  },{
        drawNS::Point3D(tab[0]-w[0],tab[1]+w[1]/2,tab[2]+w[1]/sqrt(2)),
	  drawNS::Point3D(tab[0]-w[0],tab[1]-w[1]/2,tab[2]+w[1]/sqrt(2)),
	  drawNS::Point3D(tab[0]-w[0],tab[1]-w[1],tab[2]),
	  drawNS::Point3D(tab[0]-w[0],tab[1]-w[1]/2,tab[2]-w[1]/sqrt(2)),
	  drawNS::Point3D(tab[0]-w[0],tab[1]+w[1]/2,tab[2]-w[1]/sqrt(2)),
	  drawNS::Point3D(tab[0]-w[0],tab[1]+w[1],tab[2])
	  }});
}
void gran::ruch(std::shared_ptr<drawNS::Draw3DAPI> api,wektor<double,3> r,int & p)
{
  for(int i=0;i<3;i++)
    tab[i]=tab[i]+r[i];
  api->erase_shape(p);
  rysuj(api,p);
}
