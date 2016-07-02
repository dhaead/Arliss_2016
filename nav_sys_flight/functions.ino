float getlat(){
        
float targlat = 0;
  //Serial.flush();
  
    targlat=Serial.parseFloat();
    
    Serial.print("target lat is: ");
    Serial.println(targlat);
    return(targlat);
}

float getlon(){
    float targlon = 0;

    targlon=Serial.parseFloat();
    
    Serial.print("target lat is: ");
    Serial.println(targlon);
    return(targlon);
  }

void data_header(){

Serial.print("date");
Serial.print("dsitance formula");

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
  
  }


void sd_init(){
  
  
//   while (!Serial) { // wait for serial port to connect. Needed for native USB port only

//   Serial.print("Initializing SD card...");
//pinMode(12, OUTPUT);
 // if (!SD.begin(12)) {
 //   Serial.println("initialization failed!");
 //   return;
//  }
// Serial.println("initialization done.");
//delay(2000);

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

//     baro.init();
  
 // myFile = SD.open("quad_dat.csv", FILE_WRITE);

  // if the file opened okay, write to it:
//  if (myFile) {
 //   Serial.print("Writing to quad_dat.csv...");
    
 // myFile.print("Altitude");
 // myFile.print(", ");
 // myFile.print("Latitude");
 // myFile.print(", ");
 // myFile.println("Longitude");
 
    
    // close the file:
//    myFile.close();
//   Serial.println("done.");
//  } else {
    // if the file didn't open, print an error:
 //   Serial.println("error opening testies.txt");
//  }  
//   }   
  }


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


float compassheading(){

  sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_event_t bmp_event;
  sensors_vec_t   orientation;

  
  mag.getEvent(&mag_event);
  if (dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation))
  {
    
  }

return(orientation.heading);
  
  }

float printroll(){
sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_event_t bmp_event;
  sensors_vec_t   orientation;

  
  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
  {
  return(orientation.roll);
  }
}



float printpitch(){
sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_event_t bmp_event;
  sensors_vec_t   orientation;

  
  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
  {
  return(orientation.pitch);
  }
}

float disttotarget(){

    //1° of latitude = about 69.11 miles

//1° of longitude = about 69.11 miles along the equator. But all of the longitudes
//come together at the poles, so the farther you are from the equator, the fewer
//miles there are in one degree.
float latcon=69.172;
float x_1=gpslat(gps)*latcon;//first fix lat
float y_1=(gpslon(gps)*(latcon));//first fix lon 
float gl=targetlat;
float x_2=0;//target lat fruit stand
float y_2=0;//target lon fruit stand

if(gl==0.00){
  
x_2=19.4956*69.172;//target lat fruit stand
y_2=(-154.8236)*69.172;//target lon fruit stand
}else{ 
x_2=targetlat*latcon;//target lat fruit stand
y_2=-1*targetlon*69.172;//target lon fruit stand
}

//Serial.print("getlat is given by:   ");
//Serial.println(gl);


//Serial.print("x 2 is given by:   ");
//Serial.println(x_2/latcon,5);
float distancefixtarg=sqrt(sq(x_2-x_1)+sq(y_2-y_1));//*69.11 is the conversion to miles
  return(distancefixtarg);
  }

float angletotarget(){

    //1° of latitude = about 69.11 miles

//1° of longitude = about 69.11 miles along the equator. But all of the longitudes
//come together at the poles, so the farther you are from the equator, the fewer
//miles there are in one degree.
float latcon=69.172;
//wcc 21.35635 -157.76483
float x_1=gpslat(gps)*latcon;//first fix lat
float y_1=(gpslon(gps)*(latcon));//first fix lon 
float gl=targetlat;
float x_2=0;//target lat fruit stand
float y_2=0;//target lon fruit stand


if(gl==0.00){
x_2=19.4956*69.172;//target lat fruit stand
y_2=(-154.8236)*69.172;//target lon fruit stand
}else{ 
x_2=targetlat*latcon;//target lat fruit stand
y_2=-1*targetlon*69.172;//target lon fruit stand
}
float x_3=x_1+1;//third point lat 
float y_3=y_1;//third point lon

 //   a^2 = b^2 + c^2 - 2bc\cos\alpha\,
//black rock gps  N 40.9119 W 119.1031
float distancefixtarg=sqrt(sq(x_2-x_1)+sq(y_2-y_1));//*69.11 is the conversion to miles
float distancethirdpointtarg=sqrt(sq(x_3-x_2)+sq(y_3-y_2));//*69.11 is the conversion to miles    
float distancethirdpointfix=sqrt(sq(x_3-x_1)+sq(y_3-y_1));//*69.11 is the conversion to miles    
float asqrd=sq(distancefixtarg);
float bsqrd=sq(distancethirdpointtarg);
float csqrd=sq(distancethirdpointfix);
float alpha=acos((asqrd+csqrd-bsqrd)/(2*distancethirdpointtarg*distancethirdpointfix));//alpha is the angle by which I must rotate given my 
//location with respect to 2 other coordinates this assumes the body axis "forward" being inline with the third coordinate
//I will have to find my heading relative to north and subtract the heading of the third coordinate with respect to north,
//the angle Im left with the angular separation between my heading and the heading toward my third coordinate. This then is
//added to alpha and we should get the angle by which we must rotate in order to be heading toward the target.


//   a^2 = b^2 + c^2 - 2bc\cos\alpha\,
//black rock gps  N 40.9119 W 119.1031

  return(alpha);
  }


