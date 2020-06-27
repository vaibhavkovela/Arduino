#include <SPI.h>
#include <nRF24L01.h> 
#include <RF24.h>

RF24 radio(7, 8); // CNS, CE
String response;
boolean done = false;

void setup() {
  delay(500);
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0,0xF0F0F0F0AA);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&response, sizeof(response));
    done = true;
  }
  if (done) {
    Serial.println(response);
  }
  done = false;
  delay(1000);
}
