#include <digitalWriteFast.h>

#define DEBUG false

#define sL0 2
#define sS0 0

#define sL1 2
#define sS1 0

#define sL3 2
#define sS3 0

#define sL4 2
#define sS4 0

#define sL5 2
#define sS5 0

#define sL6 2
#define sS6 0

#define sL7 2
#define sS7 0

#define sL8 100
#define sS8 0

#define sL9 2
#define sS9 0

#define sL10 2
#define sS10 0

#define sL11 2
#define sS11 0

#define sL12 2
#define sS12 0

#define sL13 100
#define sS13 0

// DO - A
// D1 - B,C
// D3 - D
// D4 - G,H
// D5 - I
// D6 - M
// D7 - N
// D8 - L
// D9 - K
// D10 - E,F
// D11 - J1
// D12 - J



const byte s0[] PROGMEM = {255,255 };

const byte s1[] PROGMEM = {255,255 };

const byte s3[] PROGMEM = {255,255 };
	
const byte s4[] PROGMEM = {255,255 };

const byte s5[] PROGMEM = {255,255 };
	
const byte s6[] PROGMEM = {255,255 };

const byte s7[] PROGMEM  = {255,255 };

const byte s8[] PROGMEM  = {255 ,247 ,239 ,232 ,224 ,216 ,208 ,200 ,192 ,184 ,177 ,169 ,162 ,154 ,147 ,140 ,133 ,126 ,119 ,112 ,106 ,99 ,93 ,87 ,81 ,75 ,70 ,64 ,59 ,54 ,49 ,45 ,40 ,36 ,32 ,28 ,25 ,21 ,18 ,16 ,13 ,11 ,9 ,7 ,5 ,4 ,3 ,2 ,1 ,1 ,0 ,1 ,1 ,2 ,3 ,4 ,5 ,7 ,9 ,11 ,13 ,16 ,18 ,21 ,25 ,28 ,32 ,36 ,40 ,45 ,49 ,54 ,59 ,64 ,70 ,75 ,81 ,87 ,93 ,99 ,106 ,112 ,119 ,126 ,133 ,140 ,147 ,154 ,162 ,169 ,177 ,184 ,192 ,200 ,208 ,216 ,224 ,232 ,239 ,247 };
	
const byte s9[] PROGMEM = {255,255 };
	
const byte s10[] PROGMEM = {255,255 };

const byte s11[] PROGMEM = {255,255 };
	
const byte s12[] PROGMEM = {255,255 };

const byte s13[] PROGMEM = {255 ,247 ,239 ,232 ,224 ,216 ,208 ,200 ,192 ,184 ,177 ,169 ,162 ,154 ,147 ,140 ,133 ,126 ,119 ,112 ,106 ,99 ,93 ,87 ,81 ,75 ,70 ,64 ,59 ,54 ,49 ,45 ,40 ,36 ,32 ,28 ,25 ,21 ,18 ,16 ,13 ,11 ,9 ,7 ,5 ,4 ,3 ,2 ,1 ,1 ,0 ,1 ,1 ,2 ,3 ,4 ,5 ,7 ,9 ,11 ,13 ,16 ,18 ,21 ,25 ,28 ,32 ,36 ,40 ,45 ,49 ,54 ,59 ,64 ,70 ,75 ,81 ,87 ,93 ,99 ,106 ,112 ,119 ,126 ,133 ,140 ,147 ,154 ,162 ,169 ,177 ,184 ,192 ,200 ,208 ,216 ,224 ,232 ,239 ,247 };

int sP0 = sS0;
int sP1 = sS1;
int sP3 = sS3;
int sP4 = sS4;
int sP5 = sS5;
int sP6 = sS6;
int sP7 = sS7;
int sP8 = sS8;
int sP9 = sS9;
int sP10 = sS10;
int sP11 = sS11;
int sP12 = sS12;
int sP13 = sS13;

int d=0;

int stepTime = 11;
int initDelay = 800;

long crossTime;
boolean crossed=false;

