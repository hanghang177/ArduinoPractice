#define CH1                1    //Channel 1 (Turn) on receiver
#define CH2                2    //Channel 2 (Speed) on receiver

int CH1reading = 1500;          //The PWM reading from CH1 on the receiver
int CH2reading = 1500;          //The PWM reading from CH2 on the receiver

long ch1start = 0;              //Used for counting PWM pulse width of CH1
long ch2start = 0;              //Used for counting PWM pulse width of CH2

void interruptinit(){
  attachInterrupt(digitalPinToInterrupt(CH1),CH1rising,RISING);
  attachInterrupt(digitalPinToInterrupt(CH2),CH2rising,RISING);
}

void CH1rising(){
  ch1start = micros();
  detachInterrupt(digitalPinToInterrupt(CH1));
  attachInterrupt(digitalPinToInterrupt(CH1),CH1falling,FALLING);
}

void CH1falling(){
  CH1reading = micros() - ch1start;
  if(CH1reading < 900 || CH1reading > 2100){
    CH1reading = 1500;
  }
  detachInterrupt(digitalPinToInterrupt(CH1));
  attachInterrupt(digitalPinToInterrupt(CH1),CH1rising,RISING);
}

void CH2rising(){
  ch2start = micros();
  detachInterrupt(digitalPinToInterrupt(CH2));
  attachInterrupt(digitalPinToInterrupt(CH2),CH2falling,FALLING);
}

void CH2falling(){
  CH2reading = micros() - ch2start;
  if(CH2reading < 900 || CH2reading > 2100){
    CH2reading = 1500;
  }
  detachInterrupt(digitalPinToInterrupt(CH2));
  attachInterrupt(digitalPinToInterrupt(CH2),CH2rising,RISING);
}

int CH1speed(){
  return (CH1reading - 1500);
}

int CH2speed(){
  return (CH2reading - 1500);
}

void setup() {
  // put your setup code here, to run once:
  interruptinit();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("CH1: "+ CH1reading);
  Serial.print("CH2: "+ CH2reading);
}


