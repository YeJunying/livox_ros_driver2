# 安装Livox SDK2

1. 依赖：

   CMake 3.0.0+

   gcc 4.8.1+

2. 安装CMake：

```shell
$ sudo apt install cmake
```

3. 安装Livox SDK2

```shell
$ git clone https://github.com/Livox-SDK/Livox-SDK2.git
$ cd ./Livox-SDK2/
$ mkdir build
$ cd build
$ cmake .. && make -j
$ sudo make install
```

#  安装Livox ROS Driver 2

1. Clone Livox ROS Driver 2 source code:

```shell
$ git clone https://github.com/YeJunying/livox_ros_driver2.git
```

2. 修改MID360_config.json文件中的雷达IP：

修改livox_ros_driver2中的MID360_config.json文件，修改的内容如下：

```c
{
  "lidar_summary_info" : {
    "lidar_type": 8
  },
  "MID360": {
    "lidar_net_info" : {
      "cmd_data_port": 56100,
      "push_msg_port": 56200,
      "point_data_port": 56300,
      "imu_data_port": 56400,
      "log_data_port": 56500
    },
    "host_net_info" : {
      "cmd_data_ip" : "192.168.1.5",  	# <-这里和修改后的电脑ip一致
      "cmd_data_port": 56101,
      "push_msg_ip": "192.168.1.5",  	# <-这里和修改后的电脑ip一致
      "push_msg_port": 56201,
      "point_data_ip": "192.168.1.5",  	# <-这里和修改后的电脑ip一致
      "point_data_port": 56301,
      "imu_data_ip" : "192.168.1.5",  	# <-这里和修改后的电脑ip一致
      "imu_data_port": 56401,
      "log_data_ip" : "",
      "log_data_port": 56501
    }
  },
  "lidar_configs" : [
    {
      "ip" : "192.168.1.1xx",		  	# <-雷达的ip，其中xx为雷达SN码最后两位数,本机为60
      "pcl_data_type" : 1,
      "pattern_mode" : 0,
      "extrinsic_parameter" : {
        "roll": 0.0,
        "pitch": 0.0,
        "yaw": 0.0,
        "x": 0,
        "y": 0,
        "z": 0
      }
    }
  ]
}
```

2. Build the Livox ROS Driver 2:

```shell
$ cd livox_ws/src/livox_ros_driver2/
$ source /opt/ros/noetic/setup.sh
$ ./build.sh ROS1
```

# 连接激光雷达

1. 设置电脑IP为静态IP

```shell
#配置IP，其中需将enx2c16dba3bbdf替换为本机网口名称
$ sudo ifconfig enx2c16dba3bbdf 192.168.1.5
```

###### Tips：

网口名称可通过 $ ifconfig -a 查询

2. 连线

# 运行Livox ROS Driver 2:

```shell
$ cd ~/ws_livox/  #进入Livox ROS Driver 2工作空间
$ source devel/setup.sh

#rviz_MID360.launch 连接MID360激光雷达设备、发送pointcloud2格式点云数据、自动加载rviz
$ roslaunch livox_ros_driver2 rviz_MID360.launch

#msg_MID360.launch 连接MID360激光雷达设备、发送livox定制点云数据
$ roslaunch livox_ros_driver2 msg_MID360.launch
```

