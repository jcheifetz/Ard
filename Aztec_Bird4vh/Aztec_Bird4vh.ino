#define _BV(bit) (1 << (bit))
#define DEBUG false

#define sL1 40

const byte s1[] PROGMEM  = {0 ,0 ,1 ,1 ,2 ,3 ,3 ,4 ,4 ,5 ,5 ,6 ,6 ,6 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,7 ,6 ,6 ,6 ,5 ,5 ,4 ,4 ,3 ,3 ,2 ,1 ,1 ,0 };


// Robus
int stepTime = 15;
int initDelay = 800;
long crossTime;
boolean crossed=false;
int IP0_pin = 2; 
int r = 100;
int t = 0;
int sP1=0;

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
    if (!digitalRead(IP0_pin) || DEBUG){
        if (!crossed || DEBUG){
          zeroCross();
          crossed = true;
        }
    } else {
       crossed = false; 
    }
}

void zeroCross(){
  // init delay
  crossTime = micros();
  while (micros() - crossTime < initDelay){   }

  if (t<1){
	  r = random(6)+1;
	  // fix level
	  r = 60;

	  //r = 256 - (r*r*r);
	  r = 256 - r;
	  
	  //t = random(31);
	  //t = 910-(t*t);
	  t = r*10;
  }
  t--;
	  
  // ONE PULSE DIVIDED INTO 255
  for (int i=0;i<256;i++){ 
	 
     if (i==(r+pgm_read_byte(&s1[sP1]))   || (r+pgm_read_byte(&s1[sP1])>255 && i==255) ){
	     PORTD |= _BV(8);//8*
	     PORTB |= _BV(3);//11*
	     PORTB |= _BV(2);//10*
	     PORTB |= _BV(4);//12*
		 PORTD |= _BV(7);//7   
		 PORTB |= _BV(5);//13
     }
     crossTime = micros();
     while (micros() - crossTime < stepTime){   }
  } 
  // END ONE PULSE DIVIDED INTO 255

   // delay for on time
     crossTime = micros();
     while (micros() - crossTime < 100){   }

   // switch all off
   PORTB &= ~_BV(5);//13
   PORTB &= ~_BV(4);//12
   PORTB &= ~_BV(3);//11   
   PORTB &= ~_BV(2);//10   
   PORTB &= ~_BV(1);//9   
   PORTB &= ~_BV(0);//8
   PORTD &= ~_BV(7);//7   
   PORTD &= ~_BV(6);//6 
   
   
   sP1++;
   if (sP1==sL1) sP1=0;
}
