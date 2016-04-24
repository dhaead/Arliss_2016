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
#include "IntersemaBaro.h"
//#include "pitch_control"

File myFile;

float tempvolt;
float tempc;
  
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)
const int tempraw = A7;

TinyGPS gps;
//Intersema::BaroPressure_MS5607B baro(true);

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


float x_1=21.4102;//first fix lat
float x_2=21.5572;//target lat 
float y_1=-157.8141;//first fix lon
float y_2=-157.8536;//target lon



//black rock gps  N 40.9119 W 119.1031
//pullman washington Latitude: 46°43′52″ N Longitude: 117°10′46″ W

float distance=sqrt(sq(x_1-x_2)+sq(y_1-y_2));
/**************************************************************************/
/*!
    @brief  Initialises all the sensors used by this example
*/
/**************************************************************************/
void initSensors()
{
  if(!accel.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println(F("Ooops, no LSM303 detected ... Check your wiring!"));
    while(1);
  }
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  if(!bmp.begin())
  {
    /* There was a problem detecting the BMP180 ... check your connections */
    Serial.println("Ooops, no BMP180 detected ... Check your wiring!");
    while(1);
  }
}

/**************************************************************************/



void setup() {
  Serial.begin(115200);
  Serial.println(F("Adafruit 10 DOF Pitch/Roll/Heading Example")); Serial.println("");
  
  /* Initialise the sensors */
  initSensors();

  
  Serial1.begin(9600);
  //#nss.begin(9600);                     // Communicate at 9600 baud (default for PAM-7Q module)
  Serial.begin(9600);

     Serial.println("Reading GPS");
Serial.print("date");
  Serial.print(", ");
  Serial.print("time");
  Serial.print(", ");
Serial.print("Altitude meters");
  Serial.print(", ");
Serial.print("Altitude feet");
  Serial.print(", ");
Serial.print("Altitude gps");
  Serial.print(", ");
  Serial.print("Latitude");
  Serial.print(", ");
  Serial.println("Longitude");
 
   
   while (!Serial) { // wait for serial port to connect. Needed for native USB port only

   Serial.print("Initializing SD card...");
pinMode(12, OUTPUT);
  if (!SD.begin(12)) {
    Serial.println("initialization failed!");
    return;
  }
 Serial.println("initialization done.");
delay(2000);

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

//     baro.init();
  
  myFile = SD.open("quad_dat.csv", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to quad_dat.csv...");
    
  myFile.print("Altitude");
  myFile.print(", ");
  myFile.print("Latitude");
  myFile.print(", ");
  myFile.println("Longitude");
 
    
    // close the file:
    myFile.close();
   Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening testies.txt");
  }  
   }   
delay(2000);
  Serial.println("Reading GPS");
Serial.print("date");
Serial.print("dsitance formula");
Serial.print(distance);

Serial.print("date");
  Serial.print(", ");
  Serial.print("time");
  Serial.print(", ");
Serial.print("Altitude meters");
  Serial.print(", ");
Serial.print("Altitude feet");
  Serial.print(", ");
Serial.print("Altitude gps");
  Serial.print(", ");
  Serial.print("Latitude");
  Serial.print(", ");
  Serial.println("Longitude");

delay(2000);

}

void setupprint(){

  
    Serial.print("Reading GPS");
Serial.print("date");
  Serial.print(", ");
  Serial.print("time");
  Serial.print(", ");
Serial.print("Altitude meters");
  Serial.print(", ");
Serial.print("Altitude feet");
  Serial.print(", ");
Serial.print("Altitude gps");
  Serial.print(", ");
  Serial.print("Latitude");
  Serial.print(", ");
  Serial.println("Longitude");
  
delay(2000);

  }


