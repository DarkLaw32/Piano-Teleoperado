#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "wiringPi.h"

int D=0;
int R=2;
int M=4;
int F=5;
int S=6;
int L=7;
int SI=1;
const char* nota;

// Funcion que se ejecuta cada ves que llega el mensaje
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  nota=(msg->data.c_str());

//CANCION "HIMNO A LA ALEGRÍA"
if(strcmp(msg->data.c_str() ,"CANCION"))
{
}
else
{ROS_INFO("La nota es %s", "CANCION");
 digitalWrite(F,HIGH);//Fa
 sleep(2.0);
 digitalWrite(F,LOW);
  digitalWrite(S,HIGH);//Sol
 sleep(1.0);
 digitalWrite(S,LOW);
digitalWrite(L,HIGH);//La
 sleep(1.0);
 digitalWrite(L,LOW);
digitalWrite(L,HIGH);//La
 sleep(1.0);
 digitalWrite(L,LOW);
 digitalWrite(S,HIGH);//SOL
 sleep(1.0);
 digitalWrite(S,LOW);
 digitalWrite(F,HIGH);//FA
 sleep(1.0);
 digitalWrite(F,LOW);
 digitalWrite(M,HIGH);//MI
 sleep(1.0);
 digitalWrite(M,LOW);
 digitalWrite(R,HIGH);//RE
 sleep(1.0);
 digitalWrite(R,LOW);
 digitalWrite(R,HIGH);//RE
 sleep(1.0);
 digitalWrite(R,LOW);
 digitalWrite(M,HIGH);//MI
 sleep(1.0);
 digitalWrite(M,LOW);
 digitalWrite(F,HIGH);//FA
 sleep(1.0);
 digitalWrite(F,LOW);
 digitalWrite(S,HIGH);//FA
 sleep(2.0);
 digitalWrite(S,LOW);
 digitalWrite(M,HIGH);
 sleep(2.0);
 digitalWrite(M,LOW);
}


//DO
if(strcmp(msg->data.c_str() ,"C"))
{
}
else
{ROS_INFO("La nota es %s", "DO");
 digitalWrite(D,HIGH);
 sleep(2.0);
 digitalWrite(D,LOW);
 sleep(2.0);
}

//RE
if(strcmp(msg->data.c_str() ,"D"))
{
}
else
{ROS_INFO("La nota es %s", "RE");
digitalWrite(R,HIGH);
 sleep(2.0);
 digitalWrite(R,LOW);
 sleep(2.0);
}

//MI
if(strcmp(msg->data.c_str() ,"E"))
{
}
else
{ROS_INFO("La nota es %s", "MI");
digitalWrite(M,HIGH);
 sleep(2.0);
 digitalWrite(M,LOW);
 sleep(2.0);
}

//FA
if(strcmp(msg->data.c_str() ,"F"))
{
}
else
{ROS_INFO("La nota es %s", "FA");
digitalWrite(F,HIGH);
 sleep(2.0);
 digitalWrite(F,LOW);
 sleep(2.0);}

//SOL
if(strcmp(msg->data.c_str() ,"G"))
{
}
else
{ROS_INFO("La nota es %s", "SOL");
digitalWrite(S,HIGH);
 sleep(2.0);
 digitalWrite(S,LOW);
 sleep(2.0);
}

//LA
if(strcmp(msg->data.c_str() ,"A"))
{
}
else
{ROS_INFO("La nota es %s", "LA");
digitalWrite(L,HIGH);
 sleep(2.0);
 digitalWrite(L,LOW);
 sleep(2.0);
}

//SI
if(strcmp(msg->data.c_str() ,"B"))
{
}
else
{ROS_INFO("La nota es %s", "SI");
digitalWrite(SI,HIGH);
 sleep(2.0);
 digitalWrite(SI,LOW);
 sleep(2.0);
}

}


int main(int argc, char **argv)
{
  // Inicializamos el nodo
  ros::init(argc, argv, "listener2");
  wiringPiSetup();
  pinMode(D,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(M,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(S,OUTPUT);
  pinMode(L,OUTPUT);
  pinMode(SI,OUTPUT);
  // Creamos un manejador de nodos
  ros::NodeHandle n;
  // Nos suscribimos y usamos la funcion de callback
  ros::Subscriber sub = n.subscribe("/nota/piano", 1000, chatterCallback);

  // Necesario
  ros::spin();

  return 0;
}
