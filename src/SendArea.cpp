#include <ros/ros.h>

#include "CreateArea.h"
#include "Real2D.h"

#include "nostop_area/AreaData.h"
#include "nostop_area/Shape.h"

#include <map>
#include <string>

enum AreaType
{
  STUDIO,
  CORRIDOIO_ING,
  CORRIDOIO_PIAGGIO,
  ISLAND,
  HARBOUR,
  EMPTY
};

std::map<std::string, AreaType> g_name_map;

std::vector<Real2D> g_external;
std::vector< std::vector<Real2D> > g_internal;

/////////////////////////////////////////
void initAreaNameMap()
{
  g_name_map.insert( std::make_pair<std::string, AreaType>("Studio", AreaType::STUDIO) );
  g_name_map.insert( std::make_pair<std::string, AreaType>("CorridoioING", AreaType::CORRIDOIO_ING) );
  g_name_map.insert( std::make_pair<std::string, AreaType>("CorridoioPiaggio", AreaType::CORRIDOIO_PIAGGIO) );
  g_name_map.insert( std::make_pair<std::string, AreaType>("Island", AreaType::ISLAND) );
  g_name_map.insert( std::make_pair<std::string, AreaType>("Harbour", AreaType::HARBOUR) );
  g_name_map.insert( std::make_pair<std::string, AreaType>("Empty", AreaType::EMPTY) );
}

/////////////////////////////////////////
bool SendArea_callback( nostop_area::AreaData::Request 	&req,
			nostop_area::AreaData::Response &res)
{
  for(size_t i = 0; i < g_external.size(); ++i)
  {
    Real2D l_real2d = g_external[i];
    res.external.vertex.push_back(l_real2d[0]);
    res.external.vertex.push_back(l_real2d[1]);
  }
    
  std::vector<nostop_area::Shape> l_shapes;
  for(size_t i = 0; i < g_internal.size(); ++i)
  {
    nostop_area::Shape l_shape;
    for(size_t j = 0; j < g_internal[i].size(); ++j)
    {
      Real2D l_real2d = g_internal[i][j];
      l_shape.vertex.push_back(l_real2d[0]);
      l_shape.vertex.push_back(l_real2d[1]);
    }
    res.internal.push_back(l_shape);
  }
  return true;
}

int main(int argc, char **argv)
{
      initAreaNameMap();
  
      ros::init(argc, argv, "Area");
                  
      // Info From Launch File
      
      // Identify robot name:
      std::string l_name;
      ros::NodeHandle l_node("~");
      if ( l_node.getParam("area_name", l_name) )
      {
	ROS_INFO("Nome ricevuto: %s", l_name.c_str());
      }
      else
      {
	std::cout << "Enter the name of the area: ";
	//std::cin >> l_name;
	l_name="Empty";//"Studio";
	ROS_ERROR("Nome non ricevuto: %s", l_name.c_str());
      }
      
      switch(g_name_map[l_name])
      {
	case AreaType::STUDIO:
	  Create_StudioLucia(g_external, g_internal);
	break;
	case AreaType::CORRIDOIO_ING:
	  Create_CorridoioING(g_external, g_internal);
	break;
	case AreaType::CORRIDOIO_PIAGGIO:
	  Create_CorridoioPiaggio(g_external, g_internal);
	break;
	case AreaType::ISLAND:
	  Create_Island(g_external, g_internal);
	break;
	case AreaType::HARBOUR:
	  Create_Harbour(g_external, g_internal);
	break;
	case AreaType::EMPTY:
	  Create_Empty(g_external, g_internal);
	default:
	  break;
      }
      
      ros::ServiceServer l_service = l_node.advertiseService("AreaInitializer", SendArea_callback);
      
      ROS_INFO("Ready to create area.");
      
      ros::spin();
      
      return 0;
}