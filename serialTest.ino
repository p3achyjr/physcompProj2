#include <Event.h>
#include <Timer.h>
#include <Pololu3pi.h>
#include <PololuQTRSensors.h>
#include <OrangutanMotors.h>
#include <OrangutanAnalog.h>
#include <OrangutanLEDs.h>
#include <OrangutanLCD.h>
#include <OrangutanPushbuttons.h>
#include <OrangutanBuzzer.h>

Pololu3pi robot;
OrangutanMotors motors;
Timer t;

int rbtSpeed;
int delayValue;
unsigned char dir;

void setup() {

   robot.init(2000);
  //Serial.begin(9600);
  
}

void loop() {

    rbtSpeed = random(70) + 30;
    dir = random(5);
    delayValue = random(100,400);
    buttonState = digitalRead(buttonPin);
    
    switch(dir)
    {
        case 1:
            // Go forward
            motors.setSpeeds(rbtSpeed, rbtSpeed);
            delay(delayValue);
            break;
        case 2:
            // Go Backward
            motors.setSpeeds(-rbtSpeed, -rbtSpeed);
            delay(delayValue);
            break;
        case 3:
            // Turn left.
            motors.setSpeeds(-rbtSpeed, rbtSpeed);
            delay(delayValue);
            break;
        case 4:
            // Turn right.
            motors.setSpeeds(rbtSpeed, -rbtSpeed);
            delay(delayValue);
            break;           
    }
  
 
}
