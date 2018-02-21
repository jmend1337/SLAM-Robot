void search(){
  sonar(); //run the sonar and recieves distance of objects 
 
  while (distance2 >= frontLimit){
    forward(); // makes the robot go forward
    delay(1000);
    halt();
    delay(200);
    sonar();
    //encoder(); //encoder0Pos is counting up
    if (compass==10){
    //then it was going north and only y was increasing
    y = y + 1; // this is to get it into cm
    list[5]=y;
  }
  else if (compass==20){
    //then it was going east and only x was increasing
    x = x + 1;
    list[4]=x;
  }
  else if (compass==30){
    //then it was going south and only y was decreasing
    y = y - 1;
    list[5]=x;
  }
  else if (compass==40){
    //then it was going west and only x was decreasing
    x = x - 1;
    list[4]=x;
  }
  }
  halt();
  delay(500);
  
  if (distance1 <= distance3){
    turncw(); //turn to the right
    if (compass == 10){
      compass = 20;
    }
    else if (compass == 20){
      compass = 30;
    }
    else if (compass == 30){
      compass = 40;
    }
    else if (compass == 40){
      compass = 10;
    }
    delay(500);
  }
  else
  {
    turnccw(); //turn to the left
    if (compass == 10){
      compass = 40;
    }
    else if (compass == 20){
      compass = 10;
    }
    else if (compass == 30){
      compass = 20;
    }
    else if (compass == 40){
      compass = 10;
    }
    delay(500);
  }
   
 }


 



