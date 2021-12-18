#include "lcd.h"
#include "config.h"
#include "atraso.h"
#include "leds.h"
#include "pwm.h"
#include <proc/pic18f4520.h>

void letramorse(unsigned char letra){
    
    switch(letra){
        case 'a':
            lcdString(".-");
            break;
        case 'b':
            lcdString("-...");
            break;
        case 'c':
            lcdString("-.-.");
            break;
        case 'd':
            lcdString("-..");
            break;
        case 'e':
            lcdString(".");
            break;
        case 'f':
            lcdString("..-.");
            break;
        case 'g':
            lcdString("--.");
            break;
        case 'h':
            lcdString("....");
            break;
        case 'i':
            lcdString("..");
            break;
        case 'j':
            lcdString(".---");
            break;
        case 'k':
            lcdString("-.-");
            break;
        case 'l':
            lcdString(".-..");
            break;
        case 'm':
            lcdString("--");
            break;
        case 'n':
            lcdString("-.");
            break;
        case 'o':
            lcdString("---");
            break;
        case 'p':
            lcdString(".--.");
            break;
        case 'q':
            lcdString("--.-");
            break;
        case 'r':
            lcdString(".-.");
            break;
        case 's':
            lcdString("...");
            break;
        case 't':
            lcdString("-");
            break;
        case 'u':
            lcdString("..-");
            break;
        case 'v':
            lcdString("...-");
            break;
        case 'w':
            lcdString(".--");
            break;
        case 'x':
            lcdString("-..-");
            break;
        case 'y':
            lcdString("-.--");
            break;
        case 'z':
            lcdString("--..");
            break;
    }
}
void morseletra( unsigned char cod[4]){
    unsigned char coda[4]={'-','.','0','0'},codb[4]={'-','.','.','.'},codc[4]={'-','.','-','.'},
    codd[4]={'-','.','.','0'}, code[4]={'.','0','0','0'}, codf[4]={'.','.','-','.'}, 
    codg[4]={'-','-','.','0'},codh[4]={'.','.','.','.'}, codi[4]={'.','.','0','0'};
    int i;
    for(i=0;i<4;i++){
        if(cod[i]!=coda[i]){
            break;
        }else{
            if(i==3){
                lcdChar('a');
            }
        }
    }
     for(i=0;i<4;i++){
        if(cod[i]!=codb[i]){
            break;
        }else{
            if(i==3){
                lcdChar('b');
            }
        }
    }
     for(i=0;i<4;i++){
        if(cod[i]!=codc[i]){
            break;
        }else{
            if(i==3){
                lcdChar('c');
            }
        }
    }
     for(i=0;i<4;i++){
        if(cod[i]!=codd[i]){
            break;
        }else{
            if(i==3){
                lcdChar('d');
            }
        }
    }
     for(i=0;i<4;i++){
        if(cod[i]!=code[i]){
            break;
        }else{
            if(i==3){
                lcdChar('e');
            }
        }
    }
     for(i=0;i<4;i++){
        if(cod[i]!=codf[i]){
            break;
        }else{
            if(i==3){
                lcdChar('f');
            }
        }
    }
     for(i=0;i<4;i++){
        if(cod[i]!=codg[i]){
            break;
        }else{
            if(i==3){
                lcdChar('g');
            }
        }
    }
     for(i=0;i<4;i++){
        if(cod[i]!=codh[i]){
            break;
        }else{
            if(i==3){
                lcdChar('h');
            }
        }
    }
     for(i=0;i<4;i++){
        if(cod[i]!=codi[i]){
            break;
        }else{
            if(i==3){
                lcdChar('i');
            }
        }
    }
}
void apitar(unsigned char val){
    pwmInit();
    config();
    TRISD = 0x00;
    if(val=='-'){
        pwmSet(100);
        atraso_ms(1000);
        pwmSet(0);
    }
    if(val=='.'){
       pwmSet(100);
       atraso_ms(500);     
       pwmSet(0);
    }
}
