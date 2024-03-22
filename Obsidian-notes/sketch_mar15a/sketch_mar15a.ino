/* Arun CS *
* https://github.com/aruncs31s/

*/

const int PIR_SENSOR_OUTPUT_PIN = 2;  /* PIR sensor O/P pin */
// int warm_up;

void setup() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);
  Serial.begin(9600); /* Define baud rate for serial communication */
  Serial.println("Waiting For Power On Warm Up");
  delay(200); /* Power On Warm Up Delay */
  Serial.println("Ready!");
}
int sensor_output;
void loop() {
   bool k =  digitalRead(PIR_SENSOR_OUTPUT_PIN); 
  Serial.println(k);

  delay(2000);
  
}