/*
 //////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Simple code for the ADXL335, prints calculated orientation via serial
//////////////////////////////////////////////////////////////////


//Analog read pins
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

//The minimum and maximum values that came from
//the accelerometer while standing still
//You very well may need to change these
int minVal = 265;
int maxVal = 402;


//to hold the caculated values
double x;
double y;
double z;


void setup(){
  Serial.begin(9600); 
}


void loop(){

  //read the analog values from the accelerometer
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);

  //convert read values to degrees -90 to 90 - Needed for atan2
  int xAng = map(xRead, minVal, maxVal, -90, 90);
  int yAng = map(yRead, minVal, maxVal, -90, 90);
  int zAng = map(zRead, minVal, maxVal, -90, 90);

  //Caculate 360deg values like so: atan2(-yAng, -zAng)
  //atan2 outputs the value of -π to π (radians)
  //We are then converting the radians to degrees
  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  //Output the caculations
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(" | y: ");
  Serial.print(y);
  Serial.print(" | z: ");
  Serial.println(z);

  delay(100);//just here to slow down the serial output - Easier to read
}

========================================================
========================================================
*/
void loop() {  


  sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_event_t bmp_event;
  sensors_vec_t   orientation;

  /* Calculate pitch and roll from the raw accelerometer data */
  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
  {
    /* 'orientation' should have valid .roll and .pitch fields */
    
    //1° of latitude = about 69.11 miles

//1° of longitude = about 69.11 miles along the equator. But all of the longitudes
//come together at the poles, so the farther you are from the equator, the fewer
//miles there are in one degree.

//Number of miles in 1° of longitude = (69.11) x (cosine of the latitude)
    
//float x_1=40.9119;//first fix long
//float x_2=46.7311;//target long 
//float y_1=119.1031;//first fix lat
//float y_2=117.1794;//target lat


float x_1=21.4102*69.172;//first fix lat
float x_2=21.5572*69.172;//target lat 
float y_1=cos(-157.8141)*69.172;//first fix lon
float y_2=cos(-157.8536)*69.172;//target lon
float x_3=21.5900*69.172;//target lat 
float y_3=cos(-158.1086)*69.172;//first fix lon

 //   a^2 = b^2 + c^2 - 2bc\cos\alpha\,
//black rock gps  N 40.9119 W 119.1031
//pullman washington Latitude: 46°43′52″ N Longitude: 117°10′46″ W


float distancefixtarg=sqrt(sq(x_2-x_1)+sq(y_2-y_1));//*69.11 is the conversion to miles

float distancethirdpointtarg=sqrt(sq(x_3-x_2)+sq(y_3-y_2));//*69.11 is the conversion to miles    

float distancethirdpointfix=sqrt(sq(x_3-x_1)+sq(y_3-y_1));//*69.11 is the conversion to miles    


float asqrd=sq(distancefixtarg);

float bsqrd=sq(distancethirdpointtarg);

float csqrd=sq(distancethirdpointfix);
float alpha=acos((bsqrd+csqrd-asqrd)/(2*sqrt(bsqrd)*sqrt(csqrd)));//alpha is the angle by which I must rotate given my 
//location with respect to 2 other coordinates this assumes the body axis "forward" being inline with the third coordinate
//I will have to find my heading relative to north and subtract the heading of the third coordinate with respect to north,
//the angle Im left with the angular separation between my heading and the heading toward my third coordinate. This then is
//added to alpha and we should get the angle by which we must rotate in order to be heading toward the target.


//   a^2 = b^2 + c^2 - 2bc\cos\alpha\,
//black rock gps  N 40.9119 W 119.1031
//pullman washington Latitude: 46°43′52″ N Longitude: 117°10′46″ W

Serial.print("dsitance formula");
Serial.print(distancefixtarg);

Serial.print("dsitance formula");
Serial.print(distancethirdpointtarg);

Serial.print("dsitance formula");
Serial.print(distancethirdpointfix);

    Serial.print(F("Roll: "));
    Serial.print(orientation.roll);
    Serial.print(F("; "));
    Serial.print(F("Pitch: "));
    Serial.print(orientation.pitch);
    Serial.print(F("; "));
  }
  
  /* Calculate the heading using the magnetometer */
  mag.getEvent(&mag_event);
  if (dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation))
  {
    /* 'orientation' should have valid .heading data now */
    Serial.print(F("Heading: "));
    Serial.print(orientation.heading);
    Serial.print(F("; "));
  }

  /* Calculate the altitude using the barometric pressure sensor */
  bmp.getEvent(&bmp_event);
  if (bmp_event.pressure)
  {
    /* Get ambient temperature in C */
    float temperature;
    bmp.getTemperature(&temperature);
    /* Convert atmospheric pressure, SLP and temp to altitude    */
    Serial.print(F("Alt: "));
    Serial.print(bmp.pressureToAltitude(seaLevelPressure,
                                        bmp_event.pressure,
                                        temperature)); 
    Serial.print(F(" m; "));
    /* Display the temperature */
    Serial.print(F("Temp: "));
    Serial.print(temperature);
    Serial.print(F(" C"));
  }
  
  Serial.println(F(""));
  delay(1000);
  
  bool newdata = false;
  unsigned long start = millis();
  while (millis() - start < 5000) {    // Update every 5 seconds
    if (feedgps())
      newdata = true;
  }
  if (newdata) {
    gpsdump(gps);
  }
  
}

// Get and process GPS data
void gpsdump(TinyGPS &gps) {
  float flat, flon, falt;
  
  unsigned long date, time;
  unsigned long age;
  unsigned long fix_age;
  
  //gps.f_altitude(&falt);    
  gps.f_get_position(&flat, &flon, &age);
 gps.get_datetime(&date, &time, &age);
//distance_between (float lat1, float long1, float lat2, float long2);
//int alt = baro.getHeightCentiMeters();
  

Serial.print(date);
  // print a tab between values:
  Serial.print(", ");

  Serial.print(time);
  // print a tab between values:
  Serial.print(", ");
  
//  Serial.print((float)(alt)/100);
  
  Serial.print(", ");
  Serial.print(" ");
  
  
//  Serial.print((float)(alt) / 30.48);
  Serial.print(", ");
    
  Serial.print(" ");
  Serial.print(gps.altitude()/100.00);  
  Serial.print(", ");
  Serial.print(" ");
  Serial.print(flat, 4);  
  Serial.print(", ");
  Serial.print(" ");
  
  Serial.print(flon, 4);
  Serial.print(", ");
  Serial.print(" ");
  
 // Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print(", ");
  Serial.print(" ");
  
 // Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print(", ");
  Serial.print(" ");
  
 // Serial.print(analogRead(zpin));
  // delay before next reading:
  delay(100);
  Serial.print(", ");
  Serial.print(" ");
  
  Serial.print("na");

  Serial.print(", ");
  Serial.print(" ");
  
//Serial.println((analogRead(tempraw) * (5.0 / 1024.0))/0.01);
  
  myFile = SD.open("quad_dat.csv", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) { 
  myFile.print(" ");
  myFile.print(gps.altitude()/100.00);  
  myFile.print(", ");
  myFile.print(" ");
  myFile.print(flat, 4);  
  myFile.print(", ");
  myFile.print(flon, 4);
  myFile.print(", ");
 // myFile.print(analogRead(xpin));
  // print a tab between values:
  myFile.print(", ");
  
 // myFile.print(analogRead(ypin));
  // print a tab between values:
  myFile.print(", ");
 // myFile.print(analogRead(zpin));
  // delay before next reading:
  delay(100);
  
  myFile.print(", ");
  myFile.print("\t");
  myFile.println("na");
    // close the file:
    myFile.close();
  
  //tempvolt = tempraw * (5.0 / 1024.0);
  //tempc = tempvolt / 0.01;

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

