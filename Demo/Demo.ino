float duration1; //Variable used in the left sonar
float distance1; //Variable used in the left sonar
float PD1;       //This is the previous Distance value

float duration2; //Variable used in the front sonar 
float distance2; //Variable used in the front sonar
float PD2;

float duration3; //Variable used in the right sonar
float distance3; //Variable used in the right sonar
float PD3;

int ENA = 23;   //Enable pin to turn on Robot's RIGHT motor and to control its strength
int ENB = 22;   //Enable pin to turn on Robot's LEFT motor and to control its strength
int IN1 = 21;   //Binary logic to control the Robot's RIGHT Motor's direction
int IN2 = 20;   //Binary logic to control the Robot's RIGHT Motor's direction
int IN3 = 19;   //Binary logic to control the Robot's LEFT Motor's direction
int IN4 = 18;   //Binary logic to control the Robot's LEFT Motor's direction

int led = 13;   //Pin to turn the led on the teensy3.2 on or off 

int IR = 17; // Sensor to detect a large anount of IR with a built in filter
int val =0; // set the value to a low value for the math for the IR sensor data
int FlameValue = 16; //Variable to understand if there is a flame infront of it
                
int echo2 = 14;  //Variable to collect the distace data in the sonar for the front sensor
int trig2 = 15;  //Variable to trigger the sonar to send a pulse of sound for the front sensor

int echo1 = 11;  //Variable to collect the distace data in the sonar for the left sensor
int trig1 = 12;  //Variable to trigger the sonar to send a pulse of sound for the left sensor

int echo3 = 10;  //Variable to collect the distace data in the sonar for the right sensor
int trig3 = 9;  //Variable to trigger the sonar to send a pulse of sound for the right sensor

int encLeftB = 8;   //Variable for reading the encoder ticks Left motor
int encLeftA = 7;   //Variable for reading the encoder ticks Left motor
int encRightB = 6;  //Variable for reading the encoder ticks Right motor
int encRightA = 5;  //Variable for reading the encoder ticks Right motor

int encoder0PinA = 7;
int encoder0PinB = 8;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n=LOW;

unsigned int encLeftBReading = 0;
unsigned int encLeftAReading = 0;
unsigned int encRightBReading = 0;
unsigned int encRightAReading = 0;



float frontLimit = 6;


int defaultMotorSpeed = 210;   //Controls how much power is being sent to the motors. The scale is from 0-255;

//unsigned long Time = 0;
//unsigned long prevTime = 0;

//unsigned int oldDiff = 0;

char data = 0;                //Variable for storing received data

//char compass= 'N';
int compass =10;
//10 north
//20 east
//30 south
//40 west
long previousMillis =0;
long t = 2000;
int i;

float list[5]; // we will print this list
float x=0;
float y=0;
float walked;
void setup() {
  
  // put your setup code here, to run once:

  pinMode(IR,INPUT);
  pinMode(echo2,INPUT); 
  pinMode(trig2, OUTPUT);

  pinMode(echo1,INPUT); 
  pinMode(trig1, OUTPUT);

  pinMode(echo3,INPUT); 
  pinMode(trig3, OUTPUT);
  
  Serial.begin(9600);
  Serial1.begin(9600);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  
  pinMode(led,OUTPUT);
  
  //pinMode(encLeftA, INPUT_PULLUP);
  //pinMode(encRightA, INPUT_PULLUP);
 //attachInterrupt(digitalPinToInterrupt(encLeftA), encLeftCount, RISING);
 // attachInterrupt(digitalPinToInterrupt(encRightA), encRightCount, RISING);

pinMode(encoder0PinA, INPUT);
pinMode(encoder0PinB, INPUT);


  digitalWrite(13,HIGH); //turns on Teensy led

  //liftoff();
}

void loop() {
  // put your main code here, to run repeatedly:
  search(); //go forward and avoid obstical 
  // remote();
  // sonar();

  // encoder(); use this to get the left encoder readings
  //lets go to each function and store the values into an array [leftsonar,frontsonar,rightsonar,x,y]
  //from here plot the array
  //going to need a for loop that iterates from 1 to 5
//  for (i=0; i <3; i=i+1){
//     Serial.println(list[i]);
//  }
  }
  


