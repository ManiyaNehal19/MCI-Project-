///////////////// LEDS /////////////////////////
void light_blue(){
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, HIGH);
}

void light_green(){
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, LOW);
}

void light_red(){
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
  digitalWrite(blueLED, LOW);
}

void light_white(){
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, HIGH);
  digitalWrite(blueLED, HIGH);
}
