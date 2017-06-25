//
// Created by gortium on 5/8/17.
//

#ifndef SARA_CONTROL_H
#define SARA_CONTROL_H

#include "std_msgs/Bool.h"

namespace sara_control_ns
{

    int main(int argc, char **argv);

    void eStopCallback(const std_msgs::Bool& msg);
}

#endif //SARA_CONTROL_H
