byte Speed = 0;
#define max_speed 170


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

byte motorSpeed9 =10;
byte motor9_a=32;
byte motor9_b=33;

 

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
  pinMode (motor9_a,OUTPUT);
 pinMode (motor9_b,OUTPUT); 

 digitalWrite (motor9_a , LOW) ;
 digitalWrite (motor9_b , LOW) ;

// initialize motorSpeed = zero 
  analogWrite(motorSpeed1, 0);
  analogWrite(motorSpeed2, 0);   
  analogWrite(motorSpeed3, 0);
  analogWrite(motorSpeed4, 0);
  analogWrite(motorSpeed5, 0);
  analogWrite(motorSpeed6, 0); 
  analogWrite(motorSpeed7, 0);
  analogWrite(motorSpeed8, 0);
  analogWrite(motorSpeed9, 0);
} 

void loop() {
  if(Serial.available()>0){
  char text = Serial.read();
  
  //the motor is forward  
  if(text=='w'){
  Speed=Speed+50;
  if (lastCommand != text) Speed = 50;
  analogWrite(motorSpeed1, Speed);
  analogWrite(motorSpeed2, Speed);
  // revers 
  analogWrite(motorSpeed3, Speed);
  analogWrite(motorSpeed5, Speed);
  if(Speed>max_speed){Speed=max_speed;}
  digitalWrite(motor1,HIGH);   
  digitalWrite(motor2,HIGH);
  digitalWrite(motor3,LOW);
  digitalWrite(motor5,HIGH);
  Serial.println("FORWARD !");
  Serial.print("PWM = ");
  Serial.println(Speed);
  lastCommand='w';
  }


 //the motor is backward 
 else if(text=='s'){
 Speed = Speed + 50;
  if (lastCommand != text) Speed=50;
  
  analogWrite(motorSpeed1, Speed);
  analogWrite(motorSpeed2, Speed);
  // revers 
  analogWrite(motorSpeed3, Speed);
  analogWrite(motorSpeed5, Speed);
  
  if(Speed>max_speed){Speed=max_speed;}
  
  
  digitalWrite(motor1,HIGH);   
  digitalWrite(motor2,LOW);
  digitalWrite(motor3,HIGH);
  digitalWrite(motor5,LOW);
  Serial.println("BACKWARD !");     
  Serial.print("PWM = ");
  Serial.println(Speed);
  lastCommand='s';
  }
  

 //the motor is up 
 else if(text=='q'){
 Speed = Speed + 50 ; 
  if (lastCommand != text) Speed = 50 ;
  analogWrite(motorSpeed1, Speed);
  analogWrite(motorSpeed2, Speed);
  analogWrite(motorSpeed3, Speed);
  analogWrite(motorSpeed5, Speed);
  if(Speed>max_speed){Speed=max_speed;}
  digitalWrite(motor1,HIGH);    
  digitalWrite(motor2,HIGH);  
  digitalWrite(motor3,HIGH);
  digitalWrite(motor5,LOW) ;  
  Serial.println("UP !");
  Serial.print("PWM = ");
  Serial.println(Speed);
  lastCommand='q';
  }


  //the motor is down  
  if(text=='e'){
  Speed = Speed+50;
  if (lastCommand != text) Speed = 50;
  analogWrite(motorSpeed1, Speed);
  analogWrite(motorSpeed2, Speed);
  analogWrite(motorSpeed3, Speed);
  analogWrite(motorSpeed5, Speed);
  if(Speed>max_speed){Speed=max_speed;}
  digitalWrite(motor1,LOW);    
  digitalWrite(motor2,LOW);  
  digitalWrite(motor3,LOW);
  digitalWrite(motor5,HIGH) ;  
  Serial.println("DOWN !");
  Serial.print("PWM = ");
  Serial.println(Speed);
  lastCommand='e';
  }


  //the motor is turn left
  if(text == 'a'){
  Speed = Speed +50;
  if (lastCommand != text) Speed=50;
  analogWrite(motorSpeed4, Speed);
  analogWrite(motorSpeed6, Speed);
  // revers 
  analogWrite(motorSpeed7, Speed);
  analogWrite(motorSpeed8, Speed);
  
  if(Speed>max_speed){Speed=max_speed;}

  digitalWrite(motor4,LOW);   
  digitalWrite(motor6,LOW);
  digitalWrite(motor7_a,LOW);   
  digitalWrite(motor7_b,HIGH);   
  digitalWrite(motor8_a,HIGH);
  digitalWrite(motor8_b,LOW);
  Serial.println("LEFT !");
  Serial.print("PWM = ");
  Serial.println(Speed);   
  lastCommand='a';
  }


  //the motor is turn right
  if(text=='d'){
  Speed = Speed + 50;
  if (lastCommand != text) Speed = 50;
  
  analogWrite(motorSpeed4, Speed);
  analogWrite(motorSpeed6, Speed);
  // revers 
  analogWrite(motorSpeed7, Speed);
  analogWrite(motorSpeed8, Speed);
  
  if(Speed>max_speed){Speed=max_speed;}

  digitalWrite(motor4,HIGH);   
  digitalWrite(motor6,HIGH);
  digitalWrite(motor7_a,HIGH);   
  digitalWrite(motor7_b,LOW);   
  digitalWrite(motor8_a,LOW);
  digitalWrite(motor8_b,HIGH);
  Serial.println("RIGHT !");
  Serial.print("PWM = ");
  Serial.println(Speed);  
  lastCommand='d';
  }
  //the motor rotate  
  if(text=='r'){
  Speed= Speed + 50;
  if (lastCommand != text) Speed=50;
  analogWrite(motorSpeed1, Speed);
  analogWrite(motorSpeed2, Speed);
  // revers 
  analogWrite(motorSpeed7, Speed);
  analogWrite(motorSpeed8, Speed);
  
  if(Speed>max_speed){Speed=max_speed;}

  digitalWrite(motor1,HIGH);   
  digitalWrite(motor2,HIGH);
 digitalWrite(motor7_a,HIGH);   
  digitalWrite(motor7_b,LOW);   
  digitalWrite(motor8_a,HIGH);
  digitalWrite(motor8_b,LOW);
  Serial.println("Rotate !");
  Serial.print("PWM = ");
  Serial.println(Speed);
  lastCommand='r';
  }


   
  if(text=='f'){
  Speed = 0 ; 
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
  digitalWrite(motor7_a,LOW);    
  digitalWrite(motor7_b,LOW);    
  analogWrite(motorSpeed7,0);   
  digitalWrite(motor8_a,LOW);    
  digitalWrite(motor8_b,LOW);    
  analogWrite(motorSpeed8,0);   
  Serial.println("STOP");
 
  lastCommand='f';
  }
  
 if(text=='y'){
  Speed = 80 ;
  analogWrite(motorSpeed9, Speed);
  digitalWrite(motor9_a,HIGH);
  digitalWrite(motor9_b,LOW) ;  
  delay(750);
  analogWrite(motorSpeed9, 0);
  digitalWrite(motor9_a,LOW);
  digitalWrite(motor9_b,LOW) ;  
  Serial.println("Arm OPEN !");
  Serial.print("PWM = ");
  Serial.println(Speed);
  lastCommand='y';
 }
   if(text=='x'){
  Speed = 80 ;
  analogWrite(motorSpeed9, Speed);
  digitalWrite(motor9_a,LOW);
  digitalWrite(motor9_b,HIGH) ;  
  delay(750);
  analogWrite(motorSpeed9, 0);
  digitalWrite(motor9_a,LOW);
  digitalWrite(motor9_b,LOW) ;  
  
  Serial.println("Arm close ");
  Serial.print("PWM = ");
  Serial.println(Speed);
  lastCommand='x';
 }
 /* Reset ROV via software :) */
 if (text == 'z') watchdog_timer_reset();
   
 }
 }


 void watchdog_timer_reset(){ 
  Serial.println("reset now !! ") ; 
  delay(1000); 
  // Clear the reset flag. 
  MCUSR &= ~(1<<WDRF);
  WDTCSR |= (1<<WDCE) | (1<<WDE);     // start time sequence 
  // we set the default watchdog reset time = 16 ms so we prescallers = 0 
  // Enable interrupt.
  WDTCSR |= (1<<WDIE);
  }
