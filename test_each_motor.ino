#define maxSpeed 120
#define step 40
byte speed =0;


/* pin descreption :    
------------------------------ */
#define motor1        22
#define motorSpeed1   2

#define motor2        23
#define motorSpeed2   3 

#define motor3        24 
#define motorSpeed3    4

#define motor4        25
#define motorSpeed4    5

#define motor5        26
#define motorSpeed5    6

#define motor6        27 
#define motorSpeed6    7

#define motor7_a      28 
#define motor7_b      29  
#define motorSpeed7    8   
 
#define motor8_a      30  
#define motor8_b      31  
#define motorSpeed8   9  

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
  if(text=='1'){
  speed =speed+ step;
  if (lastCommand != text) speed = step ;
  analogWrite(motorSpeed1, speed);
  //analogWrite(motorSpeed2, speed);
  // off the backward motors
  analogWrite(motorSpeed3, 0);
  analogWrite(motorSpeed4, 0);
  
  if(speed>maxSpeed){speed=maxSpeed;}
  
  digitalWrite(motor1,HIGH);   
  digitalWrite(motor2,HIGH);
     
  Serial.println(speed);
  lastCommand='1';
  }

if(text=='2'){
  speed =speed+ step;
  if (lastCommand != text) speed = step ;
  analogWrite(motorSpeed2, speed);
  //analogWrite(motorSpeed2, speed);
  // off the backward motors
  analogWrite(motorSpeed3, 0);
  analogWrite(motorSpeed4, 0);
  
  if(speed>maxSpeed){speed=maxSpeed;}
  
  digitalWrite(motor1,HIGH);   
  digitalWrite(motor2,HIGH);
     
  Serial.println(speed);
  lastCommand='2';
  }

 //the motor is backward 
 else if(text=='3'){
  speed = speed + step;
  if (lastCommand != text) speed = step;
  
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);
  analogWrite(motorSpeed3, speed);
  analogWrite(motorSpeed4, 0);
  
  if(speed>maxSpeed){speed=maxSpeed;}
  
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,HIGH);
      
  Serial.println(speed);
  lastCommand='3';
  }
  
else if(text=='4'){
  speed = speed + step;
  if (lastCommand != text) speed = step;
  
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);
  analogWrite(motorSpeed3, 0);
  analogWrite(motorSpeed4, speed);
  
  if(speed>maxSpeed){speed=maxSpeed;}
  
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,HIGH);
      
  Serial.println(speed);
  lastCommand='4';
  }
  




 //the motor is up 
 else if(text=='5'){
  speed = speed + step;
  if (lastCommand != text) speed= step;
  
  analogWrite(motorSpeed5, speed);
  analogWrite(motorSpeed6, 0);
  analogWrite(motorSpeed7, 0);
  analogWrite(motorSpeed8, 0);
  if(speed>maxSpeed){speed=maxSpeed;}
  digitalWrite(motor5,HIGH);
  digitalWrite(motor6,LOW);
  digitalWrite(motor7_a,HIGH);
  digitalWrite(motor7_b,LOW) ;
  digitalWrite(motor8_a,HIGH);
  digitalWrite(motor8_b,LOW) ;
  Serial.println(speed);
  lastCommand='5';
  }


  //the motor is down  
  if(text=='6'){
  speed = speed+ step; 
  if (lastCommand != text) speed= step;
  analogWrite(motorSpeed5, 0);
  analogWrite(motorSpeed6, speed);
  analogWrite(motorSpeed7, 0);
  analogWrite(motorSpeed8, 0);
  if(speed>maxSpeed){speed=maxSpeed;}
  digitalWrite(motor5,LOW);    
  digitalWrite(motor6,HIGH);  
  digitalWrite(motor7_b,HIGH);
  digitalWrite(motor7_a,LOW) ;
  digitalWrite(motor8_b,HIGH);
  digitalWrite(motor8_a,LOW) ;  
  Serial.println(speed);
  lastCommand='6';
  }


  //the motor is turn left
  if(text=='7'){
  speed =speed+step;
  if (lastCommand != text) speed= step;
  analogWrite(motorSpeed2, 0);
  analogWrite(motorSpeed7, speed);
  if(speed>maxSpeed){speed=maxSpeed;}
 digitalWrite(motor7_a,HIGH) ; 
 digitalWrite(motor7_b,LOW) ;
     
  Serial.println(speed);
  lastCommand='7';
  }
 if(text=='8'){
  speed =speed+step;
  if (lastCommand != text) speed= step;
  analogWrite(motorSpeed2, 0);
  analogWrite(motorSpeed8, speed);
  if(speed>maxSpeed){speed=maxSpeed;}
 digitalWrite(motor8_a,HIGH) ; 
 digitalWrite(motor8_b,LOW) ;
     
  Serial.println(speed);
  lastCommand='8';
  }

}
}

void motorOn () {
   
int num = Serial.read();
int Speed = 170 ; 
if (num < 28)
{  

digitalWrite (num , HIGH) ;   
analogWrite(num+20,Speed) ;  
}
else if (num = 28)   
  {
  digitalWrite (motor7_a , LOW) ; 
  digitalWrite (motor7_b , HIGH) ;
  analogWrite (motorSpeed7,Speed); 
  }
else if (num = 30)   
  {
  digitalWrite (motor8_a , LOW) ; 
  digitalWrite (motor8_b , HIGH) ;
  analogWrite (motorSpeed8,Speed); 
  }
  else if (num == 'f') {
  Speed = 0;
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);
   
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
  Serial.println(Speed);
  
    
    }
  }

