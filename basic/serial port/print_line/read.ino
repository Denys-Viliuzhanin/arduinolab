
// use the following bash command to send data from PC
// $ echo Test >> /dev/ttyUSB0
// use the following bash command to receive data on PC
// $ tail -f /dev/ttyUSB0


void setup() {

  // set  baud rate (bits per second).
  Serial.begin(9600);
  //Serial.begin(19200);

}
char buffer[255];


void loop() {
  if (Serial.available() > 0) {
    Serial.print("Received:");
    while(Serial.available() > 0) {
      byte incomingByte = Serial.read();
      sprintf (buffer, "%c", incomingByte);
      Serial.print(buffer);  
      delay(1);
    }  
    Serial.println();
  }
}
