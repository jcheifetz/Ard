#define _BV(bit) (1 << (bit))

int sine256[] = {0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,16,18,20,21,23,25,27,29,31,
  33,35,37,39,42,44,46,49,51,54,56,59,62,64,67,70,73,76,78,81,84,87,90,93,96,99,102,105,108,111,115,118,121,124, 127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,217,219,221,223,225,227,229,231,233,234,236,238,239,240,
  242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254,254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,
  221,219,217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,78,
  76,73,70,67,64,62,59,56,54,51,49,46,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0};

int subSteps = 4;
int mn = 70;
// Elite green
int stepTime = 0;//7;
int initDelay = 3000;

// Robus
//int stepTime = 15;
//int initDelay = 0;

int  D0_steps = 9; 
int  D1_steps = 10; 
int  D2_steps = 7; 
int  D3_steps = 7; 
int  D4_steps = 0; 
int  D5_steps = 0; 
int  D6_steps = 0; 
int  D7_steps = 0; 

int IP0_pin = 2; 
int D0_pin = 13;  
int D1_pin = 9;  
int D2_pin = 10;
int D3_pin = 11;  
int D4_pin = 12;  
int D5_pin = 8;  
int D6_pin = 7;  
int D7_pin = 6;  


int D0_pos = 127; 
int D1_pos = 127; 
int D2_pos = 90; 
int D3_pos = 127; 
int D4_pos = 127;
int D5_pos = 120; 
int D6_pos = 90; 
int D7_pos = 90; 

int ss=0;
long crossTime;
boolean crossed=false;

void setup(){ 
  pinMode(IP0_pin, INPUT);   
  pinMode(D0_pin, OUTPUT);  
  pinMode(D1_pin, OUTPUT);   
  pinMode(D2_pin, OUTPUT);   
  pinMode(D3_pin, OUTPUT);   
  pinMode(D4_pin, OUTPUT);   
  pinMode(D5_pin, OUTPUT); 
  pinMode(D6_pin, OUTPUT);   
  pinMode(D7_pin, OUTPUT);   
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
  
  boolean D0_crossed = false;
  boolean D1_crossed = false;
  boolean D2_crossed = false;
  boolean D3_crossed = false;
  boolean D4_crossed = false;
  boolean D5_crossed = false;
  boolean D6_crossed = false;
  boolean D7_crossed = false;
  
  // init delay
  crossTime = micros();
  while (micros() - crossTime < initDelay){   }


  for (int i=0;i<255;i++){ 
   
     if (i>=255-sine256[D0_pos] && !D0_crossed){
        PORTB |= _BV(5);//13
        D0_crossed = true;
     }
     if (i>=255-sine256[D1_pos] && !D1_crossed){
        PORTB |= _BV(4);//12
        D1_crossed = true;
     }
     if (i>=255-sine256[D2_pos] && !D2_crossed){
        PORTB |= _BV(3);//11
        D2_crossed = true;
     }
     if (i>=255-sine256[D3_pos] && !D3_crossed){
        PORTB |= _BV(2);//10
        D3_crossed = true;
     }
     if (i>=255-sine256[D4_pos] && !D4_crossed){
        PORTB |= _BV(1);//9
        D4_crossed = true;
     }
     if (i>=255-sine256[D5_pos] && !D5_crossed){
        PORTB |= _BV(0);//8
        D5_crossed = true;
     }
     if (i>=255-sine256[D6_pos] && !D6_crossed){
        PORTD |= _BV(7);//7
        D6_crossed = true;
     }
     if (i>=255-sine256[D7_pos] && !D7_crossed){
        PORTD |= _BV(6);//6
        D7_crossed = true;
     }       
  
     crossTime = micros();
     while (micros() - crossTime < stepTime){   }
  } 
    
   // delay for on time
   crossTime = micros();
   while (micros() - crossTime<200){}

   PORTB &= ~_BV(5);
   PORTB &= ~_BV(4);
   PORTB &= ~_BV(3);   
   PORTB &= ~_BV(2);   
   PORTB &= ~_BV(1);   
   PORTB &= ~_BV(0);
   PORTD &= ~_BV(7);   
   PORTD &= ~_BV(6);   

    if (ss++==subSteps){
       ss=0;
       D0_pos+= D0_steps;
       D1_pos+= D1_steps;
       D2_pos+= D2_steps;
       D3_pos+= D3_steps;
       D4_pos+= D4_steps;
       D5_pos+= D5_steps;
       D6_pos+= D6_steps;
       D7_pos+= D7_steps;
    }
   if (D0_pos>255-mn) D0_pos=mn;
   if (D1_pos>255-mn) D1_pos=mn;
   if (D2_pos>255-mn) D2_pos=mn;
   if (D3_pos>255-mn) D3_pos=mn;  
   if (D4_pos>255-mn) D4_pos=mn;
   if (D5_pos>255-mn) D5_pos=mn; 
   if (D6_pos>255-mn) D6_pos=mn; 
   if (D7_pos>255-mn) D7_pos=mn; 
   
}
