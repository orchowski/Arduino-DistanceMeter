#define TRIG 2
#define ECHO 3
void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}


void loop() {
  Serial.print(checkDistance(),1);
  Serial.println(" cm");
  delay(250);
}

