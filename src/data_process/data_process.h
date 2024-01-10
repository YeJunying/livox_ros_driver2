//
#ifndef DATA_PROCESS_H_
#define DATA_PROCESS_H_

#include "../include/ros_headers.h"
#include <pcl/conversions.h>

class Pcprocess
{
private:
	//创建节点句柄
	ros::NodeHandle nh;
	//声明订阅器变量，未初始化，可声明多个
	ros::Subscriber sub;
	//声明发布器变量，未初始化，可声明多个
	ros::Publisher pub;
public:
	//构造函数
	Pcprocess(const char* sub_topic, const char* pub_topic)
	{
		//订阅器初始化
		sub = nh.subscribe(sub_topic, 1000, &Pcprocess::Callback, this);
		//发布器初始化
		pub = nh.advertise<sensor_msgs::PointCloud2>(pub_topic, 1000);
	}
	//回调函数，实现自己的算法
	void Callback(sensor_msgs::PointCloud2 pc2);
};

#endif // DATA_PROCESS_H_