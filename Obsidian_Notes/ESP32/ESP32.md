## ESP32

- [ESP32]()
	- [Pinout](#esp32%20pinout)
	- [Specs](#esp32%20Specs)
- [PIR Sensor](#pir%20interfacing)


---


![Esp32|250x175](esp32.png)


###### Esp32 Pinout


![[esp32_pinout.png|600]]

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

----


### PIR Interfacing

![[Pasted image 20240316103329.png|200x200]]

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

#### References
1. [ElectronicWings](https://www.electronicwings.com/esp32/pir-sensor-interfacing-with-esp32)
2. [Youtube](https://www.youtube.com/watch?v=8wiCwrIaIT8)

