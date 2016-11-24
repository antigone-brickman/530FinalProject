#include <Time.h>
#include <TimeAlarms.h>
int LED = 2;
int BUTTON = 13;
void setup()
{
  Serial.begin(9600);
  setTime(8,29,50,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011
  // create the alarms
  Alarm.alarmRepeat(8,30,00, MorningAlarm);  // 8:30am every day
 
 
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
  Alarm.timerRepeat(15, Repeats);          // timer for every 15 seconds    
  Alarm.timerOnce(10, OnceOnly);          // called once after 10 seconds
  digitalWrite(LED,HIGH);
}


void  loop(){  
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
   if(digitalRead(BUTTON) != HIGH){
    digitalWrite(LED,LOW);
    LED++;
    delay(1000);
    digitalWrite(LED,HIGH);
   }
}


// functions to be called when an alarm triggers:
void MorningAlarm(){
  if(digitalRead(LED) == HIGH){
    while(digitalRead(BUTTON)== HIGH){
      digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                     // wait for a second
      digitalWrite(LED, LOW); // turn the LED off by making the voltage LOW
      delay(300);
  }
  }
}


void EveningAlarm(){
  Serial.println("Alarm: - turn lights on");         
}


void WeeklyAlarm(){
  Serial.println("Alarm: - its Monday Morning");   
}


void ExplicitAlarm(){
  Serial.println("Alarm: - this triggers only at the given date and time");    
}


void Repeats(){
  Serial.println("15 second timer");       
}


void OnceOnly(){
  Serial.println("This timer only triggers once");  
}


void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}


void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
  Serial.print('0');
  Serial.print(digits);
}

