
#define DATA_PIN 4
#define CLOCK_PIN 13

void setup() {
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(1, INPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);

}

int pressState = 0;
void loop() {

  if (digitalRead(3) == LOW || digitalRead(2) == LOW || digitalRead(1) == LOW)
  {
    if (pressState == 0)
    { digitalWrite(5, LOW);
      Serial.println("pressed");
      pressState = 1;
    }
    delay(20);
  } else
  {
    digitalWrite(5, HIGH);
    pressState = 0;
  }
}
