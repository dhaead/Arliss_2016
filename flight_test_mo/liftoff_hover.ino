
void arm_esc(){
myservo1.attach(6);  // attaches the motor on pin 6 to the servo object
myservo2.attach(10);  // attaches the servo on pin 10 to the servo object
myservo3.attach(9);  // attaches the servo on pin 11 to the servo object
myservo4.attach(5);  // attaches the servo on pin 5 to the servo object


 //for (throttle = 0; throttle <= 180; throttle += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree

 throttle=180;
   
    myservo1.write(throttle);              // tell servo to go to throttleition in variable 'throttle'
    myservo2.write(throttle);              // tell servo to go to throttleition in variable 'throttle'
    myservo3.write(throttle);              // tell servo to go to throttleition in variable 'throttle'
    myservo4.write(throttle);              // tell servo to go to throttleition in variable 'throttle'
    
    delay(1000);
throttle=0;
    myservo1.write(throttle);              
    myservo2.write(throttle);              
    myservo3.write(throttle);              
    myservo4.write(throttle);              
  
  }

void flight() {  
/*
motor1power = throttle - rolloffset - pitchoffset + yawoffset;
 
motor2power = throttle + rolloffset + pitchoffset - yawoffset;
 
motor3power = throttle + rolloffset - pitchoffset + yawoffset;
 
motor4power = throttle - rolloffset + pitchoffset - yawoffset;
*/
motor1power = throttle + offset1 - rolloffset + pitchoffset + yawoffset;
motor4power = throttle - rolloffset - pitchoffset - yawoffset;

motor2power = throttle + offset2 + rolloffset - pitchoffset + yawoffset;
motor3power = throttle + offset3 + rolloffset + pitchoffset - yawoffset;

    
    myservo1.write(motor1power);              // tell servo to go to throttleition in variable 'throttle'
    myservo4.write(motor4power);              // tell servo to go to throttleition in variable 'throttle'
    myservo2.write(motor2power);              // tell servo to go to throttleition in variable 'throttle'
    myservo3.write(motor3power);              // tell servo to go to throttleition in variable 'throttle'
    
    }
void powerdown(){
      motor1power = 0;
    motor2power = 0;
    motor3power = 0;
    motor4power = 0;
    myservo1.write(motor1power);              // tell servo to throttle in variable 'throttle'
    myservo2.write(motor2power);              // tell servo to throttle in variable 'throttle'
    myservo3.write(motor3power);              // tell servo to throttle in variable 'throttle'
    myservo4.write(motor4power);              // tell servo to throttle in variable 'throttle'

  }


