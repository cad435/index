#include <Arduino.h>


void TimChange();

volatile uint16_t T_High = 0;
volatile uint16_t T_LOW = 0;

HardwareTimer TIM(3);

void setup() {
  // put your setup code here, to run once:

  pinMode(PC15, INPUT_PULLUP);

  pinMode(PA6, OUTPUT);

  attachInterrupt(PC15,TimChange, CHANGE);

  Serial.begin(115200);


  digitalWrite(PA6, LOW);

  TIM.pause();
  TIM.setPrescaleFactor(64);


}

void loop() {
  // put your main code here, to run repeatedly:

  delay(250);
  Serial.print(T_High);
  Serial.print(",");
  Serial.println(T_LOW);
}



void TimChange()
{
  TIM.pause();
  if (digitalRead(PC15) == LOW) //falling
  {
    T_High = TIM.getCount();
  }
  else //rising
  {
    T_LOW = TIM.getCount();
  }
  
  TIM.setCount(0);
  //digitalWrite(PA6, LOW);
  TIM.resume();

  
}