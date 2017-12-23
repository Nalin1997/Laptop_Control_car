#define MR0 8
#define MR1 9
#define ML0 10
#define ML1 11
#define sp 6
#define sp1 7
#define servo1 3
#define servo2 4
#define servo3 5
#define in1 0
#define in2 0
#define in3 0
#include <Servo.h>
Servo s,s1,s2;
int ser=in1,ser1=in2,ser2=in3;
int i=0,j;
int n[8]={0,5,30,60,90,150,200,255};


void setup() 
{
s.attach(servo1);
s1.attach(servo2);
s2.attach(servo3);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
Serial.begin(9600);
}
void forward()
{
  digitalWrite(MR0,0);
  digitalWrite(MR1,1);
  digitalWrite(ML0,0);
  digitalWrite(ML1,1);
}
void backward()
{
  digitalWrite(MR0,1);
  digitalWrite(MR1,0);
  digitalWrite(ML0,1);
  digitalWrite(ML1,0);
}
void left()
{
  
  digitalWrite(MR0,0);
  digitalWrite(MR1,0);
  digitalWrite(ML0,0);
  digitalWrite(ML1,1);
}
void right()
{  
  digitalWrite(MR0,0);
  digitalWrite(MR1,1);
  digitalWrite(ML0,0);
  digitalWrite(ML1,0);
}
void Stop()
{
  digitalWrite(MR0,0);
  digitalWrite(MR1,0);
  digitalWrite(ML0,0);
  digitalWrite(ML1,0);
}

void loop() 
{int a;
    a=Serial.read();
    if(a=='w')
    {
      forward();
    }
    else if(a=='s')
    {
      Stop();
    }
    if(a=='s')
    {
      backward();
    }
    else if(a=='S')
    {
      Stop();
    }
    if (a=='a')
    {
      left();
    }
   else if (a=='A')
    {
      Stop();
    }
    if (a=='d')
    {
      right();
    }
    else if (a=='D')
    {
      Stop();
    }
    if(a=='h')
    {
      do
      {
        ser=ser+2;
        if(ser<170)
        {
          s.write(ser); 
        }
        else
        {
          s.write(170);
          ser=170;
        }
        
        a=Serial.read();
        delay(10);
      }while(a!='H');
    }
    if(a=='n')
    {
      do
      {
        ser=ser-2;
        if(ser>15)
        {
          s.write(ser);
        }
        else
        {
          s.write(15);
          ser=15;
        }
        a=Serial.read();
        delay(10);
      }while(a!='H');
    }
    if(a=='g')
    {
      do
      {
        ser1=ser1+2;
        if(ser1<170)
        {
          s1.write(ser1); 
        }
        else
        {
          s1.write(170);
          ser1=170;
        }
        a=Serial.read();
        delay(10);
      }while(a!='H');
    }
    if(a=='b')
    {
      do
      {
        ser1=ser1-2;
        if(ser1>15)
        {
          s1.write(ser1);
        }
        else
        {
          s1.write(15);
          ser1=15;
        }
        a=Serial.read();
        delay(10);
      }while(a!='H');
    }
    if(a=='j')
    {
      do
      {
        ser2=ser2+2;
        if(ser1<170)
        {
          s2.write(ser2); 
        }
        else
        {
          s2.write(170);
          ser2=170;
        }
        
        a=Serial.read();
        delay(10);
      }while(a!='H');
    }
    if(a=='m')
    {
      do
      {
        ser2=ser2-2;
        if(ser2>15)
        {
          s2.write(ser2);
        }
        else
        {
          s2.write(15);
          ser2=15;
        }
        a=Serial.read();
        delay(10);
      }while(a!='H');
    }

    //Gear part
     if(a=='=')
   { i++;
     j=n[i];
   }
  else if(a=='-')
   { i--;
     j=n[i];
   }
  analogWrite(sp,j);
  analogWrite(sp1,j);
}
