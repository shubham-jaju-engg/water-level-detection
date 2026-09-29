const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
const float tankHeight = 30.0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  long duration;
  float distance;
  float waterLevel;


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);

 
  distance = duration * 0.0343 / 2;

  waterLevel = tankHeight - distance;

  if (waterLevel < 0)
  {
    waterLevel = 0;
  }

  if (waterLevel > tankHeight)
  {
    waterLevel = tankHeight;
  }

  
  Serial.print("Distance to water: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Water Level: ");
  Serial.print(waterLevel);
  Serial.println(" cm");

  if (waterLevel >= 25)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

  Serial.println("--------------------");

  delay(1000);
}
