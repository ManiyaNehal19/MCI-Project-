//////////////////  Constants //////////////////


// LED Pins
int redLED = 30;
int greenLED = 39;
int blueLED = 40;


//motor A (Left Motor) - TivaC and L298N connections
int enA = 26;   // Enable pin (PD3) for Left Motor (PWM control)
int in1 = 12;   // IN1 pin (PA3) for Left Motor direction
int in2 = 11;   // IN2 pin (PA2) for Left Motor direction

//motor B (Right Motor) - TivaC and L298N connections
int enB = 25;   // Enable pin (PD2) for Right Motor (PWM control)
int in3 = 8;   // IN3 pin (PA4) for Right Motor direction
int in4 = 13;    // IN4 pin (PA5) for Right Motor direction

//TivaC and Front UltraSonic connections
const int echoF = 9, trigF = 10;      //Pin connections for HC-SR04 ultrasonic, Echo->PB6, Trig->PC7

//TivaC and Left UltraSonic connections
const int echoL = 27, trigL = 28;      //Pin connections for HC-SR04 ultrasonic, Echo->PD1, Trig->PB1

//TivaC and Right UltraSonic connections
const int echoR = 6, trigR = 5;      //Pin connections for HC-SR04 ultrasonic, Echo->PD0, Trig->PB0
