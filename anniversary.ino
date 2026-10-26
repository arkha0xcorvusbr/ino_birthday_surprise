#include <Wire.h>

// Portas digitais:
const int buzzer = 8;
const int button = 7;
const int led1 = 2;
const int led2 = 3; 
const int led3 = 4;

void setup() {
  // Iniciando botão, leds e som.
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button) == LOW) {
    iniciar();

    while (digitalRead(button) == LOW) {
      delay(10);
    }
  }
}

void iniciar() {
  // Contagem regressiva:
  for (int i = 4; i > 0; i--) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    tone(buzzer, 1000, 100);
    delay(100);      
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(900);
  }
  // Explosão dos leds e som:
  playExplosion();
    delay(500);

  Serial.println("EXECUTAR_SCRIPT"); // Envia mensagem para o python, autorizando a abertura de arquivos, imagens, etc.
  playBirthday();
  stopAll();
}

void playExplosion() {
  tone(buzzer, 150, 150); 
  delay(100);

  for (int freq = 120; freq > 30; freq -= 2) {
    digitalWrite(led1, random(2));
    digitalWrite(led2, random(2));
    digitalWrite(led3, random(2));
    tone(buzzer, freq, 8);
    delay(6);
  }
  
  noTone(buzzer);
}

void playBirthday() {
  int melody[] = {
    262, 262, 294, 262, 349, 330,
    262, 262, 294, 262, 392, 349,
    262, 262, 523, 440, 349, 330, 294,
    466, 466, 440, 349, 392, 349
  };

  int noteDurations[] = {
    4, 4, 2, 2, 2, 1,
    4, 4, 2, 2, 2, 1,
    4, 4, 2, 2, 2, 2, 1,
    4, 4, 2, 2, 1, 1
  };

  for (int i = 0; i < 26; i++) {
    int duration = 1000 / noteDurations[i];

    int pinoLedAtual = 2 + (i % 3); 
    digitalWrite(pinoLedAtual, HIGH);

    tone(buzzer, melody[i], duration);
    delay(duration * 1.3);

    digitalWrite(pinoLedAtual, LOW);
    noTone(buzzer);
  }
}

void stopAll() {
  noTone(buzzer);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}