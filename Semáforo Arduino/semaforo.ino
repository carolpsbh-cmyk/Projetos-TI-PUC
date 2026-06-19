// C++ code
//
int botaopressionado = 0;

int tempo = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  if (digitalRead(2) == HIGH) {
    tempo += 1;
    delay(1000); // Wait for 1000 millisecond(s)
    if (tempo == 24) {
      tempo = 0;
    }
    if (tempo <= 13) {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    }
    if (tempo > 13 && tempo < 15) {
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
    }
    if (tempo > 15 && tempo < 23) {
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
    }
  } else {
    if (digitalRead(2) == LOW) {
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(10, LOW);
      digitalWrite(12, LOW);
      delay(2000); // Wait for 2000 millisecond(s)
      tone(11, 932, 8000); // play tone 70 (A#5 = 932 Hz)
      digitalWrite(9, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(10, HIGH);
      delay(8000); // Wait for 8000 millisecond(s)
    }
  }
}
