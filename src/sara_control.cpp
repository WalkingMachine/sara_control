//
// Created by gortium on 27/04/17.
//
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <combined_robot_hw/combined_robot_hw.h>

<<<<<<< HEAD
using namespace sara_control_ns;

void stopSignalService(const std_msgs::Bool& msg)
{
  last_tic = ros::Time::now();
}

void startButton(const std_msgs::Bool& msg)
{
  last_tic = ros::Time::now();
}

=======
>>>>>>> add_kinova_joints
int main(int argc, char **argv)
{
  bool ESTOP;

  ros::init(argc, argv, "sara_control");
  ros::NodeHandle nh;

  ros::Subscriber eStopSub = nh.subscribe("start_button_msg", 1, &eStopCallback);
  stopSignalSrv_ = nh_.advertiseService("safety_stop_srv", &wmSupervisor::stopSignalService, this);

<<<<<<< HEAD
=======
  ros::NodeHandle nh;

>>>>>>> add_kinova_joints
  combined_robot_hw::CombinedRobotHW chw;

  chw.init(nh, nh);

  controller_manager::ControllerManager cm(&chw, nh);


  ros::Duration period(0.02);  // 50 Hz

  while (ros::ok())
  {
    ROS_DEBUG("Test");
    chw.read(ros::Time::now(), period);
    if (ESTOP || last_tic + 0.5 > ros::Time::now())
    {
      cm.update(ros::Time::now(), period, true);
    }
    else
    {
      cm.update(ros::Time::now(), period, false);
    }
    chw.write(ros::Time::now(), period);
    period.sleep();
  }
  return 0;
}
