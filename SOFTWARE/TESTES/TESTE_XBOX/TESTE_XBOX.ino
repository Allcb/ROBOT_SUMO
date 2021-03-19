
#include <XBOXRECV.h>

#define MotorA_Sentido 2
#define MotorA_Speed   3 //PWM
#define MotorB_Sentido 7
#define MotorB_Speed   6 //PWM

USB Usb;
XBOXRECV Xbox(&Usb);

void frente();
void re();
void esquerda();
void direita();
void parado();

void setup() {
  
  Serial.begin(115200);
  Usb.Init();
  Serial.println("Xbox Wireless Iniciado");
  
  pinMode(MotorA_Sentido, OUTPUT);
  pinMode(MotorA_Speed,   OUTPUT);
  pinMode(MotorB_Sentido, OUTPUT);
  pinMode(MotorB_Speed,   OUTPUT);
}
void loop() 
{
  Usb.Task();
  if (Xbox.XboxReceiverConnected)             
     {    
        if (Xbox.getButtonPress ( X ) ) {
          frente();
          Serial.println("X = Frente");
        }
        else if (Xbox.getButtonPress ( A ) ) {
          parado();
          Serial.println("A = Parado");
        }
      }
}
void frente()                                                //Função de controle dos atuadores do Robô
{
     digitalWrite(MotorA_Speed,   HIGH);
     digitalWrite(MotorA_Sentido, LOW);
     digitalWrite(MotorB_Sentido, HIGH);
     digitalWrite(MotorB_Speed,   LOW);
  
}
void parado()
{
      digitalWrite(MotorA_Speed,   HIGH);
      digitalWrite(MotorA_Sentido, HIGH);
      digitalWrite(MotorB_Sentido, HIGH);
      digitalWrite(MotorB_Speed,   HIGH);
} 
     
