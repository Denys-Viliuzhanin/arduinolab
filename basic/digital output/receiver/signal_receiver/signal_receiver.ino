
#define BUFFER_SIZE 1000
#define PIN 13
long counter = 0;
int previousValue = LOW;
int positiveImpulsesCount = 0;
int negativeImpulsesCount = 0;
long startTime;

void setup() {
  pinMode(PIN, INPUT);
  Serial.begin(9600);
  Serial.println("Receiver is running");
  startTime = millis();
}

void loop() {

  int value = digitalRead(PIN);
  //value = digitalRead(PIN);
  //digitalWrite(PIN, HIGH);
  if (value > previousValue) {
    Serial.println("DOWN");
  } else if (value < previousValue) {
    Serial.println("UP");
  }
  previousValue = value;
  counter++;

  long currentTime = millis();
  long duration = currentTime - startTime ;
  if (duration > 1000) {
    float rate = counter / (duration/1000);
    Serial.print("Sampling rate: ");
    Serial.print(rate);
    Serial.print("Hz.");
    Serial.println();
    counter = 0;
    startTime = millis();
  }
}
