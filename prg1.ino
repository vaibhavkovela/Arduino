#include<math.h>

void setup()
{
  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(11,OUTPUT);
}
void loop()
{ 
  for(int i=0;i<10;i++)
  {
  analogWrite(11,(255-(26*i)));
  float p = analogRead(A2);
  float vout = p / 204.6;
  float r = (11000 - vout * 1000) / vout;
  double l = (pow(r, (1 / -0.8616))) / (pow(10, (5.118 / -0.8616)));
  Serial.write("l=");
  Serial.print(l);
  Serial.print("\n");
  Serial.print(p);Serial.print("\n");
  delay(2000);
}}
