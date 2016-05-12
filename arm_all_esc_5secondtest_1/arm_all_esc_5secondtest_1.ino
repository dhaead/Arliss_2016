/*
created by Damion Rosbrugh
This code arms four next level 30 amp ESC's
Then implements an 11 second test of the motors at
two speeds.
Additional code has been added to further explore
roll, pitch, and yaw tests.
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo

int motor1power, motor3power; // Motors on the X axis
int motor2power, motor4power; // Motors on the Y axis
int pos1 = 0;    // variable to store the servo position
int pos2 = 0;    // variable to store the servo position
int pos3 = 0;    // variable to store the servo position
int pos4 = 0;    // variable to store the servo position
int pos = 0;    // variable to store the servo position
int throttle = 0;
int rolloffset = 0;// change ths should make the drone move left and right
int pitchoffset = 0; //changing this should make the drone move forward
int yawoffset = 0;//changing this should rotate the drone
void setup() {  
myservo1.attach(6);  // attaches the motor on pin 6 to the servo object
myservo2.attach(10);  // attaches the servo on pin 10 to the servo object
myservo3.attach(11);  // attaches the servo on pin 11 to the servo object
myservo4.attach(5);  // attaches the servo on pin 5 to the servo object


 //for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree

 pos=180;
   
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    
    delay(1000);
pos=0;
    myservo1.write(pos);              
    myservo2.write(pos);              
    myservo3.write(pos);              
    myservo4.write(pos);              
    
    delay(1000);                       // waits 15ms for the motor to reach the position
//}  

    delay(3000); // waits 7s 



pos1 = 0; // goes from 0 degrees to 180
pos2 =0; 
pos3 =0; 
pos4 = 0; 



motor1power = pos1 - rolloffset - pitchoffset + yawoffset;
 
motor2power = pos2 + rolloffset + pitchoffset - yawoffset;
 
motor3power = pos3 + rolloffset - pitchoffset + yawoffset;
 
motor4power = pos4 - rolloffset + pitchoffset - yawoffset;

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

           
    myservo1.write(motor1power);              // tell servo to go to position in variable 'pos'
    myservo2.write(motor2power);              // tell servo to go to position in variable 'pos'
    myservo3.write(motor3power);              // tell servo to go to position in variable 'pos'
    myservo4.write(motor4power);              // tell servo to go to position in variable 'pos'



    delay(3000); // waits 7s 

pos1 = 0; // goes from 0 degrees to 180
pos2 =0; 
pos3 =0; 
pos4 = 0; 



motor1power = 0;
 
motor2power = 0;
 
motor3power = 0;
 
motor4power = 0;

    myservo1.write(motor1power);              // tell servo to go to position in variable 'pos'
    myservo2.write(motor2power);              // tell servo to go to position in variable 'pos'
    myservo3.write(motor3power);              // tell servo to go to position in variable 'pos'
    myservo4.write(motor4power);              // tell servo to go to position in variable 'pos'


}


void loop() {


}


