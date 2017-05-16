//
// Created by gortium on 27/04/17.
//
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <sara_control/sara_control.h>
#include <combined_robot_hw/combined_robot_hw.h>


using namespace sara_control_ns;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sara_control");

  ros::AsyncSpinner spinner(1);
  spinner.start();

  ros::NodeHandle nh;
  combined_robot_hw::CombinedRobotHW chw;

  chw.init(nh, nh);

  controller_manager::ControllerManager cm(&chw, nh);

  ros::Duration period(0.02);

  while (ros::ok()) {
    chw.read(ros::Time::now(), period);
    cm.update(ros::Time::now(), period);
    chw.write(ros::Time::now(), period);
    period.sleep();
  }
  return 0;
}