#include <Servo.h>
#include <SoftwareSerial.h>
#include<Cytron_PS2Shield.h>

Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
  #define led 13
  
  #define left_mot 11  //left motor BLDC
  #define right_mot 10 //right motor BLDC
  #define ser_pin 9 //servo position

  Servo servo,left_esc,right_esc;

  int mot_speed=0;  // MOTOR SPEED
  int pos=0;// initial position of servo
void setup() {
  
  ps2.begin(32000);
  Serial.begin(32000);// begin serial transmission

  servo.attach(ser_pin);
  left_esc.attach(left_mot);
  right_esc.attach(right_mot);

  //calibrating left  ESC
  left_esc.write(0);  //MINIMUM
  left_esc.write(180); //MAXIMUM
  left_esc.write(90);  //CENTRE
  
  //calibrating right  ESC
  right_esc.write(0); //MINIMUM
  right_esc.write(180);  //MAXIMUM
  right_esc.write(90); //CENTRE
// put your setup code here, to run once:

}

void loop() {

  mot_speed=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);
  mot_speed=map(mot_speed,0,255,0,180);
  left_esc.write(mot_speed);
  right_esc.write(mot_speed);
                  
  pos=ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS);
  pos=map(pos,0,255,-180,180);
  servo.write(pos);
     // put your main code here, to run repeatedly:

}
