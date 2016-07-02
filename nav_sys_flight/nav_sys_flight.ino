/* 
This is a modification of the Demonstration code for the Parallax PAM-7Q module, #28509
This code uses the default factory settings of the PAM-7Q module.

The GPS output is displayed in the Arduino Serial Terminal Window.
After uploading the sketch open this window to view the output. 
Make sure the baud rate is set to 9600.

Numeric output is shown as signed latitude and longitude degrees and
minutes. Values may be directly copied and pasted into the location bar
of Google Maps to visually show your location.

For best results use the PAM-7Q module outdoors, or near an open window.
Use indoors away from windows may result in inconsistent results.

This example code is for the Arduino Uno and direct compatible boards. 
It has not been tested, nor designed for, other Arduino boards, including
the Arduino Due.

Important: This version is intended for Arduino 1.0 or later IDE. It will
not compile in earlier versions. Be sure the following files are
present in the folder with this sketch:

TinyGPS.h
TinyGPS.cpp
keywords.txt

A revised version of the TinyGPS object library is included in the sketch folder
to avoid conflict with any earlier version you may have in the Arduino libraries 
location.

Connections:
PAM-7Q    Feather
GND       GND
VDD       5V
TXD       RX0

Reminder! Wait for the satellite lock LED to begin flashing before
taking readings. The flashing LED indicates satellite lock. Readings taken
before satellite lock may be inaccurate.

*/

#include <SPI.h>
#include <SD.h>
#include "./TinyGPS.h"                 // Use local version of this library
#include <Wire.h>
//#include "IntersemaBaro.h"
//#include "pitch_control"

File myFile;

float tempvolt;
float tempc;
  
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)
const int tempraw = A7;

TinyGPS gps;

#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_10DOF.h>

/* Assign a unique ID to the sensors */
Adafruit_10DOF                dof   = Adafruit_10DOF();
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_BMP085_Unified       bmp   = Adafruit_BMP085_Unified(18001);

/* Update this with the correct SLP for accurate altitude measurements */
float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

//float x_1=40.9119;//first fix long
//float x_2=46.7311;//target long 
//float y_1=119.1031;//first fix lat
//float y_2=117.1794;//target lat




//black rock gps  N 40.9119 W 119.1031
//pullman washington Latitude: 46°43′52″ N Longitude: 117°10′46″ W

/**************************************************************************/
/*!
    @brief  Initialises all the sensors used by this example
*/
/**************************************************************************/
/**************************************************************************/



  float targetlat = 0;
  float targetlon = 0;
  


#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo

int motor1power, motor3power; // Motors on the X axis
int motor2power, motor4power; // Motors on the Y axis
int throttle = 0;    // throttle position
int rolloffset = 5;// change ths should make the drone move left and right
int pitchoffset = 7; //7changing this should make the drone move forward
int yawoffset = -8;//changing this should rotate the drone
int offset1 = 0;//15;

int offset2 = 7;//15;
int offset3 = 12;//25;






void setup() {
  Serial.begin(115200);



  
  //Serial.begin(9600);
  while (!Serial);
  Serial.print("enter target lat: ");

  while (Serial.available()==0){}
  targetlat=getlat();

  Serial.print("enter target lon: ");

  while (Serial.available()==0){}
  targetlon=getlon();


    
  //Serial.println(F("Adafruit 10 DOF Pitch/Roll/Heading Example")); Serial.println("");
  
  /* Initialise the sensors */
  initSensors();
  Serial1.begin(9600);
  //Serial.begin(9600);
  //mission();  
//  data_header();
  delay(500);

  Serial.println("Reading GPS");

  delay(2000);

//====================sd===================    
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("quadnav2.txt", FILE_WRITE);

  // if the file opened okay, write to it:

  //=================================
  //setsd();
  //sd_init();


//arm_esc();
//delay(4000);
//throttle=30;
//flight();
//delay(1000);
//throttle=40;
//flight();
//delay(1000);

//throttle=50;
//flight();
//delay(1000);

//throttle=54;
//flight();
//delay(500);

//powerdown();    



}

void loop() {  
/*
  float income = 0;
  while (Serial.available()==0){}
    income=Serial.read();
    Serial.print("I got: ");
    Serial.println(income);
  */  
  //lp();
 // roll_pitch_heading();
  float myroll=printroll();
//  Serial.print("roll: ");
  
//  Serial.println(myroll);
  float mypitch=printpitch();
//  Serial.print("pitch: ");
  
//  Serial.println(mypitch);

float myhead=compassheading();
  //Serial.print("heading: ");
  //Serial.println(myhead);

  float angletarg=angletotarget();

  //Serial.print("Rotate to: ");
  //Serial.print((180/(22/7))*angletarg-myhead,5);
  //Serial.println(" degrees to be facing the target");
  
float disttarg=disttotarget();

//  Serial.print("The distance in feet to target is: ");
 // Serial.println(disttarg*5280);//distance to target in miles converted to feet 1 mile = 5280 feet
//  Serial.print("The distance in miles to target is: ");
//  Serial.println(disttarg);//distance to target in miles converted to feet 1 mile = 5280 feet
float mylat=gpslat(gps);
//  Serial.println("lattitude is: ");
 // Serial.println(mylat,5);
float mylon=gpslon(gps);
 // Serial.println("lattitude is: ");
 // Serial.println(mylon,5);

 // Serial.println(F(""));
  
gpers();

if(((180/(22/7))*angletarg-myhead)<5 & ((180/(22/7))*angletarg-myhead)>-5){
  Serial.println(F("on target"));
  ontarget();
  }
else if ((180/(22/7))*angletarg-myhead<0){
  Serial.println(F("turn left"));
  rotateleft();
  }
else{Serial.println(F("turn right"));
  rotateright();
  }




myFile = SD.open("quadnav2.txt", FILE_WRITE);

 if (myFile) {
  //myFile.print("heading: ");
  myFile.println(myhead);
  //myFile.print("Rotate to: ");
  myFile.print((180/(22/7))*angletarg-myhead,5);
  //myFile.println(" degrees to be facing the target");
  
   
    
    // myFile.print("The distance in feet to target is: ");
  myFile.println(disttarg*5280);//distance to target in miles converted to feet 1 mile = 5280 feet
 // myFile.print("The distance in miles to target is: ");
  myFile.println(disttarg);//distance to target in miles converted to feet 1 mile = 5280 feet


    
    myFile.println(mylat,5);
    myFile.println(mylon,5);
    
    myFile.close();
    }
 
  
  
  
  }


// Feed data as it becomes available 
bool feedgps() {
  while (Serial1.available()) {
   if (gps.encode(Serial1.read()))
      return true;
  }
  return false;
}

