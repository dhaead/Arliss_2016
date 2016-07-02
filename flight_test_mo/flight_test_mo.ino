/*
created by Damion Rosbrugh
This code arms four next level 30 amp ESC's
Then implements an 11 second test of the motors at
two speeds.
Additional code has been added to further explore
roll, pitch, and yaw tests.
*/

//myquad orientation
//  1  3
//  \-/
//  /-\
//  4  2

//c = throttle - roll + pitch + yaw
//d = throttle + roll + pitch - yaw
//b = throttle - roll - pitch - yaw
//a = throttle + roll - pitch + yaw

//CW motors    A,C
//CCW motors   D,B

      //     Front
    //       +1 pitch
  //        C   D
//-1 roll    \-/     +1 roll   right
      //     /-\
     //     B   A
     //      -1 pitch

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo

int motor1power, motor3power; // Motors on the X axis
int motor2power, motor4power; // Motors on the Y axis
int throttle = 0;    // throttle position
int rolloffset = 0;// change ths should make the drone move left and right
int pitchoffset = 0; //7changing this should make the drone move forward
int yawoffset = 0;//changing this should rotate the drone
int offset1 = 0;//15;

int offset2 = 0;//15;
int offset3 = 0;//25;

//Serial.begin(9600);
//Serial.println(50 + pitchoffset);

void setup() {  
arm_esc();
delay(4000);
throttle=30;
flight();
delay(1000);
throttle=40;
flight();
delay(1000);

throttle=50;
flight();
delay(1000);

throttle=54;
flight();
delay(500);

throttle=57;
flight();
delay(500);

throttle=59;
flight();
delay(500);
throttle=60;
flight();
delay(3000);
powerdown();    

}



void loop() {


}


