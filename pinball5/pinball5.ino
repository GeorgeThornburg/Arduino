/* @file MultiKey.ino
|| @version 1.0
|| @author Mark Stanley
|| @contact mstanley@technologist.com
||
|| @description
|| | The latest version, 3.0, of the keypad library supports up to 10
|| | active keys all being pressed at the same time. This sketch is an
|| | example of how you can get multiple key presses from a keypad or
|| | keyboard.
|| #
*/

#include <Keypad.h>

const byte ROWS = 8; //four rows
const byte COLS = 5; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','4','5','6','7','8'},
  {'9','A','B','C','D','E','F','G'},
  {'H','I','J','K','L','M','N','O'},
  {'P','Q','R','S','T','U','V','W'},
  {'X','Y','Z','@','#','$','%','&'}
};
byte rowPins[ROWS] = {13, 12, 11, 10, 9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {30, 31, 32, 33, 34}; //connect to the column pinouts of the keypad

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;


void setup() {
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    msg = "";
}


void loop() {
    loopCount++;
    if ( (millis()-startTime)>5000 ) {
        Serial.print("Average loops per second = ");
        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                    if (String(kpd.key[i].kchar) == "G") { //top top bumper
                      digitalWrite(3, HIGH);
                      delay(40);
                    }
                    if (String(kpd.key[i].kchar) == "Q") { //lower top bumper
                      digitalWrite(4, HIGH);
                      delay(40);
                    }
                    if (String(kpd.key[i].kchar) == "Y") { //lower top bumper
                      digitalWrite(2, HIGH);
                      digitalWrite(4, HIGH);
                      digitalWrite(3, HIGH);
                      digitalWrite(5, HIGH);
                      delay(40);
                    }
                    if (String(kpd.key[i].kchar) == "O") { //lower bottom bumper
                      digitalWrite(3, HIGH);
                      digitalWrite(4, HIGH);
                      delay(40);
                    }
                    if (String(kpd.key[i].kchar) == "$") { //sling shot
                      digitalWrite(3, HIGH);
                      digitalWrite(4, HIGH);
                      digitalWrite(5, HIGH);
                      delay(40);
                    }
                    if (String(kpd.key[i].kchar) == "&") { //s targets
                      digitalWrite(4, HIGH);
                      digitalWrite(5, HIGH);
                      delay(80);
                    }
                    if (String(kpd.key[i].kchar) == "F") { //h targets
                      digitalWrite(4, HIGH);
                      digitalWrite(5, HIGH);
                      delay(80);
                    }
                    if (String(kpd.key[i].kchar) == "9") { //2nd o targets
                      digitalWrite(4, HIGH);
                      digitalWrite(5, HIGH);
                      delay(80);
                    }
                    if (String(kpd.key[i].kchar) == "7") { //t targets
                      digitalWrite(4, HIGH);
                      digitalWrite(5, HIGH);
                      delay(80);
                    }
                    if (String(kpd.key[i].kchar) == "N") { //e targets
                      digitalWrite(4, HIGH);
                      digitalWrite(5, HIGH);
                      delay(80);
                    }
                    if (String(kpd.key[i].kchar) == "V") { //r targets
                      digitalWrite(4, HIGH);
                      digitalWrite(5, HIGH);
                      delay(80);
                    }
                    if (String(kpd.key[i].kchar) == "C") { //ball return
                      digitalWrite(2, HIGH);
                      delay(80);
                    }
                    else {
                      //Serial.println("something else");
                      digitalWrite(2, LOW);
                      digitalWrite(3, LOW);
                      digitalWrite(4, LOW);
                      digitalWrite(5, LOW);
                      }
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(msg);
            }
        }
    }
}  // End loop
