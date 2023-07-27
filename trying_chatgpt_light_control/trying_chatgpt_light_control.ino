const int numChips = 4;              // Number of 4 to 16 decoder chips
const int numLinesPerChip = 4;       // Number of output lines per chip
const int timeSlotDuration = 1;      // Time slot duration in milliseconds

// Pin connections for the chip enable lines
int enablePins[numChips] = {A1, A2, A3, A4};

// Pin connections for the output lines per chip
int outputPins[numChips][numLinesPerChip] = {
  {A8, A9, A10, A11},   // Chip 1
  {A8, A9, A10, A11},   // Chip 2
  {A8, A9, A10, A11},   // Chip 3
  {A8, A9, A10, A11}    // Chip 4
};

// Light status array (0 for OFF, 1 for ON)
int lightStatus[numChips][numLinesPerChip] = {
  {0, 0, 0, 0},  // Chip 1
  {0, 0, 0, 0},  // Chip 2
  {0, 0, 0, 0},  // Chip 3
  {0, 0, 0, 0}   // Chip 4
};

void setup() {
  // Set all enable pins as outputs
  for (int i = 0; i < numChips; i++) {
    pinMode(enablePins[i], OUTPUT);
  }

  // Set all output pins as outputs
  for (int chip = 0; chip < numChips; chip++) {
    for (int line = 0; line < numLinesPerChip; line++) {
      pinMode(outputPins[chip][line], OUTPUT);
    }
  }
}

void loop() {
  // Iterate through each time slot
  for (int timeSlot = 0; timeSlot < numLinesPerChip; timeSlot++) {
    // Activate the corresponding chip enable line
    for (int chip = 0; chip < numChips; chip++) {
      digitalWrite(enablePins[chip], LOW);  // Ground the enable line of the chip
      lightStatus[chip][timeSlot] = 1;

      // Activate the corresponding output line
      if (chip == 1) {
        // For chip 2
        if (timeSlot == 2) {
          digitalWrite(outputPins[chip][timeSlot], HIGH);
        } else {
          digitalWrite(outputPins[chip][timeSlot], LOW);
        }
      } else if (chip == 2) {
        // For chip 3
        digitalWrite(outputPins[chip][timeSlot], HIGH);
      } else {
        // For other chips
        digitalWrite(outputPins[chip][timeSlot], LOW);
      }
    }

    // Pause for the duration of the time slot
    delay(timeSlotDuration);

    // Deactivate all output lines
    for (int chip = 0; chip < numChips; chip++) {
      digitalWrite(outputPins[chip][timeSlot], LOW);
    }

    // Deactivate all chip enable lines
    for (int chip = 0; chip < numChips; chip++) {
      digitalWrite(enablePins[chip], HIGH);  // Disconnect the enable line of the chip
      lightStatus[chip][timeSlot] = 0;
    }
  }
}
