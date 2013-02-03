int MotorPin = 9; //Same ping as PWM example.

void setup()  { 
  // Not yet. Not yet.
} 

void loop()  { 
  // Increase PWM duty cycle (and motor speed) from 0 to 255.
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue++ ) { 
    // This is how easy setting the PWM duty-cycle in Arduino is!
    analogWrite(MotorPin, fadeValue); 
    delay(30); // Oh snap! There's a delay function already! Delaying 30 milliseconds.
  } 

  // Same thing but go to 0% Duty Cycle
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue--) { 
    // sets the value (range from 0 to 255):
    analogWrite(MotorPin, fadeValue);         
    // wait for 30 milliseconds to see the that motor stopped.
    delay(300);                            
  } 
}
