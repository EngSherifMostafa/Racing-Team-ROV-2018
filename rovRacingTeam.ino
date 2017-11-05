
int i=0;

int motor1=13;
int motorSpeed1=11;
int motor2=12;
int motorSpeed2=10; 

int motor3=8;
int motorSpeed3=9;
int motor4=7;
int motorSpeed4=6;

int motor5=4;
int motorSpeed5=5;
int motor6=2; 
int motorSpeed6=3;

char lastCommand;

void setup() {
  Serial.begin(9600);
  
 pinMode(motor1,OUTPUT);  
 digitalWrite(motor1,LOW); 
 pinMode(motorSpeed1,OUTPUT);  
 pinMode(motor2,OUTPUT);  
 digitalWrite(motor2,LOW); 
 pinMode(motorSpeed2,OUTPUT);

 pinMode(motor3,OUTPUT);  
 digitalWrite(motor3,LOW); 
 pinMode(motorSpeed3,OUTPUT);  
 pinMode(motor4,OUTPUT);  
 digitalWrite(motor4,LOW); 
 pinMode(motorSpeed4,OUTPUT);  

 pinMode(motor5,OUTPUT);  
 digitalWrite(motor5,LOW); 
 pinMode(motorSpeed5,OUTPUT);  
 pinMode(motor6,OUTPUT);  
 digitalWrite(motor6,LOW); 
 pinMode(motorSpeed6,OUTPUT);  

// ---------------
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);   
  analogWrite(motorSpeed3, 0);
  analogWrite(motorSpeed4, 0);
  analogWrite(motorSpeed5, 0);
  analogWrite(motorSpeed6, 0); 
}

void loop() {
  if(Serial.available()>0){
  char text=Serial.read();
  
  if(text=='w'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed1, i);
  analogWrite(motorSpeed2, i);
  if(i>200){i=200;}
  digitalWrite(motor1,HIGH);    //the motor is forward 
  digitalWrite(motor2,HIGH);    
  digitalWrite(motor3,LOW);    
  analogWrite(motorSpeed3, 0);
  digitalWrite(motor4,LOW);    
  analogWrite(motorSpeed4, 0);
  digitalWrite(motor5,LOW);    
  analogWrite(motorSpeed5, 0);
  digitalWrite(motor6,LOW);    
  analogWrite(motorSpeed6,0);   
  Serial.println(i);
  lastCommand='w';
  }



 else if(text=='s'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed3, i);
  analogWrite(motorSpeed4, i);
  if(i>200){i=200;}
  digitalWrite(motor3,HIGH);    //the motor is backward 
  digitalWrite(motor4,HIGH);    
  digitalWrite(motor1,LOW);    
  analogWrite(motorSpeed1, 0);
  digitalWrite(motor2,LOW);    
  analogWrite(motorSpeed2, 0);
  digitalWrite(motor5,LOW);    
  analogWrite(motorSpeed5, 0);
  digitalWrite(motor6,LOW);    
  analogWrite(motorSpeed6,0);   
  Serial.println(i);
  lastCommand='s';
  }
  


 else if(text=='e'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed5, i);
  analogWrite(motorSpeed6, i);
  if(i>200){i=200;}
  digitalWrite(motor5,HIGH);    //the motor is up 
  digitalWrite(motor6,LOW);    
  digitalWrite(motor3,LOW);    
  analogWrite(motorSpeed3, 0);
  digitalWrite(motor4,LOW);    
  analogWrite(motorSpeed4, 0);
  digitalWrite(motor1,LOW);    
  analogWrite(motorSpeed1, 0);
  digitalWrite(motor2,LOW);    
  analogWrite(motorSpeed2,0);   
  Serial.println(i);
  lastCommand='e';
  }



  if(text=='q'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed5, i);
  analogWrite(motorSpeed6, i);
  if(i>200){i=200;}
  digitalWrite(motor5,LOW);    //the motor is down 
  digitalWrite(motor6,HIGH);    
  digitalWrite(motor3,LOW);    
  analogWrite(motorSpeed3, 0);
  digitalWrite(motor4,LOW);    
  analogWrite(motorSpeed4, 0);
  digitalWrite(motor1,LOW);    
  analogWrite(motorSpeed1, 0);
  digitalWrite(motor2,LOW);    
  analogWrite(motorSpeed2,0);   
  Serial.println(i);
  lastCommand='q';
  }



  if(text=='a'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed2, i);
  analogWrite(motorSpeed4, i);
  if(i>200){i=200;}
  digitalWrite(motor2,HIGH);    //the motor is turn left 
  digitalWrite(motor4,HIGH);    
  digitalWrite(motor3,LOW);    
  analogWrite(motorSpeed3, 0);
  digitalWrite(motor1,LOW);    
  analogWrite(motorSpeed1, 0);
  digitalWrite(motor5,LOW);    
  analogWrite(motorSpeed5, 0);
  digitalWrite(motor6,LOW);    
  analogWrite(motorSpeed6,0);   
  Serial.println(i);
  lastCommand='a';
  }



  if(text=='d'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed1, i);
  analogWrite(motorSpeed3, i);
  if(i>200){i=200;}
  digitalWrite(motor1,HIGH);    //the motor is turn right 
  digitalWrite(motor3,HIGH);    
  digitalWrite(motor2,LOW);    
  analogWrite(motorSpeed2, 0);
  digitalWrite(motor4,LOW);    
  analogWrite(motorSpeed4, 0);
  digitalWrite(motor5,LOW);    
  analogWrite(motorSpeed5, 0);
  digitalWrite(motor6,LOW);    
  analogWrite(motorSpeed6,0);   
  Serial.println(i);
  lastCommand='d';
  }
  
if(text=='r'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed2, i);
  analogWrite(motorSpeed3, i);
  if(i>200){i=200;}
  digitalWrite(motor2,HIGH);    //the motor rotate 
  digitalWrite(motor3,HIGH);    
  digitalWrite(motor1,LOW);    
  analogWrite(motorSpeed1, 0);
  digitalWrite(motor4,LOW);    
  analogWrite(motorSpeed4, 0);
  digitalWrite(motor5,LOW);    
  analogWrite(motorSpeed5, 0);
  digitalWrite(motor6,LOW);    
  analogWrite(motorSpeed6,0);   
  Serial.println(i);
  lastCommand='r';
  }
  if(text=='f'){
  i = 0;
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);
 // if(i>200){i=200;}
  digitalWrite(motor1,LOW);    //all motors is off(stop) 
  digitalWrite(motor2,LOW);    
  digitalWrite(motor3,LOW);    
  analogWrite(motorSpeed3, 0);
  digitalWrite(motor4,LOW);    
  analogWrite(motorSpeed4, 0);
  digitalWrite(motor5,LOW);    
  analogWrite(motorSpeed5, 0);
  digitalWrite(motor6,LOW);    
  analogWrite(motorSpeed6,0);   
  Serial.println(i);
  lastCommand='f';
  }
}}
