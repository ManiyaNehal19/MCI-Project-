//////////////////////// Car Motion ////////////////////////////


int max_right_speed = 80;
int max_left_speed = 80;

int min_right_speed = 0;
int min_left_speed = 0;




// Function to move both motors forward at 80% speed
void moveForward()  {

    // Left Motor Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, max_left_speed);  // 80% Duty Cycle

    // Right Motor Forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, max_right_speed);  // 80% Duty Cycle
}


void turn90Left(long speed_cmPerMicrosec)  {

    // Left Motor
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, max_left_speed);  // 80% Duty Cycle

    // Right Motor
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, min_right_speed);  // 20% Duty Cycle

    //delayMicroseconds(max_turn_distance_cm/speed_cmPerMicrosec);
    delay(350);

    moveForward();
    //PID_stable();
}


void turn90Right(long speed_cmPerMicrosec)  {

    // Left Motor
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, min_left_speed);  // 20% Duty Cycle

    // Right Motor
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, max_right_speed);  // 80% Duty Cycle

    //delayMicroseconds(max_turn_distance_cm/speed_cmPerMicrosec);
    delay(350);

    moveForward();
    //PID_stable();
}



void turnLeft(long delayms)  {
  
    // Left Motor
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, max_left_speed);  // 80% Duty Cycle

    // Right Motor
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, min_right_speed);  // 20% Duty Cycle

    //delayMicroseconds(max_turn_distance_cm/speed_cmPerMicrosec);
    delay(delayms);

    moveForward();
    //PID_stable();
}


void turnRight(long delayms)  {

    // Left Motor
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, min_left_speed);  // 20% Duty Cycle

    // Right Motor
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, max_right_speed);  // 80% Duty Cycle

    //delayMicroseconds(max_turn_distance_cm/speed_cmPerMicrosec);
    delay(delayms);

    moveForward();
    //PID_stable();
}


void stop_car()  {

    // Left Motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);

    // Right Motor
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enB, 0);
}
