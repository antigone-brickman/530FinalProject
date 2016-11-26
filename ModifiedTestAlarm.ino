#include <Time.h>
#include <TimeAlarms.h>
int LED = 2;
int BUTTON = 13;

// Storage for alarm status

// State 0: Unlit
// State 1: Lit
// State 2: Flashing
  
int days[7];

void setup()
{
  Serial.begin(9600);
  setTime(8,29,50,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011
  // create the alarms

  /**
  // The timing of the following alarms allows us to fudge the numbers.
  // A normal layout would look like this:

  Alarm.alarmRepeat(8,30,00, MorningAlarm);  // 8:30am every day
  Alarm.alarmRepeat(23,00,00, LightIncrement); // Midnight every day

  // MorningAlarm can be set at any time to remind the user
  // LightIncrement should be called to move on to the next LED

  **/
  
  //Alarm.alarmRepeat(8,30,00, MorningAlarm);  // 8:30am every day
  Alarm.alarmRepeat(8,30,05, LightIncrement); // It is now Monday
  
  //Alarm.alarmRepeat(8,30,10, MorningAlarm);
  Alarm.alarmRepeat(8,30,15, LightIncrement); // It is now Tuesday
  
  //Alarm.alarmRepeat(8,30,20, MorningAlarm);
  Alarm.alarmRepeat(8,30,25, LightIncrement); // It is now Wednesday
  
  //Alarm.alarmRepeat(8,30,30, MorningAlarm);
  Alarm.alarmRepeat(8,30,35, LightIncrement); // It is now Thursday
  
  //Alarm.alarmRepeat(8,30,40, MorningAlarm);
  Alarm.alarmRepeat(8,30,45, LightIncrement); // It is now Friday
  
  //Alarm.alarmRepeat(8,30,50, MorningAlarm);
  Alarm.alarmRepeat(8,30,55, LightIncrement); // It is now Saturday
  
  //Alarm.alarmRepeat(8,30,57, MorningAlarm);

 // Initialize all lights for output
  for(int i = 2; i<9; i++){
    pinMode(i,OUTPUT);
  }

 
  pinMode(BUTTON,INPUT);
  Alarm.timerRepeat(15, Repeats);         // timer for every 15 seconds    
  Alarm.timerOnce(10, OnceOnly);          // called once after 10 seconds
  digitalWrite(LED,HIGH);
  
  // As a placeholder, assume the cycle starts on Sunday
  days[LED-2] = 1;
}


void loop(){  
  digitalClockDisplay();
  Alarm.delay(500); // wait one second between clock display

  // If a button is pressed, reset all reminders
   if(digitalRead(BUTTON) != HIGH){
    for(int i = LED; i > 1; i--){
      days[i-2] = 0;
      digitalWrite(i,LOW);
    }
   }

  // Testing LED 7

  // Check every LED
  //*
  for(int day = 2; day < 9; day++){
    // If the LED is in alarm state, flash it
    
    if(days[day-2] == 2 || days[day-2] == 0){
      digitalWrite(day, LOW);    // turn the LED off by making the voltage LOW
      //delay(200);                       // wait for a second
    }
  }
      delay(500);                       // wait for a second

  for(int day = 2; day < 9; day ++){
    if(days[day-2] == 2 || days[day-2] == 1){
      digitalWrite(day, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
  }
  //*/
   
}


// functions to be called when an alarm triggers:
void MorningAlarm(){
  if(digitalRead(LED) == HIGH){
    days[LED-2] = 2;
  }
}

void LightIncrement(){
  if(LED != 8){
    LED++;
  }
  else{
    LED = 2;
  }
  //delay(1000);
  days[LED-2] = 1;
  digitalWrite(LED, HIGH);
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

