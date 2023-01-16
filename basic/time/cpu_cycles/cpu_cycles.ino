volatile uint8_t pin = 2;
volatile uint8_t value = HIGH;

void before_measuring() {
  // Set Timer 1 to normal mode at F_CPU.
  TCCR1A = 0;
  TCCR1B = 1;

  // Time digitalWrite().
  cli();  
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

void loop(){
  
  

    before_measuring();
    
    uint16_t start = measure_cpu_cycles_count();
    // ===============================
    // place work here
    // ===============================
    digitalWrite(pin, value);
    // ===============================
    uint16_t finish = measure_cpu_cycles_count();
    after_measuring();
    uint16_t cycles = finish - start - overhead;
    Serial.print("digitalWrite() took ");
    Serial.print(cycles);
    Serial.print(" CPU cycles. ");
    Serial.print(" and overhead was");
    Serial.print(overhead);
    Serial.println(" CPU cycles.");
  }
