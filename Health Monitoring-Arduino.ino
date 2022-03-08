

#define USE_ARDUINO_INTERRUPTS true   
#include <PulseSensorPlayground.h>   

const int PulseWire = A7;     
const int LED13 = 13;        
int Threshold = 550; 
int inVal;  

int stdBPMh=80; 
int stdBPMl=30; 
int stdSweat=500;     
                            
                               
PulseSensorPlayground pulseSensor; 

void setup() {   

  pinMode(A1,INPUT);
  pinMode(A2,OUTPUT);
  
  
  Serial.begin(9600);       
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);      
  pulseSensor.setThreshold(Threshold);   

   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !"); 
  }
}


void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();  
 inVal=analogRead(A1);                                           
 
if (pulseSensor.sawStartOfBeat()) {            
 Serial.println("♥  A HeartBeat Happened ! "); 
 Serial.print("BPM: ");                     
 Serial.print("BPM: "+String(myBPM)+"   Sweat: "+String(inVal)+"    ");                     
 myBPM>stdBPMh || myBPM<stdBPMl || inVal>stdSweat?sound(true):sound(false);
}

  delay(20);                  

}

void sound(bool val){
  if(val){
       digitalWrite(A2,1);
       Serial.println("Something is wrong!");
  }

  else{
        digitalWrite(A2,0); 
        Serial.println("Everything is fine!");
  }

    
}

  
