

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
int sLight = 0;
int hLight = 0;
int o1Light = 0;
int o2Light = 0;
int tLight = 0;
int eLight = 0;
int rLight = 0;

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
  
  pinMode(A0, OUTPUT);
//  pinMode(A1, OUTPUT);
//  pinMode(A2, OUTPUT);
//  pinMode(A3, OUTPUT);
//  pinMode(A4, OUTPUT);
//  pinMode(A8, OUTPUT);
//  pinMode(A9, OUTPUT);
//  pinMode(A10, OUTPUT);
//  pinMode(A11, OUTPUT);
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
  Serial.begin(115200);
 
}



void loop(){
  digitalWrite(2, LOW);
  digitalWrite(A0, LOW); //audio board
//  digitalWrite(A1, LOW); //Enable LDU 1
//  digitalWrite(A2, LOW); //Enable LDU 2
//  digitalWrite(A3, LOW); //Enable LDU 3
//  digitalWrite(A4, LOW); //Enable LDU 4
//  digitalWrite(A8, LOW); //Pin 1 for 4-to-16
//  digitalWrite(A9, LOW); //Pin 2 for 4-to-16
//  digitalWrite(A10, LOW); //Pin 3 for 4-to-16
//  digitalWrite(A11, LOW); //Pin 4 for 4-to-16

  
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
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  



  //put function to control lights here
 if (sLight == 1){
     digitalWrite(A2, LOW);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     digitalWrite(A10, HIGH);  // A10 - LOW
     digitalWrite(A2, HIGH);  // A10 - LOW
     digitalWrite(A2, LOW);  // A10 - LOW
     //delay(.5);
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     delay(1);
     
 }
 if (sLight == 0) {
     digitalWrite(A2, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
 }
 if (hLight == 1){
     digitalWrite(A2, LOW);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     digitalWrite(A8, HIGH);  // A10 - LOW
     digitalWrite(A9, HIGH);  // A10 - LOW
     digitalWrite(A10, HIGH);  // A10 - LOW
     digitalWrite(A11, HIGH);  // A10 - LOW
     digitalWrite(A3, HIGH);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     //delay(1);
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     delay(1);
     
  
 }

  if (hLight == 0) {

      digitalWrite(A3, LOW);  // A10 - LOW
      digitalWrite(A8, LOW);  // A10 - LOW
      digitalWrite(A9, LOW);  // A10 - LOW
      digitalWrite(A10, LOW);  // A10 - LOW
      digitalWrite(A11, LOW);  // A10 - LOW
 }

 if (o1Light == 1){
     digitalWrite(A2, LOW);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, HIGH);  // A10 - LOW
     digitalWrite(A11, HIGH);  // A10 - LOW
     digitalWrite(A3, HIGH);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     //delay(1);
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     delay(1);
     
  
 }

  if (o1Light == 0) {

      digitalWrite(A3, LOW);  // A10 - LOW
      digitalWrite(A8, LOW);  // A10 - LOW
      digitalWrite(A9, LOW);  // A10 - LOW
      digitalWrite(A10, LOW);  // A10 - LOW
      digitalWrite(A11, LOW);  // A10 - LOW
 }

  if (o2Light == 1){
     digitalWrite(A2, LOW);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     digitalWrite(A8, HIGH);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     digitalWrite(A2, HIGH);  // A10 - LOW
     digitalWrite(A2, LOW);  // A10 - LOW
     //delay(1);
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     delay(1);
     
  
 }

  if (o2Light == 0) {

      digitalWrite(A2, LOW);  // A10 - LOW
      digitalWrite(A8, LOW);  // A10 - LOW
      digitalWrite(A9, LOW);  // A10 - LOW
      digitalWrite(A10, LOW);  // A10 - LOW
      digitalWrite(A11, LOW);  // A10 - LOW
 }

   if (tLight == 1){
     digitalWrite(A2, LOW);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     digitalWrite(A8, HIGH);  // A10 - LOW
     digitalWrite(A9, HIGH);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     digitalWrite(A3, HIGH);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     //delay(1);
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     delay(1);
     
  
 }

  if (tLight == 0) {

      digitalWrite(A3, LOW);  // A10 - LOW
      digitalWrite(A8, LOW);  // A10 - LOW
      digitalWrite(A9, LOW);  // A10 - LOW
      digitalWrite(A10, LOW);  // A10 - LOW
      digitalWrite(A11, LOW);  // A10 - LOW
 }
    
   if (eLight == 1){
     digitalWrite(A2, LOW);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, HIGH);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     digitalWrite(A3, HIGH);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     //delay(1);
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     delay(1);
     
  
 }

  if (eLight == 0) {

      digitalWrite(A3, LOW);  // A10 - LOW
      digitalWrite(A8, LOW);  // A10 - LOW
      digitalWrite(A9, LOW);  // A10 - LOW
      digitalWrite(A10, LOW);  // A10 - LOW
      digitalWrite(A11, LOW);  // A10 - LOW
 }

    if (rLight == 1){
     digitalWrite(A2, LOW);  // A10 - LOW
     digitalWrite(A3, LOW);  // A10 - LOW
     digitalWrite(A8, HIGH);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, HIGH);  // A10 - LOW
     digitalWrite(A2, HIGH);  // A10 - LOW
     digitalWrite(A2, LOW);  // A10 - LOW
     //delay(1);
     digitalWrite(A8, LOW);  // A10 - LOW
     digitalWrite(A9, LOW);  // A10 - LOW
     digitalWrite(A10, LOW);  // A10 - LOW
     digitalWrite(A11, LOW);  // A10 - LOW
     delay(1);
     
  
 }

  if (rLight == 0) {

      digitalWrite(A2, LOW);  // A10 - LOW
      digitalWrite(A8, LOW);  // A10 - LOW
      digitalWrite(A9, LOW);  // A10 - LOW
      digitalWrite(A10, LOW);  // A10 - LOW
      digitalWrite(A11, LOW);  // A10 - LOW
 }

  if (targets > 6) {
    delay(500);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    targets = 0 ;
    sLight = 0;
    hLight = 0;
    o1Light = 0;
    o2Light = 0;
    tLight = 0;
    eLight = 0;
    rLight = 0;
    //digitalWrite(48, HIGH); //targets - gunshot - red wire
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

                            digitalWrite(A0, HIGH);
                            delay(500);
                            digitalWrite(A0, LOW);
                            delay(3000);
                            digitalWrite(47, HIGH); //start game // return ball --whistle sound
                            digitalWrite(2, HIGH);
                            delay(100);
                            digitalWrite(2, LOW);
                            delay(100);
                            digitalWrite(4, HIGH);
                            digitalWrite(5, HIGH);
                            delay(100);
                            targets = 0;
                            sLight = 0;
                            hLight = 0;
                            o1Light = 0;
                            o2Light = 0;
                            tLight = 0;
                            eLight = 0;
                            rLight = 0;
                            break;

                        case '@': //horse
                            digitalWrite(53, HIGH); //horse
                            delay(100);
                            break;
                        case '&': //s in shooter
                            targets = targets + 1;
                            sLight = 1;
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'F': //h in shooter
                            hLight = 1;
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case '4': //o in shooter
                            o1Light = 1;
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                            
                        case '9': //o in shooter
                            o2Light = 1;
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case '7': //t in shooter
                            tLight = 1;
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'N': //e in shooter
                            eLight = 1;
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'V': //r in shooter
                            rLight = 1;
                            targets = targets + 1;
                            digitalWrite(48, HIGH); //horse
                            delay(100);
                            break;
                        case 'O': //lower bottom target
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(3, HIGH);
                            digitalWrite(4, HIGH);
                            delay(100);
                            break;
                        case 'G': //upper bottom target
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(3, HIGH);
                            delay(100);
                            break;
                        case 'Y': //lower bottom target
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(2, HIGH);
                            digitalWrite(4, HIGH);
                            digitalWrite(3, HIGH);
                            digitalWrite(5, HIGH);
                            delay(100);
                            break;
                        case 'Q': //lower top target
                            digitalWrite(51, HIGH); //bumpers
                            digitalWrite(4, HIGH);
                            delay(100);
                            break;
                        case '$': //lower top target
                            digitalWrite(52, HIGH); //slingshot
                            digitalWrite(3, HIGH);
                            digitalWrite(4, HIGH);
                            digitalWrite(5, HIGH);
                            delay(100);
                            break;
                        case 'B': //lower top target
                            digitalWrite(50, HIGH); //OUT HOLE
                            delay(3000);
                            digitalWrite(2, HIGH);
                            digitalWrite(3, LOW);
                            digitalWrite(4, LOW);
                            digitalWrite(5, HIGH);
                            delay(100);
                            break;
                        case 'X': //lower top target
                            digitalWrite(52, HIGH); //slingshot
                            delay(100);
                            break;
                        case 'D': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'L': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'J': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'T': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
                            break;
                        case 'E': //lower top target
                            digitalWrite(49, HIGH); //roll over
                            delay(100);
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
