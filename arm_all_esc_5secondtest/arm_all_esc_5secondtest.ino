
//for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  //  myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo

// twelve servo objects can be created on most boards
int pos1 = 0;    // variable to store the servo position
int pos2 = 0;    // variable to store the servo position
int pos3 = 0;    // variable to store the servo position
int pos4 = 0;    // variable to store the servo position

int pos = 0;    // variable to store the servo position

void setup() {
  
  
  
  myservo1.attach(6);  // attaches the servo on pin 9 to the servo object
myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
myservo3.attach(11);  // attaches the servo on pin 9 to the servo object
myservo4.attach(5);  // attaches the servo on pin 9 to the servo object


 //for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree

 pos=180;
   
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    
    delay(15);
pos=0;
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    
    delay(15);                       // waits 15ms for the servo to reach the position
//}  




    delay(7000);                       // waits 15ms for the servo to reach the position



//for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  //  myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position



pos1 = 180; // goes from 0 degrees to 180 degrees
pos2 =180; // goes from 0 degrees to 180 degrees
pos3 =180; // goes from 0 degrees to 180 degrees
pos4 = 180; // goes from 0 degrees to 180 degrees

    // in steps of 1 degree
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    myservo3.write(pos3);              // tell servo to go to position in variable 'pos'
    myservo4.write(pos4);              // tell servo to go to position in variable 'pos'
   
    delay(2000);                       // waits 15ms for the servo to reach the position

  

pos1 = 150; // goes from 0 degrees to 180 degrees
pos2 =150; // goes from 0 degrees to 180 degrees
pos3 =150; // goes from 0 degrees to 180 degrees
pos4 = 150; // goes from 0 degrees to 180 degrees

    // in steps of 1 degree
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    myservo3.write(pos3);              // tell servo to go to position in variable 'pos'
    myservo4.write(pos4);              // tell servo to go to position in variable 'pos'
   delay(15);



    delay(2000);                       // waits 15ms for the servo to reach the position

  

pos1 = 0; // goes from 0 degrees to 180 degrees
pos2 =0; // goes from 0 degrees to 180 degrees
pos3 =0; // goes from 0 degrees to 180 degrees
pos4 = 0; // goes from 0 degrees to 180 degrees

    // in steps of 1 degree
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    myservo3.write(pos3);              // tell servo to go to position in variable 'pos'
    myservo4.write(pos4);              // tell servo to go to position in variable 'pos'
   delay(15);



              
                       // waits 15ms for the servo to reach the position
 // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  // myservo1.write(pos);              // tell servo to go to position in variable 'pos'
  // myservo2.write(pos);              // tell servo to go to position in variable 'pos'
  // myservo3.write(pos);              // tell servo to go to position in variable 'pos'
  // myservo4.write(pos);              // tell servo to go to position in variable 'pos'
  //  delay(15);                       // waits 15ms for the servo to reach the position
 // }

}


void loop() {

}


