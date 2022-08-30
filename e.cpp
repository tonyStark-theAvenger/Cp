#include <reg51.h>


sfr port0 = 0x80;
sfr port1 = 0x90;
sfr port2 = 0xA0;


//delay
void Delay(unsigned int time) {
    unsigned int i, j;
    for (int i = 0; i < time; i++) {
        for (j = 0; j < 1275; j++) {

        }
    }
}


void main(void) {

    port0 = 0x55;
    port1 = 0x55;
    while (1) {
        port2 = 0x55;

        Delay(250);

        port0 = 0xAA;
        port1 = 0xAA;
        port2 = 0xAA;

        Delay(250);
    }
}