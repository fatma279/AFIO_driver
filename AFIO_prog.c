/*  Autour  : fatma                          */
/*  Date    : 16 April 2021                  */														
/*  version : V1                             */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


 void MAFIO_voidSetEXTIConfiguration(u8 copy_u8Line, u8 copy_u8PortMap){
	 u8 LOC_u8RegIndex = 0;
	 /* LOC_u8RegIndex which register in array and the right position for line  */
	 if(copy_u8Line < 4)
	 {
		LOC_u8RegIndex = 0;		
	 }
	 else if(copy_u8Line < 8)
	 {
		 LOC_u8RegIndex = 1;
		 copy_u8Line -=4;
	 }
	 else if(copy_u8Line < 12)
	 {
		 LOC_u8RegIndex = 2;
		 copy_u8Line -=4;
	 }
	 else if(copy_u8Line < 16)
	 {
		 LOC_u8RegIndex = 3;
		 copy_u8Line -=4;
	 }	 
	 /* clear the line position before write its port*/
	 AFIO->EXTICR[LOC_u8RegIndex] &= ~((0b1111)<< (copy_u8Line * 4));
	 /* write port for line (pin) */
	 AFIO->EXTICR[LOC_u8RegIndex] |= ((copy_u8PortMap)<< (copy_u8Line * 4));
 }