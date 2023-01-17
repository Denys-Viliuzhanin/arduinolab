volatile uint8_t pin = 2;
volatile uint8_t value = HIGH;

void before_measuring() {
  // Set Timer 1 to normal mode at F_CPU.
  TCCR1A = 0;
  TCCR1B = 1;

  // Time digitalWrite().
  //cli();  
}

void after_measuring() {
   sei();
}

uint16_t measure_cpu_cycles_count() {
  return TCNT1;
}


uint16_t overhead;
void setup()
{
    Serial.begin(9600);

    before_measuring();
    
    uint16_t start = measure_cpu_cycles_count();
    uint16_t finish = measure_cpu_cycles_count();
    
    after_measuring();
    overhead = finish - start;
   
    Serial.print("Overhead");
    Serial.print(overhead);
    Serial.println(" CPU cycles.");
}

void someWork(int amountOfWork);


long prevTimeMs = 0;
uint16_t cycles;
long timeDurationMs;

void measure() {
    before_measuring();
    
    uint16_t start = measure_cpu_cycles_count();
    // ===============================
    // place work here
    // ===============================
    someWork(1);
    // ===============================
    uint16_t finish = measure_cpu_cycles_count();
    long currentTimeMs = millis();
    after_measuring();
    cycles = finish - start - overhead;
    timeDurationMs = currentTimeMs - prevTimeMs;
    prevTimeMs = currentTimeMs;
    // ===============================    
}

void outputResults() {
    Serial.print("digitalWrite() took ");
    Serial.print(cycles);
    Serial.print(" CPU cycles. ");
    Serial.print(" and overhead was ");
    Serial.print(overhead);
    Serial.print(" CPU cycles. ");
    Serial.print("Time: ");
    Serial.print(timeDurationMs);
    Serial.println();  
}


int iteration = 0;
void loop(){

    if ((iteration % 3 == 0) || (iteration % 3 == 1)) {
      measure() ;   
    } else {
      outputResults(); 
    }
    iteration++;

    
    
    
}

#define DATA_SIZE 1024*10
byte data[DATA_SIZE];
void someWork(int amountOfWork) {
  
  for(int i = 0; i < amountOfWork; i++) {
    for(int j = 0; j < DATA_SIZE; j++) {
      data[j] = (int)j*0.003 + millis();
    }
  }
}
