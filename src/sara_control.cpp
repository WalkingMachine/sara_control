//
// Created by gortium on 27/04/17.
//
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <combined_robot_hw/combined_robot_hw.h>

#include "WMAdmittance/WMAdmittance.h"

using namespace wm_admittance;

int main(int argc, char **argv) {
    ros::init(argc, argv, "sara_control");
    ros::NodeHandle nh;

    ROS_INFO("MAIN SARA CONTROL");

    ros::AsyncSpinner spinner(1);
    spinner.start();

    combined_robot_hw::CombinedRobotHW chw;

    chw.init(nh, nh);
    ROS_INFO("ALL HARDWARE INTERFACES LOADED PROPERLY");

    controller_manager::ControllerManager cm(&chw, nh);

    WMAdmittance* lAdmittance = WMAdmittance::getInstance();


    // Initialise period timers
    ros::Time lastRead(ros::Time::now());
    ros::Time lastUpdate(ros::Time::now());
    ros::Time lastWrite(ros::Time::now());
    ros::Time currTime;


    ros::Rate rate(50);  // 50 Hz
    while (ros::ok()) {

        currTime = ros::Time::now();
        chw.read(ros::Time::now(), currTime-lastRead);
        lastRead = currTime;

        currTime = ros::Time::now();
        cm.update(ros::Time::now(), currTime-lastUpdate);
        lastUpdate = currTime;

        lAdmittance->process();

        currTime = ros::Time::now();
        chw.write(ros::Time::now(), currTime-lastWrite);
        lastWrite = currTime;

        rate.sleep();
    }
    spinner.stop();
    return 0;
}

