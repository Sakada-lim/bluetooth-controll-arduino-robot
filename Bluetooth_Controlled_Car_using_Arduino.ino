
// Motor A
 
int enA = 7;
int in1 = 6;
int in2 = 5;
 
// Motor B
 
int enB = 2;
int in3 = 3;
int in4 = 4;

// Ultrasonic sensor
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
int duration, cm;
// motor speed
byte motorspeed = 100;
int differential = 10;
int turnspeed = 90;
void setup()
{
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}

void loop()
{
  if(Serial.available()> 0)
    {
      char data = Serial.read();
      if (data == 'f')
      {
        forward();
      }
      else if(data == 'b')
      {
        backward();
      }
      else if(data == 'r')
      {
        right();
      }
      else if (data == 'l')
      {
        left();
      }
      else if (data == 's')
      {
        Stop();
      }
      else
      {
        Serial.println(data);  
      }
    }
}
void Send_echo()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}
void forward()
{

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 150);
    analogWrite(enB, 150);
}
void backward()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 150);
    analogWrite(enB, 150);
}
void right()
{

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, motorspeed+turnspeed);
    analogWrite(enB, motorspeed+differential+turnspeed);
}
void left()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, motorspeed+turnspeed);
    analogWrite(enA, motorspeed+differential+turnspeed);

}


void Stop()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}
