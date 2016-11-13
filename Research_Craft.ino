bool m1a=LOW;   //Initializing values for motor pins:-  m1a=a pin of motor 1,m1b=b pin of motor 1
bool m1b=LOW;   //  m2a=a pin of motor 2,m2b=b pin of motor 2
bool m2a=LOW;
bool m2b=LOW;
int val,ch1,ch4,ch3,valu,va;

void Stop(){  //function to stop motors from turning
  m1a=LOW;
  m1b=LOW;
  m2a=LOW;
  m2b=LOW;
  digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
}
void backward(){  //function to make ROB move backwards
   m1a=HIGH;
  m1b=LOW;
  m2a=HIGH;
  m2b=LOW;
  digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
}

void forward(){  //function to make ROB move forward
  m1a=LOW;
  m1b=HIGH;
  m2a=LOW;
  m2b=HIGH;
   digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
}

void left(){  //function to make ROB turn left
  m1a=LOW;
  m1b=HIGH;
  m2a=LOW;
  m2b=LOW;
  digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
}

void right(){ //function to make ROB turn right
  m1a=LOW;
  m1b=LOW;
  m2a=LOW;
  m2b=HIGH;
  digitalWrite(4,m1a);
  digitalWrite(5,m1b);
  digitalWrite(12,m2a);
  digitalWrite(13,m2b);
}

void setup() {
  pinMode(7,INPUT);     //to get pwm input from reciever
  pinMode(11,INPUT);   //to get forward and backward values from reciever
  pinMode(2,INPUT);   //to get left and right values from reciever
  pinMode(5,OUTPUT);  //write value to pin b of motor 1
  pinMode(13,OUTPUT);  //write value to pin b of motor 2 
  pinMode(9,OUTPUT);  //to send pwm values to motor driver
  pinMode(12,OUTPUT); //write value to pin a of motor 2
  pinMode(4,OUTPUT);  //write value to pin a of motor 1
  Serial.begin(9600); //start serial monitor
  

}

void loop() {
  int ch3=pulseIn(7,HIGH);           //reading value from pin 7
  int val=map(ch3,993,2000,25,255);  //mapping values from reciever to appropriate pwm values
  int ch2=pulseIn(11,HIGH);           //reading value from pin 11
  int valu=map(ch2,980,2000,1,10);    //mapping recieved values to managable values
  int ch4=pulseIn(2,HIGH);            //reading value from pin 2
  int va=map(ch4,980,2000,1,10);      //mapping recieved values to managable values
  
  analogWrite(9,val);                 //writing pwm values to motor driver

  if((valu>=5 && valu<=7)&& (va>=3 && va<=7)){
    Stop();                                //calling stop() function according to condition
  }
  else
  if(valu>=8)
  forward();                            //calling forward() function according to condition
  else
  if(va>=8){
    right();                            //calling right() function according to condition
  }
  else
  if(va<=2){
    left();                             //calling left() function according to condition
  }
  else
  if(valu<4){
    backward();                         //calling backward() function according to condition
  }
  //printing to serial monitor :
  Serial.print("channel 3: ");
  Serial.println(ch3);
  Serial.print(" channel 2: ");
  Serial.println(ch2);
  Serial.println("channel 4: ");
  Serial.println(ch4);
}
