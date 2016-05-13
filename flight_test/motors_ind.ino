
void flightleft() {  
/*
motor1power = throttle - rolloffset - pitchoffset + yawoffset;
 
motor2power = throttle + rolloffset + pitchoffset - yawoffset;
 
motor3power = throttle + rolloffset - pitchoffset + yawoffset;
 
motor4power = throttle - rolloffset + pitchoffset - yawoffset;
*/
motor1power = throttle + offset1 - rolloffset + pitchoffset + yawoffset;
motor4power = throttle - rolloffset - pitchoffset - yawoffset;

    
    myservo1.write(motor1power);              // tell servo to go to throttleition in variable 'throttle'
    myservo4.write(motor4power);              // tell servo to go to throttleition in variable 'throttle'
}
void flightright(){
motor2power = throttle + offset2 + rolloffset - pitchoffset + yawoffset;
motor3power = throttle + offset3 + rolloffset + pitchoffset - yawoffset;

    myservo2.write(motor2power);              // tell servo to go to throttleition in variable 'throttle'
    myservo3.write(motor3power);              // tell servo to go to throttleition in variable 'throttle'
    
    }
