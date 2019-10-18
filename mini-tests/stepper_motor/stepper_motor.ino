//Created by Rudy Schlaf after a sketch by Sam Leong
#include <Stepper.h>
#define pin1  8//these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin2  9
#define pin3  10
#define pin4  11

#define delaytime 80   //delay time in ms to control the stepper motor delaytime.
                      //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps
                   

void setup() {
  // initialize the 8 pin as an output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT); 
  pinMode(pin4, OUTPUT);
}

void loop(){
  int numberOfSteps = 48;
  step_OFF();         //turning all coils off
  while(numberOfSteps>0){
    forward();        //going forward
    numberOfSteps -- ;//counting down the number of steps
  }
  delay(2000);
  
  step_OFF();         //turning all coils off
  numberOfSteps = 48;
  while(numberOfSteps>0){
    backward();       //going backward
    numberOfSteps -- ;//counting down the number of steps
  }
  delay(2000);
}
