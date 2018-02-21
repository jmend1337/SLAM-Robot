void liftoff(){
    sonar();
    digitalWrite(13,HIGH); //turns on Teensy led
    
    while (distance2 > 6)
    sonar();
    
    digitalWrite(13, LOW);
    delay(1000);
}

void remote(){
  
    {
      if(Serial1.available() > 0)  // Send data only when you receive data:
      {
        data = Serial1.read();      //Read the incoming data and store it into variable data
        Serial1.print(data);        //Print Value inside data in Serial monitor
        Serial1.print("\n");        //New line 
        if(data == 'w'){            //Checks whether value of data is equal to 1 
          forward();
        }
        if(data == 'a'){
          turnccw();
        }
        if(data == 'd'){
          turncw();
        }
        if(data == 's'){
          halt();
        }
      }                            
     
    }
}

