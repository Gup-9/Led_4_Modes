#include <Arduino.h>
const uint8_t ledpin = 9;//Digital pin 9 for led output
const uint8_t buttonpin = 2;//Digital pin 2 for button input

uint8_t mode = 0;    /*for mode selection
                     0 = OFF, 1 = ON ,2 = Slow Blinking, 3 = Fast Blinking*/
bool LastState = HIGH;//Button Last State
unsigned long PreviousMillis = 0;//Prev Led blink ms
unsigned long CurrentMillis;//Current on/off time(ms)
uint8_t ledState = LOW;//Led State on/off

void ledBlink(int interval)//Blink LED Function
{
  CurrentMillis = millis();//Starting of operation in ms
  if (CurrentMillis - PreviousMillis >= interval)//Blink Calculation
  {
     PreviousMillis = CurrentMillis;

    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    digitalWrite(ledpin, ledState);
  }
}

void setup()
{
  pinMode(ledpin, OUTPUT);//Setting up Led Output
  pinMode(buttonpin, INPUT_PULLUP);// Input with pullup resistance to read HIGH whenver the button is OFF
  Serial.begin(9600);
}
void loop()
{
  bool CurrentState = digitalRead(buttonpin);//Reading Current State of Butonpin High if off and LOW if pressed
  if (LastState == HIGH && CurrentState == LOW)//Checking for button press
  {
    mode++;
    if (mode > 3)//back to 0 mode
    {
      mode = 0;
    }
    delay(200); // Simple Debounce
  }
  LastState = CurrentState;
  Serial.println(mode);
  //Setting Mode of Operations
  if (mode == 0)
  {
    digitalWrite(ledpin, LOW);
  }
  else if (mode == 1)
  {
    digitalWrite(ledpin, HIGH);
  }
  else if (mode == 2)
  {
    ledBlink(160);
  }
  else if (mode == 3)
  {
    ledBlink(75);
  }
}
