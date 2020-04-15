#include<Keyboard.h>

int currstatel = HIGH;
int currstater = HIGH;
int currstated = HIGH;
int currstateu = HIGH;

long lastDebounceTimeL = 0;
long lastDebounceTimeU = 0;
long lastDebounceTimeD = 0;
long lastDebounceTimeR = 0;
long debounceDelay = 50; //ms

void setup() {
  // put your setup code here, to run once:

  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  Keyboard.begin();
  Serial.begin(9600);
}

void fire(char k) {
  Keyboard.print(k);
  Serial.println(k);
}

void loop() {
  // read
  int statel = digitalRead(2);
  int stater = digitalRead(4);
  int stated = digitalRead(6);
  int stateu = digitalRead(8);

  long t = millis();
  // act
  if (currstatel == HIGH &&
      statel == LOW &&
      (t - lastDebounceTimeL) > debounceDelay) {
    fire('L');
    lastDebounceTimeL = t;
  }
  if (currstateu == HIGH &&
      stateu == LOW &&
      (t - lastDebounceTimeU) > debounceDelay) {
    fire('U');
    lastDebounceTimeU = t;
  }
  if (currstated == HIGH &&
      stated == LOW &&
      (t - lastDebounceTimeD) > debounceDelay) {
    fire('D');
    lastDebounceTimeD = t;
  }
  if (currstater == HIGH &&
      stater == LOW &&
      (t - lastDebounceTimeR) > debounceDelay) {
    fire('R');
    lastDebounceTimeR = t;
  }


  // update
  currstatel = statel;
  currstater = stater;
  currstated = stated;
  currstateu = stateu;

  // no debounce
}
