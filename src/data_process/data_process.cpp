
#include "data_process.h"
#include <vector> 

const double ANG_MIN1 = 0.55;
const double ANG_MAX1 = 1.2;
const double ANG_MIN2 = -1.67;
const double ANG_MAX2 = -0.85;

Pcprocess::Pcprocess(const char* sub_topic, const char* pub_topic)
{
		
		sub = nh.subscribe(sub_topic, 1000, &Pcprocess::Callback, this);
	
		pub = nh.advertise<sensor_msgs::PointCloud2>(pub_topic, 1000);
}

Pcprocess::~Pcprocess() {}

void Pcprocess::Callback(sensor_msgs::PointCloud2 pc2)
{
	sensor_msgs::PointCloud2 pc2_pub;

	pcl::PointCloud<pcl::PointXYZI> cloud;

    fromROSMsg(pc2, cloud);
    
    for(int i=0; i<cloud.points.size(); i++)
    {
        double angle=cloud.points[i].y/cloud.points[i].x;
        if(angle<ANG_MAX1 && angle>ANG_MIN1 || angle<ANG_MAX2 && angle>ANG_MIN2)
        {
            cloud.points[i].x=0;
            cloud.points[i].y=0;
            cloud.points[i].z=0;
            cloud.points[i].intensity=0;
        }

    }

    toROSMsg(cloud, pc2_pub);

    pub.publish(pc2_pub);
};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "Pcprocess");

    Pcprocess pcprocesser("/livox/lidar", "/scan");
    
    ros::spin();

    return 0;
}