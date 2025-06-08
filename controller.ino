#include <Servo.h>

Servo sparkMax;

const int oscillationModeInputPin = 12;
const int continuousModeInputPin = 11;
const int PWMOutputPin = 9;
const int speedInputPin = A1;
const int ledPin = LED_BUILTIN;

enum mode {
  OFF, OSCILLATE, CONTINUE };
mode currentMode = OFF;

enum direction {
  FORWARD, REVERSE };
direction currentDirection = FORWARD;

const int stop = 1500;
const int maxSpeedPercent = 5;
const unsigned long reversalMillis = 2000;

int speedOutput = stop;
int blinkState = LOW;
unsigned long lastReversalMillis = 0;
unsigned long lastBlinkMillis = 0;

void setup() { 
  sparkMax.attach(PWMOutputPin);

  pinMode(ledPin, OUTPUT);

  pinMode(oscillationModeInputPin, INPUT_PULLUP);
  pinMode(continuousModeInputPin, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();

  // reverse current direction if an interval has passed
  if (currentMillis - lastReversalMillis >= reversalMillis) {
    lastReversalMillis = currentMillis;

    if (currentDirection == FORWARD) {
      currentDirection = REVERSE;
    } else {
      currentDirection = FORWARD;
    }
  }
  
  int speedInput = analogRead(speedInputPin);

  // set the LED blink interval to the range [1-2] seconds
  // and inversely proportional to the speed input
  int blinkMillis = map(speedInput, 0, 1023, 2000, 1000);

  // change the LED state if an interval has passed
  if (currentMillis - lastBlinkMillis >= blinkMillis) {
    lastBlinkMillis = currentMillis;

    if (blinkState == LOW) {
      blinkState = HIGH;
    } else {
      blinkState = LOW;
    }
  }

  // read the state of the mode selector switch
  if (digitalRead(continuousModeInputPin) == LOW) {
    currentMode = CONTINUE;
  } else if (digitalRead(oscillationModeInputPin) == LOW) {
    currentMode = OSCILLATE;
  } else {
    currentMode = OFF;
  }

  // set the outputs based on the selected control mode
  switch (currentMode) {
    case OFF: {
      digitalWrite(ledPin, LOW);
      speedOutput = stop;
    }
    break;

    case OSCILLATE: {
      digitalWrite(ledPin, blinkState);
      speedOutput = getSpeed(speedInput, currentDirection);
    }
    break;

    case CONTINUE: {
      digitalWrite(ledPin, HIGH);
      speedOutput = getSpeed(speedInput, FORWARD);
    }
    break;
  }

  sparkMax.writeMicroseconds(speedOutput);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}

int getSpeed(int input, direction dir) {
  int maxSpeed = (maxSpeedPercent * 1000 / 100) + stop;

  // map the input value to the positive output range [1500-2000]
  int speed = map(input, 0, 1023, stop, maxSpeed);

  // move the output to the negative range [1000-1500] if reversing
  if (dir == FORWARD) {
    return speed;
  } else {
    return stop + stop - speed;
  }
}
