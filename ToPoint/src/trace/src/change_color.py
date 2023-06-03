#!/usr/bin/python3

import rospy as ros

# /turtlesim/background_b
# /turtlesim/background_g
# /turtlesim/background_r

if __name__ == "__main__":
    ros.init_node("change_background_color_p")
    ros.set_param("/turtlesim/background_b", 0)
    ros.set_param("/turtlesim/background_g", 100)
    ros.set_param("/turtlesim/background_r", 100)