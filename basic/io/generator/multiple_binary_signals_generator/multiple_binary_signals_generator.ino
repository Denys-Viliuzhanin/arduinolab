
/**
 * Results:
 *  1. 1  pin:  100 KHz length  4.7us
 *  2. 2  pins: 50  KHz length  8us  hdelay 3.44us
 *  3  5  pins: 20  KHz length: 24us delay 4us
 *  4. 10 pins: 10  KHz length: 54us delay 4us, 8us, ..., 44us (10*4. us)
 */
#define LENGTH 1
#define PINS_COUNT 1
// (sizeof(pins)/sizeof(pins[0]))
byte pins[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
int counter = 0;

void setup() {
  for(int i = 0; i < PINS_COUNT; i++) {
    pinMode(pins[i], OUTPUT);  
  }
  Serial.begin(9600);
  Serial.println("Generated is running");
}


void loop() {
  for(int i = 0; i < PINS_COUNT; i++) {
    if (counter >= 0) {
      digitalWrite(pins[i], HIGH); 
    } else {
      digitalWrite(pins[i], LOW); 
    }  
  }
          
  counter++;  
  if (counter >= LENGTH) {
    counter = -LENGTH;
  }
}
