//DETTE ER TRANSMITTER (1101)


#include <SPI.h>                      // include SPI library
#include <nRF24L01.h>                 // include nRF24L01 library
#include <RF24.h>                     // include RF24 library

RF24 radio(2, 4);                     // set RF24 Chip enable to port 7 and Chip Select Not to port 8
const byte address[6] = "00001";      // set variable address as byte and store 00001

int state = 0;                        // set state variable to 0

struct DataPacket {
  int value;        // e.g., sensor reading
  char text[20];    // short message or label
};



void setup() {
  Serial.begin(9600);
  radio.begin();                      // start radio communication via NRF24L01
  radio.openWritingPipe(address);     // set the address at which we will send the data
  radio.setPALevel(RF24_PA_MIN);      // set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();              // stop NRF24L01 for listening and start the module as receiver
  radio.setChannel(82);
  Serial.println("hello world");


}

void loop()
{
  DataPacket packet;

  packet.value = 1;
  strcpy(packet.text, "Dette virker right?");     // Copy string into struct

  Serial.println(radio.write(&packet, sizeof(packet)));
  delay(1000);

}
