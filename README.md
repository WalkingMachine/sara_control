# Sara control
Ce repo contient les configurations matérielles de Sara.
Notament, le fichier sara_hardware.yaml qui déclare tout les hardware interfaces de Sara.
On utilise la stack des [combined hardware interfaces](https://wiki.ros.org/combined_robot_hw?distro=kinetic)

### Installing
```bash
sudo apt install ros-kinetic-ros-control
sudo apt install ros-kinetic-combined-robot-hw

cd <your catkin workspace>/src
git clone <ce repo>
git clone <https://github.com/WalkingMachine/wm_fake_hardware_interface>
git clone <https://github.com/WalkingMachine/wm_kinova_hardware_interface>
git clone <https://github.com/WalkingMachine/wm_roboteq_hardware_interface>
git clone <https://github.com/WalkingMachine/wm_robotiq_hardware_interface>
git clone <https://github.com/WalkingMachine/wm_lifting-column_hardware_interface>
git clone <https://github.com/WalkingMachine/wm_dynamixel>
git clone <https://github.com/WalkingMachine/dynamixel_control_hw>
```

## Running the tests
```bash
rosslaunch sara_control sara_hardware.launch
```

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/JeffCousineau/5ddad03418b09750e2a4afcb198b50e1) for details on our code of conduct, and the process for submitting pull requests to us.

## Authors

See the list of [contributors](https://github.com/walkingmachine/sara_control/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to all the ROS comunity
