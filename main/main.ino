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

    delay(2000);
    stop_car();
    light_white();

    //PID_stable();
}

void loop(){
  
  //speed = get_speed_cmPerMicrosec();
  
  front_distance_cm = get_front_distance();
  left_distance_cm = get_left_distance();
  right_distance_cm = get_right_distance();
  Serial.println(front_distance_cm);
  Serial.println(left_distance_cm);
  Serial.println(right_distance_cm);


  moveForward();

  if (front_distance_cm < 40 && front_distance_cm){
      light_red();
      stop_car();
      delay(200);
      if (left_distance_cm < 20) turnRight(470);
      else turnLeft(470);
  } else {
    if (left_distance_cm < 10){
      light_red();
      stop_car();
      delay(200);
      turnRight(100);
    }
  
    if (right_distance_cm < 10){
      light_red();
      stop_car();
      delay(200);
      turnLeft(100);
    }
  }
  
  

  light_blue();

}



/////////////// Connecting ESP32 ///////////////////////


void sendString(char strData[]){
  Wire.beginTransmission(4);  // transmit to device #2
  Wire.write(strData);      // sends consecutive bytes for each character
  Wire.write(' ');
  Wire.endTransmission();     // stop transmitting
}

void sendInteger(long data){
  char snum[5];
  int dataInt = round(data);
  itoa(dataInt, snum, 10);
  
  Wire.beginTransmission(4);  // transmit to device #2
  Wire.write(snum); // sends six bytes
  Wire.endTransmission();     // stop transmitting
}
