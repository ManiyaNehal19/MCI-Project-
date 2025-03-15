#include "PINS_CONSTANTS.h"
#include "distance.h"
#include "movement.h"



long front_distance_cm = 0;
long left_distance_cm = 0;
long right_distance_cm = 0;
long speed = 0;

void setup() {
    Serial.begin(115200); // Serial for debugging

    // Set motor control pins as OUTPUT
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // Move forward at 50% speed
    moveForward();

    //PID_stable();
}

void loop(){
  speed = get_speed_cmPerMicrosec();
  
  front_distance_cm = get_front_distance();
  left_distance_cm = get_left_distance();
  right_distance_cm = get_right_distance();

  if (front_distance_cm < 25){
    if (left_distance_cm > right_distance_cm) turnLeft(speed);
    else if (left_distance_cm < right_distance_cm) turnRight(speed);
  }

}
