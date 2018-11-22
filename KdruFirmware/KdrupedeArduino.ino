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
#include "ServoPinBinding.h"

#define SLAVE_MODE
//#define MASTER_MODE


// set the names of the servos

Servo Servo_Leg_1;
Servo Servo_Foot_1;
Servo Servo_Leg_2;
Servo Servo_Foot_2;
Servo Servo_Leg_3;
Servo Servo_Foot_3;
Servo Servo_Leg_4;
Servo Servo_Foot_4;

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
String data = "";

///////////////////////////////////////
/*        Main Setup Function        */
///////////////////////////////////////

void setup()
{
  #include "kdruSetup.h"
}

///////////////////////////////////////
/* Inmporting Preconfigured Movement */
///////////////////////////////////////

#include "MovementFunction.h"

///////////////////////////////////////
/*        Main loop Function         */
///////////////////////////////////////

void loop()
{
  #if (defined(SLAVE_MODE))
		Serial.println("SLAVE MODE");
		if ( Serial.available() ) {
			int lu = Serial.parseInt();
			Serial.println(lu);
			slaveMovement(lu);
		} else {
			Serial.println("Nothing");
		}
	#elif (defined(MASTER_MODE))
		Serial.println("MASTER MODE")
		if ( Serial.available() ) {
			int lu = Serial.parseInt()
			Serial.println(lu);
			// switch (lu){
			// 	case CMD_FLATOUT:   flatout();break;
			// 	default:
			// 		Serial.println("Erreur Input");break;
			// } else {
			// 	Serial.println("Nothing catch");
			}
  #endif

  data =  ("1_1:"+ String(Servo_Foot_1.read()) +" - 1_2 " + String(Servo_Leg_1.read()));
  data += ("2_1:"+ String(Servo_Foot_2.read()) +" - 2_2 " + String(Servo_Leg_2.read()));
  data += ("3_1:"+ String(Servo_Foot_3.read()) +" - 3_2 " + String(Servo_Leg_3.read()));
  data += ("4_1:"+ String(Servo_Foot_4.read()) +" - 4_2 " + String(Servo_Leg_4.read()));

  Serial.println(data);
  delay(2000);
}
