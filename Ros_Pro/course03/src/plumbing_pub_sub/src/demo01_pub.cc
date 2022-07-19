#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"

int main(int argc, char* argv[]){
    //1. init ROS node
    ros::init(argc, argv, "erGouZi");

    //2. create ROS handle
    ros::NodeHandle nh;

    //3. create pub object
    //advertise' first pram is msg what u want to sent, and second is the msg queue length
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10);

    //4. create msg pub
    std_msgs::String msg;

    //5. give a loop and sent the msg what u want to send
    //if the node is exist, ros::ok return a true value
    //We need send the msg by 10Hz and have a id to identify it

    //send Hz, The Rate class's pram is Hz
    ros::Rate rate(100);

    //give a timer, to sign a id 
    size_t count = 0;

    while (ros::ok()){
        //msg.data = "hello";
        //pub.publish(msg);

        std::stringstream ss;
        ss << "hello ------> " << count++;
        msg.data = ss.str();
        pub.publish(msg);

        ROS_INFO("The data is : %s", ss.str().c_str());

        rate.sleep();
    }

    return 0;
}