#define _BV(bit) (1 << (bit))
#define DEBUG false

// Robus
int stepTime = 20;
int initDelay = 800;
long crossTime;
boolean crossed=false;
int IP0_pin = 2; 
int r = 100;
int t = 0;


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

  if (t==0){
	  r = random(16)+1;
	  r = 256 - (r*r);
	  t = random(31);
	  t = 910-(t*t);
  }
  t--;
	  
// ONE PULSE DIVIDED INTO 255
  for (int i=0;i<256;i++){ 
	 
     if (i==r){
	     PORTD |= _BV(7);//7*
	     PORTB |= _BV(3);//11*
	     PORTB |= _BV(2);//10*
	     PORTB |= _BV(4);//12*
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
}
