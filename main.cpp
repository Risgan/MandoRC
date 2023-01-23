#include "mbed.h"
// #include "Servo.h"
#include "RF24L01.h"


float map(float in, float inMin, float inMax, float outMin, float outMax);
float map_limit(float in, float inMin, float inMax, float outMin, float outMax, float limitMin, float limitMax);


Serial pc(PA_9,PA_10) ; //tx rx

DigitalOut led(PC_13);

DigitalIn SW1(PB_10);
DigitalIn SW2(PB_11);

AnalogIn M(A0);
AnalogIn T(A1);
AnalogIn A(A2);
AnalogIn E(D13);

int main()
{

    while(true) {
        led = !led;
        // pc.printf(" percentage: %3.10f%%", a.read()*100.0f);
        float x = map(M.read(),0.0f,1.0f,0.0f,100.0f);
        pc.printf("M %3.2f \n\r",map(M.read(),0.0f,1.0f,0.0f,100.0f));
        // wait(1.0f);

        pc.printf("E %3.2f \n \r",map(E.read(),0.0f,1.0f,0.0f,100.0f));
        // wait(1.0f);
        pc.printf("A %3.2f \n \r",map(A.read(),0.0f,1.0f,0.0f,100.0f));
        // wait(1.0f);
        pc.printf("T %3.2f \n \r",map(T.read(),0.0f,1.0f,0.0f,100.0f));
        // x = map_limit(a.read(),0.0f,1.0f,-1.0f,1.0f,-100,100);
        // pc.printf(" %3.2f",x);
        wait(1.0f);
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

float map_limit(float in, float inMin, float inMax, float outMin, float outMax, float limitMin, float limitMax)
{
    if(in<=inMin) {
        if (limitMin > outMin) {
            return limitMin;
        }
        else {
            return outMin;
        }
    } else if(in>=inMax) {
        if (limitMax < outMax) {
            return limitMax;
        }
        else {
            return outMax;
        }
    } else {
        float data = (in - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
        if (limitMin > data) {
            return limitMin;
        }
        else if(limitMax < data){
            return limitMax;
        }
        else {
            return data;
        }   
    }
}