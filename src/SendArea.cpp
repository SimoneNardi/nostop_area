#include "Real2D.h"
#include <vector.h>

int main(int argc, char **argv)
{
      ros::init(argc, argv, "Guard");
                  
      // Info From Launch File
      
      // Identify robot name:
      std::string l_name;
      ros::NodeHandle l_node("~");
      if (l_node.getParam("robot_name", l_name))
      {
	ROS_INFO("Nome ricevuto: %s", l_name.c_str());
      }
      else
      {
	std::cout << "Enter the name of the robot: ";
	//std::cin >> l_name;
	l_name="red_blue";
	ROS_ERROR("Nome non ricevuto: %s", l_name.c_str());
      }
      
      return 0;
}