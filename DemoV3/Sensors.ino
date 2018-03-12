void encoder() {
  n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == HIGH) {
      encoder0Pos--;
    }
    else {
      encoder0Pos++;
    }
  }
}

void sonar() {
  // put your main code here, to run repeatedly:
  //////////////////////////////////////////////

  // This is for the left sensor
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  // we are initializing the sonar sensor

  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  // we are sending a pulse of 10 uS of sound to measure distance

  duration1 = pulseIn(echo1, HIGH);
  //pulseIn is reading the time it takes for the signal to bounce off of the object and records the distance
  distance1 = duration1 / 58;
  //list[1]=distance1;

  if (distance1 <= 400) {
    PD1 = distance1;
    //list[1]=PD1;
  }

  //////////////////////////////////////////////
  // This is for the front sensor
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);

  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  duration2 = pulseIn(echo2, HIGH);
  distance2 = duration2 / 58;
  //list[2]=distance2;

  if (distance2 <= 400) {
    PD2 = distance2;
    //list[2]=PD2;
  }

  //////////////////////////////////////////////
  // This is for the right sensor
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);

  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);

  duration3 = pulseIn(echo3, HIGH);
  distance3 = duration3 / 58;
  //list[3]=distance3;

  if (distance3 <= 400) {
    PD3 = distance3;
    //list[3]=distance3;
  }

  //divide by 58 to convert to cm
  //divide by 148 for inches

  /////////////////////////////////////////////
  // filter out values
  if (distance1 <= 400 ) {
    // the sonar sensor has a max distance reading of 400 cm
    //Serial.print(" L ");
    //Serial.print(distance1); // this is the left sonar sensor
    //Serial.print(" , ");
    list[0] = distance1;
  }
  else if (distance1 > 400) {
    //Serial.print(" L ");
    //Serial.print(PD1);
    //Serial.print(" , ");
    list[0] = PD1;
  }

  if (distance2 <= 400 ) {
    // the sonar sensor has a max distance reading of 400 cm
    //Serial.print(" F ");
    //Serial.print(distance2);  //this is the front sonar sensor
    //Serial.print(" , ");
    list[1] = distance2;
  }

  else if (distance2 > 400) {
    //Serial.print(" F ");
    //Serial.print(PD2);
    //Serial.print(" , ");
    list[1] = PD2;
  }

  if (distance3 <= 400 ) {
    //Serial.print(" R ");
    //Serial.print(distance3); // this is the right sonar sensor
    //Serial.print(" , ");
    list[2] = distance3;
  }
  else if (distance3 > 400) {
    //Serial.print(" R ");
    //Serial.print(PD3);
    //Serial.print(" , ");
    list[2] = PD3;
  }
  //  Serial.print(x);
  //  Serial.print(" , ");
  //  Serial.println(y);
  //  Serial.println();
  //  delay(200);

}
