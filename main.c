#include <proc/pic18f4520.h>
#include "config.h"
#include "atraso.h"
#include "lcd.h"
#include "serial.h"
#include "ds1307.h"
#include "i2c.h"
#include "io.h"
#include "so.h"
#include "bits.h"
#include "letramorse.h"
#include "keypad.h"
#include "timer.h"
#include "pwm.h"
#include "leds.h"

#define L_ON 0x0F
#define L_OFF 0x08
#define L_CLR 0x01
#define L_L1 0x80
#define L_L2 0xC0

void main(void) 
{
    unsigned char tmp,op;
    unsigned char cod[4];
    unsigned int i,j;
    TRISA = 0xC3;
    TRISB = 0x03;
    TRISC = 0x01;
    TRISD = 0x00;
    TRISE = 0x00;
    ADCON1 = 0x06;
    
    lcdInit();
    serial_init();
    pwmInit();

    TRISCbits.TRISC7 = 1; //RX
    TRISCbits.TRISC6 = 0; //TX
    PORTB = 0;
    //COMUNICAÇÃO LETRA(SERIAL)=> EXIBIÇÃO LETRA E CÓDIGO MORSE(LCD)
    TRISD =0x00;
    for(;;)
    {
        lcdCommand(L_CLR);
        lcdCommand(L_L1);
        lcdString("qual a operacao?");
        atraso_ms(3000);
        lcdCommand(L_CLR);
        lcdCommand(L_L1);
        lcdString("1 letra->morse");
        lcdCommand(L_L2);
        lcdString("2 morse->letra");
        op=serial_rx(0);
        if(op=='1'){
            lcdCommand(L_CLR);
            lcdCommand(L_L1);
            lcdString("qual a letra?");
            tmp = serial_rx(0);
            lcdCommand(L_CLR);
            lcdCommand(L_L1);
            lcdString("LETRA:");
            lcdPosition(0, 6);      
            serial_tx(tmp);
            lcdChar(tmp);
            lcdCommand(L_L2);
            lcdString("MORSE: ");
            lcdPosition(1, 6);
            atraso_ms(500);       
            letramorse(tmp);
            atraso_ms(3000);
            
        }
        //CODIGO MORSE PELO SERIAL ==> EXIBIÇÃO LCD
        if(op=='2'){
          lcdCommand(L_CLR);
          lcdCommand(L_L1);
          lcdString("MORSE: ");
          lcdPosition(0,6);       
          cod[0]=serial_rx(0);
          apitar(cod[0]);
          lcdChar(cod[0]);
          
          cod[1]=serial_rx(0);
          apitar(cod[1]);
          lcdChar(cod[1]);
          
          cod[2]=serial_rx(0);
          apitar(cod[2]);
          lcdChar(cod[2]);
          
          cod[3]=serial_rx(0);
          apitar(cod[3]);
          lcdChar(cod[3]);
          
          lcdCommand(L_L2);
          lcdString("LETRA:");
          lcdPosition(1,6);
          morseletra(cod);
          atraso_ms(3000);
          
          lcdCommand(L_CLR);
          lcdCommand(L_L1);
          
          //EXIBIÇÃO USANDO LEDS PORTD
          lcdString("codigo em leds");2
          lcdCommand(L_L2);
          lcdString("------------>>");
            for(j=0;j<4;j++){
               if(cod[j]=='-'){
                   traco();
               }
               if(cod[j]=='.'){
                   ponto();
               }
               
           }
            
        }
        
        atraso_ms(100);
    }
    

}