// coding : UTF-8

#include "ActionBindingDef.h"

//////////////////////////////////////
void idle() // this is the delay between the steps -> walking speed
{
  delay(100);  // if set to a bigger number (more delay between the steps -> slower walking) you will see the walking pattern more clearly
}
//////////////////////////////////////
void test() /* just for debugging -> if need a delay between the subroutines
 you can let the LED blink as an indicator that something is still running  */
{
  Serial.println("Test");
  for(b = 0; b < 3; b++) // this let the LED blink 5 times
  {
    digitalWrite(13, HIGH);   // turn the LED on
    delay(300);               // wait for .5 second
    digitalWrite(13, LOW);    // turn the LED off
    delay(300);
  }
}
//////////////////////////////////////
void flatout()
{
  Serial.println("flatout");
  Servo_Leg_2.write(home_Servo_Leg_2);
  Servo_Foot_2.write(home_Servo_Foot_2);
  Servo_Leg_1.write(home_Servo_Leg_1);
  Servo_Foot_1.write(home_Servo_Foot_1);
  Servo_Leg_4.write(home_Servo_Leg_4);
  Servo_Foot_4.write(home_Servo_Foot_4);
  Servo_Leg_3.write(home_Servo_Leg_3);
  Servo_Foot_3.write(home_Servo_Foot_3);
}
//////////////////////////////////////
void servoZero()
{
  Serial.println("Zero Servo");
  Servo_Leg_2.write(0);
  Servo_Foot_2.write(0);
  Servo_Leg_1.write(0);
  Servo_Foot_1.write(0);
  Servo_Leg_4.write(0);
  Servo_Foot_4.write(0);
  Servo_Leg_3.write(0);
  Servo_Foot_3.write(0);
}
//////////////////////////////////////
void standup()
{
  Serial.println("standUp");
  up2 = 0;
  up3 = 0;
  Servo_Leg_2.write(home_Servo_Leg_2-20);
  Servo_Leg_1.write(home_Servo_Leg_1-10);
  Servo_Leg_4.write(home_Servo_Leg_4+30);
  Servo_Leg_3.write(home_Servo_Leg_3-20);
  for(up = 0; up < 80; up++)
  {
    Servo_Foot_2.write(up+home_Servo_Foot_2);
    up2 = up2 - 1;
    Servo_Foot_1.write(up2+home_Servo_Foot_1);
    delay(20);
  }

  for(up = 0; up < 90; up++)
  {
    Servo_Foot_4.write(up+home_Servo_Foot_4);
    up3 = up3 - 1;
    Servo_Foot_3.write(up3+home_Servo_Foot_3);
    delay(15);
  }
}
//////////////////////////////////////
void sleep()
{
  Serial.println("sleep");
  // hips
  Servo_Leg_2.write(home_Servo_Leg_2-20);
  Servo_Leg_1.write(home_Servo_Leg_1);
  Servo_Leg_4.write(home_Servo_Leg_4-20);
  Servo_Leg_3.write(home_Servo_Leg_3);
  // legs
  Servo_Foot_2.write(home_Servo_Foot_2-90);
  Servo_Foot_1.write(home_Servo_Foot_1+90);
  Servo_Foot_4.write(home_Servo_Foot_4-90);
  Servo_Foot_3.write(home_Servo_Foot_3+90);
}
//////////////////////////////////////
void stand()
{
  Serial.println("stand");
  Servo_Leg_2.write(home_Servo_Leg_2-20);
  Servo_Foot_2.write(home_Servo_Foot_2+80);
  delay(20);
  Servo_Leg_1.write(home_Servo_Leg_1-10);
  Servo_Foot_1.write(home_Servo_Foot_1-70);
  delay(20);
  Servo_Leg_4.write(home_Servo_Leg_4-10);
  Servo_Foot_4.write(home_Servo_Foot_4+80);
  delay(20);
  Servo_Leg_3.write(home_Servo_Leg_3-20);
  Servo_Foot_3.write(home_Servo_Foot_3-70);
  delay(20);
}
//////////////////////////////////////
void forward()
{
  Serial.println("forward");
  // lift front right leg, move front right hip forward and rear right hip backward, lower front right leg
  Servo_Foot_4.write(home_Servo_Foot_4+50);  // lower the diagonal opposite leg a bit to keep the balance
  Servo_Foot_2.write(home_Servo_Foot_2+30);  //orig 140
  idle();
  Servo_Leg_2.write(home_Servo_Leg_2-45);
  Servo_Leg_3.write(home_Servo_Leg_3+60); // orig 90
  idle();
  Servo_Foot_2.write(home_Servo_Foot_2+80);  //orig 170
  Servo_Foot_4.write(home_Servo_Foot_4+60);  //orig 170  //put the diagonal opposite leg down to keep the balance
  // lift rear left leg, move rear left hip forward and front right hip backward, lower rear left leg
  Servo_Foot_2.write(home_Servo_Foot_2+80);  //orig 140 //lower the diagonal opposite leg a bit to keep the balance
  Servo_Foot_4.write(home_Servo_Foot_4+50);
  idle();
  Servo_Leg_4.write(home_Servo_Leg_4+30); //orig 120
  Servo_Leg_2.write(home_Servo_Leg_2+20);
  idle();
  Servo_Foot_4.write(home_Servo_Foot_4+60);  // orig 170
  Servo_Foot_1.write(home_Servo_Foot_1+80);  // put the diagonal opposite leg down to keep the balance
  // lift front left leg, move front left hip forward and rear left hip backward, lower front left leg
  Servo_Foot_3.write(home_Servo_Foot_3-20);  // orig 50  //lower the diagonal opposite leg a bit to keep the balance
  Servo_Foot_1.write(home_Servo_Foot_1-40);
  idle();
  Servo_Leg_1.write(home_Servo_Leg_1+60); //orig 110
  Servo_Leg_4.write(home_Servo_Leg_4-50);//orig 60
  idle();
  Servo_Foot_1.write(home_Servo_Foot_1-70);
  Servo_Foot_3.write(home_Servo_Foot_3-70);  // put the diagonal opposite leg down to keep the balance
  // lift rear right leg, move rear right hip forward and front left hip backward, lower rear right leg
  Servo_Foot_1.write(home_Servo_Foot_1-40);  // lower the diagonal opposite leg a bit to keep the balance
  Servo_Foot_3.write(home_Servo_Foot_3-40);
  idle();
  Servo_Leg_3.write(home_Servo_Leg_3-20); //orig 30
  Servo_Leg_1.write(home_Servo_Leg_1); //orig 50
  idle();
  Servo_Foot_3.write(home_Servo_Foot_3-50); //orig 20
  Servo_Foot_1.write(home_Servo_Foot_1-70);  // orig 20 //put the diagonal opposite leg down to keep the balance
  idle();
}
/////////////////////////////////////
void rightturn()
{
  Serial.println("rightTurn");
  // lift front right leg, move front right hip forward and rear right hip backward, lower front right leg
  Servo_Foot_2.write(home_Servo_Foot_2+60);
  idle();
  Servo_Leg_2.write(home_Servo_Leg_2-60);
  Servo_Leg_3.write(home_Servo_Leg_3);
  idle();
  Servo_Foot_2.write(home_Servo_Foot_2+80);
  // lift rear left leg, move rear left hip forward and front right hip backward, lower rear left leg
  Servo_Foot_4.write(home_Servo_Foot_4+60);
  idle();
  Servo_Leg_4.write(home_Servo_Leg_4+40);
  Servo_Leg_2.write(home_Servo_Leg_2+10);
  idle();
  Servo_Foot_4.write(home_Servo_Foot_4+80);
  // lift front left leg, move front left hip forward and rear left hip backward, lower front left leg
  Servo_Foot_1.write(home_Servo_Foot_1-50);
  idle();
  Servo_Leg_1.write(home_Servo_Leg_1+40);
  Servo_Leg_4.write(home_Servo_Leg_4-40);
  idle();
  Servo_Foot_1.write(home_Servo_Foot_1-70);
  // lift rear right leg, move rear right hip forward and front left hip backward, lower rear right leg
  Servo_Foot_3.write(home_Servo_Foot_3-30);
  idle();
  Servo_Leg_3.write(home_Servo_Leg_3-20);
  Servo_Leg_1.write(home_Servo_Leg_1-40);
  idle();
  Servo_Foot_3.write(home_Servo_Foot_3-70);
  idle();
}
/////////////////////////////////////
void leftturn()
{
  Serial.println("leftTurn");
  // lift front right leg, move front right hip forward and rear right hip backward, lower front right leg
  Servo_Foot_2.write(home_Servo_Foot_2+60);
  idle();
  Servo_Leg_2.write(home_Servo_Leg_2-60);
  Servo_Leg_3.write(home_Servo_Leg_3+10);
  idle();
  Servo_Foot_2.write(home_Servo_Foot_2+80);
  // lift rear left leg, move rear left hip forward and front right hip backward, lower rear left leg
  Servo_Foot_4.write(home_Servo_Foot_4+60);
  idle();
  Servo_Leg_4.write(home_Servo_Leg_4);
  Servo_Leg_2.write(home_Servo_Leg_2+30);
  idle();
  Servo_Foot_4.write(home_Servo_Foot_4+80);
  // lift front left leg, move front left hip forward and rear left hip backward, lower front left leg
  Servo_Foot_1.write(home_Servo_Foot_1-30);
  idle();
  Servo_Leg_1.write(home_Servo_Leg_1);
  Servo_Leg_4.write(home_Servo_Leg_4-30);
  idle();
  Servo_Foot_1.write(home_Servo_Foot_1-70);
  // lift rear right leg, move rear right hip forward and front left hip backward, lower rear right leg
  Servo_Foot_3.write(home_Servo_Foot_3-30);
  idle();
  Servo_Leg_3.write(home_Servo_Leg_3-60);
  Servo_Leg_1.write(home_Servo_Leg_1-10);
  idle();
  Servo_Foot_3.write(home_Servo_Foot_3-70);
  idle();
}
/////////////////////////////////////
void backward()
{
  Serial.println("backWard");
  // lift front right leg, move front right hip backward and rear right hip forward, lower front right leg
  Servo_Foot_2.write(home_Servo_Foot_2+60);
  idle();
  Servo_Leg_2.write(home_Servo_Leg_2+10);
  Servo_Leg_3.write(home_Servo_Leg_3-40);
  idle();
  Servo_Foot_2.write(home_Servo_Foot_2+80);
  // lift rear left leg, move rear left hip backward and front right hip forward, lower rear left leg
  Servo_Foot_4.write(home_Servo_Foot_4+40);
  idle();
  Servo_Leg_4.write(home_Servo_Leg_4-30);
  Servo_Leg_2.write(home_Servo_Leg_2-45);
  idle();
  Servo_Foot_4.write(home_Servo_Foot_4+80);
  // lift front left leg, move front left hip backward and rear left hip forward, lower front left leg
  Servo_Foot_1.write(home_Servo_Foot_1-50);
  idle();
  Servo_Leg_1.write(home_Servo_Leg_1-20);
  Servo_Leg_4.write(home_Servo_Leg_4+30);
  idle();
  Servo_Foot_1.write(home_Servo_Foot_1-70);
  // lift rear right leg, move rear right hip backward and front left hip forward, lower rear right leg
  Servo_Foot_3.write(home_Servo_Foot_3-30);
  idle();
  Servo_Leg_3.write(home_Servo_Leg_3+20);
  Servo_Leg_1.write(home_Servo_Leg_1+20);
  idle();
  Servo_Foot_3.write(home_Servo_Foot_3-70);
  idle();
}
/////////////////////////////////////
void laydown() // lay down
{
  Serial.println("laydown");
  Servo_Leg_2.write(home_Servo_Leg_2-20);
  Servo_Leg_1.write(home_Servo_Leg_1-10);
  for (down = 80; down > 0; down = down - 1){
    Servo_Foot_2.write(home_Servo_Foot_2+down);
    down2 = 100 - down;
    Servo_Foot_1.write(home_Servo_Foot_1+down2);
    delay(15);
  }
  delay(1000);
  Servo_Leg_4.write(home_Servo_Leg_4-10);
  Servo_Leg_3.write(home_Servo_Leg_3-20);
  for (down = 80; down > 0; down = down - 1){
    Servo_Foot_4.write(home_Servo_Foot_4+down);
    down2 = 100 - down;
    Servo_Foot_3.write(home_Servo_Foot_3+down2);
    delay(15);
  }
}
/////////////////////////////////////
void gym() // ok, this is not very serious but I needed to cheer me up a bit ;-) just see...
{
  Serial.println("gym");
  Servo_Leg_2.write(home_Servo_Leg_2-20);
  Servo_Foot_4.write(home_Servo_Foot_4+40);
  delay(200);
  Servo_Foot_1.write(home_Servo_Foot_1-50);
  Servo_Leg_1.write(home_Servo_Leg_1+20);
  Servo_Foot_1.write(home_Servo_Foot_1-70);
  delay(20);
  Servo_Foot_2.write(home_Servo_Foot_2-30);
  delay(20);
  Servo_Leg_4.write(home_Servo_Leg_4+30);
  delay(20);
  Servo_Leg_3.write(home_Servo_Leg_3-20);
  Servo_Foot_3.write(home_Servo_Foot_3-70);
  delay(20);
}
/////////////////////////////////////
void wink()
{
  Serial.println("wink");
  for (b = 0; b < 3; b++){
    for (w = -30; w < -70; w = w -1)
    {
      Servo_Foot_2.write(home_Servo_Foot_2+w);
      delay(10);
    }
    for (w = -70; w < -30; w++)
    {
      Servo_Foot_2.write(home_Servo_Foot_2+w);
      delay(10);
    }
    delay(200);
  }
}
/////////////////////////////////////
void sweep()
{
  Serial.println("sweep");
  for(pos = 20; pos < 160; pos += 1)   // goes from 0 degrees to 180 degrees 
  {                                    // in steps of 1 degree 
    eye.write(pos);                    // tell servo to go to position in variable 'pos' 
    delay(10);                         // waits 15ms for the servo to reach the position 
    distance = analogRead(sensor);
    //Serial.print(distance);
    //Serial.print(" - Position ");
    //Serial.print(pos);
    //Serial.println();
  }
  for(pos = 160; pos >= 20; pos -= 1)      // goes from 180 degrees to 0 degrees 
  {
    eye.write(pos);                    // tell servo to go to position in variable 'pos' 
    delay(10);                         // waits 15ms for the servo to reach the position 
    distance = analogRead(sensor);
  }
}

