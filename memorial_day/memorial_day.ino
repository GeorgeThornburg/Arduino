// Pin connections
const int outputPins[] = {A8, A9, A10, A11};

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
  // Enable LDU 1 (A1)
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  
  // Test all combinations
  for (int i = 0; i < 16; i++) {
    // Set the output pins according to the current combination
    for (int j = 0; j < 4; j++) {
      digitalWrite(outputPins[j], (i >> j) & 1);
      //Serial.println(outputPins[j], (i >> j) & 1);
    }
    
    // Print the combination
    Serial.print("Combination: ");
    for (int j = 0; j < 4; j++) {
      Serial.print((i >> j) & 1);
    }
    Serial.println();
    
    delay(1500); // 5-second delay between tests
  }

  // Enable LDU 2 (A2)
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  
  // Test all combinations
  for (int i = 0; i < 16; i++) {
    // Set the output pins according to the current combination
    for (int j = 0; j < 4; j++) {
      digitalWrite(outputPins[j], (i >> j) & 1);
      Serial.println(outputPins[j], (i >> j) & 1);
    }
    
    // Print the combination
    Serial.print("Combination: ");
    for (int j = 0; j < 4; j++) {
      Serial.print((i >> j) & 1);
    }
    Serial.println();
    
    delay(1500); // 5-second delay between tests
  }
  
  // Enable LDU 3 (A3)
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, LOW);
  
  // Test all combinations
  for (int i = 0; i < 16; i++) {
    // Set the output pins according to the current combination
    for (int j = 0; j < 4; j++) {
      digitalWrite(outputPins[j], (i >> j) & 1);
      Serial.println(outputPins[j], (i >> j) & 1);
    }
    
    // Print the combination
    Serial.print("Combination: ");
    for (int j = 0; j < 4; j++) {
      Serial.print((i >> j) & 1);
    }
    Serial.println();
    
    delay(1500); // 5-second delay between tests
  }
  
  // Enable LDU 4 (A4)
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, HIGH);
  
  // Test all combinations
  for (int i = 0; i < 16; i++) {
    // Set the output pins according to the current combination
    for (int j = 0; j < 4; j++) {
      digitalWrite(outputPins[j], (i >> j) & 1);
      Serial.println(outputPins[j], (i >> j) & 1);
    }
    
    // Print the combination
    Serial.print("Combination: ");
    for (int j = 0; j < 4; j++) {
      Serial.print((i >> j) & 1);
    }
    Serial.println();
    
    delay(1500); // 5-second delay between tests
  }
}
