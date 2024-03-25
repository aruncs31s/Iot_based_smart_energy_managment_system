---
id: ESP32 Codes
aliases: []
tags: []
---

- [LDR Interfacing](#ldr%20interfacing)
- [PIR Interfacing](#pir%20interfacing)
- [Servo Motor Interfacing](#servo%20motor%20interfacing)
    - [Servo Motor Interfacing](#servo%20motor%20interfacing)
    - [Servo Motor Interfacing 2](#servo%20motor%20interfacing%202)



#### LDR Interfacing


```c
const int LDR_PIN = 36;

void setup() {
   // put your setup code here, to run once:
   Serial.begin(115200);
   analogReadResolution(10); //default is 12. Can be set between 9-12.
}
void loop() {
   // put your main code here, to run repeatedly:
   // LDR Resistance: 90k ohms
   // Resistance in series: 150k ohms
   // Pinouts:
   // Vcc −> 3.3 (CONNECTED TO LDR FREE END)
   // Gnd −> Gnd (CONNECTED TO RESISTOR FREE END)
   // Analog Read −> Vp (36) − Intermediate between LDR and resistance. int LDR_Reading = analogRead(LDR_PIN);
   float LDR_Voltage = ((float)LDR_Reading*3.3/1023);
   Serial.print("Reading: ");Serial.print(LDR_Reading); Serial.print("\t");Serial.print("Voltage: ");Serial.println(LDR_Voltage);
}
```


#### PIR **Interfacing**
[Source](https://www.electronicwings.com/esp32/pir-sensor-interfacing-with-esp32)
```c
  Serial.println("Waiting For Power On Warm Up");
  delay(20000); /* Power On Warm Up Delay */
  Serial.println("Ready!");
}
int sensor_output;
void loop() {
  
  sensor_output = digitalRead(PIR_SENSOR_OUTPUT_PIN);
  Serial.println(sensor_output + "\n"); 
  delay(100);
  // if( sensor_output == LOW )
  // {
  //   if( warm_up == 1 )
  //    {
  //     Serial.print("Warming Up\n\n");
  //     warm_up = 0;
  //     delay(2000);
  //   }
  //   // Serial.print("No object in sight\n\n");
  //   delay(1000);
  // }
  // else
  // {
  //   // Serial.print("Object detected\n\n");   
  //   warm_up = 1;
  //   delay(100);
  // } 
}
```

---

#### Servo Motor Interfacing

```c
/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/
  Written by BARRAGAN and modified by Scott Fitzgerald
*********/

#include <Servo.h>

static const int servoPin = 13;

Servo servo1;

void setup() {
  Serial.begin(115200);
  servo1.attach(servoPin);
}

void loop() {
  for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }

```


#### Servo Motor Interfacing 2

#TestCode
[Source](https://chat.openai.com/)

```c
#include <ESP32Servo.h>

// Define the GPIO pin connected to the servo
const int servoPin = 2;

// Create a Servo object
Servo myservo;

void setup() {
  Serial.begin(9600);

  // Attach the servo to the GPIO pin
  myservo.attach(servoPin);
}

void loop() {
  // Sweep the servo back and forth
  for (int angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
    delay(15);
  }
  for (int angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
    delay(15);
  }
}
```


---




