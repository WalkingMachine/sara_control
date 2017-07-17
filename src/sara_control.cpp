//
// Created by gortium on 27/04/17.
//
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <combined_robot_hw/combined_robot_hw.h>
#include <realtime_tools/realtime_publisher.h>
#include <std_srvs/SetBool.h>
#include <std_msgs/Bool.h>

bool ESTOP;

bool callback(std_srvs::SetBool::Request &request, std_srvs::SetBool::Response &response) {
    ESTOP = request.data;
    response.success = true;
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "sara_control");
    ros::NodeHandle nh;

    ros::ServiceServer status_service = nh.advertiseService("estop_service", callback);

    realtime_tools::RealtimePublisher<std_msgs::Bool> *rt_pub;

    rt_pub = new realtime_tools::RealtimePublisher<std_msgs::Bool>(nh, "estop_status", 4);

    ros::AsyncSpinner spinner(1);
    spinner.start();

    combined_robot_hw::CombinedRobotHW chw;

    chw.init(nh, nh);

    controller_manager::ControllerManager cm(&chw, nh);

    ros::Duration period(0.02);  // 50 Hz

    while (ros::ok()) {
        chw.read(ros::Time::now(), period);
        cm.update(ros::Time::now(), period, !ESTOP);
        chw.write(ros::Time::now(), period);
        if (rt_pub->trylock()) {
            rt_pub->msg_.data = (char)(ESTOP ? 1:0);
            rt_pub->unlockAndPublish();
        }
        period.sleep();
    }
    free(rt_pub);
    return 0;
}
