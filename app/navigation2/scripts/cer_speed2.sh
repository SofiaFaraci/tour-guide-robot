#!/bin/sh

echo "set_max_joy_lin_vel 0.6" | yarp write ... /baseControl/rpc
echo "set_max_lin_vel 0.6" | yarp write ... /baseControl/rpc