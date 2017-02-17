const int INPUT_PIN1 = 2; //D2
const int OUTPUT_PIN1 = 13; //B5

const int INPUT_PIN2 = 3; //D3
const int OUTPUT_PIN2 = 10; //B2
//I want a 1.25ms delay

void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT_PIN1, INPUT_PULLUP);
  pinMode(OUTPUT_PIN1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(INPUT_PIN1), foo, CHANGE);

  pinMode(INPUT_PIN2, INPUT_PULLUP);
  pinMode(OUTPUT_PIN2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(INPUT_PIN2), foo2, CHANGE);

//  //timer setup
  TCCR2A = 0;
  TCCR2B = 0x04; //div 32
  TIMSK2 = 0; //disable both interrupts

}

void loop() {
  // put your main code here, to run repeatedly:

}

void foo()
{
  OCR2A=TCNT2 -1;
  TIFR2 |= 0x02;
  TIMSK2 |= 0x02;  //Enable OCA
//  digitalWrite(OUTPUT_PIN1, digitalRead(INPUT_PIN1));
//  bitWrite(PORTB, 5, bitRead(PIND, 2));
//  bitWrite(PORTB, 5, digitalRead(2));
}

void foo2()
{
  OCR2B=TCNT2 -1;
  TIFR2 |= 0x04;
    TIMSK2 |= 0x04;  //Enable OCB
//  bitWrite(PORTB, 2, bitRead(PIND, 3));
//digitalWrite(OUTPUT_PIN2, digitalRead(INPUT_PIN2));

}

ISR(TIMER2_COMPA_vect)
{
  TIFR2 &= 0xFD;
  TIMSK2 &= 0xFD;
  bitWrite(PORTB, 5, bitRead(PIND, 2));
//  digitalWrite(OUTPUT_PIN1, digitalRead(INPUT_PIN1));
}

ISR(TIMER2_COMPB_vect)
{
  TIFR2 &= 0xFB;
  TIMSK2 &= 0xFB;
  bitWrite(PORTB, 2, bitRead(PIND, 3));

//  digitalWrite(OUTPUT_PIN2, digitalRead(INPUT_PIN2));
}


