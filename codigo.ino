
int botonAtras = 5;

int trigger_pin = 13;
int echo_pin = 4;
int time;
int distance;

int buzzer = 7;


int IN1 = 2;
int IN2 = 3;
int ENA = 9;


int IN3 = 11;
int IN4 = 12;
int ENB = 10;

unsigned long tiempoAnterior = 0;
bool sonido = false;

void setup()
{
  Serial.begin(9600);

  pinMode(botonAtras, INPUT_PULLUP);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{

  if (digitalRead(botonAtras) == LOW)
  {
    atras();
  }
  else
  {
    detener();
  }


  digitalWrite(trigger_pin, 0);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, 1);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, 0);

  time = pulseIn(echo_pin, HIGH, 25000);
  distance = (time * 0.034)/2;

  

if(time == 0 || distance > 100){
  noTone(buzzer);
}

if(time > 0 && distance >= 31 && distance <= 100){
  tone(buzzer, 1000);
}

if(time > 0 && distance >= 0 && distance <= 30){
  tone(buzzer, 2000);
}
}

void atras()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void detener()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
