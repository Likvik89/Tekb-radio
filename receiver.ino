// DETTE ER RECEIVER (1440) tror jeg :) 


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);                  // CE = D7, CSN = D8
const byte address[6] = "00001";

struct DataPacket {
  int value;
  char text[20];
};

DataPacket packet;


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
  radio.setChannel(82);
  pinMode(6, OUTPUT);

}

void loop() {
  if (radio.available()) {
    radio.read(&packet, sizeof(packet));

    Serial.print("Received Value: ");
    Serial.print(packet.value);
    Serial.print(" | Text: ");
    Serial.println(packet.text);
    digitalWrite(6, HIGH);
    delay(1000);
  }
}


