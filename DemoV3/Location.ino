void UpdateCompassRightTurn() {
  if (compass == 10) {
    compass = 20;
  }
  else if (compass == 20) {
    compass = 30;
  }
  else if (compass == 30) {
    compass = 40;
  }
  else if (compass == 40) {
    compass = 10;
  }
}

void UpdateCompassLeftTurn() {
  if (compass == 10) {
    compass = 40;
  }
  else if (compass == 20) {
    compass = 10;
  }
  else if (compass == 30) {
    compass = 20;
  }
  else if (compass == 40) {
    compass = 10;
  }
}


void pos() {
  if (compass == 10) {
    //then it was going north and only y was increasing
    y = y + encoder0Pos * 0.011;
    list[4] = y;
  }
  else if (compass == 20) {
    //then it was going east and only x was increasing
    x = x + encoder0Pos * 0.011;
    list[3] = x;
  }
  else if (compass == 30) {
    //then it was going south and only y was decreasing
    y = y - encoder0Pos * 0.011;
    list[4] = y;
  }
  else if (compass == 40) {
    //then it was going west and only x was decreasing
    x = x - encoder0Pos * 0.011;
    list[3] = x;
  }
}

