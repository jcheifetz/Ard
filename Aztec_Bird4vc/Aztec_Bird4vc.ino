#define _BV(bit) (1 << (bit))
#define SINE_LENGTH 3
#define SUB_STEP_LENGTH 2
#define MIN -1
//365
int sine[SINE_LENGTH+1] = {200,200,200};
int subSteps[SUB_STEP_LENGTH+1] = {100,200};
int subStepsTime[SUB_STEP_LENGTH+1] = {1000,1000};

int subStepsCurrent = 0;//4
int ssTime = 0;

// Robus
int stepTime = 5;
int initDelay = 1800;

int IP0_pin = 2; 

int D0_pos = 0; 
int D1_pos = 100; 
int D2_pos = 200; 
int D3_pos = 300; 
int D4_pos = 0;
int D5_pos = 100; 
int D6_pos = 200; 
int D7_pos = 300; 

int D0_step = 4; 
int D1_step = 5; 
int D2_step = 6; 
int D3_step = 7; 
int D4_step = 4;
int D5_step = 5; 
int D6_step = 6; 
int D7_step = 7; 



int ss=0;
long crossTime;
boolean crossed=false;

void setup(){ 
  pinMode(IP0_pin, INPUT);   
  pinMode(13, OUTPUT);  
  pinMode(12, OUTPUT);   
  pinMode(11, OUTPUT);   
  pinMode(10, OUTPUT);   
  pinMode(9, OUTPUT);   
  pinMode(8, OUTPUT); 
  pinMode(7, OUTPUT);   
  pinMode(6, OUTPUT);   
} 

void loop(){ 
    if (!digitalRead(IP0_pin)){
        if (!crossed){
          zeroCross();
          crossed = true;
        }
    } else {
       crossed = false; 
    }
}

void zeroCross(){
 PORTB |= _BV(5);//13
  // init delay
  crossTime = micros();
  while (micros() - crossTime < initDelay){   }
 PORTB &= ~_BV(5);


// ONE PULSE DIVIDED INTO 255
  for (int i=0;i<256;i++){ 
   
     if (i==255-sine[D0_pos] || i==MIN){
    //    PORTB |= _BV(5);//13
     }
     if (i==255-sine[D1_pos] || i==MIN){
        PORTB |= _BV(4);//12
     }
     if (i==255-sine[D2_pos] || i==MIN){
        PORTB |= _BV(3);//11  
     }
     if (i==255-sine[D3_pos] || i==MIN){
        PORTB |= _BV(2);//10 
     }
     if (i==255-sine[D4_pos] || i==MIN){
        PORTB |= _BV(1);//9   
     }
     if (i==255-sine[D5_pos] || i==MIN){
        PORTB |= _BV(0);//8
     }
     if (i==255-sine[D6_pos] || i==MIN){
        PORTD |= _BV(7);//7
     }
     if (i==255-sine[D7_pos] || i==MIN){
        PORTD |= _BV(6);//6
     }       


  
     crossTime = micros();
     while (micros() - crossTime < stepTime){   }
  } 
// END -ONE PULSE DIVIDED INTO 255

    
   // delay for on time
     crossTime = micros();
     while (micros() - crossTime < 100){   }


   // switch all off
   //PORTB &= ~_BV(5);//13
   PORTB &= ~_BV(4);//12
   PORTB &= ~_BV(3);//11   
   PORTB &= ~_BV(2);//10   
   PORTB &= ~_BV(1);//9   
   PORTB &= ~_BV(0);//8
   PORTD &= ~_BV(7);//7   
   PORTD &= ~_BV(6);//6 



   ssTime++;
   if (ssTime==subStepsTime[subStepsCurrent]){
     ssTime=0;
     subStepsCurrent++;
     if (subStepsCurrent==SUB_STEP_LENGTH+1){
       subStepsCurrent=0;
     }   
   }

   if (ss++>=subSteps[subStepsCurrent]){
       ss=0;
       D0_pos+=D0_step;
       D1_pos+=D1_step;
       D2_pos+=D2_step;
       D3_pos+=D3_step;
       D4_pos+=D4_step;
       D5_pos+=D5_step;
       D6_pos+=D6_step;
       D7_pos+=D7_step;
   }
   
   if (D0_pos>SINE_LENGTH) D0_pos=0;
   if (D1_pos>SINE_LENGTH) D1_pos=0;
   if (D2_pos>SINE_LENGTH) D2_pos=0;
   if (D3_pos>SINE_LENGTH) D3_pos=0;  
   if (D4_pos>SINE_LENGTH) D4_pos=0;
   if (D5_pos>SINE_LENGTH) D5_pos=0; 
   if (D6_pos>SINE_LENGTH) D6_pos=0; 
   if (D7_pos>SINE_LENGTH) D7_pos=0; 
   
}
