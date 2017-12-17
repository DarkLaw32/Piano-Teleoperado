#!/usr/bin/env python
import rospy
import serial
import time
from std_msgs.msg import String
ser=serial.Serial('/dev/ttyACM1',9600)

def callback(nota):
    
    if nota.data is "C":
        rospy.loginfo("La nota es %s", "DO")
        ser.write('090')
        time.sleep(0.5)

    if nota.data is "D":
        rospy.loginfo("La nota es %s", "RE")
        ser.write('080')
        time.sleep(0.5)

    if nota.data is "E":
        rospy.loginfo("La nota es %s", "MI")
        ser.write('070')
        time.sleep(0.5)

    if nota.data is "F":
        rospy.loginfo("La nota es %s", "FA")
        ser.write('060')
        time.sleep(0.5)

    if nota.data is "G":
        rospy.loginfo("La nota es %s", "SOL")
        ser.write('050')
        time.sleep(0.5)

    if nota.data is "A":
        rospy.loginfo("La nota es %s", "LA")
        ser.write('040')
        time.sleep(0.5)

    if nota.data is "B":
        rospy.loginfo("La nota es %s", "SI")
        ser.write('030')
        time.sleep(0.5)
        
    if nota.data is "X":
        rospy.loginfo("La nota es %s", "CANCION")
        ser.write('020')
        time.sleep(0.5)

    
def listener():
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("/nota/piano", String, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()
