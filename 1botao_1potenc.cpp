#include <Servo.h>

Servo motor1;
Servo motor2;

int pos1 = 0;  // Posição inicial do motor 1
int pos2 = 0;  // Posição inicial do motor 2
int pino_bot1 = 4;  // Pino onde o botão está conectado
int pino_potenciometro = A3;  // Pino analógico onde o potenciômetro está conectado
int motorSelecionado = 1;  // Variável para rastrear o motor selecionado

void setup() {
  motor1.attach(11);  // Anexa o motor 1 ao pino 11
  motor2.attach(3);  // Anexa o motor 2 ao pino 10
  pinMode(pino_bot1, INPUT_PULLUP);  // Configura o botão como entrada com resistor pull-up
  Serial.begin(9600);
  motor1.write(pos1);
  motor2.write(pos2);
}

void loop() {
  int botao1 = digitalRead(pino_bot1);  // Lê o estado do botão
  int valorPotenciometro = analogRead(pino_potenciometro);  // Lê o valor do potenciômetro

  // Verifique se o botão foi pressionado
  if (botao1 == LOW) {
    // Alterna entre os motores
    motorSelecionado = (motorSelecionado == 1) ? 2 : 1;
    delay(200); // Pequeno atraso para evitar leituras múltiplas ao pressionar o botão
  }

  // Mova o motor selecionado com base no valor do potenciômetro
  if (motorSelecionado == 1) {
    pos1 = map(valorPotenciometro, 0, 1023, 0, 180);  // Mapeie o valor do potenciômetro para o intervalo de ângulo do servo
    motor1.write(pos1);  // Mova o motor 1 para a posição
  } else {
    pos2 = map(valorPotenciometro, 0, 1023, 0, 180);  // Mapeie o valor do potenciômetro para o intervalo de ângulo do servo
    motor2.write(pos2);  // Mova o motor 2 para a posição
  }

  // Saída de informações para monitor serial
  Serial.print("Motor Selecionado: ");
  Serial.println(motorSelecionado);
  Serial.print("Posição do Motor 1: ");
  Serial.println(pos1);
  Serial.print("Posição do Motor 2: ");
  Serial.println(pos2);

  delay(100); // Pequeno atraso para estabilidade
}
