#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempSensor = A0;
int tempReading;
int led = 13;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("The temp is now:");
  
  pinMode(led, OUTPUT); 
  
  //Serial.begin(9600);
  
}

void loop() {
  
  tempReading = analogRead(tempSensor); // take reading at pin A0
  float voltage = tempReading * 5; // re-scale to 5V/1024
  voltage /= 1024;
 
   float tempF = voltage*100; // LM34 is 10mV/F so multiple by 100 to get 1V/F
   //eg. if temp is 70F then voltage = 0.7 so multiply by 100 to show 70.
  
  float tempC = (tempF-32)*5/9;
  
  lcd.setCursor(0, 1); // point to 2nd line
  lcd.print(tempF); // print the measured temp in F
  lcd.print((char)223); // print the degree symbol
  lcd.print("F"); // print F
  lcd.print("/");
  lcd.print(tempC);
  lcd.print((char)223);
  lcd.print("C");
  digitalWrite(led, HIGH);   // make LED on pin 13 on
  delay(10); // on for 0.1sec
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);  // wait 1.9sec before re-starting loop
delay(1);
}
