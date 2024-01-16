//
#ifndef DATA_PROCESS_H_
#define DATA_PROCESS_H_

#include "../include/ros_headers.h"
#include <pcl/conversions.h>

class Pcprocess
{
private:
	
	ros::NodeHandle nh;

	ros::Subscriber sub;

	ros::Publisher pub;
public:

	Pcprocess(const char* sub_topic, const char* pub_topic)
	{
		//订阅器初始化
		sub = nh.subscribe(sub_topic, 1000, &Pcprocess::Callback, this);
		//发布器初始化
		pub = nh.advertise<sensor_msgs::PointCloud2>(pub_topic, 1000);
	}

	void Callback(sensor_msgs::PointCloud2 pc2);
};

#endif // DATA_PROCESS_H_