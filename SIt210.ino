#define light A0
#define echoPin 7
#define trigPin 8
#define m1 13
#define m2 4

long duration;
long distance;

void setup() 
{
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2;

  delay(50);

  

  int Lvalue = analogRead(light);// read the light
  int mVolt = map(Lvalue,0, 1023, 0, 5000);// map analogue reading to 5000mV
  float volt =(double)mVolt/1000;// convert millivolt to volt

  if (distance < 500 & volt > 50)
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
  }
}