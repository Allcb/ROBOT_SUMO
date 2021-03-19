
#define pinSentido1MotorA 3
#define pinSentido2MotorA 2
#define pinSentido1MotorB 7
#define pinSentido2MotorB 6

char letra;

void setup() {

  Serial.begin(9600);
  Serial.println("Digite a direcao!");
  Serial.println("[F,B,D,E,P], OFF");
  
  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);
}

void loop() {
  

 while (Serial.available())
 {
   letra = Serial.read();
   if (letra == 'F') {
     digitalWrite(pinSentido1MotorA, HIGH);
     digitalWrite(pinSentido2MotorA, LOW);
     digitalWrite(pinSentido1MotorB, HIGH);
     digitalWrite(pinSentido2MotorB, LOW);
     Serial.println ("F");    

  } 
   else if (letra == 'B') {
        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH);
        digitalWrite(pinSentido1MotorB, LOW);
        digitalWrite(pinSentido2MotorB, HIGH);
        Serial.println ("B");  
     }
        
   else if (letra == 'D') { 
        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH);
        digitalWrite(pinSentido1MotorB, HIGH);
        digitalWrite(pinSentido2MotorB, LOW);
        Serial.println ("D");        
     }
     else if (letra == 'E') { 
        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, LOW);
        digitalWrite(pinSentido1MotorB, LOW);
        digitalWrite(pinSentido2MotorB, HIGH);
        Serial.println ("E");        
     }
     else if (letra == 'P') { 
        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, HIGH);
        digitalWrite(pinSentido1MotorB, HIGH);
        digitalWrite(pinSentido2MotorB, HIGH);
        Serial.println ("P");        
     }
}
}

