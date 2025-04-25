#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pinos
const int ldrPin = A0;
const int buzzerPin = 8;
const int ledVerde = 3;
const int ledAmarelo = 4;
const int ledVermelho = 5;
const int botaoPin = 2; // Pino do botão

// Blocos do "X"
byte X1[8] = {0b00000,0b00000,0b00000,0b10000,0b01000,0b00100,0b00010,0b00001};
byte X2[8] = {0b00000,0b00000,0b00000,0b00001,0b00010,0b00100,0b01000,0b10000};
byte X3[8] = {0b00001,0b00010,0b00100,0b01000,0b10000,0b00000,0b00000,0b00000};
byte X4[8] = {0b10000,0b01000,0b00100,0b00010,0b00001,0b00000,0b00000,0b00000};

// Blocos do "U"
byte U1[8] = {0b00000,0b00000,0b00000,0b01000,0b01000,0b01000,0b01000,0b01000};
byte U2[8] = {0b00000,0b00000,0b00000,0b00010,0b00010,0b00010,0b00010,0b00010};
byte U3[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b00111,0b00000,0b00000};
byte U4[8] = {0b00010,0b00010,0b00010,0b00010,0b00010,0b11100,0b00000,0b00000};

void setup() {
  // LCD
  lcd.init();
  lcd.backlight();

  // Pinos
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP); // Botão com resistor de pull-up interno
  Serial.begin(9600);

  // Caracteres personalizados
  lcd.createChar(0, U1);
  lcd.createChar(1, U2);
  lcd.createChar(2, U3);
  lcd.createChar(3, U4);
  lcd.createChar(4, X1);
  lcd.createChar(5, X2);
  lcd.createChar(6, X3);
  lcd.createChar(7, X4);

  // Animação "UX"
  lcd.setCursor(0, 0); lcd.write(byte(0));
  lcd.setCursor(1, 0); lcd.write(byte(1));
  lcd.setCursor(0, 1); lcd.write(byte(2));
  lcd.setCursor(1, 1); lcd.write(byte(3));
  tone(buzzerPin, 600, 120); // Plim mais suave // Plim
  delay(400);
  lcd.setCursor(2, 0); lcd.write(byte(4));
  lcd.setCursor(3, 0); lcd.write(byte(5));
  lcd.setCursor(2, 1); lcd.write(byte(6));
  lcd.setCursor(3, 1); lcd.write(byte(7));
  tone(buzzerPin, 700, 120); // Segundo plim // Plim
  delay(400);

  // Animação "CELLENCE"
  lcd.setCursor(5, 1); lcd.print("C"); tone(buzzerPin, 1500, 100); delay(150);
  lcd.print("E"); tone(buzzerPin, 1600, 100); delay(150);
  lcd.print("L"); tone(buzzerPin, 1700, 100); delay(150);
  lcd.print("L"); tone(buzzerPin, 1800, 100); delay(150);
  lcd.print("E"); tone(buzzerPin, 1900, 100); delay(150);
  lcd.print("N"); tone(buzzerPin, 2000, 100); delay(150);
  lcd.print("C"); tone(buzzerPin, 2100, 100); delay(150);
  lcd.print("E"); tone(buzzerPin, 2200, 100); delay(600);
  lcd.print(" *");  // Brilho à direita
  delay(300);
}

void loop() {
  int leituraBotao = digitalRead(botaoPin);

  if (leituraBotao == LOW) {  // Se o botão for pressionado (LOW)
    // Lê o valor da LDR e mapeia para 0-100
    int valorLido = analogRead(ldrPin);
    int porcentagemLuz = map(valorLido, 0, 1023, 0, 100);

    Serial.print("Luminosidade: ");
    Serial.print(porcentagemLuz);
    Serial.println(" %");

    // Atualiza o LCD com a luminosidade
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Luminosidade: ");
    lcd.setCursor(0, 1);
    lcd.print(porcentagemLuz);
    lcd.print(" %          ");
    delay(300);
    // Reset LEDs e buzzer
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzerPin);

    // Controle dos LEDs e buzzer com base na luminosidade
    if (porcentagemLuz <= 50) {
      digitalWrite(ledVerde, HIGH); // Tudo ok
    } 
    else if (porcentagemLuz > 50 && porcentagemLuz <= 75) {
      digitalWrite(ledAmarelo, HIGH); // Alerta
      tone(buzzerPin, 300, 80); // Som fraquinho
    } 
    else if (porcentagemLuz > 75) {
      digitalWrite(ledVermelho, HIGH); // Perigo
      tone(buzzerPin, 1000);           // Alarme contínuo
    }
  } 
  else {
    // Se o botão não estiver pressionado, mantém os LEDs e buzzer desligados
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzerPin);
  }

  delay(100);  // Atraso para evitar leituras rápidas demais
}