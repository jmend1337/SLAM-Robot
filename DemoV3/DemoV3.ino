
///////////////////////////////////////////////////
// for sonar
float duration1; //Variable used in the left sonar
float distance1; //Variable used in the left sonar
float PD1;       //This is the previous Distance value

float duration2; //Variable used in the front sonar
float distance2; //Variable used in the front sonar
float PD2;

float duration3; //Variable used in the right sonar
float distance3; //Variable used in the right sonar
float PD3;

int echo2 = 14;  //Variable to collect the distace data in the sonar for the front sensor
int trig2 = 15;  //Variable to trigger the sonar to send a pulse of sound for the front sensor

int echo1 = 11;  //Variable to collect the distace data in the sonar for the left sensor
int trig1 = 12;  //Variable to trigger the sonar to send a pulse of sound for the left sensor

int echo3 = 10;  //Variable to collect the distace data in the sonar for the right sensor
int trig3 = 9;  //Variable to trigger the sonar to send a pulse of sound for the right sensor

///////////////////////////////////////////////////
// for motors and encoders
int ENA = 23;   //Enable pin to turn on Robot's RIGHT motor and to control its strength
int ENB = 22;   //Enable pin to turn on Robot's LEFT motor and to control its strength
int IN1 = 21;   //Binary logic to control the Robot's RIGHT Motor's direction
int IN2 = 20;   //Binary logic to control the Robot's RIGHT Motor's direction
int IN3 = 19;   //Binary logic to control the Robot's LEFT Motor's direction
int IN4 = 18;   //Binary logic to control the Robot's LEFT Motor's direction


int encoder0PinA = 7; //Variable for Encoder
int encoder0PinB = 8; //Variable for Encoder
volatile long encoder0Pos = 0;
long encoder0LastPos = 0;

///////////////////////////////////////////////////
// Logic and other expressions
float frontLimit = 6; //limit of distance to the front in cm

int n = LOW;
int encoder0PinALast = LOW;

int defaultMotorSpeed = 210;   //Controls how much power is being sent to the motors. The scale is from 0-255;

int led = 13;   //Pin to turn the led on the teensy3.2 on or off

float list[5]; // we will print this list
//[leftSonarDistance,frontSonarDistance,rightSonarDistance,xPosition,yPosition];
//list[0]=leftSonarDistance;
//list[1]=frontSonarDistance;
//list[2]=rightSonarDistance;
//list[3]=xPosition;
//list[4]=yPosition;

float x = 0; //x position
float y = 0; //y position

int compass = 10;
//10 north
//20 east
//30 south
//40 west

int i;
int j = 2; //used for logic

void setup() {

  // put your setup code here, to run once:
  //Motor PinModes
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  //Sonar PinModes
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);



  //Encoder PinModes
  pinMode(encoder0PinA, INPUT_PULLUP);
  pinMode(encoder0PinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoder0PinA), encoder, RISING);

  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
  liftoff();
}

void loop() {
  // put your main code here, to run repeatedly:
  explore();
}