void setup(){ 
  pinMode(2, INPUT);  
  //pinMode(0, OUTPUT); 
  //pinMode(1, OUTPUT);
  //pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  //pinMode(6, OUTPUT);
  //pinMode(7, OUTPUT);
  //pinMode(8, OUTPUT);
  //pinMode(9, OUTPUT);
  //pinMode(10, OUTPUT);
  //pinMode(11, OUTPUT);
  //pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
} 

void loop(){ 
    if (!digitalRead(2) || DEBUG){
	    if (!crossed || DEBUG){

		  if (DEBUG) digitalWriteFast2(13, HIGH);
		  
		  // init delay
		  crossTime = micros();
		  while (micros() - crossTime < initDelay){   }
			  
		  if (DEBUG) digitalWriteFast2(13, LOW);
          zeroCross();
          crossed = true;
        }
    } else {
       crossed = false; 
    }
}

void zeroCross(){

// ONE PULSE DIVIDED INTO 255
  for (int i=0;i<256;i++){ 
     if (i==pgm_read_byte(&s0[sP0])){
	     digitalWriteFast2(0, HIGH);
     }
     if (i==pgm_read_byte(&s1[sP1])){
	     digitalWriteFast2(1, HIGH);
     }
     if (i==pgm_read_byte(&s3[sP3])){
	     digitalWriteFast2(3, HIGH);
     }
     if (i==pgm_read_byte(&s4[sP4])){
	     digitalWriteFast2(4, HIGH);
     }
     if (i==pgm_read_byte(&s5[sP5])){
	     digitalWriteFast2(5, HIGH);
     }
     if (i==pgm_read_byte(&s6[sP6])){
	     digitalWriteFast2(6, HIGH);
     }
     if (i==pgm_read_byte(&s7[sP7])){
	     digitalWriteFast2(7, HIGH);
     }
     if (i==pgm_read_byte(&s8[sP8])){
	     digitalWriteFast2(8, HIGH);
     }
     if (i==pgm_read_byte(&s9[sP9])){
	     digitalWriteFast2(9, HIGH);
     }
     if (i==pgm_read_byte(&s10[sP10])){
	     digitalWriteFast2(10, HIGH);
     }
     if (i==pgm_read_byte(&s11[sP11])){
	     digitalWriteFast2(11, HIGH);
     }
     if (i==pgm_read_byte(&s12[sP12])){
	     digitalWriteFast2(12, HIGH);
     }
     if (i==pgm_read_byte(&s13[sP13])){
	     digitalWriteFast2(13, HIGH);
     }
     crossTime = micros();
     while (micros() - crossTime < stepTime){   }
  } 
// END -ONE PULSE DIVIDED INTO 255
    
   // delay for on time
     crossTime = micros();
     while (micros() - crossTime < 100){   }

   // switch all off
   digitalWriteFast2(0, LOW);   
   digitalWriteFast2(1, LOW);
   digitalWriteFast2(3, LOW);
   digitalWriteFast2(4, LOW);
   digitalWriteFast2(5, LOW);
   digitalWriteFast2(6, LOW);
   digitalWriteFast2(7, LOW);
   digitalWriteFast2(8, LOW);
   digitalWriteFast2(9, LOW);
   digitalWriteFast2(10, LOW);
   digitalWriteFast2(11, LOW);
   digitalWriteFast2(12, LOW);
   digitalWriteFast2(13, LOW);

	if (d==0){
		sP0++;		
		sP1++;
		sP3++;
		sP4++;
		sP5++;
		sP6++;
		sP7++;
	}
	if (d==1){
		sP8++;	
		sP9++;
		sP10++;
		sP11++;
		sP12++;
		sP13++;
	}

   if (sP0==sL0) sP0=0;
   if (sP1==sL1) sP1=0;
   if (sP3==sL3) sP3=0;
   if (sP4==sL4) sP4=0;
   if (sP5==sL5) sP5=0;
   if (sP6==sL6) sP6=0;
   if (sP7==sL7) sP7=0;
   if (sP8==sL8) sP8=0;
   if (sP9==sL9) sP9=0;
   if (sP10==sL10) sP10=0;
   if (sP11==sL11) sP11=0;
   if (sP12==sL12) sP12=0;
   if (sP13==sL13) sP13=0;

	d++;
	if (d==2) d=0;
}
