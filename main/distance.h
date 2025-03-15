long microsecondsToCentimeters(long microseconds)
{
  //Gives the distance equivalent to time taken by pulse, speed of sound 340m/s
  long distance = 0.034 * microseconds;
  return distance / 2;
}


//////////////////////////////////

long get_front_distance()
{
  //Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
  digitalWrite(trigF, LOW);
  delayMicroseconds(2);
  digitalWrite(trigF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigF, LOW);

  long duration = pulseIn(echoF, HIGH);   // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
  return microsecondsToCentimeters(duration); // convert the time into a distance, refer to function below
}

long get_left_distance()
{
  //Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
  digitalWrite(trigL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigL, LOW);

  long duration = pulseIn(echoL, HIGH);   // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
  return microsecondsToCentimeters(duration); // convert the time into a distance, refer to function below
}


long get_right_distance()
{
  //Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
  digitalWrite(trigR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigR, LOW);

  long duration = pulseIn(echoR, HIGH);   // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
  return microsecondsToCentimeters(duration); // convert the time into a distance, refer to function below
}

long get_speed_cmPerMicrosec()
{
  long initial_distance = get_front_distance();
  delayMicroseconds(200);
  return (get_front_distance() - initial_distance)/200;
}

////////////////////////////////////////////////////
