/*
 * LED.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */
#include"LED.h"
#include"DIO.h"




void LED_on(void)
{

	DIO_write(PORT_D,PIN7,HIGH);


}


void LED_oFF(void)
{
	DIO_write(PORT_D,PIN7,LOW);


}



void LED_toggle(void)
{
	uint8_t static flag=0;
	if(flag==0)
	{
		DIO_write(PORT_D,PIN7,HIGH);
		flag=1;
	}
	else
	{
		DIO_write(PORT_D,PIN7,LOW);
		flag=0;
	}



}
