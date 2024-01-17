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

	Pcprocess(const char* sub_topic, const char* pub_topic);

	~Pcprocess();

	void Callback(sensor_msgs::PointCloud2 pc2);
};

#endif // DATA_PROCESS_H_