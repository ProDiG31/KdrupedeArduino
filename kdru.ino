/*///////////////////////////////////////////////////
///                                               ///
///    Code for printed Mini 9G Quadruped         ///
///    http://www.thingiverse.com/thing:38159     ///
///    TheCase v.1 Dec2012                        ///
///                                               ///
///    derived from Chopstick Junior 1.0          ///
///    version 1.0.6                              ///
///    by Lutz Michaelis, November 2011           ///  
///    more about this robot and contact form:    ///
///    http://letsmakerobots.com/node/29708       ///
///    powered by                                 ///
///    http://www.roboter-selbstgebaut.com        ///
///////////////////////////////////////////////////*/

// Importing Libary Ext
#include <Servo.h>

// Importing Library Int
#include "ActionBindingDef.h"
#include "ServoPinBinding.h"

// set the names of the servos
Servo Servo_Leg_2;
Servo Servo_Foot_2;
Servo Servo_Leg_1;
Servo Servo_Foot_1;
Servo Servo_Leg_4;
Servo Servo_Foot_4;
Servo Servo_Leg_3;
Servo Servo_Foot_3;
Servo eye;

int b;
int x;
int w;
int up;
int up2;
int up3;
int down;
int down2;
int steps;
int rightsteps;
int leftsteps;
int back;
int pos;
int sensor = A0;
int distance = 0;

unsigned long echo = 0;
int ultraSoundPulse = 13;
int ultraSoundEcho = 3; // Ultrasound signal pin
unsigned long ultrasoundValue = 0;

const int buttonPin = 2;     
int buttonState = 0;

//////////////////////////////////////
void setup()
{
  #include "kdruSetup.h"
}

///////////////////////////////////////
/* Inmporting Preconfigured Movement */
///////////////////////////////////////

#include "MovementFunction.h"

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void loop()
{
  if ( Serial.available() ) {
    int lu = Serial.parseInt();
    Serial.println(lu);
    int valeur;
	  switch (lu){
		  case CMD_FLATOUT:   flatout();break;
		  case CMD_STANDUP:   standup();break;
		  case CMD_SLEEP:     sleep();break;
		  case CMD_STAND:     stand();break;
		  case CMD_FORWARD:   forward();break;
		  case CMD_RIGHTTURN: rightturn();break;
		  case CMD_LEFTTURN:  leftturn(); break;
		  case CMD_BACKWARD:  backward(); break;
		  case CMD_LAYDOWN:   laydown();break;
		  case CMD_GYM:       gym();break;
		  case CMD_WINK:      wink();break;
		  case CMD_SWEEP:     sweep();break;
		  default:			      Serial.println("Erreur Input");break;
	  }
  } else {
    Serial.println("Nothing");
  }
  delay(2000);
}
