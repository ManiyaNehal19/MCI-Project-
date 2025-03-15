

// Function to move both motors forward at 80% speed
void moveForward()  {
    Serial.println("Moving Forward at 80% speed");

    // Left Motor Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 205);  // 80% Duty Cycle

    // Right Motor Forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 205);  // 80% Duty Cycle
}


void turnLeft(long speed_cmPerMicrosec)  {
    Serial.println("Turning Left");

    // Left Motor
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 205);  // 80% Duty Cycle

    // Right Motor
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 51);  // 20% Duty Cycle

    delayMicroseconds(max_turn_distance_cm/speed_cmPerMicrosec);

    moveForward();
    //PID_stable();
}


void turnRight(long speed_cmPerMicrosec)  {
    Serial.println("Turning Right");

    // Left Motor
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 51);  // 20% Duty Cycle

    // Right Motor
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 205);  // 80% Duty Cycle

    delayMicroseconds(max_turn_distance_cm/speed_cmPerMicrosec);

    moveForward();
    //PID_stable();
}



void stop_car()  {
    Serial.println("Stopped");

    // Left Motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);

    // Right Motor
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enB, 0);
}
