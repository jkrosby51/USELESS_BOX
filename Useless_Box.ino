#include <ServoTimer2.h>
#include <toneAC.h>
//#include <Servo.h>
//Useless Box
//Johnny Krosby, Lucy Gray
//flip switch --> flip switch back

//Servo myServo;
ServoTimer2 myServo;

//notes

#define  c     261 
#define  d     294 
#define  e     329 
#define  f     349 
#define  g     392 
#define  a     440 
#define  b     493 
#define  C     523 
#define  D     587
// Define a special note, 'R', to represent a rest
#define  R     0
//delays based on quarter (q) notes, eighth notes (qq), and the length of the notes (n)
#define  q     187
#define  qq    93
#define  n     50


int origin = 1700; //variable for when the servo is in its original position
int closing = 750; //variable for when the servo is touching switch
int delayVar = 0; //how long each delay lasts
int servoPin = 8;
//int screechPin = 9; //pin for piezo buzzer
int switchPinClose = 12; //if(HIGH){DUCK ATTACK;}
int switchPinOpen = 11; //if(HIGH){HUMAN ATTACK;}
int val1 = 0; //close
int val2 = 0; //open
int servoAngle = 0; //variable used for servo angle

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  pinMode(switchPinClose, INPUT);
  pinMode(switchPinOpen, INPUT);
  myServo.attach(servoPin);
  myServo.write(origin);
  delayVar = 0;
}

void loop() {

  val1 = digitalRead(switchPinClose);
  val2 = digitalRead(switchPinOpen);
  Serial.print(val1);
  Serial.println(" = val1");

  Serial.print("             ");
  Serial.print(val2);
  Serial.print(" = val2");
  Serial.print("         ");
  Serial.print(servoAngle);
  Serial.println(" = servoAngle");
  
//if the switch is pointing towards the duck then bring duck towards switch for DUCK ATTACK
  if (val1 == HIGH && val2 == LOW) {
    //switch toward box
    servoAngle = closing;
    myServo.write(servoAngle);
    //tone(screechPin, 1000, 100);
    delay(delayVar);
    music();
  }
//if the switch is pointing towards the human then bring duck back to original place
  else if (val1 == LOW && val2 == HIGH) {
    //switch towards human
    servoAngle = origin;
    myServo.write(servoAngle);
    delay(delayVar);
  }
}

void music() { 
   // toneAC(d); // Play the frequency (150 Hz to 15 kHz in 10 Hz steps).
    //delay(qq);     //makes it eight note
    toneAC(220);delay(n);toneAC(R);delay(qq);
    toneAC(c);delay(n);toneAC(R);delay(qq);
    toneAC(d);delay(n);toneAC(R);delay(q);
    toneAC(d);delay(n);toneAC(R);delay(q);
    toneAC(d);delay(n);toneAC(R);delay(qq);
    toneAC(e);delay(n);toneAC(R);delay(qq);
    toneAC(f);delay(n);toneAC(R);delay(q);
    toneAC(f);delay(n);toneAC(R);delay(q);
    toneAC(f);delay(n);toneAC(R);delay(qq);
    toneAC(g);delay(n);toneAC(R);delay(qq);
    toneAC(e);delay(n);toneAC(R);delay(q);
    toneAC(e);delay(n);toneAC(R);delay(q);
    toneAC(d);delay(n);toneAC(R);delay(qq);
    toneAC(c);delay(n);toneAC(R);delay(qq);
    toneAC(c);delay(n);toneAC(R);delay(qq);
    toneAC(d);delay(n);toneAC(R);delay(428);
    toneAC(R);delay(100);
  //toneAC(0); // Turn off toneAC, can also use noToneAC().
}

//References

//https://www.arduino.cc/en/tutorial/pushbutton
//https://create.arduino.cc/projecthub/SBR/working-with-two-leds-and-two-push-buttons-1d4182       wiring
//https://create.arduino.cc/projecthub/glowascii/button-arduino-basics-5ecffc       more wiring
