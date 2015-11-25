#include "CreateArea.h"

/////////////////////////////////////////////////
void Create_StudioLucia(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-2.075,-2.015));
  external.push_back(Real2D (1.115,-2.015));
  external.push_back(Real2D (1.115,-1.185));
  external.push_back(Real2D (.385,-1.185));
  external.push_back(Real2D (.385,-1.145));
  external.push_back(Real2D (2.075,-1.145));
  external.push_back(Real2D (2.075,2.015));
  external.push_back(Real2D (1.625,2.015));
  external.push_back(Real2D (1.625,1.515));
  external.push_back(Real2D (-.175,1.515));
  external.push_back(Real2D (-.175,2.015));
  external.push_back(Real2D (-2.075,2.015));

  std::vector<Real2D> obstacle;
  obstacle.push_back(Real2D (.405,-.045));
  obstacle.push_back(Real2D (1.085,-.045));
  obstacle.push_back(Real2D (1.085,-.05));
  obstacle.push_back(Real2D (.405,-.05));
 
  internal.push_back(obstacle);
}

/////////////////////////////////////////////////
void Create_CorridoioING(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-207.5,-201.5));
  external.push_back(Real2D (207.5,-201.5));
  external.push_back(Real2D (207.5,201.5));
  external.push_back(Real2D (-207.5,201.5));
}

/////////////////////////////////////////////////
void Create_CorridoioPiaggio(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-207.5,-201.5));
  external.push_back(Real2D (207.5,-201.5));
  external.push_back(Real2D (207.5,201.5));
  external.push_back(Real2D (-207.5,201.5));
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

/////////////////////////////////////////////////
void Create_Empty(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-10.,-10.) );
  external.push_back(Real2D (10.,-10.) );
  external.push_back(Real2D (10.,10.) );
  external.push_back(Real2D (-10.,10.) );
}