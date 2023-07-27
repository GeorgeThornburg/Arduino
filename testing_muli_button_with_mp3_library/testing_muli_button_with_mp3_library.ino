

#include <Keypad.h>
const byte ROWS = 8; //four rows
const byte COLS = 5; //four columns

//outhole = 3
//Kickout hole = B
//lower bottom bumper = O
//lower top bumper = Y
//upper top bumper = G
//lower top bumber = Q
//sling shot = $
//rails = X (worth 10 points)
//S in SHOOTER = &
//H in SHOOTER = F
//1st O in SHOOTER = 4
//2nd O in SHOOTER = 9
//T in SHOOTER = 7
//E in SHOOTER = N
//R in SHOOTER = 3
//Loop 1 = Z
//Loop 2 = 5
//Loop 3 = A
//Loop 4 = U
//Loop 5 = K
//S in SHARP = J
//H in SHARP = T
//A in SHARP = 8
//R in SHARP = I
//P in SHARP = S
// 50k lane = %
//Spinner = @
//Special = L
//Extra = D
//Start Game Button = C
//1k lane = E (1000 points)
//Top Target = 1
//Bottom Target = 1


int targets = 0;

//define the cymbols on the buttons of the keypads
char hexaKeys[COLS][ROWS] = {
  {'1','2','3','4','5', '6','7','8'},
  {'9','A','B','C','D','E','F', 'G'},
  {'H','I','J','K', 'L','M','N','O'},
  {'P','Q','R','S','T','U', 'V','W'},
  {'X','Y','Z','@','#','$','%','&'}
};
byte rowPins[ROWS] = {13, 12, 11, 10, 9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {30, 31, 32, 33, 34}; //connect to the column pinouts of the keypad
 
//initialize an instance of class NewKeypad
Keypad kpd = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
String msg; 
void setup(){
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  msg = "";
  
 
}

void loop(){
  digitalWrite(2, LOW);
  digitalWrite(A0, LOW); //audio board
  digitalWrite(47, LOW); //start game // return ball --whistle sound - white wire
  digitalWrite(48, LOW); //targets - gunshot - red wire
  digitalWrite(49, LOW); //roll over - random buzz - yellow wire
  digitalWrite(50, LOW); //out hole - reach for the sky - blue wire
  digitalWrite(51, LOW); //bumpers - coins - grey
  digitalWrite(52, LOW); //slingshot -richocet sound - black wire
  digitalWrite(53, LOW); //horse-gallop - green wire
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  if (targets > 6) {
    targets = 0;
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(80);
  }

    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                      switch (kpd.key[i].kchar) {
                        case '3': //outhole
                            targets = 0;
                            digitalWrite(A0, HIGH);
                            delay(500);
                            digitalWrite(A0, LOW);
                            delay(3000);
                            digitalWrite(47, HIGH); //start game // return ball --whistle sound
                            digitalWrite(2, HIGH);
                            delay(80);
                            digitalWrite(2, LOW);
                            delay(80);
                            digitalWrite(4, HIGH);
                            digitalWrite(5, HIGH);
                            delay(80);
                            break;

                        case '@': //horse
                            digitalWrite(53, HIGH); //horse
                            delay(80);
                            break;
                        case '&': //s in shooter
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(80);
                            Serial.print(String(targets));
                            break;
                        case 'F': //h in shooter
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(80);
                            break;
                        case '4': //o in shooter
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(80);
                            break;
                        case '9': //o in shooter
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(80);
                            break;
                        case '7': //t in shooter
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(80);
                            break;
                        case 'N': //e in shooter
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(80);
                            break;
                        case 'V': //r in shooter
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(80);
                            break;
                            break;
                        case 'O': //lower bottom target
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(3, HIGH);
                            digitalWrite(4, HIGH);
                            delay(80);
                            break;
                        case 'G': //upper bottom target
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(3, HIGH);
                            delay(80);
                            break;
                        case 'Y': //lower bottom target
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(2, HIGH);
                            digitalWrite(4, HIGH);
                            digitalWrite(3, HIGH);
                            digitalWrite(5, HIGH);
                            delay(80);
                            break;
                        case 'Q': //lower top target
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(4, HIGH);
                            delay(80);
                            break;
                        case '$': //lower top target
                            digitalWrite(52, HIGH); //slingshot
                            digitalWrite(3, HIGH);
                            digitalWrite(4, HIGH);
                            digitalWrite(5, HIGH);
                            delay(80);
                            break;
                        case 'B': //lower top target
                            digitalWrite(50, HIGH); //OUT HOLE
                            delay(3000);
                            digitalWrite(2, HIGH);
                            digitalWrite(3, LOW);
                            digitalWrite(4, LOW);
                            digitalWrite(5, HIGH);
                            delay(80);
                            break;
                        case 'X': //lower top target
                            digitalWrite(52, HIGH); //slingshot
                            delay(80);
                            break;
                        case 'D': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(80);
                            break;
                        case 'L': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(80);
                            break;
                        case 'J': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(80);
                            break;
                        case 'T': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(80);
                            break;
                        case 'E': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(80);
                            break;
                        }
                    msg = " PRESSED.";
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
 
}
