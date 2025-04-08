#include "PINS_CONSTANTS.h"  // Every Needed Constants
#include "led.h"           // Light Connection
#include "movement.h"     // Motion library for movements
#include "distance.h"      // Measure Distances through sensors

#include <Wire.h>

 



/////////////////////// Variables //////////////////////////

long front_distance_cm = 0;
long left_distance_cm = 0;
long right_distance_cm = 0;
long speed = 0;
int stopDetect=0;     //For different color detection 
char received;  
bool flagOff = false;
bool flagOn = false;
///////////////////////  Main Code  ////////////////////////

void setup() {

    //Initializing the I2C Communication below
    Wire.begin(); // join i2c bus (address optional for master)

  
    Serial.begin(9600); // Serial for debugging

    // Set motor control pins as OUTPUT
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    pinMode(trigF, OUTPUT);
    pinMode(echoF, INPUT);
    
    pinMode(trigL, OUTPUT);
    pinMode(echoL, INPUT);
    
    pinMode(trigR, OUTPUT);
    pinMode(echoR, INPUT);

    // Set UltraSonic Pins
    pinMode(trigF, OUTPUT);
    pinMode(echoF, INPUT);
    pinMode(trigL, OUTPUT);
    pinMode(echoL, INPUT);
    pinMode(trigR, OUTPUT);
    pinMode(echoR, INPUT);


    // Set LED pins as output
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    
    // Move forward at 50% speed
        
    stop_car();
    light_white();
    delay(2000);

    //PID_stable();
}
void loop() {
    // Read sensor values
    front_distance_cm = get_front_distance();
    left_distance_cm = get_left_distance();
    right_distance_cm = get_right_distance();

    // Bluetooth string receiving logic
    if (Serial.available() > 0) {
        String input = Serial.readString();   // read entire string sent
        input.trim();                         // remove \n or \r characters

        Serial.println("Received: " + input); // debug

        if (input == "stop") {
            flagOff = true;
            flagOn = false;
            Serial.println("Car stopped via Bluetooth");
           
        }
        if (input == "start") {
           
            flagOff = false;
            flagOn = true;
            Serial.println("Car stopped via Bluetooth");
           
        }
    }
    if(flagOff){
       stop_car();
       light_green(); // maybe show green when stopped
      }

    // If "stop" wasn't received, continue normal logic
    else if(flagOn){
        moveForward();
        if (front_distance_cm < 40) {
            light_red();
            stop_car();
            delay(200);
            if (left_distance_cm >40) {
                turnLeft(430);
            } else if (right_distance_cm > 40) {
                turnRight(430);
            }
        } else {
            if (left_distance_cm < 12) {
                light_red();
                stop_car();
                delay(200);
                turnRight(85);
            } else if (right_distance_cm < 12) {
                light_red();
                stop_car();
                delay(200);
                turnLeft(85);
            }
        }

        light_blue();
    }
}