void roll_pitch_heading(){
  sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_event_t bmp_event;
  sensors_vec_t   orientation;

  /* Calculate pitch and roll from the raw accelerometer data */
  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
  {
    /* 'orientation' should have valid .roll and .pitch fields */
    
//    Serial.print(F("Roll: "));
//    Serial.print(orientation.roll);
//    Serial.print(F("; "));
//    Serial.print(F("Pitch: "));
//    Serial.print(orientation.pitch);
//    Serial.print(F("; "));
  }
  
  /* Calculate the heading using the magnetometer */
  mag.getEvent(&mag_event);
  if (dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation))
  {
    /* 'orientation' should have valid .heading data now */
    //Serial.print(F("Heading: "));
    //Serial.print(orientation.heading);
    //Serial.print(F("; "));
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
    Serial.print(F(" C "));
  }
}

void gpers(){
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
  
//  myFile = SD.open("navsdtest.csv", FILE_WRITE);

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



float gpslat(TinyGPS &gps) {
  float flat, flon, falt;
  
  unsigned long date, time;
  unsigned long age;
  unsigned long fix_age;
  
  //gps.f_altitude(&falt);    
  gps.f_get_position(&flat, &flon, &age);
 gps.get_datetime(&date, &time, &age);

return(flat);
  }
  

float gpslon(TinyGPS &gps) {
  float flat, flon, falt;
  
  unsigned long date, time;
  unsigned long age;
  unsigned long fix_age;
  
  //gps.f_altitude(&falt);    
  gps.f_get_position(&flat, &flon, &age);
 gps.get_datetime(&date, &time, &age);

return(flon);
  }





void distblink(){
  String stringOne = "";
float disttarg=disttotarget();
stringOne = String(disttarg*5280, 3);
int len=stringOne.length();
for (int i=0;i <= len; i++){
  Serial.println(stringOne.charAt(i));
  
  for(int m=0;m<=i;m++){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(300);              // wait for a second
  }
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);              // wait for a second
  
  }

  }

  
float ontarget(){
 float mylat=gpslat(gps);
  Serial.print("lattitude is: ");
  Serial.print(mylat,5);
float mylon=gpslon(gps);
  Serial.print(" lattitude is: ");
  Serial.println(mylon,5);

  //Serial.println(F(""));
  
  
  float disttarg=disttotarget();
  Serial.println(F("on target"));
  Serial.println(F("travel forward"));
  Serial.print(disttarg*5280);//distance to target in miles converted to feet 1 mile = 5280 feet
  Serial.println(F("feet"));
  
  }

void rotateright(){
  
  data_header();
  roll_pitch_heading();
  float myroll=printroll();
  Serial.print("roll: ");
  
  Serial.print(myroll);
  float mypitch=printpitch();
  Serial.print(" pitch: ");
  
  Serial.print(mypitch);


  
  
float myhead=compassheading();
  Serial.print(" heading: ");
  Serial.print(myhead);
 float mylat=gpslat(gps);
  Serial.print(" lattitude is: ");
  Serial.print(mylat,5);
float mylon=gpslon(gps);
  Serial.print(" lattitude is: ");
  Serial.println(mylon,5);

  //Serial.println(F(""));
  

  float angletarg=angletotarget();

  Serial.print("Rotate to: ");
  Serial.print((180/(22/7))*angletarg-myhead,5);
  Serial.println(" degrees to be facing the target");
  
  float disttarg=disttotarget();
 
  Serial.print(F("rotate right "));
  Serial.print(disttarg*5280);//distance to target in miles converted to feet 1 mile = 5280 feet
  Serial.println(F("feet"));
  
  }

void rotateleft(){
    data_header();
    roll_pitch_heading();
  float myroll=printroll();
  Serial.print("roll: ");
  
  Serial.print(myroll);
  float mypitch=printpitch();
  Serial.print(" pitch: ");
  
  Serial.print(mypitch);


float myhead=compassheading();
  Serial.print(" heading: ");
  Serial.print(myhead);
 float mylat=gpslat(gps);
  Serial.print(" lattitude is: ");
  Serial.print(mylat,5);
float mylon=gpslon(gps);
  Serial.print(" lattitude is: ");
  Serial.println(mylon,5);

  //Serial.println(F(""));
  

  float angletarg=angletotarget();

  Serial.print("Rotate to: ");
  Serial.print((180/(22/7))*angletarg-myhead,5);
  Serial.println(" degrees to be facing the target");
  
  
  float disttarg=disttotarget();
 
  Serial.print(F("rotate left"));
  Serial.print(disttarg*5280);//distance to target in miles converted to feet 1 mile = 5280 feet
  Serial.println(F("feet"));
  distblink();
  }
  
  
