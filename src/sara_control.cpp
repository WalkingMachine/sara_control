//
// Created by gortium on 27/04/17.
//
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <combined_robot_hw/combined_robot_hw.h>


int main(int argc, char **argv)
{
  bool ESTOP;

  ros::init(argc, argv, "sara_control");
  ros::NodeHandle nh;

  ros::AsyncSpinner spinner(1);
  spinner.start();
    
  combined_robot_hw::CombinedRobotHW chw;

  chw.init(nh, nh);

  controller_manager::ControllerManager cm(&chw, nh);

  ros::Duration period(0.02);  // 50 Hz

  while (ros::ok())
  {
    chw.read(ros::Time::now(), period);
    //cm.update(ros::Time::now(), period, true);
    cm.update(ros::Time::now(), period, false);
    chw.write(ros::Time::now(), period);
    period.sleep();
  }
  return 0;
}
