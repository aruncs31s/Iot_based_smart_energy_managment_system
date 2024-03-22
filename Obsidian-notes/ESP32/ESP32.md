---
id: ESP32
aliases: []
tags: []
---

## ESP32

- [ESP32]()
	- [Pinout](#esp32%20pinout)
	- [Specs](#esp32%20Specs)
	- [Notes]()
### ESP Codes
#### Interfacing

- [PIR Sensor](#pir%20interfacing)
	- [Code](#codes)
- [MultiThreding](#multithreding)
- [Servo Motor](#servo%20motor)
#### Modified Code
- [[SolarTrackingCodes]]

---


![Esp32|250x175](esp32.png)

---

###### Esp32 Pinout


![[esp32_pinout.png|600]]

---

![[Pasted image 20240320224627.png]]
##### ESP32 Specs

- Single or Dual-Core ==32-bit== LX6 Microprocessor with clock frequency up to ==240 MHz==.
- 520 KB of SRAM, 448 KB of ROM and 16 KB of RTC SRAM.
- Supports 802.11 b/g/n Wi-Fi connectivity with speeds up to 150 Mbps.
- Support for both Classic Bluetooth v4.2 and ==BLE==specifications.
- 34 Programmable GPIOs.
- Up to 18 channels of ==12-bit SAR ADC== and 2 channels of ==8-bit DAC==
- Serial Connectivity include 4 x ==SPI==, 2 x ==I2C==, 2 x ==I2S==, 3 x ==UART==.
- Ethernet MAC for physical LAN Communication (requires external PHY).
- 1 Host controller for SD/SDIO/MMC and 1 Slave controller for SDIO/SPI.
- Motor PWM and up to 16-channels of LED PWM.
- Secure Boot and Flash Encryption.
- Cryptographic Hardware Acceleration for AES, Hash (SHA-2), RSA, ECC and RNG
[Source](https://www.electronicshub.org/getting-started-with-esp32/)

##### ESP32 Notes
[Source](https://www.tutorialspoint.com/esp32_for_iot/interfacing_esp32_with_analog_sensors.htm#:~:text=In%20the%20image%20shown%20below,36%20(VN)%20of%20ESP32.)

- The analog voltage provided to the ADC pin should be less than or equal to the reference voltage
- The reference voltage is generally the supply voltage
- The resolution indicates the number of bits that will be used to represent the digital value. Thus, if the resolution is 8 bits, then the value will be represented by 8 bits, and the maximum value possible is 255.
- This maximum value corresponds to the value of the reference voltage. The values for other voltages are often derived by scaling


<details><summary>More</summary>
<ul>
<li> Thus, if the reference voltage is 5V and an 8−bit ADC is used, then 5V corresponds to a reading of 255, 1V corresponds to a reading of (255/5*1) = 51, 2V corresponds to a reading (255/5*2) = 102 and so on. If we had a 12 bit ADC, then 5V would correspond to a reading of 4095, 1V would correspond to a reading of (4095/5*1) = 819, and so on.</li>
<li>The reverse calculations can be performed similarly. If you get a value of 1000 on a 12 bit ADC with a reference voltage of 3.3V, then it corresponds to a value of (1000/4095*3.3) = 0.8V approximately. If you get a reading of 825 on a 10 bit ADC with a reference voltage of 5V, it corresponds to a value of (825/1023*5) = 4.03V approximately.</li>
</ul>
<details><summary>Bit More</summary>With the above explanation, it will be clear that both the reference voltage and the number of bits used for ADC determine the minimum possible voltage change that can be detected. If the reference voltage is 5V and the resolution is 12-bit, you have 4095 values to represent a voltage range of 0−5V. Thus, the minimum change that can be detected is 5V/4095 = 1.2mV. Similarly, for a 5V and 8-bit reference voltage, you have only 255 values to represent a range of 0-5V. Thus, the minimum change that can be detected is 5V/255 = 19.6mV, or about 16 times higher than the minimum change detected with a 12-bit resolution.
</details>
</details>

---


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
````


----


### PIR Interfacing

![[Pasted image 20240316103329.png|200x200]]

---

#### Codes
1. **Interfacing** [Source](https://www.electronicwings.com/esp32/pir-sensor-interfacing-with-esp32)
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


#### MultiThreding
- [Introduction]()
- [Steps](#multithreding%20Steps)
- [Sources](#sources)

##### MultiThreding Steps
1. Create a task handle
```c
TaskHandle_t Task1;
```

2. In the setup() create a a task assigned to a specific core using the xTaskCreatePinnedToCore function. That function takes several arguments, including the priority and the core where the task should run (the last parameter)
```c
xTaskCreatePinnedToCore( Task1code, /* Function to implement the task */ "Task1", /* Name of the task */ 10000, /* Stack size in words */ NULL, /* Task input parameter */ 0, /* Priority of the task */ &Task1, /* Task handle. */ 0); /* Core where the task should run */
```

```c
/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

void setup() {
  Serial.begin(9600);
  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());
}

void loop() {
  Serial.print("loop() running on core ");
  Serial.println(xPortGetCoreID());
}
```

[Source](https://randomnerdtutorials.com/esp32-dual-core-arduino-ide/)
##### Sources
- [1](https://randomnerdtutorials.com/esp32-dual-core-arduino-ide/)
- [2]()

---


### Servo Motor

- Interfacing

[Source](https://randomnerdtutorials.com/esp32-servo-motor-web-server-arduino-ide/)
![[Pasted image 20240322043007.png|300x150]]
#TestCode 
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
#TestCode2
[Source](https://chat.openai.com/)

```c
#include <ESP32Servo.h>

// Define the GPIO pin connected to the servo
const int servoPin = 13;

// Create a Servo object
Servo myservo;

void setup() {
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

#modifiedCode


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


#### References
1. [ElectronicWings](https://www.electronicwings.com/esp32/pir-sensor-interfacing-with-esp32)
2. [Youtube](https://www.youtube.com/watch?v=8wiCwrIaIT8)

