#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
   // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}
int i=0;
int pos=0;
void loop(){
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos); 
  if(pos==0){
    i++;
  }
  if(i==4){
    break;
  }
  if(pos==180){
    pos=0;
  }
  Serial.println(pos);
    delay(15);                      
  }
}
