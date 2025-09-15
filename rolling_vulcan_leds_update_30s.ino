const int leds[] = {2, 3, 4, 5, 6};
const int numLeds = 5;
const int botao = 7;

bool estado = false;          // indica se está piscando ou não
unsigned long inicioPiscar = 0; // guarda quando começou o efeito
const unsigned long duracao = 30000; // 30 segundos em ms

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  static bool botaoPressionado = false;

  // Detecta clique no botão
  if (digitalRead(botao) == LOW) {
    if (!botaoPressionado) {
      estado = true;                 // ativa efeito
      inicioPiscar = millis();       // registra tempo de início
      botaoPressionado = true;
      delay(200); // debounce simples
    }
  } else {
    botaoPressionado = false;
  }

  // Se efeito está ativo, verifica tempo
  if (estado) {
    if (millis() - inicioPiscar <= duracao) {
      // ainda dentro dos 30s → pisca aleatoriamente
      int ledIndex = random(numLeds);
      int tempoPiscar = random(10, 100);

      digitalWrite(leds[ledIndex], HIGH);
      delay(tempoPiscar);
      digitalWrite(leds[ledIndex], LOW);

      delay(random(1, 5));
    } else {
      // tempo acabou → desliga LEDs e reseta estado
      estado = false;
      for (int i = 0; i < numLeds; i++) {
        digitalWrite(leds[i], LOW);
      }
    }
  } else {
    // estado desligado → garante LEDs apagados
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
    }
  }
}
