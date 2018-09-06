/****************************************************************************
 * File:   main.c                                                           *
 * Author: Esteban Lemos                                                    *
 * Created on 5 de febrero de 2014, 20:49                                   *
 * En caso de necesitar el proyecto completo ingresar en                    *
 * https://github.com/EEST1/Plantilla_6to                                   *
 ****************************************************************************/

#include <xc.h>
#include "confbits.h"       //no se debe de modificar este archivo para
//garantizar el funcionamiento del BOOTLOADER

#include "Tecnica1.h"       //segun el shield habilita distintas librerias

void init_Shield (void);

/*variables globales ********************************************************/
void main (void) {
    init_Shield();
    while (1) {


    }
}

void __interrupt myISR (void) {
    if (TMR0IF) {
        TMR0 = 65160;
        TMR0IF = 0;
    }
}

void init_Shield (void) {
    CMCON = 0x07; //comparadores de entrada deshabilitados
    ADCON1 = 0x0F; //Conversores AD deshabilitados la habilitación 

    /*Configuracion Interrupciones*********************************************/

    INTCONbits.GIE = 1; //Interrupciones Globales (Global Enable Interrupt)
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0; //falg en 0 (Timer 0)
    TIMER0_INI(); //Conf Timer0
    T0CONbits.TMR0ON = 1; //Timer 0 ON

    /*Configuracion Puertos****************************************************/
    TRISA = 0x00;
    TRISEbits.RE0 = 0;
    TRISEbits.RE1 = 0;
    TRISEbits.RE2 = 0;
    ei() :
}