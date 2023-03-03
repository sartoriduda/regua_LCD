#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define endereco  0x27
#define colunas   16
#define linhas    2

#define echoPin 9
#define trigPin 8
long duration;
int distance;

LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  CalcDistance();
  PrintDistance();
  delay(500);
  lcd.setCursor(0, 1);
  CalcDistance();
  PrintDistance();
  delay(500);
  lcd.clear();
  delay(300);
}

void CalcDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2;
}

void PrintDistance(){
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
}
