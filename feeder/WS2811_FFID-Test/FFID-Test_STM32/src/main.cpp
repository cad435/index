#include <Arduino.h>


void TimChange();

#define LP_Length 5

volatile uint16_t T_High[LP_Length] = {0};
volatile uint16_t T_Low[LP_Length] = {0};

volatile uint8_t lowpassID = 0;

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
  TIM.resume();


}

void loop() {
  // put your main code here, to run repeatedly:

  delay(200);

  uint32_t h = 0;
  uint32_t l = 0;

  for (uint8_t i = 0; i < LP_Length; i++)
  {
    h+= T_High[i];
    l+= T_Low[i];
  }

  h = h /LP_Length;
  l = l /LP_Length;
  

  uint16_t DC = h*255 / (h+l);
  Serial.println(DC);

}



void TimChange()
{
  TIM.pause();
  if (digitalRead(PC15) == LOW) //falling
  {
    T_High[lowpassID] = TIM.getCount();
  }
  else //rising
  {
    T_Low[lowpassID] = TIM.getCount();
  }
  TIM.setCount(0);
  //digitalWrite(PA6, LOW);
  TIM.resume();

  if (lowpassID == LP_Length-1)
  {
    lowpassID = 0;
  }
  else
  {
    lowpassID++;
  }
  
  
}