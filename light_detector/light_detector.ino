int leftsensor1 = A0;
int rightsensor2 = A1;
int middlesensor3 = A2;
int leftmotor1 = 11;
int leftmotor2 = 10;
int rightmotor1 = 9;
int rightmotor2 = 3;
int sensorvalue1 = 0;
int sensorvalue2 = 0;
int sensorvalue3 = 0;

void forward(){
  analogWrite(leftmotor1,70);
  analogWrite(leftmotor2,0);
  analogWrite(rightmotor1,70);
  analogWrite(rightmotor2,0);
}
void backward(){
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,70);
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,70);
}
void left(){
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,70);
  analogWrite(rightmotor1,70);
  analogWrite(rightmotor2,0);

}
void right(){
 analogWrite(leftmotor1,70);
  analogWrite(leftmotor2,0);
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,70);

}
void stp(){
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,0);
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,0);
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(leftmotor1,OUTPUT);
   pinMode(leftmotor2,OUTPUT);
   pinMode(rightmotor1,OUTPUT);
   pinMode(rightmotor2,OUTPUT);
   pinMode(leftsensor1 , INPUT);
    pinMode(rightsensor2 , INPUT);
     pinMode(middlesensor3 , INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorvalue1= analogRead(leftsensor1);
  sensorvalue2= analogRead(rightsensor2);
  sensorvalue3= analogRead(middlesensor3);
 // Serial.print(sensorvalue1);
 // Serial.print(sensorvalue2);
 // Serial.print(sensorvalue3);
  if(sensorvalue1>sensorvalue2 && sensorvalue1>sensorvalue3){
    left();
    Serial.print("left");
  }
   if(sensorvalue2>sensorvalue1 && sensorvalue2>sensorvalue3){
    Serial.print("right");
  };
   if(sensorvalue3>sensorvalue2 && sensorvalue3>sensorvalue1){
    forward();
    Serial.print("forward");
  };
   if(sensorvalue1 == 0 && sensorvalue2 == 0 && sensorvalue3 == 0){
    stp();
  };
  

}
