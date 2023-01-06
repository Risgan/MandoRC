#include "mbed.h"
#include <RF24.h>

DigitalOut led(PC_13);

RF24 radio(PA_7, PA_6, PA_5,PB_0,PA_4);

Serial pc(USBTX,USBRX) ;
int counter=0;
const uint64_t address = 0x0A0A0A0A0ALL;
int main()
{
    pc.printf("\n uno");
    radio.begin();
//    radio.setAutoAck(false);
    radio.setDataRate(RF24_250KBPS);
    radio.setChannel(90);
    radio.setPALevel(RF24_PA_MAX);
    radio.openReadingPipe(1, address);
    radio.openWritingPipe(address);
    radio.setRetries(15,15);
    radio.startListening();
//    radio.stopListening();  
    pc.printf("\n%u",radio.getPALevel());
    pc.printf("\n%u",radio.get_status());
    pc.printf("\n ok");

    while(1) {

         //led = sw;
//        if(sw) {
//            char s[50]="Hola Mundo";
////            sprintf(yy, "%f",map(ain.read(),0.02,1,0,255));
////            unsigned long motor_code=213;
////            radio.write(&yy, sizeof(yy));
//radio.write(&s, sizeof(s));
//            pc.printf("\n %f %f", map(ain.read(),0.02,1,0,255),ain.read());
//        }

        z

//        pc.printf(str);
        counter++;
        wait_ms(2000);

//char s[50]="Hola Mundo\n";
//radio.write(&s, sizeof(s));
//pc.printf(s);
    }
}


float map(float in, float inMin, float inMax, float outMin, float outMax)
{
    if(in<=inMin) {
        return outMin;
    } else if(in>=inMax) {
        return outMax;
    } else {
        return (in - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
    }
}