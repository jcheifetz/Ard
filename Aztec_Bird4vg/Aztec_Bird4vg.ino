#define _BV(bit) (1 << (bit))
#define SINE_LENGTH 365
#define SUB_STEP_LENGTH 1
#define MIN 130
//365
int sine[SINE_LENGTH+1] = {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,245,244,243,241,240,239,237,235,234,232,230,228,226,224,222,220,218,216,213,211,209,206,204,201,199,196,193,191,188,185,182,179,177,174,171,168,165,162,159,156,153,150,147,144,140,137,134,131,128,125,122,119,116,112,109,106,103,100,97,94,91,88,85,82,79,77,74,71,68,65,63,60,57,55,52,50,47,45,43,40,38,36,34,32,30,28,26,24,22,21,19,17,16,15,13,12,11,10,8,7,6,6,5,4,3,3,2,2,2,1,1,1,1,1,1,1,2,2,2,3,3,4,5,6,6,7,8,10,11,12,13,15,16,17,19,21,22,24,26,28,30,32,34,36,38,40,43,45,47,50,52,55,57,60,63,65,68,71,74,77,79,82,85,88,91,94,97,100,103,106,109,112,116,119,122,125,128,131,134,137,140,144,147,150,153,156,159,162,165,168,171,174,177,179,182,185,188,191,193,196,199,201,204,206,209,211,213,216,218,220,222,224,226,228,230,232,234,235,237,239,240,241,243,244,245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};

int subSteps[SUB_STEP_LENGTH+1] = {16,-1};
int subStepsTime[SUB_STEP_LENGTH+1] = {3000,2000};

int subStepsCurrent = 0;//4
int ssTime = 0;

// Robus
int stepTime = 16;
int initDelay = 800;

int IP0_pin = 2; 

int D0_pos = 0; 
int D1_pos = 50; 
int D2_pos = 100; 
int D3_pos = 150; 
int D4_pos = 200;
int D5_pos = 250; 
int D6_pos = 300; 
int D7_pos = 300; 

int D0_step = 53; 
int D1_step = 51; 
int D2_step = 49; 
int D3_step = 47; 
int D4_step = 45;
int D5_step = 43; 
int D6_step = 41; 
int D7_step = 15; 

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

// using 8,9,10,11


 PORTB |= _BV(5);//13
  // init delay
  crossTime = micros();
  while (micros() - crossTime < 2000){   }
 PORTB &= ~_BV(5);

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
// PORTB |= _BV(5);//13
  // init delay
  crossTime = micros();
  while (micros() - crossTime < initDelay){   }
// PORTB &= ~_BV(5);


// ONE PULSE DIVIDED INTO 255
  for (int i=0;i<256;i++){ 
   
     if ((i==sine[D0_pos] || i==MIN) && subSteps[subStepsCurrent]!=-1){
    //    PORTB |= _BV(5);//13
     }
     if ((i==sine[D1_pos] || i==MIN) && subSteps[subStepsCurrent]!=-1){
        PORTB |= _BV(4);//12
     }
     if ((i==sine[D2_pos] || i==MIN) && subSteps[subStepsCurrent]!=-1){
        PORTB |= _BV(3);//11*  
     }
     if ((i==sine[D3_pos] || i==MIN) && subSteps[subStepsCurrent]!=-1){
        PORTB |= _BV(2);//10* 
     }
     if ((i==sine[D4_pos] || i==MIN) && subSteps[subStepsCurrent]!=-1){
        PORTB |= _BV(1);//9*   
     }
     if ((i==sine[D5_pos] || i==MIN) && subSteps[subStepsCurrent]!=-1){
        PORTB |= _BV(0);//8*
     }
     if ((i==sine[D6_pos] || i==MIN) && subSteps[subStepsCurrent]!=-1){
        PORTD |= _BV(7);//7
     }
     if ((i==sine[D7_pos] || i==MIN) && subSteps[subStepsCurrent]!=-1){
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

   if (ss++>=subSteps[subStepsCurrent] && subSteps[subStepsCurrent]!=-1){
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
