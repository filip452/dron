#include "tafla.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void tafla::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  double x=wym[1],y=wym[3];
  while(x<wym[0])
    {
      y=wym[3];
      while(y<wym[2])
	{
	  api->draw_surface(vector<vector<Point3D> > {{
		drawNS::Point3D(x,y,18),drawNS::Point3D(x+5,y,20),drawNS::Point3D(x+10,y,18)
		  },{
		drawNS::Point3D(x,y+5,18),drawNS::Point3D(x+5,y+5,20),drawNS::Point3D(x+10,y+5,18)
		  }},"red");
	  y=y+5;
	}
      x=x+10;
    }
}
