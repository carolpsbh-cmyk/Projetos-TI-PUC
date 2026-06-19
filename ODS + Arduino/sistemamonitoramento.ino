#include <Servo.h>

// LEDs RGB
#define LED_VERMELHO 11
#define LED_VERDE 10
#define LED_AZUL 9

// Buzzer
#define BUZZER 7

// Sensor Ultrassônico
#define EMISSOR 4
#define RECEPTOR 5

// Botão
#define BOTAO 2

// Servo Motor
#define PINO_SERVO 6

// Sensores Analógicos
#define SENSOR_FLUXO A0
#define SENSOR_NIVEL A1
#define SENSOR_CALIBRACAO A2


Servo valvula;

//Variações 

int fluxoFiltrado = 0;
int nivelFiltrado = 0;
int calibracao = 0;

int limiteFluxo = 0;

long distancia = 0;

// Função do sensor ultrassônico

long medirDistancia(int emissor, int receptor)
{
  digitalWrite(emissor, LOW);
  delayMicroseconds(2);

  digitalWrite(emissor, HIGH);
  delayMicroseconds(10);

  digitalWrite(emissor, LOW);

  long duracao = pulseIn(receptor, HIGH, 30000);

  if (duracao == 0)
  {
    return -1;
  }

  return duracao * 0.055 / 2;
}

// Filtro da média móvel

int mediaMovel(int pino)
{
  int soma = 0;

  for(int i = 0; i < 5; i++)
  {
    soma += analogRead(pino);
    delay(5);
  }

  return soma / 5;
}

void rotinaTeste()
{
  Serial.println("MODO TESTE ");


  Serial.println("Testando LEDs");

  digitalWrite(LED_VERMELHO, HIGH);
  delay(500);
  digitalWrite(LED_VERMELHO, LOW);

  digitalWrite(LED_VERDE, HIGH);
  delay(500);
  digitalWrite(LED_VERDE, LOW);

  digitalWrite(LED_AZUL, HIGH);
  delay(500);
  digitalWrite(LED_AZUL, LOW);


  Serial.println("Testando buzzer");

  tone(BUZZER, 1000);
  delay(1000);
  noTone(BUZZER);

  Serial.println("Testando servo");

  valvula.write(0);
  delay(1000);

  valvula.write(90);
  delay(1000);

  valvula.write(180);
  delay(1000);


  Serial.println("Testando sensores");

  Serial.print("Fluxo: ");
  Serial.println(analogRead(SENSOR_FLUXO));

  Serial.print("Nivel: ");
  Serial.println(analogRead(SENSOR_NIVEL));

  Serial.print("Calibracao: ");
  Serial.println(analogRead(SENSOR_CALIBRACAO));

  Serial.print("Distancia: ");
  Serial.println(medirDistancia(EMISSOR, RECEPTOR));

  Serial.println("======================");
}


void setup()
{
  Serial.begin(9600);

  // LEDs

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  // Buzzer

  pinMode(BUZZER, OUTPUT);

  // Sensor Ultrassônico

  pinMode(EMISSOR, OUTPUT);
  pinMode(RECEPTOR, INPUT);

  // Botão

  pinMode(BOTAO, INPUT);

  // Servo

  valvula.attach(PINO_SERVO);

  // Inicialização

  digitalWrite(LED_VERDE, HIGH);

  tone(BUZZER, 700, 500);

  valvula.write(90);

  Serial.println("Sistema iniciado");
}


void loop()
{
// Leitura dos sensores 

  fluxoFiltrado = mediaMovel(SENSOR_FLUXO);

  nivelFiltrado = mediaMovel(SENSOR_NIVEL);

  calibracao = analogRead(SENSOR_CALIBRACAO);

  distancia = medirDistancia(EMISSOR, RECEPTOR);


  limiteFluxo = map(calibracao, 0, 1023, 300, 900);

  Serial.print("Fluxo: ");
  Serial.print(fluxoFiltrado);

  Serial.print(" | Nivel: ");
  Serial.print(nivelFiltrado);

  Serial.print(" | Limite: ");
  Serial.print(limiteFluxo);

  Serial.print(" | Distancia: ");
  Serial.println(distancia);

  if(fluxoFiltrado < limiteFluxo && distancia > 20)
  {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_VERMELHO, LOW);

    noTone(BUZZER);

    // válvula aberta
    valvula.write(90);

    Serial.println("Consumo normal");
  }

  else if(fluxoFiltrado >= limiteFluxo && distancia > 20)
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_VERMELHO, LOW);

    tone(BUZZER, 800);

    // reduz fluxo
    valvula.write(60);

    Serial.println("Consumo elevado");
  }

  if(distancia <= 20 && distancia > 0)
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_VERMELHO, HIGH);

    tone(BUZZER, 1200);

    // fecha válvula
    valvula.write(0);

    Serial.println("VAZAMENTO DETECTADO");
  }

  if(digitalRead(BOTAO) == HIGH)
  {
    Serial.println("Botao pressionado");
  }

  if(Serial.available())
  {
    char comando = Serial.read();

    if(comando == 't' || comando == 'T')
    {
      rotinaTeste();
    }
  }

  delay(300);
}
