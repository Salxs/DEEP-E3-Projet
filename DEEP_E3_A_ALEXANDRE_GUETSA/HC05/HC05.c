/*
 * 	HC05.c
 *
 *  Created on: 30 novembre 2020
 *  Author: Xavier Mahe
 *
 *	Pour configurer le module HC-05, il faut entrer dans un mode « AT », et lui envoyer des « commandes AT ».
 *  Ouvrir le port COM Ã  38400 bauds/sec
 *  Entrer en mode AT en appuyant sur le bouton pendant l'arrivee de l'alim.
 *  On doit observer un clignotement regulier rapide
 *
 */


/*
 * @brief	Cette fonction initialise le module HC05
 * @note	Le module HC-05 doit etre dans un mode AT pour que cette fonction initialise reellement le module
 * @param 	Aucun
 * @note	Aucune
 */

#include "macro_types.h"
#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
 
void HC05_Init()
{
	uint32_t Receive_size = 0;
	char Receive_string[30] = "";

	//Reconfigure le module HC-05 avec les paramÃ¨tres d'usine
	//printf("AT+ORGL\r\n");
	//HAL_Delay(500);

	//To clear any paired devices
	printf("AT+RMAAD\r\n");
	HAL_Delay(500);

	//To set it as slave
	printf("AT+ROLE=0\r\n");
	HAL_Delay(500);

	printf("AT+ROLE?\r\n");
	HAL_Delay(500);

	//Pour pouvoir noter l'adresse, qui sera utile pour configurer le maitre
	printf("AT+ADDR?\r\n");
	//Receive_size = UART_gets_blocking(UART2_ID, Receive_string, 30, 10);
	//Receive_size = UART_gets(UART2_ID, Receive_string, 30);
	HAL_Delay(500);
	printf("Taille de la chaine recue : %ld\n chaine recue : %s\r\n",Receive_size, Receive_string);
	HAL_Delay(500);

	//Set the module device name: ESEO
	printf("AT+NAME=ESEO\r\n");
	HAL_Delay(500);

	//Read the module device name
	printf("AT+NAME?\r\n");
	HAL_Delay(500);
}

/*
 * @brief	Cette fonction permet un echange de donnees via une liaison BLUETOOTH avec, par exemple, une application
 *          type "BT Simple Terminal" sur ANDROID
 * @note	Aucune
 * @param 	Aucun
 * @note	Aucune
 */
 
 void HC05_Test()
{
	char BT_Receive = '\0';

	BT_Receive = UART_getc_blocking(UART2_ID, 10);
	//printf("BT_Receive = %c\r\n",BT_Receive);

	switch (BT_Receive)
	{
	  case 0:
		printf("DROITE");
		break;
	  case 1:
		printf("GAUCHE");
		break;
	  case 2:
		printf("AVANCER");
		break;
	  case 3:
		printf("RECULER");
		break;
	  case 4:
		printf("STOP");
		break;
	  case 5:
		printf("PLUS");
		break;
	  case 6:
		printf("MOINS");
		break;
	  case 63: // symbole ASCII du ?
		printf("%i",100); // Vitesse_ent
		printf("%i",50); //Vitesse_dec
		printf("%i",100); //Distance_ent
		printf("%i",12); //V_batterie_ent
		printf("%i",2); //V_batterie_dec
		printf("%i",1); //I_robot_ent;
		printf("%i",6);  //I_robot_dec;
		printf("%i",1); //Obstacle
		break;
	  default:
		printf("!");
	}


}
 
