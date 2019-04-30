#Sara control
Ce repo contient les configurations matérielles de Sara.
Notament, le fichier sara_hardware.yaml qui déclare tout les hardware interfaces de Sara.
On utilise la stack des [combined hardware interfaces](https://wiki.ros.org/combined_robot_hw?distro=kinetic)

# Installation
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

# Pour lancer
```bash
rosslaunch sara_control sara_hardware.launch
```
