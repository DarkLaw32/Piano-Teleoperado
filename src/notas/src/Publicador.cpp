#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>
// se crea una variable global que almacene el mensaje recibido



int main(int argc, char **argv)
{
  // Inicializamos el nodo
  ros::init(argc, argv, "Publicador");

  // Creamos un manejador de nodos
  ros::NodeHandle n;

  //publicador
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>(argv[1], 1000);
  
  ros::Rate loop_rate(10);
  ros::Rate poll_rate(100);
  while(chatter_pub.getNumSubscribers()==0)
     poll_rate.sleep();
  int count=0;
  while (ros::ok())	
  {
    std_msgs::String msg;
    msg.data = argv[2];
    // Logeamos en consola
    ROS_INFO("%s", argv[2]);

    // Pubicamos el mensaje
    chatter_pub.publish(msg);

    // Necesario
    ros::spin();

    // Necesario 
    loop_rate.sleep();
    // Conteo
    ++count;
  }

  return 0;
}





