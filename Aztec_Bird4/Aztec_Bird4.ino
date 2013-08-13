#define _BV(bit) (1 << (bit))
#define SINE_LENGTH 365
#define SUB_STEP_LENGTH 2
#define MIN -1
//365
int sine[SINE_LENGTH+1] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,16,18,20,21,23,25,27,29,31,
  33,35,37,39,42,44,46,49,51,54,56,59,62,64,67,70,73,76,78,81,84,87,90,93,96,99,102,105,108,111,115,118,121,124, 127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,217,219,221,223,225,227,229,231,233,234,236,238,239,240,
  242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254,254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,
  221,219,217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,78,
  76,73,70,67,64,62,59,56,54,51,49,46,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int subSteps[SUB_STEP_LENGTH+1] = {5,5,5};
int subStepsTime[SUB_STEP_LENGTH+1] = {1000,1000,1000};

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


   // switch all off
   //PORTB &= ~_BV(5);//13
   PORTB &= ~_BV(4);//12
   PORTB &= ~_BV(3);//11   
   PORTB &= ~_BV(2);//10   
   PORTB &= ~_BV(1);//9   
   PORTB &= ~_BV(0);//8
   PORTD &= ~_BV(7);//7   
   PORTD &= ~_BV(6);//6 

  } 
// END -ONE PULSE DIVIDED INTO 255

    
   // delay for on time
     crossTime = micros();
     while (micros() - crossTime < 100){   }




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
