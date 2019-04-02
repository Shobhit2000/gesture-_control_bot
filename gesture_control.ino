#define l1 9 //arduino pin 3 to input pin 1 (IN3) of motor driver (LEFT WHEEL)
#define l2 3 //arduino pin 5 to input pin 2 (IN4) of motor driver (LEFT WHEEL)
#define r1 10 //arduino pin 6 to input pin 3 (IN1) of motor driver (RIGHT WHEEL)
#define r2 11 //arduino pin 9 to input pin 4 (IN2) of motor driver (RIGHT WHEEL)
int xout=A0;
int yout=A1;
int zout=A2;
int x0,y0,x,y;
void setup() 
{
  Serial.begin(9600);
 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(xout,INPUT);
 pinMode(yout,INPUT);
 x0=analogRead(xout);
 y0=analogRead(yout);
}

void loop() 
{
  x=analogRead(xout);
  y=analogRead(yout);
  if((y-30)>y0)
  {
    forward();
  }
  if(y+30<y0)
  {
    backward();
  }
  if(x-30>x0)
  {
    right();
  }
  if(x+30<x0)
  {
    left();
  }
}
void forward()
{
  analogWrite(l1,0);
  analogWrite(l2,200);
  analogWrite(r1,0);
  analogWrite(r2,200);
}
void backward()
{
  analogWrite(l1,200);
  analogWrite(l2,0);
  analogWrite(r1,200);
  analogWrite(r2,0);
}
void right()
{
  analogWrite(l1,0);
  analogWrite(l2,200);
  analogWrite(r1,200);
  analogWrite(r2,0);
}
void left()
{
  digitalWrite(l1,200);
  digitalWrite(l2,0);
  digitalWrite(r1,0);
  digitalWrite(r2,200);
  //delay(500);
}
void wait()
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
}
