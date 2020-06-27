void setup() {
  pinMode(11,OUTPUT);
  pinMode(A2,INPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(11,0);
  int l=analogRead(A2);
  Serial.print(A2);
  Serial.print("\n");
}
