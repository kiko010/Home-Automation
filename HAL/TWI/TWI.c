/*
 * TWI_init.c
 *
 *  Created on: Oct 10, 2016
 *      Author: ahmed
 */

#include "TWI.h"

/*****************************************************/
/*I2c initialization*/
void TWI_init(void)
{
	TWBR=32;   // to set the speed 100kb/s
	TWSR=0;   // TWPS=0; //PreScaler 1:1
	TWCR=(1<<TWEN)|(1<<TWEA); // enable the TWI peripheral
}

/*****************************************************/
/*Device Address*/
void TWI_address(unsigned char address)
{
	TWAR=((address<<1)&(0xfe));
}

/*****************************************************/
/*Sending a start bit for starting the comm.*/
void TWI_start(void)
{
	TWCR =(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}

/*****************************************************/
/*Sending the Address*/
void TWI_send_DeviceAddress_Read(unsigned char address)
{
	TWDR=((address<<1)|(0x01));//Address+WriteBit
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while(!(TWCR & (1<<TWINT)));
}

/*****************************************************/
void TWI_send_DeviceAddress_Write(unsigned char address)
{
	TWDR=((address<<1)&(0xfe));//Address+WriteBit
	TWCR=(1<<TWEN)|(1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
}

/*****************************************************/
/*Sending a byte of data*/
void TWI_send_data(unsigned char Data)
{
	TWDR=Data;
	TWCR=(1<<TWEN)|(1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
}

/*****************************************************/
/*Sending a stop bit*/
void TWI_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);


}

/*****************************************************/
/*Receive with ACK*/
unsigned char  TWI_recieve_data_ACK(void)
{
	while(((!(TWCR & (1<<TWINT))))&&((((TWSR&0xf8)!=0x80))||((TWSR&0xf8)!=0x50)));
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	return TWDR;
}
/*****************************************************/
/*Receive with NACK*/
unsigned char  TWI_recieve_data_NACK(void)
{
	while(((!(TWCR & (1<<TWINT))))&&((((TWSR&0xf8)!=0x88))||((TWSR&0xf8)!=0x58)));
	TWCR=(1<<TWEN)|(1<<TWINT);
	return TWDR;
}
/*****************************************************/
