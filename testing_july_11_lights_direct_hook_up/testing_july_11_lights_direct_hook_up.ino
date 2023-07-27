void setup() {
  // put your setup code here, to run once:

pinMode(22, OUTPUT); //R on SHARP
pinMode(23, OUTPUT); //S on SHARP
pinMode(24, OUTPUT); //R on SHOOTER
pinMode(25, OUTPUT); //A on SHARP
pinMode(26, OUTPUT); //O on SHOOTER (2nd)
pinMode(27, OUTPUT); //S on SHOOTER
pinMode(28, OUTPUT); //O on SHOOTER (1st)
pinMode(29, OUTPUT); //E on SHOOTER
pinMode(30, OUTPUT); //H on SHOOTER

pinMode(32, OUTPUT); //H on SHARP
pinMode(33, OUTPUT); //T on SHOOTER
pinMode(34, OUTPUT); //Lower Bottom Bumper
pinMode(35, OUTPUT); //Top Lower Bumpers
pinMode(36, OUTPUT); //P on SHARP


}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(35, HIGH);

}
