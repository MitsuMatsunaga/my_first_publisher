#include <ros/ros.h>
#include <vector>
#include <iostream>
#include <std_msgs/String.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include "../../../devel/include/goal_regist_server/goalRegist.h"

////////////////////////////////////名前空間の宣言/////////////////////////////////
using namespace std;
////////////////////////////////////構造体定義/////////////////////////////////////
int main(int argc, char** argv){

  unsigned int i =0;
  char text[]="";

  goal_regist_server::goalRegist msg1;
  std_msgs::String msg2;
  
  string goalname;
  srand((unsigned)time(NULL));

  ros::init(argc, argv, "grs_tester");
  ros::NodeHandle n;
  ROS_INFO("GRS Tester");

  ros::Publisher pub1 = n.advertise<goal_regist_server::goalRegist>("GoalPoint", 100);
  ros::Publisher pub2 = n.advertise<std_msgs::String>("GoToPoint", 100);
  ros::Rate loop_rate(1);
/*
    msg1.x = 1.0000;
    msg1.y = 258.45;
    goalname =  "Point_A";
    msg1.GoalName = goalname;
    pub1.publish(msg1);

    
    msg2.data = "Point_A";
    pub2.publish(msg2);
*/

  while(ros::ok()){
    msg1.x = 1000.00*rand()/RAND_MAX;
    msg1.y = 1000.00*rand()/RAND_MAX;
    sprintf(text,"地点_%d",i);
    goalname=  text;
    msg1.GoalName = goalname;
    pub1.publish(msg1);


    msg2.data = text;
    pub2.publish(msg2);
    i++;
    printf("count = %d \n",i);
    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}


/*
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv){

	ros::init(argc,argv ,"publisher_node");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise <std_msgs::String> ("my_topic",1000);
	ros::Rate loop_rate(10);
	while(ros::ok()){
		
		std_msgs::String msg;
		msg.data = "hello ! Thenk you to subscrive this topic !";
		ROS_INFO("[%s]",msg.data.c_str());

		pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();

	}

	return 0;

}
*/
