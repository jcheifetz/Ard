

int IP0_pin = 2; 
int D0_pin = 13;  


void setup(){ 
  pinMode(IP0_pin, INPUT);   
  pinMode(D0_pin, OUTPUT);  
} 

void loop(){ 
    if (!digitalRead(IP0_pin)){
          digitalWrite(D0_pin,HIGH);
          //delay(2);
     }
       digitalWrite(D0_pin,LOW );

}

