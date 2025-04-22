const int leds[] = {2, 3, 4, 5, 6};
const int numLeds = 5;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  randomSeed(analogRead(0));
}

void loop() {
  int ledIndex = random(numLeds);
  int tempoPiscar = random(10, 100);

  digitalWrite(leds[ledIndex], HIGH);
  delay(tempoPiscar);
  digitalWrite(leds[ledIndex], LOW);
  
  delay(random(1, 5));
}
