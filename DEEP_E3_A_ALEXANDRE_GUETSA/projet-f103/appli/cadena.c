/*
 * cadena.c
 *
 *  Created on: 6 janv. 2023
 *      Author: Salxs
 */

#include "cadena.h"
#include "config.h"
#include "macro_types.h"
#include "systick.h"

/*void CADENA_state_machine(void)
{
	//r�alisation de la machine � �tat du projet

	typedef enum
	{
		INIT = 0,
		WAIT_CONNEXION,
		CONNEXION,
		BADGE,
		DEVERROUILLAGE
	}state_e;

	static state_e etat_cadena = INIT;

	switch(etat_cadena){

		case INIT :
			//Inititalisation des liaisons UART
			UART_init(UART2_ID,115200);
			UART_init(UART3_ID, 9600);
			//Initialisation des ports GPIO pour les LEDs
			BSP_GPIO_PinCfg(GPIOA, GPIO_PIN_6, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
			BSP_GPIO_PinCfg(GPIOA, GPIO_PIN_7, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
			//Initialisation du module Bluetooth HC-05
			HC05_Init();
			//Initialisation du module NFC
			NFC03A1_Init(PCD);
			etat_cadena = WAIT_CONNEXION;
			break;

		case WAIT_CONNEXION :
			//Si on d�tecte une connexion on passe dans l'�tat connexion
			if()
			{

			}
			//Si on d�tecte un badge NFC on d�verouille le cadena
			else if()
			{
				etat_cadena = DEVERROUILLAGE;
			}
			break;

		case CONNEXION :
			//Si on re�oit le message "verrouille" on verouille le cadena
			if()
			{

			}
			//Si on re�oit le message "badge" on passe dans l'etat BADGE
			else if()
			{
				etat_cadena = BADGE;
			}
			//Si on re�oit le message "gps" on envoie les coordonn�es GPS � l'application
			else if()
			{

			}
			//On v�rifie si la connexion Bluetooth fonctionne toujours, si non on repasse dans l'�tat WAIT_CONNEXION
			if()
			{
				etat_cadena = WAIT_CONNEXION;
			}
			break;

		case BADGE :
			//On laisse 20 secondes � l'utilisateur pour placer un badge valide sur le capteur NFC
			uint16_t time = 20000;
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
			while(time > 0)
			{
				//Si un badge est d�tect� sur le capteur on enregistre celui-ci
				if()
				{
					//On enregistre le badge de sorte � ce qu'il puisse d�verrouiller le cadena.
					//Si plus de deux badges sont enregistr�s on supprime le plus ancien (� voir)
					//Envoie d'un message � l'application pour confirmer l'enregistrement du badge
				}
			}
			etat_cadena = CONNEXION;
			break;

		case DEVERROUILLAGE :
			//On v�rifie si le badge est autoris� � d�verrouiller le cadena
			if()
			{
				//Si le badge est correct on d�verrouille et on fait clignoter la LED verte
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
			}
			else
			{
				//Si le badge n'est pas valide on fait clignoter la LED rouge
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
			}
			break;
	}
}*/
