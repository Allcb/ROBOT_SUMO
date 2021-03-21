/*
   ROBÔ SUMO: ELEVEN 2.0
   
   Software de Controle do Robô
   
   Versão 2.0
    
   Autores: 
   
   ALLAN CARVALHO BARBOSA
   ÁLLAN LISBOA
   GUSTAVO OLIVEIRA
   LUCAS QUEIRÓZ
   
   
   Data: Maio de 2019 
   PROIBIDA A REPRODUÇÂO DESTE CONTEUDO
*/

#include <XBOXRECV.h>

// =============================================================================================================
// --- Mapeamento de Hardware ---

#define MotorA_SentidoH   2
#define MotorA_SentidoAH  4 
#define MotorA_Speed      3 //PWM

#define MotorB_SentidoH   7
#define MotorB_SentidoAH  8 
#define MotorB_Speed      9 //PWM

// =============================================================================================================
// --- Protótipo das funções auxiliares ---
void frente();
void re();
void esquerda();
void direita();
void parado();

// =============================================================================================================
// --- Inicia o Pareamento ---

USB Usb;
XBOXRECV Xbox(&Usb);

// =============================================================================================================
// --- Configurações iniciais ---
void setup()
{ 
  Serial.begin(115200);
  Usb.Init();
  Serial.println("Xbox Wireless Iniciado");
  
  pinMode(MotorA_SentidoH,  OUTPUT);
  pinMode(MotorA_SentidoAH, OUTPUT);
  pinMode(MotorA_Speed,     OUTPUT);
  
  pinMode(MotorB_SentidoH,  OUTPUT);
  pinMode(MotorB_SentidoAH, OUTPUT);
  pinMode(MotorB_Speed,     OUTPUT);
  
} //end setup


// =============================================================================================================
// --- Loop Infinito ---
void loop()

{
  Usb.Task();
  if (Xbox.XboxReceiverConnected)             
     {    
       if (Xbox.getButtonPress ( A ) ) {
          parado();
          Serial.println("pres A = Parado ");
        }
       else if (Xbox.getButtonPress ( X ) ) {
          frente();
          Serial.println("pres X = Frente");
        }
       else if (Xbox.getAnalogHat(LeftHatY)< -20768) {
          re();
          Serial.println("re");
        }
       else if (Xbox.getAnalogHat(LeftHatY) > 20767) {
          frente();
          Serial.println("Frente");
        }
       else if (Xbox.getAnalogHat(RightHatX) > 20767) {
          direita();
          Serial.println("Direita");
        }
       else if (Xbox.getAnalogHat(RightHatX)< -20768) {
          esquerda();
          Serial.println("Esquerda");
        }
       else if (Xbox.getButtonPress ( L1 ) ) {
          parado();
          Serial.println("pres LB = Parado ");
        }
       else if (Xbox.getButtonPress ( R1 ) ) {
          parado();
          Serial.println("pres RB = Parado ");
        }
        
        
      else 
      {
          parado();
      }
     }
}

// =============================================================================================================
// --- Funções Auxiliares --- Função de controle dos atuadores do Robô
void esquerda()                         
{
     digitalWrite(MotorA_SentidoH,  LOW);
     digitalWrite(MotorA_SentidoAH, HIGH);  
     analogWrite (MotorA_Speed,     255); 
           
     digitalWrite(MotorB_SentidoH,  HIGH); 
     digitalWrite(MotorB_SentidoAH, LOW);
     analogWrite (MotorB_Speed,     255);    
  
} //end 

void direita()
{
      digitalWrite(MotorA_SentidoH, HIGH);     
      digitalWrite(MotorA_SentidoAH,LOW);
      analogWrite (MotorA_Speed,    255); 
            
      digitalWrite(MotorB_SentidoH, LOW);
      digitalWrite(MotorB_SentidoAH,HIGH);
      analogWrite (MotorB_Speed,    255); 
      
} //end 

void frente()
{
      digitalWrite(MotorA_SentidoH, LOW);
      digitalWrite(MotorA_SentidoAH,HIGH);
      analogWrite (MotorA_Speed,    255); 
      
      digitalWrite(MotorB_SentidoH, LOW);
      digitalWrite(MotorB_SentidoAH,HIGH);
      analogWrite (MotorB_Speed,    255);     
      
} //end

void re()
{
      digitalWrite(MotorA_SentidoH, HIGH);
      digitalWrite(MotorA_SentidoAH,LOW);
      analogWrite (MotorA_Speed,    255);      
      
      digitalWrite(MotorB_SentidoH, HIGH);
      digitalWrite(MotorB_SentidoAH,LOW);
      analogWrite (MotorB_Speed,    255);      
      
} //end
void parado()
{
      digitalWrite(MotorA_SentidoH, HIGH);
      digitalWrite(MotorA_SentidoAH,HIGH);
      analogWrite (MotorA_Speed,    255);
      
      digitalWrite(MotorB_SentidoH, HIGH);
      digitalWrite(MotorB_SentidoAH,HIGH);
      analogWrite (MotorB_Speed,    255);

      
} //end

// =============================================================================================================

 
   
 
