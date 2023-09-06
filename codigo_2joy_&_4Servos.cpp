#include <Servo.h>

Servo servo1, servo2, servo3, servo4; // Cria quatro objetos Servo para controlar os quatro servos

int potpin1 = A0; // Define o pino do primeiro potenciômetro
int potpin2 = A1; // Define o pino do segundo potenciômetro
int potpin3 = A2; // Define o pino do terceiro potenciômetro
int potpin4 = A3; // Define o pino do quarto potenciômetro

int servopin1 = 10; // Define o pino para o primeiro servo
int servopin2 = 11; // Define o pino para o segundo servo
int servopin3 = 12; // Define o pino para o terceiro servo
int servopin4 = 13; // Define o pino para o quarto servo

int val1 = 0; // Variável para armazenar o valor lido do primeiro potenciômetro
int val2 = 0; // Variável para armazenar o valor lido do segundo potenciômetro
int val3 = 0; // Variável para armazenar o valor lido do terceiro potenciômetro
int val4 = 0; // Variável para armazenar o valor lido do quarto potenciômetro

int s1 = 70; // Variável para armazenar a posição do primeiro servo
int s2 = 70; // Variável para armazenar a posição do segundo servo
int s3 = 70; // Variável para armazenar a posição do terceiro servo
int s4 = 70; // Variável para armazenar a posição do quarto servo

void setup()
{
  Serial.begin(9600); // Inicia a comunicação serial para depuração

  // Anexa os servos aos pinos correspondentes
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);

  // Inicializa a posição dos servos
  servo1.write(s1);
  servo2.write(s2);
  servo3.write(s3);
  servo4.write(s4);
}

void loop()
{
  // Lê os valores dos quatro potenciômetros
  val1 = analogRead(potpin1);
  val2 = analogRead(potpin2);
  val3 = analogRead(potpin3);
  val4 = analogRead(potpin4);

  // Controle do Servo 1 com base no Potenciômetro 1
  if (val1 < 164)
  {
    s1 = s1 - 5;
    if (s1 <= 10)
      s1 = 10;
    servo1.write(s1);
    delay(100);
  }
  if (val1 > 800)
  {
    s1 = s1 + 5;
    if (s1 >= 120)
      s1 = 120;
    servo1.write(s1);
    delay(100);
  }

  // Controle do Servo 2 com base no Potenciômetro 2
  if (val2 < 164)
  {
    s2 = s2 - 5;
    if (s2 <= 10)
      s2 = 10;
    servo2.write(s2);
    delay(100);
  }
  if (val2 > 800)
  {
    s2 = s2 + 5;
    if (s2 >= 120)
      s2 = 120;
    servo2.write(s2);
    delay(100);
  }

  // Controle do Servo 3 com base no Potenciômetro 3
  if (val3 < 150)
  {
    s3 = s3 - 5;
    if (s3 <= 10)
      s3 = 10;
    servo3.write(s3);
    delay(100);
  }
  if (val3 > 350)
  {
    s3 = s3 + 5;
    if (s3 >= 120)
      s3 = 120;
    servo3.write(s3);
    delay(100);
  }

  // Controle do Servo 4 com base no Potenciômetro 4
  if (val4 < 164)
  {
    s4 = s4 - 5;
    if (s4 <= 10)
      s4 = 10;
    servo4.write(s4);
    delay(100);
  }
  if (val4 > 800)
  {
    s4 = s4 + 5;
    if (s4 >= 120)
      s4 = 120;
    servo4.write(s4);
    delay(100);
  }

  // Imprime informações de depuração
  Serial.print("Servo 1: ");
  Serial.print(s1);
  Serial.print("\t");
  Serial.print("Potenciometro 1: ");
  Serial.print(val1);
  Serial.print("\t");

  Serial.print("Servo 2: ");
  Serial.print(s2);
  Serial.print("\t");
  Serial.print("Potenciometro 2: ");
  Serial.print(val2);
  Serial.print("\t");

  Serial.print("Servo 3: ");
  Serial.print(s3);
  Serial.print("\t");
  Serial.print("Potenciometro 3: ");
  Serial.print(val3);
  Serial.print("\t");

  Serial.print("Servo 4: ");
  Serial.print(s4);
  Serial.print("\t");
  Serial.print("Potenciometro 4: ");
  Serial.print(val4);
  Serial.println();
}
