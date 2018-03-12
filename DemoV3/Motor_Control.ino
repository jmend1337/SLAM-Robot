void forward(int leftSpeed, int rightSpeed) {
  // function to move the robot forward and allows for acceleration of the wheels

  analogWrite(ENA, rightSpeed);
  // (motorpowerENA controls the power through PWM ie: quarter, half, fullpower, and is used to turn the motor off and on)
  // (rightSpeed is the speed for the right motor that is used in the PID control)

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Switch Polarity of 1 side of the motor

  analogWrite(ENB, leftSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Note: do not have both motor logics the same, this will damage the motor
  // Note: MotorPowerENA
  // This combination turns this wheel cw
}


void forward() {
  // function to move the robot forward with a default speed of the motor
  // so the wheels are going at a constant velocity ie: no acceleration

  analogWrite(ENA, 100);
  //digitalWrite(ENA, HIGH);
  // (ENA controls the power through PWM ie: quarter, half, fullpower, and is used to turn the motor off and on)
  // (defaultMotorSpeed is a default speed given to the motors)

  digitalWrite(IN1, LOW); // Switch Polarity of 1 side of the motor
  digitalWrite(IN2, HIGH); // Switch Polarity of 1 side of the motor

  analogWrite(ENB, defaultMotorSpeed);
  //digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Note: do not have both motor logics the same, this will damage the motor
  // Note: ENA
  // This combination turns this wheel cw
}


void turnccw() {

  analogWrite(ENA, defaultMotorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // turns ccw

  analogWrite(ENB, defaultMotorSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // turns cw
}

void turncw() {

  analogWrite(ENA, defaultMotorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // turns cw

  analogWrite(ENB, defaultMotorSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // turns cw
}

void backward() {

  analogWrite(ENA, defaultMotorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // turns ccw

  analogWrite(ENB, defaultMotorSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // turns ccw
}

void halt() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

}


