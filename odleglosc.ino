#define DS_PIN 8
#define STCP_PIN 9
#define SHCP_PIN 10
#define TRIG 2
#define ECHO 3

void setup()
{
  pinMode(DS_PIN , OUTPUT);
  pinMode(STCP_PIN , OUTPUT);
  pinMode(SHCP_PIN , OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
  writeReg();
}

boolean registers[8];
float distance;
int diodeAmount;

void writeReg()
{
  digitalWrite(STCP_PIN , LOW);
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(SHCP_PIN , LOW);
    digitalWrite(DS_PIN , registers[i] );
    digitalWrite(SHCP_PIN, HIGH);
  }
  digitalWrite(STCP_PIN, HIGH);
}

void setDiodes(float distance){
    diodeAmount=((int)(distance/25));
  if(diodeAmount>7)
  diodeAmount=7;
  
  for (int i = 0; i < 8; i++)
  {
    if (i < diodeAmount) {
      registers[i] = LOW;
    } else {
      registers[i] = HIGH;
    }
    writeReg();
  }
}

void loop()
{
  distance = checkDistance();
  Serial.print(distance, 1);
  Serial.println(" cm");
  setDiodes(distance);
  delay(250);
}

