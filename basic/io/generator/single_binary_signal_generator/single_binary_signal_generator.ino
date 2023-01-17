
#define PIN 13
#define LENGTH 1
int counter = 0;

void setup() {
  pinMode(PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Generated is running");
}


void loop() {
  if (counter >= 0) {
    digitalWrite(PIN, HIGH); 
    //digitalWrite(PIN, LOW); 
  } else {
    digitalWrite(PIN, LOW); 
    //digitalWrite(PIN, HIGH);   
  }        
  counter++;  
  if (counter >= LENGTH) {
    counter = -LENGTH;
  }
}
