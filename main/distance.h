///////////////////// Calculate Distance ////////////////////////////



long microsecondsToCentimeters(long microseconds)
{
  //Gives the distance equivalent to time taken by pulse, speed of sound 340m/s
  //long distance = 0.034 * microseconds;
  return microseconds / 29 / 2;
}


long getDistance(int trig, int echo) {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    long duration = pulseIn(echo, HIGH);
    return duration / 29 / 2;
}


//////////////////////////////////

long get_front_distance()
{
  return getDistance(trigF, echoF);
}

long get_left_distance()
{
  return getDistance(trigL, echoL);
}


long get_right_distance()
{
  return getDistance(trigR, echoR);
}

long get_speed_cmPerMicrosec()
{
  long initial_distance = get_front_distance();
  delay(200);
  return (get_front_distance() - initial_distance)/200;
}

void checkSideDistances(long left_distance_cm,long right_distance_cm) {
    if (left_distance_cm < 7) {
        light_red();
        light_left_on();
        stop_car();
       delay(100);
        turnRight(90);
        turnLeft(35);
        moveForward();
        return;
    }

    if (right_distance_cm <7) {
        light_red();
        light_right_on();
        stop_car();
        delay(100);
        turnLeft(90);
        turnRight(35 );
        moveForward();
        return;
    }
}
