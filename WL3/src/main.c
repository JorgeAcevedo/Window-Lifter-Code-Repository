/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "S32K144p.h"

/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

/** Short description of the function.
 Detailed description
 with multiline
*/

int main(void) {

	cps_PCC-> PCC_PORTC = 0x40000000; /*Clock enabled for PORTC (Page 573)*/ /*Modifica el bit 30 (0100 000 000 000 000 000 000 000) del puerto C
	                                                                           lo que modifica el CGC (pagina 609)*/
	cps_PCC-> PCC_PORTD = 0x40000000; /*Clock enabled for PORTD*/ /*Modifica el bit 30 (0100 000 000 000 000 000 000 000) del puerto D
	                                                                           lo que modifica el CGC (pagina 610)*/

	cps_PTC->PDDR &= ~(1<<12);  /*Página 186 (GPIO)*/ /*Pin C12 settled as input*/ /*La operación &= sirve para no poner los demás como output,
	                                                           si sólo se pusiera = también funcionaria pero
	                                                           cambiaria todos los valores (ahora no afecta porque sólo estamos usando
	                                                           uno pero podría desconfigurar los demás*/
	                                                          /*Establece el valor del bit 12 (asignado al pin 12 del puerto C) a 0 lo que hace que sea una entrada*/

	cps_PTD->PDDR |= 1<<0;  /*Página 186 (GPIO)*/ /*Pin D0 settled as output*/  /*Establece el valor del bit 0 (asignado al pin 0 del puerto C) a 1 lo que hace que sea una salida*/

	cps_PORTC->PORT_PCR[12]=0x00000110; /*Starts in page 170*/ /*Pin 12 (entre corchetes) del puerto C (puntero)
	                                                            used MUX as GPIO and has the filter activated (0000 0000 0000 0000 0000 0001 0001 0000)*/
	                                                           /*
	                                                            *(página 172) El bit 4 activa el filtro de señales. La combinación de los bit 10, 9 y 8 (en este caso 001)
	                                                            * determina el uso del multiplexor
	                                                            */
	cps_PORTD->PORT_PCR[0]=0x00000100; /*Starts in page 170*/ /*Pin D0 used MUX as GPIO*/ /*Lo mismo que el anterior */



	for(;;){
		if(cps_PTC->PDIR & (0x00001000)){ /* (página 190) Registra las entradas en los pines. En este caso, se compara la señal 0000 0000 0000 0000 0001 0000 0000 0000
		                                                              para averiguar si el bit 12 del puerto C (PTC) (asignado al pin 12, boton)
		                                                              recibe una señal alta (se presiona el boton)*/
			cps_PTD->PCOR |= 1<<0;   /*(página 189) se escribe sobre el registro del bit 0 en el puerto D (asignado al pin 0, led azul).
			                                                          Al escribir un 1 el pin es "cleared to logic 0" en el PDOR,
			                                                          por lo que el led se enciende (Es equivalente a escribir cps_PTD->PDOR = 0<<0*/
		}
		else {
			cps_PTD->PSOR |= 1<<0;  /*(página 188) se escribe sobre el registro del bit 0 en el puerto D (asignado al pin 0, led azul).
			                                                          Al escribir un 1 el pin es "set to logic 0", por lo que el led se apaga
			                                                          es equivalente a cps_PTD->PDOR=1<<0*/
		}

	}



}

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

