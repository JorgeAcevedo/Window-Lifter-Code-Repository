/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.x $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \S32K144.h
    Driver for the use of MC NXP S32K144.
    On this file are
    all the mapping of
    ports and address to
    use the specified MC
    on a Window Lifter module
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
 * $Log: filename.h  $
  ============================================================================*/
#ifndef S32K144_H
#define S32K144_H

/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/
typedef unsigned char T_UBYTE;
typedef unsigned short T_UWORD;
typedef unsigned long T_ULONG;
typedef signed char T_SBYTE;
typedef signed short T_SWORD;
typedef signed long T_SLONG;


/*GPIO (General Purpose Input Output) memory map
 * página 186
 */

typedef struct {
	T_ULONG PDOR; //configures the logic leves that are driven on each general-purpose output pin (0=high, 1=low)
	T_ULONG PSOR; //configures wheter to set the field of the PDOR (0=set to logic 1; 1= does not change)
	T_ULONG PCOR; //configures wheter to clear the fields of PDOR (0=does not change; 1=corresponding bit in PDORn is cleared to logic 0
	T_ULONG PTOR; //Toggles (alterna) the logic levels that are driven on each GP output pin (0=Corresponding bit(Cb) in PDORn does not change; 1= Cb is set to the inverse)
	T_ULONG PDIR; //Captures the logic level that are driven into each GP input pin (0=logic 0 or not configured; 1= logic 1)
	T_ULONG PDDR; //configures individual por pins for input or output (0=input; 1=output)
	T_ULONG PIDR; //disables each GP pin from acting as an input (0=GP input; 1=not GP input)
}S_GPIO;

#define GPIO_PORTA_BASE_ADDRESS      0x400FF000
#define GPIO_PORTB_BASE_ADDRESS      0x400FF040
#define GPIO_PORTC_BASE_ADDRESS      0x400FF080
#define GPIO_PORTD_BASE_ADDRESS      0x400FF0C0
#define GPIO_PORTE_BASE_ADDRESS      0x400FF100

#define cps_PTA                     ((S_GPIO *)GPIO_PORTA_BASE_ADDRESS)
#define cps_PTB                     ((S_GPIO *)GPIO_PORTB_BASE_ADDRESS)
#define cps_PTC                     ((S_GPIO *)GPIO_PORTC_BASE_ADDRESS)
#define cps_PTD                     ((S_GPIO *)GPIO_PORTD_BASE_ADDRESS)
#define cps_PTE                     ((S_GPIO *)GPIO_PORTE_BASE_ADDRESS)

/*Ports Multiplexing Controls*/

typedef struct {
	T_ULONG PORT_PCR[32]; /*Pin Control Register*/ //configures each pin from the different ports (página 172)
	T_ULONG PORT_GPCLR;
	T_ULONG PORT_GPCHR;
	T_ULONG PORT_GICLR;
	T_ULONG PORT_GICHR;
	T_ULONG PORT_ISFR;
	T_ULONG PORT_DFER;
	T_ULONG PORT_DFCR;
	T_ULONG PORTDFWR;
}S_PORT;

#define PORTA_BASE_ADDRESS         0x40049000
#define PORTB_BASE_ADDRESS         0x4004A000
#define PORTC_BASE_ADDRESS         0x4004B000
#define PORTD_BASE_ADDRESS         0x4004C000
#define PORTE_BASE_ADDRESS         0x4004D000

#define cps_PORTA         ((S_PORT *)PORTA_BASE_ADDRESS)
#define cps_PORTB         ((S_PORT *)PORTB_BASE_ADDRESS)
#define cps_PORTC         ((S_PORT *)PORTC_BASE_ADDRESS)
#define cps_PORTD         ((S_PORT *)PORTD_BASE_ADDRESS)
#define cps_PORTE         ((S_PORT *)PORTE_BASE_ADDRESS)

/*PCC (Peripheral Clock Controller) memory map */ //página 573

typedef struct {
                        T_ULONG RESERVED0[32];
  T_ULONG PCC_FTFC;
  T_ULONG PCC_DMAMUX;
                        T_ULONG RESERVED1[2];
  T_ULONG PCC_FlexCAN0;
  T_ULONG PCC_FlexCAN1;
  T_ULONG PCC_FTM3;
  T_ULONG PCC_ADC1;
                        T_ULONG RESERVED2[3];
  T_ULONG PCC_FlexCAN2;
  T_ULONG PCC_LPSPI0;
  T_ULONG PCC_LPSPI1;
  T_ULONG PCC_LPSPI2;
                        T_ULONG RESERVED3[2];
  T_ULONG PCC_PDB1;
  T_ULONG PCC_CRC;
                        T_ULONG RESERVED4[3];
  T_ULONG PCC_PDB0;
  T_ULONG PCC_LPIT;
  T_ULONG PCC_FTM0;
  T_ULONG PCC_FTM1;
  T_ULONG PCC_FTM2;
  T_ULONG PCC_ADC0;
                        T_ULONG RESERVED5;
  T_ULONG PCC_RTC;
                        T_ULONG RESERVED6[2];
  T_ULONG PCC_LPTMR0;
                        T_ULONG RESERVED7[8];
  T_ULONG PCC_PORTA; //página 605
  T_ULONG PCC_PORTB; //página 607
  T_ULONG PCC_PORTC; //página 608
  T_ULONG PCC_PORTD; //página 610
  T_ULONG PCC_PORTE; //página 611
                        T_ULONG RESERVED8[9];
  T_ULONG PCC_SAI0;
  T_ULONG PCC_SAI1;
                        T_ULONG RESERVED9[4];
  T_ULONG PCC_FlexIO;
                        T_ULONG RESERVED10[6];
  T_ULONG PCC_EWM;
                        T_ULONG RESERVED11[4];
  T_ULONG PCC_LPI2C0;
  T_ULONG PCC_LPI2C1;
                        T_ULONG RESERVED12[2];
  T_ULONG PCC_LPUART0;
  T_ULONG PCC_LPUART1;
  T_ULONG PCC_LPUART2;
                        T_ULONG RESERVED13;
  T_ULONG PCC_FTM4;
  T_ULONG PCC_FTM5;
  T_ULONG PCC_FTM6;
  T_ULONG PCC_FTM7;
                        T_ULONG RESERVED14;
  T_ULONG PCC_CMP0;
                        T_ULONG RESERVED15[2];
  T_ULONG PCC_QSPI;
                        T_ULONG RESERVED16[2];
  T_ULONG PCC_ENET;
} S_PCC;

#define PCC_BASE_ADDRESS   0x40065000 //página 573
#define cps_PCC            ((S_PCC *)PCC_BASE_ADDRESS)


/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
