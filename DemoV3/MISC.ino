void SerPrint() {
  //print out the stored values to serial
  for (i = 0; i < 5; i++) {
    Serial.print(list[i]);
    if (i < 4) {
      Serial.print(" , ");
    }
    else if (i == 4) {
      Serial.println();
    }
  }
}

void liftoff() {
  sonar();
  digitalWrite(13, HIGH); //turns on Teensy led

  while (distance2 > 4)
    sonar();

  digitalWrite(13, LOW);
  delay(1000);
}
