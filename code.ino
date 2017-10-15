#include <math.h>

double finalArray[7][3] = 
{
    {52,0.77,-69.75},
    {353,0.14,-29.7},
    {563,0.099,9.2236},
    {871,0.15,27.5},
    {920,0.34,77.5},
    {960,0.55,93.6},
    {1023,2.98,78.94}
    };

    
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(A0, INPUT);

} 

double Temprature(int RawADC, double a, double b) {
   double Temp;
   Temp = a*RawADC + b;
   Serial.println(a);
   Serial.println(b);
   return Temp;
}
  


int increment = 0;
int i = 0;
bool value = true;
int v = 0;

void loop() {
  i = -1;
  value = true;
  v = analogRead(A0);
  Serial.print(int(v));
  Serial.print("  Measure ");
  Serial.print(int(increment));
  Serial.print(" : ");
  while((i<=6) && (value))
  {
    i++;
    if(v <= finalArray[i][0])
    {
      value = false;
      Serial.println(i);
    }
  }
  Serial.println(int (Temprature(v,finalArray[i][1], finalArray[i][2])));  // display Celsius
  increment++;
  delay(5000);

}

