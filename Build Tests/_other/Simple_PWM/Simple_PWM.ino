
int led = 13;
int op = 10;
int IP0_pin = 2; 
boolean crossed=false;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  pinMode(op, OUTPUT);  
  pinMode(IP0_pin, INPUT);   
}

// the loop routine runs over and over again forever:
void loop() {
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
  delay(7); 
  digitalWrite(led, HIGH); 
  digitalWrite(op, HIGH);
  delay(1);         
  digitalWrite(led, LOW);
  digitalWrite(op, LOW); 
}
