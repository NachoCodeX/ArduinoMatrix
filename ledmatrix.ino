
#define PIN_SIZE 12 
#define BUTTON 1
#define ANIMATION_SPEED 250
#define ANIMATION_SPEED0 300
int leds[3][3]={
     {2,3,4},
     {5,6,7},
     {8,9,10}
};

byte animation_index=2;
int btnState=1;



void turnLevels(int state){
  
  digitalWrite(11,state);
  digitalWrite(12,state);
  digitalWrite(13,state);
    
}

void setup() {

  
  Serial.begin(9600);
  Serial.print("PITOOO");

  
  for(int i =2 ; i <=PIN_SIZE; i++ ){
    pinMode(i,OUTPUT);  
  }

  pinMode(BUTTON,INPUT);


}


void changeAnimation(){
  for(int i=0; i<10;i++){
       turnAll(LOW);
      delay(50);
      turnAll(HIGH);
      delay(50);
    
  }
  turnAll(LOW);
  delay(1000); 

  
}


void loop() {
  
  
  // put your main code here, to run repeatedly:
  animations(0);
  changeAnimation();
  animations(1);
  changeAnimation();
  animations(2);
  changeAnimation();

  
}



void animations(int index){
  
  switch(index){
     case 0:{animation_0();break;}
     case 1:{animation_1();break;}
     case 2:{animation_2();break;}
  }

}


void setLed(int led , int level,int state){
  digitalWrite(led,state);
  digitalWrite(level,state);
}


void toggleHorizontalLevel(int level,int state){
  for(int i= 0; i<9;i++){
    digitalWrite(i+2,state); 
  }
  digitalWrite(level+11,state);
}


void toggleVerticalLevel(int index,int state){
     
     
     digitalWrite(11,state);
     digitalWrite(12,state);
     digitalWrite(13,state);
     digitalWrite(leds[0][index],state);
     digitalWrite(leds[1][index],state);
     digitalWrite(leds[2][index],state);
}

void turnAll(int state){
  for(int i=0;i<9;i++){
      digitalWrite(i+2,HIGH);
  }

  turnLevels(state);
  
}



void animation_0(){

  for(int i=0;i<3;i++){
    toggleHorizontalLevel(i,HIGH);
    delay(ANIMATION_SPEED0);
    toggleHorizontalLevel(i,LOW);
    delay(10);
   }

   for(int i=0;i<3;i++){
    toggleVerticalLevel(i,HIGH);
    delay(ANIMATION_SPEED0);
    toggleVerticalLevel(i,LOW);
    delay(10);
   }
  
   delay(500);

   for(int i=2;i>=0;i--){
    toggleVerticalLevel(i,HIGH);
    delay(ANIMATION_SPEED0);
    toggleVerticalLevel(i,LOW);
    delay(10);
   }
   
   turnAll(HIGH);
   delay(ANIMATION_SPEED0);
   turnAll(LOW);
   delay(500);
    
  

  
}






void animation_1(){
  
   for(int i=2;i>=0;i--){
    toggleVerticalLevel(i,HIGH);
    delay(ANIMATION_SPEED);
    toggleVerticalLevel(i,LOW);
    delay(10);
    
   }

   turnAll(HIGH);
   delay(ANIMATION_SPEED+200);
   turnAll(LOW);
   delay(1);

   for(int i=0;i<3;i++){
    toggleVerticalLevel(i,HIGH);
    delay(ANIMATION_SPEED);
    toggleVerticalLevel(i,LOW);
    delay(1);
   }


     for(int i=2;i>=0;i--){
    toggleVerticalLevel(i,HIGH);
    delay(ANIMATION_SPEED);
    toggleVerticalLevel(i,LOW);
    delay(10);
    
   }


}





void animation_2(){

  turnLevels(HIGH);
  
  digitalWrite(leds[0][0],HIGH);
  delay(ANIMATION_SPEED);
  digitalWrite(leds[0][0],LOW);
  delay(10);

  digitalWrite(leds[0][1],HIGH);
  delay(ANIMATION_SPEED);
  digitalWrite(leds[0][1],LOW);
  delay(10);

  digitalWrite(leds[0][2],HIGH);
  delay(ANIMATION_SPEED);
  digitalWrite(leds[0][2],LOW);
  delay(10);


  digitalWrite(leds[1][2],HIGH);
  delay(ANIMATION_SPEED);
  digitalWrite(leds[1][2],LOW);
  delay(10);

  digitalWrite(leds[2][2],HIGH);
  delay(ANIMATION_SPEED);
  digitalWrite(leds[2][2],LOW);
  delay(10);

   digitalWrite(leds[2][1],HIGH);
  delay(ANIMATION_SPEED);
  digitalWrite(leds[2][1],LOW);
  delay(10);

  digitalWrite(leds[2][0],HIGH);
  delay(ANIMATION_SPEED);
  digitalWrite(leds[2][0],LOW);
  delay(10);

   digitalWrite(leds[1][0],HIGH);
  delay(ANIMATION_SPEED);
  digitalWrite(leds[1][0],LOW);
  delay(500);

  
   turnAll(LOW);
   delay(ANIMATION_SPEED);
   turnAll(HIGH);
   delay(500);
   turnAll(LOW);
   delay(ANIMATION_SPEED);
   
  

  

  

  
  
  
  
  
}



