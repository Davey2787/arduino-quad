#include <Servo.h> 

Servo FL_CCW, FR_CW, BL_CW, BR_CCW; // create servo objects

// My outrunner servos will start to turn at appox 1200 micro seconds
// PWM pulse length
int PWM_pulse = 1150; 

void setup() 
{ 
  Serial.begin(9600);
   FL_CCW.attach(9); // attaches the servo on pin 9 to the servo object
   FR_CW.attach(10);
   BL_CW.attach(11);
   BR_CCW.attach(6);
   delay(1);
   // gives the servos initial starting position 
   // N.B. must use .write() and give position in degrees not
   // .writeMicroseconds() pulse length.
   FL_CCW.write(10); 
   FR_CW.write(10); 
   BL_CW.write(10);
   BR_CCW.write(10);
   delay(5000);
} 

void loop() {
    while(Serial.available() > 0){
        if(Serial.read() =='u'){ // Send 'u' in serial monitor increase
            PWM_pulse += 50;     // speed  
        }
        else{                    // Send any other charactor decrease
            PWM_pulse -= 50;    // speed
        }
        Serial.println(PWM_pulse);
    }
   FL_CCW.writeMicroseconds(PWM_pulse);  // Write pulse length to Servos
   FR_CW.writeMicroseconds(PWM_pulse);  
   BL_CW.writeMicroseconds(PWM_pulse);
   BR_CCW.writeMicroseconds(PWM_pulse); 
} 
