const int echo = 9 , Trig = 10;
long duration,cm;
long distance = 0;

unsigned long LastUpdateMicrosecs = 0;
unsigned long LastUpdateMillisecs = 0;
unsigned long CurrentMicrosecs = 0;
unsigned long MicrosecsSinceLastpdate = 0;
float SecondsSinceLastUpdate = 0;





void setup() {
  Serial.begin(115200);
  pinMode(Trig, OUTPUT);
  pinMode(echo, OUTPUT);
  

}

void loop() {
  UpdateUltraSonic();
  delay(200);
  
}
void UpdateUltraSonic(){
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicrosecond(10);
  digitalWrite(Trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm = microtocenti(duration);
  Serial.print("Distance=");
  Serial.print("\t");
  Serial.print(cm);
  Serial.print("\n");
  
  
  }
 long microtocenti(long microsecond){
  distance = microsecond/29;
  return distance/2;
  }
