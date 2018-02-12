#define maxSpeed 120
#define step 10 
byte speed =0;


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
  speed =speed+ step;
  if (lastCommand != text) speed = step ;
  analogWrite(motorSpeed1, speed);
  analogWrite(motorSpeed2, speed);
  // off the backward motors
  analogWrite(motorSpeed3, 0);
  analogWrite(motorSpeed4, 0);
  
  if(speed>maxSpeed){speed=maxSpeed;}
  
  digitalWrite(motor1,HIGH);   
  digitalWrite(motor2,HIGH);
     
  Serial.println(speed);
  lastCommand='w';
  }


 //the motor is backward 
 else if(text=='s'){
  speed =speed+step;
  if (lastCommand != text) speed = step;
  
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);
  analogWrite(motorSpeed3, i);
  analogWrite(motorSpeed4, i);
  
  if(speed>maxSpeed){speed=maxSpeed;}
  
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,HIGH);
      
  Serial.println(speed);
  lastCommand='s';
  }
  

 //the motor is up 
 else if(text=='e'){
  i =i+50;
  if (lastCommand != text) i=50;
  
  analogWrite(motorSpeed5, speed);
  analogWrite(motorSpeed6, speed);
  analogWrite(motorSpeed7, speed);
  analogWrite(motorSpeed8, speed);
  if(speed>maxSpeed){speed=maxSpeed;}
  digitalWrite(motor5,HIGH);
  digitalWrite(motor6,LOW);
  digitalWrite(motor7_a,HIGH);
  digitalWrite(motor7_b,LOW) ;
  digitalWrite(motor8_a,HIGH);
  digitalWrite(motor8_b,LOW) ;
  Serial.println(speed);
  lastCommand='e';
  }


  //the motor is down  
  if(text=='q'){
  speed = speed+ step; 
  if (lastCommand != text) speed= step;
  analogWrite(motorSpeed5, speed);
  analogWrite(motorSpeed6, speed);
  analogWrite(motorSpeed7, speed);
  analogWrite(motorSpeed8, speed);
  if(speed>maxSpeed){speed=maxSpeed;}
  digitalWrite(motor5,LOW);    
  digitalWrite(motor6,HIGH);  
  digitalWrite(motor7_b,HIGH);
  digitalWrite(motor7_a,LOW) ;
  digitalWrite(motor8_b,HIGH);
  digitalWrite(motor8_a,LOW) ;  
  Serial.println(speed);
  lastCommand='q';
  }


  //the motor is turn left
  if(text=='a'){
  speed =speed+step;
  if (lastCommand != text) speed= step;
  analogWrite(motorSpeed2, speed);
  analogWrite(motorSpeed4, speed);
  if(i>200){i=200;}
  digitalWrite(motor2,HIGH);     
  digitalWrite(motor4,HIGH);    
  
     
  Serial.println(speed);
  lastCommand='a';
  }


  //the motor is turn right
  if(text=='d'){
  speed =speed+step;
  if (lastCommand != text) speed = step;
  analogWrite(motorSpeed1, i);
  analogWrite(motorSpeed3, i);
  if(speed>maxSpeed){speed=maxSpeed;}
  digitalWrite(motor1,HIGH);     
  digitalWrite(motor3,HIGH);    
  
  Serial.println(speed);
  lastCommand='d';
  }
  //the motor rotate  
if(text=='r'){
  speed =speed +step ;
  if (lastCommand != text) speed=step;
  analogWrite(motorSpeed2, speed);
  analogWrite(motorSpeed3, speed);
  if(speed>maxSpeed){speed=maxSpeed;}
  digitalWrite(motor2,HIGH);   
  digitalWrite(motor3,HIGH);    
  
  Serial.println(speed);
  lastCommand='r';
  }
  
  if(text=='f'){
  speed = 0;
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
  Serial.println(speed);
  lastCommand='f';
  }
}}
