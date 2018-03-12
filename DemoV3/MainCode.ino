void explore() {
  while (j = 2 && encoder0Pos < 451) {
    //count up encoder0Pos until it reaches 450 or j !=2
    //j !=2 if the front limit is reached
    forward();
    sonar(); //run sonar to check for a obstacle in front of the robot

    //check to see if you will run into a wall
    if (distance2 <= frontLimit) {
      j = 3; //this is to stop the while loop
      halt();
      delay(500);
      // save the last position of the encoder before you start to turn and get error
      encoder0LastPos = encoder0Pos;
      
      //check if there is an opening to turn right
      if (distance1 <= distance3) {
        turncw(); //turn to the right
        UpdateCompassRightTurn();
        delay(500);
      }
      //if not turn left
      else {
        turnccw(); //turn to the left
        UpdateCompassLeftTurn();
        delay(500);
      }
      //I still need to program statements to do a 180 if it can't turn left or right
      
      // reset the encoder0Pos to what it was before turning
      encoder0Pos = encoder0LastPos;
    }

  }

  //update the position of the robot
  pos();

  //print stored values to serial
  SerPrint();

  //reset the encoders
  //reset the logic control
  encoder0Pos = 0;
  j = 2;
}

