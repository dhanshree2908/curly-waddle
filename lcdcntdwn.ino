#include <LiquidCrystal.h>

int count = 20;
int flag = 0;

// Define LCD pins
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6,d7);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(7, INPUT); // Set pin 7 as input
  Serial.begin(9600);
  lcd.begin(16, 2); // Initialize LCD
}

void loop() {
  if (flag == 0) {
    int pin7Status = digitalRead(7); // Read pin 7 status
    if (pin7Status == HIGH) {
      digitalWrite(LED_BUILTIN, LOW);
      lcd.clear();
      if (count == 0) {
        digitalWrite(LED_BUILTIN, HIGH);
        lcd.setCursor(0, 0); // Set cursor to top left
        lcd.print("Count: ");
        lcd.print(count);
        Serial.println("Count: " + String(count)); // Print to serial monitor
        flag = 1;
      } else {
        lcd.setCursor(0, 0); // Set cursor to top left
        lcd.print("Count: ");
        lcd.print(count);
        Serial.println("Count: " + String(count)); // Print to serial monitor
        delay(1000);
        count = count - 1;
      }
    } else {
      lcd.setCursor(0, 0); // Set cursor to top left
      lcd.print("Power supply off");
      //lcd.clear();
      Serial.println("Power supply off"); // Print to serial monitor
      digitalWrite(LED_BUILTIN, HIGH); // Turn on LED
      while (digitalRead(7) == LOW) {
        // Wait until pin 7 goes high
      }
    }
  }
}
