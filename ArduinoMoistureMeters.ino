const int dry1 = 506;
const int wet1 = 187;

const int dry2 = 507;
const int wet2 = 192;

const int dry3 = 506;
const int wet3 = 188;

const int dry4 = 515;
const int wet4 = 202;

const int dry5 = 506;
const int wet5 = 193;

const int dry6 = 506;
const int wet6 = 192;

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int LED6 = 8;
void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

void loop() {
  int sensorVal1 = analogRead(A0);
  int sensorVal2 = analogRead(A1);
  int sensorVal3 = analogRead(A2);
  int sensorVal4 = analogRead(A3);
  int sensorVal5 = analogRead(A4);
  int sensorVal6 = analogRead(A5);
  //Serial.println(analogRead(A5));
  Serial.println(analogRead(A3));
  Serial.println(analogRead(A4));

  int MonsteraHumidity = map(sensorVal1, wet1, dry1, 100, 0);
  int PothosHumidity = map(sensorVal2, wet2, dry2, 100, 0);
  int PitcherHumidity = map(sensorVal3, wet3, dry3, 100, 0);
  int VenusHumidity = map(sensorVal4, wet4, dry4, 100, 0);
  int AloeHumidity = map(sensorVal5, wet5, dry5, 100, 0);
  int FalseAraliaHumidity = map(sensorVal6, wet6, dry6, 100, 0);
  Serial.print("Meter 1: ");
  Serial.print(MonsteraHumidity);
  Serial.println("%");
  Serial.print("Meter 2: ");
  Serial.print(PothosHumidity);
  Serial.println("%");
  Serial.print("Meter 3: ");
  Serial.print(PitcherHumidity);
  Serial.println("%");
  Serial.print("Meter 4: ");
  Serial.print(VenusHumidity);
  Serial.println("%");
  Serial.print("Meter 5: ");
  Serial.print(AloeHumidity);
  Serial.println("%");
  Serial.print("Meter 6: ");
  Serial.print(FalseAraliaHumidity);
  Serial.println("%");

  if (MonsteraHumidity < 40){
    digitalWrite(LED1,HIGH);
  }else{
    digitalWrite(LED1,LOW);
  }
  if (PothosHumidity < 40){
    digitalWrite(LED2,HIGH);
  }else{
    digitalWrite(LED2,LOW);
  }
  if (PitcherHumidity < 55){
    digitalWrite(LED3,HIGH);
  }else{
    digitalWrite(LED3,LOW);
  }
  if (VenusHumidity < 50){
    digitalWrite(LED4,HIGH);
  }else{
    digitalWrite(LED4,LOW);
  }
  if (AloeHumidity < 10){
    digitalWrite(LED5,HIGH);
  }else{
    digitalWrite(LED5,LOW);
  }
  if (FalseAraliaHumidity < 55){
    digitalWrite(LED6,HIGH);
  }else{
    digitalWrite(LED6,LOW);
  }
  delay(1000);
}
