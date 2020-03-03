//Gina Gerace, 664765515, ggerac3
//Lab 3 - LCD Screen
//The code should display my name and a quote on the LCD screen.
//I expect that the quote will scroll across the screen, while my name should not scroll.
//    I also expect that the potentiometer will control the screen brightness.
//I used the Arduino "LiquidCrystalScroll" as reference.
//I also used https://forum.arduino.cc/index.php?topic=422542.0 for reference on 
//    only scrolling one line.



// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//store quote in a string and create an array to later store the quote by character
String quote = "Dont believe in isms believe in yourself";
const int len = 41;
char quoteArray[len];

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Gina Gerace");
  delay(1000);
}

void loop() {

  lcd.clear();                            //clear the screen of text from last loop
  lcd.print("Gina Gerace");               //print name again on first row
  
  lcd.setCursor(0,1);                     //set the curson to the second line
  quote.toCharArray(quoteArray, len);     //store the quote in an array
  
  //print the first 16 characters
  for(int i=0; i<=16; i++)
    lcd.write(quoteArray[i]);

  delay(1000);                            //delay so you can read

  //print the rest of the quote
  for(int j=17; j<len; j++){
    lcd.write(quoteArray[j]);
    lcd.scrollDisplayLeft();

    //keep row 1 the same
    lcd.setCursor(j-16,0);                //Set the cursor to the first character space on the first row [visually].
    lcd.print("Gina Gerace");             //Re-print the row 1 message.
    lcd.setCursor(j+1,1);                 //Set the cursor one character space to the right of the last printed character on row 2.
    delay(700);                           //delay for .3 seconds so the user has time to read.
  }

  // delay at the end of the full loop:
  delay(1000);

}
