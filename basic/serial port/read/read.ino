
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
