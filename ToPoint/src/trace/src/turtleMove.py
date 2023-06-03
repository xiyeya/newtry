#! /usr/bin/env python
 
from pickle import TRUE
import rospy
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from rospy.timer import Timer
import numpy as np
import math
 
i=0
PI=3.141592653
turn=True
now_pose=Pose()
twist=Twist()
data = np.genfromtxt("/home/xuan/projects/ToPoint/src/trace/msg/points.txt",dtype=[float, float, float, float, int],delimiter=',')  # 将文件中数据加载到data数组里

def subCallback(pose):
    global i
    if i<=data.shape[0]:
        rospy.loginfo("come into subCallback!%f %f %d",pose.x,pose.y, i)
    else:
        rospy.signal_shutdown("completed!")
    
 
def timeCallback(event):
 
    pub=rospy.Publisher("turtle1/cmd_vel",Twist,queue_size=1)
    global turn
    global now_pose
    global i
    global data
    if turn:
        twist.linear.x=0
        twist.angular.z=now_pose.theta - math.atan2(data[i][1]-now_pose.y,data[i][0]-now_pose.x)
        turn=False
        i = i+1    
    else:
        twist.linear.x = 1
        twist.angular.z = 0.0
        turn=TRUE    
    pub.publish(twist)
    rospy.sleep(data[i-1][4])
 
if __name__=="__main__":
 
 
    rospy.init_node("go_point")
 
    sub = rospy.Subscriber("turtle1/pose", Pose, subCallback, queue_size=10)
 
    rospy.Timer(rospy.Duration(1),timeCallback, oneshot=False)
 
 
    rospy.spin()
 
    
    pass