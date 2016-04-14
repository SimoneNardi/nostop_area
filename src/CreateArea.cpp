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
  external.push_back(Real2D (-5.9,0.)	);
  external.push_back(Real2D (0.,0.) 	);
  external.push_back(Real2D (0,-9.1)	);
  external.push_back(Real2D (2.4,-9.1)	);
  external.push_back(Real2D (2.4,3.4)	);
  external.push_back(Real2D (-5.9,3.4)	);
}

/////////////////////////////////////////////////
void Create_CorridoioUnipiPiano4(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  external.push_back(Real2D (-1.8,0.)	);
  external.push_back(Real2D (-1.8,3.) 	);
  external.push_back(Real2D (-1.8,-9.1)	);
  external.push_back(Real2D (2.4,-9.1)	);
  external.push_back(Real2D (2.4,3.4)	);
  external.push_back(Real2D (-5.9,3.4)	);
}

/////////////////////////////////////////////////
void Create_Acquario(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  external.push_back(Real2D (0.3,0.3)	);
  external.push_back(Real2D (2.7,0.3) 	);
  external.push_back(Real2D (2.7,6.3)	);
  external.push_back(Real2D (0.3,6.3)	);
}

/////////////////////////////////////////////////
void Create_CorridoioPiaggio(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  external.push_back(Real2D (-5.9,0.)	);
  external.push_back(Real2D (0.,0.) 	);
  external.push_back(Real2D (0,-9.1)	);
  external.push_back(Real2D (2.4,-9.1)	);
  external.push_back(Real2D (2.4,3.4)	);
  external.push_back(Real2D (-5.9,3.4)	);
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

/////////////////////////////////////////////////
void Create_Medium(std::vector<Real2D> &external, std::vector< std::vector<Real2D> > &internal)
{
  double param = 3;
  // Collect point from rviz or read configuration file if not available
  external.push_back(Real2D (-param,-param) );
  external.push_back(Real2D (param,-param) );
  external.push_back(Real2D (param,param) );
  external.push_back(Real2D (-param,param) );
}