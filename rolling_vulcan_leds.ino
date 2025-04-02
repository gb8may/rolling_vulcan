const int leds[] = {2, 3, 4, 5, 6};
const int numLeds = 5;
const int botao = 7;

bool estado = false;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  static bool botaoPressionado = false;

  if (digitalRead(botao) == LOW) {
    if (!botaoPressionado) {
      estado = !estado;
      botaoPressionado = true;
      delay(200);
    }
  } else {
    botaoPressionado = false;
  }

  if (estado) {
    int ledIndex = random(numLeds);
    int tempoPiscar = random(10, 100);

    digitalWrite(leds[ledIndex], HIGH);
    delay(tempoPiscar);
    digitalWrite(leds[ledIndex], LOW);
    
    delay(random(1, 5));
  } else {
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
    }
  }
}
