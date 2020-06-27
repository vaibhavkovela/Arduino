#include <Servo.h>
Servo ESC;     // create servo object to control the ESC
int potValue;  // value from the analog pin
void setup() {
  Serial.begin(9600);
  // Attach the ESC on pin 9
  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
}
void loop() {
  for(int i =0;i<1023;i++){
   potValue = i/*analogRead(A5)*/;  // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue  , 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
 ESC.write(potValue);// Send the signal to the ESC
 Serial.println(potValue);
 delay(50);
 
}
}
