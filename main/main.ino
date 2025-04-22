#include "PINS_CONSTANTS.h"  // Every Needed Constants
#include "led.h"           // Light Connection
#include "movement.h"     // Motion library for movements
#include "distance.h"      // Measure Distances through sensors
#include "buzzer.h"

#include <Wire.h>

 



/////////////////////// Variables //////////////////////////

long front_distance_cm = 0;
long left_distance_cm = 0;
long right_distance_cm = 0;
long speed = 0;
int stopDetect=0;     //For different color detection 
char received;  
bool start = true;
///////////////////////  Main Code  ////////////////////////

void setup() {

    //Initializing the I2C Communication below
    Wire.begin(); // join i2c bus (address optional for master)

  
    Serial.begin(9600); // Serial for debugging


    pinMode(BUZZER_PIN, OUTPUT);

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
    pinMode(rightLED, OUTPUT);
    pinMode(leftLED, OUTPUT);
    
    // Move forward at 50% speed
    //music();
    //digitalWrite(BUZZER_PIN, LOW);

    light_right_off();
    light_left_off();
        
    stop_car();
    light_white();
    delay(2000);
    

    //PID_stable();
}
void loop() {

    
    

    // Bluetooth string receiving logic
    if (Serial.available() > 0) {
        char input = Serial.read();   // read entire string sent
        //input.trim();                         // remove \n or \r characters

        Serial.println(input); // debug

        if (input == '2') {
            start = true;
            Serial.println("Car start via Bluetooth");
           
        }
        if (input == '3') {
           
            start = false;
            Serial.println("Car stopped via Bluetooth");
           
        }
    }
    if(start == false){
       stop_car();
       light_green(); // maybe show green when stopped
      }

    // If "stop" wasn't received, continue normal logic
    else if(start){
        // Read sensor values
        front_distance_cm = get_front_distance();
        left_distance_cm = get_left_distance();
        right_distance_cm = get_right_distance();
        Serial.print("Front Distance: ");
        Serial.println(front_distance_cm);
        
        Serial.print("Left Distance: ");
        Serial.println(left_distance_cm);
  
        Serial.print("Right Distance: ");
        Serial.println(right_distance_cm);
        moveForward();
        if (front_distance_cm < 28) {
            light_red();
            stop_car();
            delay(300);
            
            if (left_distance_cm >20) {
                light_left_on();
                turnLeft(482);
                
            }
//            } else if (right_distance_cm > 30) {
//                light_right_on();
//                turnRight(470);
//            }
            light_right_off();
            light_left_off();
            
        } else{
          checkSideDistances(left_distance_cm, right_distance_cm);
    }
     light_blue();
    }
}
