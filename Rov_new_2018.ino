byte i=0;

byte motor1 = 22;
byte motorSpeed1 = 2;

byte motor2 = 23;
byte motorSpeed2 = 3; 

byte motor3 = 24 ;
byte motorSpeed3 = 4;

byte motor4 = 25;
byte motorSpeed4 = 5;

byte motor5 = 26;
byte motorSpeed5 = 6;

byte motor6 = 27; 
byte motorSpeed6 = 7;

byte motor7_a = 28 ;
byte motor7_b = 29 ; 
byte motorSpeed7 = 8 ;  
 
byte motor8_a = 30 ;
byte motor8_b = 31 ; 
byte motorSpeed8 = 9 ; 

char lastCommand;

void setup() {
  
 Serial.begin(115200);
  
 pinMode(motor1,OUTPUT);  
 digitalWrite(motor1,LOW); 
   
 pinMode(motor2,OUTPUT);  
 digitalWrite(motor2,LOW); 

 pinMode(motor3,OUTPUT);  
 digitalWrite(motor3,LOW);
   
 pinMode(motor4,OUTPUT);  
 digitalWrite(motor4,LOW); 
 
 pinMode(motor5,OUTPUT);  
 digitalWrite(motor5,LOW); 
   
 pinMode(motor6,OUTPUT);  
 digitalWrite(motor6,LOW); 
 
 pinMode (motor7_a,OUTPUT);
 pinMode (motor7_b,OUTPUT);
 digitalWrite (motor7_a , LOW) ; 
 digitalWrite (motor7_b , LOW) ;
  
 pinMode (motor8_a,OUTPUT);
 pinMode (motor8_b,OUTPUT); 

 digitalWrite (motor8_a , LOW) ;
 digitalWrite (motor8_b , LOW) ;

// initialize motorSpeed = zero 
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);   
  analogWrite(motorSpeed3, 0);
  analogWrite(motorSpeed4, 0);
  analogWrite(motorSpeed5, 0);
  analogWrite(motorSpeed6, 0); 
  analogWrite(motorSpeed7, 0);
  analogWrite(motorSpeed8, 0);
}

void loop() {
  if(Serial.available()>0){
  char text=Serial.read();
  
  //the motor is forward  
  if(text=='w'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed1, i);
  analogWrite(motorSpeed2, i);
  // off the backward motors
  analogWrite(motorSpeed3, 0);
  analogWrite(motorSpeed4, 0);
  
  if(i>200){i=200;}
  
  digitalWrite(motor1,HIGH);   
  digitalWrite(motor2,HIGH);
     
  Serial.println(i);
  lastCommand='w';
  }


 //the motor is backward 
 else if(text=='s'){
  i =i+50;
  if (lastCommand != text) i=50;
  
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);
  analogWrite(motorSpeed3, i);
  analogWrite(motorSpeed4, i);
  
  if(i>200){i=200;}
  
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,HIGH);
      
  Serial.println(i);
  lastCommand='s';
  }
  

 //the motor is up 
 else if(text=='e'){
  i =i+50;
  if (lastCommand != text) i=50;
  
  analogWrite(motorSpeed5, i);
  analogWrite(motorSpeed6, i);
  analogWrite(motorSpeed7, i);
  analogWrite(motorSpeed8, i);
  if(i>200){i=200;}
  digitalWrite(motor5,HIGH);
  digitalWrite(motor6,LOW);
  digitalWrite(motor7_a,HIGH);
  digitalWrite(motor7_b,LOW) ;
  digitalWrite(motor8_a,HIGH);
  digitalWrite(motor8_b,LOW) ;
  Serial.println(i);
  lastCommand='e';
  }


  //the motor is down  
  if(text=='q'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed5, i);
  analogWrite(motorSpeed6, i);
  analogWrite(motorSpeed7, i);
  analogWrite(motorSpeed8, i);
  if(i>200){i=200;}
  digitalWrite(motor5,LOW);    
  digitalWrite(motor6,HIGH);  
  digitalWrite(motor7_b,HIGH);
  digitalWrite(motor7_a,LOW) ;
  digitalWrite(motor8_b,HIGH);
  digitalWrite(motor8_a,LOW) ;  
  Serial.println(i);
  lastCommand='q';
  }


  //the motor is turn left
  if(text=='a'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed2, i);
  analogWrite(motorSpeed4, i);
  if(i>200){i=200;}
  digitalWrite(motor2,HIGH);     
  digitalWrite(motor4,HIGH);    
  
     
  Serial.println(i);
  lastCommand='a';
  }


  //the motor is turn right
  if(text=='d'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed1, i);
  analogWrite(motorSpeed3, i);
  if(i>200){i=200;}
  digitalWrite(motor1,HIGH);     
  digitalWrite(motor3,HIGH);    
  
  Serial.println(i);
  lastCommand='d';
  }
  //the motor rotate  
if(text=='r'){
  i =i+50;
  if (lastCommand != text) i=50;
  analogWrite(motorSpeed2, i);
  analogWrite(motorSpeed3, i);
  if(i>200){i=200;}
  digitalWrite(motor2,HIGH);   
  digitalWrite(motor3,HIGH);    
  
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
