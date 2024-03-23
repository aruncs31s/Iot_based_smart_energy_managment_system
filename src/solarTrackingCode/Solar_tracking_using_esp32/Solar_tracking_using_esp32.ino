/*
Author : Arun CS
Github : https://github.com/aruncs31s
*/

#include <ESP32Servo.h>

// Define the GPIO (2,15) pin connected to the servo
const int servoPin_1 = 2;
const int servoPin_2 = 15;

// Define the GPIO ADC Pins for LDR Sensors
const int LDR_left_top =36 ;
const int LDR_left_bottom = 39 ;
const int LDR_right_top = 34;
const int LDR_right_bottom = 35;

// Setting the LDR resistance Value thresholds
const int LDR_Value_High = 900;
const int LDR_Value_Low = 20 ;

// Servo Motor Rotation Values
const int servooMotor_High = 180;
const int servooMotor_Low = 10;


// Create a Servo object
Servo Servo_1; // Horizontal
Servo Servo_2; // Vertical




void setup() {
  Serial.begin(9600);

  // Attach the servo to the GPIO pin
  Servo_1.attach(servoPin_1);
  Servo_2.attach(servoPin_2);

  // Bring the servo to inital Position
  Servo_1.write(0);
  Servo_2.write(0);
  delay(500); //Need To find Out :)


// Read The LDR Values 
int reading_LDR_left_bottom = analogRead(LDR_left_bottom);
int reading_LDR_left_top = analogRead(LDR_right_top);
int reading_LDR_right_top = analogRead(LDR_right_top);
int reading_LDR_right_bottom = analogRead(LDR_right_bottom);

}
void loop() {

  
  int reading_LDR_left_avg = (reading_LDR_left_top + reading_LDR_left_bottom) / 2;
  int reading_LDR_right_avg = (reading_LDR_right_bottom +  reading_LDR_right_top) /2 ;
  int reading_LDR_bottom_avg = (reading_LDR_right_bottom +reading_LDR_left_bottom  ) /2 ;

  int reading_LDR_top_avg = (reading_LDR_right_top  + reading_LDR_left_top ) /2 ;

if ( reading_LDR_top_avg < reading_LDR_bottom_avg){
  
  }

  


//
//   // Sweep the servo back and forth
//   for (int angle = 0; angle <= 180; angle += 1) {
//     Servo_1.write(angle);
//     delay(5);
//   }
//   for (int angle = 180; angle >= 0; angle -= 1) {
//     Servo_1.write(angle);
//     delay(5);
//   }
//   for (int angle = 0; angle <= 180; angle += 1) {
//     Servo_2.write(angle);
//     delay(5);
//   }
//   for (int angle = 180; angle >= 0; angle -= 1) {
//     Servo_2.write(angle);
//     delay(5);
//   }
// `

}

