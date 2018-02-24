/*
 * Home Automation
 *
 * Created: 24/02/2018 10:00:07 am
 * Author : kiko010
 */ 
 
 /* Including the main drivers to be Used */
 
 #include "c:\users\kiko0\Documents\Atmel Studio\7.0\Home Automation\Home Automation\HAL\LCD\LCD.h"
 #include "c:\users\kiko0\Documents\Atmel Studio\7.0\Home Automation\Home Automation\HAL\UART\UART.h"
 #include "c:\users\kiko0\Documents\Atmel Studio\7.0\Home Automation\Home Automation\HAL\TWI\TWI.h"
 #include "c:\users\kiko0\Documents\Atmel Studio\7.0\Home Automation\Home Automation\HAL\EEPROM\EEPROM.h"
 
 /* Main Function */
 
 int main (void)
 {
	 LCD_Init();
	 UART_init();
	 TWI_init();
	 while (1)
	 { 
		/* Update the Passwords from the EEPROM */
		/* Post Updated Password on the Server's Database */
		/* Check the status of "Safety lock" Feature */
		/* Post Updated status on the Server's Database via WIFI */
		/* Check every Sensor (Heat, Power Consumption, Magnetic Sensors (Doors - Windows)) */
		/* Post Updated status on the Server's Database via WIFI */
		/* Check the Position of light switches */
		/* Post Updated status on the Server's Database via WIFI */
		/* Print "Enter Your Password" on Every Locked Door */
		/* Post Updated status on the Server's Database via WIFI */
	 }
 }
