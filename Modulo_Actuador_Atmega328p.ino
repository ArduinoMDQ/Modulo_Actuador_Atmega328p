// demo: CAN-BUS Shield, send data
#include <mcp_can.h>
#include <SPI.h>

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 9;
const int LED=5;

unsigned char Prog[8] = {0xff,0x00,0,0,0,0x01,0x02,0x03};

unsigned char onR1_onR2[8]   = {0x01,0x11,0,0,0,0,0,0};
unsigned char offR1_offR2[8] = {0x01,0x00,0,0,0,0,0,0};
unsigned char onR1_offR2[8]  = {0x01,0x01,0,0,0,0,0,0};
unsigned char offR1_onR2[8]  = {0x01,0x10,0,0,0,0,0,0};

unsigned char ID_Local=0x02;
unsigned char ID_Master=0x00;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(9600);
     pinMode(LED,OUTPUT);
     digitalWrite(LED,LOW);
  

START_INIT:

    if(CAN_OK == CAN.begin(CAN_250KBPS,MCP_8MHz))                   // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init ok!");
          digitalWrite(LED,true);
           delay(200);
           digitalWrite(LED,false);
           delay(200);
           digitalWrite(LED,true);
           delay(200);
           digitalWrite(LED,false);
            delay(200);
            
                CAN.sendMsgBuf(ID_Local,0, 8,Prog);
                 CAN.sendMsgBuf(ID_Local,0, 8, offR1_offR2);
   
    }
    else
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        digitalWrite(LED,true);
           delay(100);
           digitalWrite(LED,false);
           delay(200);
           digitalWrite(LED,true);
           delay(100);
           digitalWrite(LED,false);
           delay(200);
           digitalWrite(LED,true);
           delay(800);
            digitalWrite(LED,false);
           delay(200);
        goto START_INIT;
    }
}


void loop()
{   
  
    CAN.sendMsgBuf(ID_Local,0, 8,onR1_offR2);
    Led_mensaje_enviado_blink_uno();
    delay(5000);
  
    CAN.sendMsgBuf(ID_Local,0, 8, onR1_onR2);
     Led_mensaje_enviado_blink_dos();
    delay(10000);  
   
    CAN.sendMsgBuf(ID_Local,0, 8, offR1_onR2);
    Led_mensaje_enviado_blink_tres();
    delay(5000);                  
   
    CAN.sendMsgBuf(ID_Local,0, 8, offR1_offR2);
    Led_mensaje_enviado_blink_OFF();
    delay(5000);  
}


 void Led_mensaje_enviado_blink_uno(){
          digitalWrite(LED,true);
          delay(100);
          digitalWrite(LED,false);  
  }

void Led_mensaje_enviado_blink_dos(){
          digitalWrite(LED,true);
          delay(100);
          digitalWrite(LED,false);
          delay(100);  
          digitalWrite(LED,true);
          delay(100);
          digitalWrite(LED,false);  
  }
void Led_mensaje_enviado_blink_tres(){
          digitalWrite(LED,true);
          delay(100);
          digitalWrite(LED,false);
          delay(100);  
          digitalWrite(LED,true);
          delay(100);
          digitalWrite(LED,false);  
          delay(100);
          digitalWrite(LED,true);
          delay(100);
          digitalWrite(LED,false);
         
  }
 void Led_mensaje_enviado_blink_OFF(){
          digitalWrite(LED,true);
          delay(500);
          digitalWrite(LED,false);  
  }

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
