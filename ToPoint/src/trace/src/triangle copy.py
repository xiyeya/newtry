#! /usr/bin/env python
 
from genpy.message import fill_message_args
import rospy
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from rospy.timer import Timer
from math import cos, fabs, sin
from enum import Enum
import numpy as np
 
State=Enum('State',('MOVE','STOP_MOVE','TURN','STOP_TURN'))
 
now_pose=Pose()
goal_pose=Pose()
g_state=State.MOVE                                                                            
PI = 3.141592653
twist = Twist()
first_set_goal=True
i=0
 
data = np.genfromtxt("/home/xuan/projects/ToPoint/src/trace/msg/points.txt",dtype=[float, float, float, float, int],delimiter=',')  # 将文件中数据加载到data数组里 
 
def subCallback(pose):
    
    global now_pose
    now_pose = pose
 
def control(pub,linear,angular):
    global twist
    twist.linear.x=linear
    twist.angular.z=angular
    pub.publish(twist)
 
#whether the turtle has reached the goal 
def hasReachedGoal():
    global now_pose, goal_pose
   
    return (fabs(now_pose.theta-goal_pose.theta)<0.001)&(fabs(now_pose.x-goal_pose.x)<0.001)&(fabs(now_pose.y-goal_pose.y)<0.001)
 
#wheather the turtle has stopped 
def hasStopped():
    global now_pose
    return ((now_pose.linear_velocity<0.001)&(now_pose.angular_velocity<0.001))
 
 
def stopMove(pub):
    global goal_pose,g_state,now_pose
 
    if hasStopped():
        g_state=State.TURN
        goal_pose.x = now_pose.x
        goal_pose.y = now_pose.y
        goal_pose.theta = now_pose.theta+PI/2
        if goal_pose.theta>PI:
            goal_pose.theta=goal_pose.theta-2*PI
    else:
        control(pub,0,0)
    rospy.loginfo('停止行走')
 
 
def stopTurn(pub):
    global goal_pose,g_state,now_pose
 
    if hasStopped():
        g_state=State.MOVE
        goal_pose.x = now_pose.x+cos(now_pose.theta)
        goal_pose.y = now_pose.y+sin(now_pose.theta)
        goal_pose.theta = now_pose.theta
    else:
        control(pub,0,0)
    rospy.loginfo('停止转弯')
 
 
def move(pub):
 
    global g_state
    if hasReachedGoal():
        g_state=State.STOP_MOVE
        control(pub,0,0)
    else:
        control(pub,0.5,0)
    rospy.loginfo('直线行走move')
 
 
def turn(pub):
    global g_state
    if hasReachedGoal():
        g_state=State.STOP_TURN
        control(pub,0,0)
    else:
        control(pub,0,PI/4)
    rospy.loginfo('转弯')
 
 
 
def timeCallback(event):
    
    rospy.loginfo("come into timeCallback.....")
 
    pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=1)
 
    global goal_pose,now_pose, first_set_goal,g_state
    #if this is the first time to call this function
    if first_set_goal:
        goal_pose.x = now_pose.x+cos(now_pose.theta)
        goal_pose.y = now_pose.y+sin(now_pose.theta)
        goal_pose.theta = now_pose.theta
 
        first_set_goal=False
 
    if g_state==State.STOP_MOVE:
        rospy.loginfo('状态为：'+str(g_state))
        stopMove(pub)
    elif g_state==State.MOVE:
        rospy.loginfo('状态为：'+str(g_state))
        move(pub)
    elif g_state==State.TURN:
        turn(pub)
    else:
        stopTurn(pub)
 
if __name__ == "__main__":
 
    rospy.init_node("go_square")
 
 
    sub = rospy.Subscriber("turtle1/pose", Pose, subCallback,queue_size=10)
 
    rospy.Timer(rospy.Duration(0.016), timeCallback, oneshot=False)
 
 
    rospy.spin()
 
 
 
    pass