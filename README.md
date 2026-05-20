# Led_4_Modes
Using a push button to toggle the led into 4 modes (off , on , slow blinking , fast blinking) with an arduino uno.
Using the INPUT_PULLUP to add a pullup resistor so that the input pin reads HIGH when the button is not pressed,
When the button is pressed the input pin is connected to GND so it reads LOW , this is how we switch the modes.
Using the millis() for delay is better than the delay() for multitasking.
