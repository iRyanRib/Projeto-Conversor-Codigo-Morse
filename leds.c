#include "config.h"
#include "leds.h"
#include "atraso.h"
void config(void){
    #define TRISD (*(volatile __near unsigned char*) 0xF95) 
    #define PORTD (*(volatile __near unsigned char*) 0xF83)
}
void traco(void){

    volatile float i;
    PORTD = 0x00;
    for (i = 0; i < 500; i++);
    PORTD = 0xF;
    atraso_ms(2000);
    PORTD = 0x00;

}
void ponto(void){
    volatile float i;
    PORTD = 0x00;
    for (i = 0; i < 500; i++);
    PORTD = 0x0C;
    atraso_ms(2000);
    PORTD = 0x00;
    
}
