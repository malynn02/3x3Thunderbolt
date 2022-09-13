// MightyMacro Code Template
// ESP32-Enabled Macro Keyboard
// Malynn Price || September 1

// Buttons
#include <Bounce2.h>                      // Bounce2 Library
const uint8_t buttonPins[9] = {19, 18, 16, 21, 17, 4, 22, 15, 13};     // Fill in { } with list of GPIO pins
Bounce * buttons = new Bounce[9];         // Creates an array of Bounce objects

// Bluetooth
// Additional documentation available here:  https://github.com/T-vK/ESP32-BLE-Keyboard
#include <BleKeyboard.h>                  // BleKeyboard Library          
BleKeyboard bleKeyboard("3x3 Thunderbolt", "Malynn Price", 100);

void setup() {
  Serial.begin(115200);
  initButtons();                      // Initialize Buttons on Startup
  initBattery();                      // Initialize Battery on Startup
  bleKeyboard.begin();                // Begin Bluetooth Connection
}

void loop() {
  if(bleKeyboard.isConnected()){      // If Bluetooth is Connected
    readButtons();                    // Read State of Buttons and Perform Functions
    updateBattery();                  // Update Battery Status if Needed
  }
} 