String getMode(){
  Serial.println("getMode");
  #if (defined(SLAVE_MODE)) 
    return ("SLAVE");
  #elif (defined(MASTER_MODE)) 
    return ("MASTER");
  #endif
}

unsigned long ping()
{
  Serial.println("ping");
  // Switch signalpin to output
  digitalWrite(ultraSoundPulse, LOW); // Send low pulse
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundPulse, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundPulse, LOW); // Holdoff
  // Switch signalpin to input
  digitalWrite(ultraSoundPulse, HIGH); // Turn on pullup resistor
  echo = pulseIn(ultraSoundEcho, HIGH); //Listen for echo
  ultrasoundValue = (echo / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValue;
}


void slaveMovement(int lu)
{
  switch (lu){
    case CMD_FLATOUT:   flatout(); break;
    case CMD_STANDUP:   standup(); break;
    case CMD_SLEEP:     sleep(); break;
    case CMD_STAND:     stand(); break;
    case CMD_FORWARD:   forward(); break;
    case CMD_RIGHTTURN: rightturn(); break;
    case CMD_LEFTTURN:  leftturn();  break;
    case CMD_BACKWARD:  backward();  break;
    case CMD_LAYDOWN:   laydown(); break;
    case CMD_GYM:       gym(); break;
    case CMD_WINK:      wink(); break;
    case CMD_SWEEP:     sweep(); break;
    case CMD_GETMODE:   getMode(); break;
    case CMD_ZEROSERVO: servoZero(); break;
    default: Serial.println("Erreur Input");
  }
}
