/*  Autour  : fatma                          */
/*  Date    : 16 April 2021                  */														
/*  version : V1                             */

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];   /*  To SET PORT(A or B or C) to EXTI from LINE 0  TO LINE 15
                               	        AFIO_EXTICR[4] = {AFIO_EXTICR1, AFIO_EXTICR2, AFIO_EXTICR3, 
										AFIO_EXTICR4 */
	volatile u32 MAPR2;	
}AFIO_type;


#define AFIO ((volatile AFIO_Type *) 0x40010000)







#endif