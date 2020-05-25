#include "dno.hh"
#include <iostream>
#include <cmath>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void dno::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  double x=wym[1],y=wym[3];
  for(int i=0;i<abs(wym[0])+abs(wym[1]);i=i+5)
    {
      api->draw_line(drawNS::Point3D(wym[0],y,0),drawNS::Point3D(wym[1],y,0),"yellow");
      y=y+5;
    }
  for(int i=0;i<abs(wym[2])+abs(wym[3]);i++)
    {
      api->draw_line(drawNS::Point3D(x,wym[2],0),drawNS::Point3D(x,wym[3],0),"yellow");
      x=x+5;
    }
}
