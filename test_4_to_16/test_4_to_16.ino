// Pin connections
const int outputPins[] ={A8, A9, A10, A11};

void setup() {
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  // Initialize output pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
  
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  digitalWrite(A1, LOW); // Disable LDU 1
  digitalWrite(A2, LOW); // Enable LDU 2
  digitalWrite(A3, HIGH); // Disable LDU 3
  digitalWrite(A4, LOW); // Disable LDU 4
  
  // Test all combinations
  for (int i = 0; i < 16; i++) {
    // Set the output pins according to the current combination
    for (int j = 0; j < 4; j++) {
     
      digitalWrite(outputPins[j], (i >> j) & 1);
      
    }
    
    // Print the combination
    Serial.print("Combination: ");
    for (int j = 0; j < 4; j++) {
      Serial.print((i >> j) & 1);
    }
    Serial.println();
    
    delayMicroseconds(10); // 2-second delay between tests
  }
}
