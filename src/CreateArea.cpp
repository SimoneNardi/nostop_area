#include "CreateArea.h"

/////////////////////////////////////////////////
void Create_StudioLucia(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-207.5.,-201.5));
  external.push_back(Real2D (111.5.,-201.5));
  external.push_back(Real2D (111.5.,-118.5));
  external.push_back(Real2D (38.5,-118.5));
  external.push_back(Real2D (38.5,-114.5));
  external.push_back(Real2D (207.5,-114.5));
  external.push_back(Real2D (207.5,201.5));
  external.push_back(Real2D (162.5,201.5));
  external.push_back(Real2D (162.5,151.5));
  external.push_back(Real2D (-17.5,151.5));
  external.push_back(Real2D (-17.5,201.5));
  external.push_back(Real2D (-207.5,201.5));

  std::vector<Real2D> obstacle;
  obstacle.push_back(Real2D (40.5,-4.5));
  obstacle.push_back(Real2D (108.5,-4.5));
  obstacle.push_back(Real2D (108.5,-.5));
  obstacle.push_back(Real2D (40.5,-.5));
 
  internal.push_back(obstacle);
}

/////////////////////////////////////////////////
void Create_CorridoioING(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-207.5.,-201.5));
  external.push_back(Real2D (207.5.,-201.5));
  external.push_back(Real2D (207.5.,201.5));
  external.push_back(Real2D (-207.5.,201.5));
}

/////////////////////////////////////////////////
void Create_Island(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-10.,-10.) );
  external.push_back(Real2D (10.,-10.) );
  external.push_back(Real2D (10.,10.) );
  external.push_back(Real2D (-10.,10.) );
}

/////////////////////////////////////////////////
void Create_Harbour(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-10.,-10.) );
  external.push_back(Real2D (10.,-10.) );
  external.push_back(Real2D (10.,10.) );
  external.push_back(Real2D (-10.,10.) );
}