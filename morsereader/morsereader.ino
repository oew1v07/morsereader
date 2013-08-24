// this constant won't change:
const int  buttonPin = 9;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
long ButtonPressTimeOn = 0;  // time from when button goes on to being off
long ButtonPressTimeOff = 0; // time from when button goes off to being on
long TimeHeld = 0;           // time between button going on and button going off

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // went from off to on:
      ButtonPressTimeOn = millis();
      Serial.println("on");
      
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      ButtonPressTimeOff = millis();
      Serial.println("off");
    }
    
    TimeHeld = ButtonPressTimeOff - ButtonPressTimeOn;
    Serial.print("The button was held for:  ");
    Serial.print(TimeHeld);
    Serial.println("ms");
    
  }
  
  
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;
}
