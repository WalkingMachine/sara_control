//
// Created by gortium on 27/04/17.
//
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <elmec_robot_control/elmec_hardware.h>


using namespace sara_control;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "sara_control");

  ros::AsyncSpinner spinner(1);
  spinner.start();

  ros::NodeHandle nh;
  combined_robot_hw::CombinedRobotHW chw;

  controller_manager::ControllerManager cm(&chw, nh);

  ros::Duration period(0.02);

  while (ros::ok())
  {
    chw.read();
    cm.update(ros::Time::now(), period);
    chw.write();
    period.sleep();
  }
  return 0;
  }