//motor A (Left Motor) - TivaC and L298N connections
int enA = 26;   // Enable pin (PD3) for Left Motor (PWM control)
int in1 = 12;   // IN1 pin (PA3) for Left Motor direction
int in2 = 11;   // IN2 pin (PA2) for Left Motor direction

//motor B (Right Motor) - TivaC and L298N connections
int enB = 25;   // Enable pin (PD2) for Right Motor (PWM control)
int in3 = 13;   // IN3 pin (PA4) for Right Motor direction
int in4 = 8;    // IN4 pin (PA5) for Right Motor direction


const int echo = 14, Trig = 34;      //Pin connections for HC-SR04 ultrasonic, Echo->PB6, Trig->PC7


long front_distance_cm = 0;


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
}

void loop(){
  moveForward();
   delay(1000);
  moveLeftSlowly();
  delay(200);
}

// Function to move both motors forward at 50% speed
void moveForward()  {
    Serial.println("Moving Forward at 50% speed");

    // Left Motor Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 128);  // 50% Duty Cycle

    // Right Motor Forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 128);  // 50% Duty Cycle
}


void moveLeftSlowly()  {
    Serial.println("Moving Forward at 50% speed");

    // Left Motor Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 102);  // 40% Duty Cycle

    // Right Motor Forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 26);  // 10% Duty Cycle
}


void moveRightSlowly()  {
    Serial.println("Moving Forward at 50% speed");

    // Left Motor Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 26);  // 10% Duty Cycle

    // Right Motor Forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 102);  // 40% Duty Cycle
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






void Update_Front_Distance()
{
  //Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  long duration = pulseIn(echo, HIGH);   // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
  front_distance_cm  = microsecondsToCentimeters(duration); // convert the time into a distance, refer to function below
  
  //Sending through serial port to print on Monitor
  Serial.print("Distance=");
  Serial.print("\t");
  Serial.print(front_distance_cm); 
  Serial.print(" cm");
  Serial.print("\n");
}

////////////////////////////////////////////////////
long microsecondsToCentimeters(long microseconds)
{
  //Gives the distance equivalent to time taken by pulse, speed of sound 340m/s
  long distance = 0.034 * microseconds;
  return distance / 2;
}
