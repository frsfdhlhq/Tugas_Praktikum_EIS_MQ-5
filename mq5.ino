#include <LiquidCrystal.h> // Sertakan library LiquidCrystal

// Pin LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define ledPin 7  // Pin LED
#define buzzerPin 8 // Pin buzzer
#define Sensor A0 // Pin sensor MQ-5

void setup() {
  pinMode(Sensor, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2); // Inisialisasi LCD 16x2
  Serial.begin(9600);
  Serial.println("MQ5 Heating Up!");
  delay(2000); // Waktu pemanasan sensor
}

void loop() {
  int gas_value = analogRead(Sensor);
  Serial.print("Sensor Value: ");
  Serial.println(gas_value);

  lcd.setCursor(0, 0); // Atur kursor ke baris pertama, kolom pertama
  lcd.print("Sensor: ");
  lcd.print(gas_value);

  if (gas_value > 100) { // Atur ambang batas sesuai kebutuhan
    digitalWrite(ledPin, HIGH); // Nyalakan LED
    digitalWrite(buzzerPin, HIGH); // Nyalakan buzzer
    lcd.setCursor(0, 1); // Atur kursor ke baris kedua, kolom pertama
    lcd.print("Gas Terdeteksi!");
  } else {
    digitalWrite(ledPin, LOW); // Matikan LED
    digitalWrite(buzzerPin, LOW); // Matikan buzzer
    lcd.setCursor(0, 1); 
    lcd.print("Aman           "); // Bersihkan baris kedua
  }
}
