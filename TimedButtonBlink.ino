/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN takes care 
  of use the correct LED pin whatever is the board used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  

  modified 2 Sep 2016
  by Arturo Guadalupi
*/
#include <Time.h>
#include <TimeAlarms.h>

int ledPin =  2;
int buttonPin = 13;


// the setup function runs once when you press reset or power the board
void setup() {
    // initialize the LED pin as an output:
    for(int i = 2; i<9; i++){
      pinMode(i, OUTPUT);
    }
    pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
//*
  // If the button is pressed:
  if(digitalRead(buttonPin) == LOW){
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW

    // Move on to the next LED
    if(ledPin == 8){
      ledPin = 2;
    }
    else{
      ledPin++;
    }
    delay(1000);                  // wait for a second
  }//*/
}
