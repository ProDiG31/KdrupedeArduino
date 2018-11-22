pinMode(13, OUTPUT);  // LED pin
pinMode(buttonPin, INPUT);

// assign servos to pins and center servos
Servo_Leg_1.attach(Servo_Leg_Pin_1);
Servo_Foot_1.attach(Servo_Foot_Pin_1);
Servo_Leg_2.attach(Servo_Leg_Pin_2);
Servo_Foot_2.attach(Servo_Foot_Pin_2);
Servo_Leg_3.attach(Servo_Leg_Pin_3);
Servo_Foot_3.attach(Servo_Foot_Pin_3);
Servo_Leg_4.attach(Servo_Leg_Pin_4);
Servo_Foot_4.attach(Servo_Foot_Pin_4);

Servo_Leg_1.write(home_Servo_Leg_1);
Servo_Foot_1.write(home_Servo_Foot_1);
Servo_Leg_2.write(home_Servo_Leg_2);
Servo_Foot_2.write(home_Servo_Foot_2);
Servo_Leg_3.write(home_Servo_Leg_3);
Servo_Foot_3.write(home_Servo_Foot_3);
Servo_Leg_4.write(home_Servo_Leg_4);
Servo_Foot_4.write(home_Servo_Foot_4);

//eyes
Serial.begin(9600);
pinMode(ultraSoundPulse,OUTPUT);
pinMode(ultraSoundEcho,INPUT);
