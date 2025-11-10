int pinVermelho = 10;
int pinAzul = 9;
int pinVerde = 8;
int pinBotao = 7;
int pinPedestreVermelho = 3;
int pinPedestreVerde = 2;
int pinSecundarioVermelho = 11;
int pinSecundarioAzul = 4;
int pinSecundarioVerde = 5;

int faseSemaforo;

int estadoBotao;
int estadoAnteriorBotao;

int tempoPisca;
int estadoPisca;


void setup() {
  // put your setup code here, to run once:

  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinBotao, INPUT);
  pinMode(pinPedestreVerde, OUTPUT);
  pinMode(pinPedestreVermelho, OUTPUT);
  pinMode(pinSecundarioVerde, OUTPUT);
  pinMode(pinSecundarioAzul, OUTPUT);
  pinMode(pinSecundarioVermelho, OUTPUT);

  faseSemaforo = 1;

  estadoAnteriorBotao = digitalRead(pinBotao);

  tempoPisca = 0;
  estadoPisca = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:

  estadoBotao = digitalRead(pinBotao);

  if ((estadoBotao == HIGH) && (estadoAnteriorBotao == LOW)) {

    if (faseSemaforo < 4) {
      faseSemaforo = faseSemaforo + 1;

    } else {
      faseSemaforo = 1;
    }
  }

  estadoAnteriorBotao = estadoBotao;

  if (faseSemaforo == 1) {  // SEMAFORO ABERTO (VERDE)
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAzul, LOW);
    digitalWrite(pinVermelho, LOW);

    digitalWrite(pinPedestreVermelho, HIGH);
    digitalWrite(pinPedestreVerde, LOW);

    digitalWrite(pinSecundarioVerde, HIGH);  // SEMAFORO SECUNDARIO (VERDE)
    digitalWrite(pinSecundarioAzul, LOW);
    digitalWrite(pinSecundarioVermelho, LOW);
  }

  if (faseSemaforo == 2) {  // SEMAFORO AMARELO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, HIGH);
    digitalWrite(pinVermelho, LOW);

    digitalWrite(pinPedestreVermelho, HIGH);
    digitalWrite(pinPedestreVerde, LOW);

    digitalWrite(pinSecundarioVerde, LOW);  // SEMAFORO SECUNDARIO AMARELO (AZUL)
    digitalWrite(pinSecundarioAzul, HIGH);
    digitalWrite(pinSecundarioVermelho, LOW);
  }

  if (faseSemaforo == 3) {  // SEMAFORO FECHADO (VERMELHO)
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
    digitalWrite(pinVermelho, HIGH);

    digitalWrite(pinPedestreVermelho, LOW);
    digitalWrite(pinPedestreVerde, HIGH);

    digitalWrite(pinSecundarioVerde, LOW);  // SEMAFORO SECUNDARIO ABERTO (VERDE)
    digitalWrite(pinSecundarioAzul, LOW);
    digitalWrite(pinSecundarioVermelho, HIGH);
  }

  if (faseSemaforo == 4) {  // SEMAFORO PEDESTRE PISCANDO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
    digitalWrite(pinVermelho, HIGH);

    digitalWrite(pinSecundarioVerde, LOW);
    digitalWrite(pinSecundarioAzul, LOW);
    digitalWrite(pinSecundarioVermelho, HIGH);

    tempoPisca = tempoPisca + 1;
    if (tempoPisca == 400) {
      estadoPisca = !estadoPisca;
      tempoPisca = 0;
    }

    digitalWrite(pinPedestreVermelho, estadoPisca);
    digitalWrite(pinPedestreVerde, LOW);
  }

  delay(1);
}
