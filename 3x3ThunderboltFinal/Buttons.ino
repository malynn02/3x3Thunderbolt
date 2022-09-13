// Functions for Button Control

int numButtons = 9; // the number of buttons
int charDelay = 10; // Amount of time between keypresses to avoid key buffer overflows
String sadCat = "https://tenor.com/view/rip-juice-cry-cat-kitten-tears-gif-15751834";
String thumbsUpRat = "https://tenor.com/view/rat-thumbs-up-meme-funny-fortune-cookie-gif-25069738";
String beanBurrito = "https://tenor.com/view/the-legend-of-zelda-botw-link-breath-of-the-wild-gif-22342421";


// initButtons loops through the array of Bounce2 buttons and attaches them as inputs
// It also sets an interval of 25ms for responsiveness
void initButtons() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT);  // Attaches the buttons in the array
    buttons[i].interval(25);                  // Interval for buttons in the array
  }
}

// readButtons loops through the array of Bounce2 buttons and updates each of them.
// It then checks to see if any button has risen and calls sendKey() if it has.
void readButtons() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].update();          // Updates state of first button
    if (buttons[i].rose()) {      // Returns true/false if button press
      sendKey(i);
    }
  }
}

// sendKey takes one argument (int k) and uses a switch/case structure to either call the
// sendShortcut(), sendCompount(), or sendMacro() functions. You can also create your own custom functions if needed.
void sendKey(int k) {
  switch (k) {
    case 0: sendCompoundCMDALTUP(); break;              // SERVER NAV UP
    case 1: sendShortcutALTUP(); break;                 // CHANNEL NAV UP
    case 2: sendCompoundCMDSHIFT('m'); break;           // MUTE
    case 3: sendCompoundCMDALTDOWN(); break;            // SERVER NAV DOWN
    case 4: sendShortcutALTDOWN(); break;               // CHANNEL NAV DOWN
    case 5: sendCompoundCMDSHIFT('d'); break;           // DEAFEN
    case 6: sendMacro(sadCat, charDelay); break;        // SEND SAT CAT GIF
    case 7: sendMacro(thumbsUpRat, charDelay); break;   // SEND THUMBS UP GIF
    case 8: sendMacro(beanBurrito, charDelay); break;   // SEND BEAN BURRITO GIF
  }

}

// sendShortcutALTUP combines ALT and the up arrow key
void sendShortcutALTUP() {
  bleKeyboard.press(KEY_LEFT_ALT);
  delay(charDelay);
  bleKeyboard.press(KEY_UP_ARROW);
  delay(charDelay);
  bleKeyboard.release(KEY_UP_ARROW);
  delay(charDelay);
  bleKeyboard.release(KEY_LEFT_ALT);
  delay(charDelay);
  bleKeyboard.releaseAll();
}

// sendShortcutALTDOWN combines ALT and the down arrow key
void sendShortcutALTDOWN() {
  bleKeyboard.press(KEY_LEFT_ALT);
  delay(charDelay);
  bleKeyboard.press(KEY_DOWN_ARROW);
  delay(charDelay);
  bleKeyboard.release(KEY_DOWN_ARROW);
  delay(charDelay);
  bleKeyboard.release(KEY_LEFT_ALT);
  delay(charDelay);
  bleKeyboard.releaseAll();
}

// sendCompoundCMDALTUP combines CMD, ALT, and the up arrow key
void sendCompoundCMDALTUP() {
  bleKeyboard.press(KEY_LEFT_GUI);
  delay(charDelay);
  bleKeyboard.press(KEY_LEFT_ALT);
  delay(charDelay);
  bleKeyboard.press(KEY_UP_ARROW);
  delay(charDelay);
  bleKeyboard.release(KEY_UP_ARROW);
  delay(charDelay);
  bleKeyboard.release(KEY_LEFT_ALT);
  delay(charDelay);
  bleKeyboard.release(KEY_LEFT_GUI);
  delay(charDelay);
  bleKeyboard.releaseAll();
}

// sendCompoundCMDALTDOWN combines CMD, ALT, and the down arrow key
void sendCompoundCMDALTDOWN() {
  bleKeyboard.press(KEY_LEFT_GUI);
  delay(charDelay);
  bleKeyboard.press(KEY_LEFT_ALT);
  delay(charDelay);
  bleKeyboard.press(KEY_DOWN_ARROW);
  delay(charDelay);
  bleKeyboard.release(KEY_DOWN_ARROW);
  delay(charDelay);
  bleKeyboard.release(KEY_LEFT_ALT);
  delay(charDelay);
  bleKeyboard.release(KEY_LEFT_GUI);
  delay(charDelay);
  bleKeyboard.releaseAll();
}

// sendCompound takes one argument (char c) and combines it with multiple modifiers CMD & SHIFT
void sendCompoundCMDSHIFT(char c) {
  bleKeyboard.press(KEY_LEFT_GUI);
  delay(charDelay);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  delay(charDelay);
  bleKeyboard.press(c);
  delay(charDelay);
  bleKeyboard.release(c);
  delay(charDelay);
  bleKeyboard.release(KEY_LEFT_SHIFT);
  delay(charDelay);
  bleKeyboard.release(KEY_LEFT_GUI);
  delay(charDelay);
  bleKeyboard.releaseAll();
}

// sendMacro takes one argument (String s) and sends the string one character at a time.
void sendMacro(String s, int d) {
  int l = s.length() + 1;           // Determine length of string
  char c[l];                        // Create array for characters
  s.toCharArray(c, l);              // Copy characters to array
  for (int i = 0; i < l - 1; i++) { // Loop through character array
    char p = c[i];                  // Get the current character
    bleKeyboard.press(p); delay(d); // Press/Release the key w/ delay
    bleKeyboard.release(p); delay(d);
  }
  bleKeyboard.press(KEY_RETURN);
  delay(d);
  bleKeyboard.release(KEY_RETURN);
  delay(d);
  bleKeyboard.releaseAll();
}
