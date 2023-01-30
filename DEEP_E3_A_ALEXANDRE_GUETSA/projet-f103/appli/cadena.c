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
#include "NFC03A1/nfc03a1.h"
#include "GPS/GPS.h"

#define BUFFER_SIZE 128

static ISO14443A_CARD badge_1;
static ISO14443A_CARD badge_2;


void CADENA_state_machine(void)
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
	static char message;
	uint8_t numero_badge_ancien = 1;
	//uint8_t tag;
	ISO14443A_CARD card;
	uint8_t t = 20;
	gps_datas_t coord;
	nmea_frame_e result;
	uint8_t tagToFind;


	switch(etat_cadena){

		case INIT :
			//Inititalisation des liaisons UART
			UART_init(UART2_ID,9600);
			//UART_init(UART3_ID,9600);
			//On envoie les printf vers la sortie UART3
			SYS_set_std_usart(UART3_ID, UART3_ID, UART3_ID);
			//Initialisation des ports GPIO pour les LEDs
			BSP_GPIO_PinCfg(GPIOA, GPIO_PIN_6, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
			BSP_GPIO_PinCfg(GPIOA, GPIO_PIN_7, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
			//Initialisation du module Bluetooth HC-05
			HC05_Init();
			//Initialisation du module NFC
			NFC03A1_Init(PCD);
			etat_cadena = WAIT_CONNEXION;
			printf("INIT");
			break;

		case WAIT_CONNEXION :
			printf("Wait connexion");
			message = CADENA_recuperation_message();
			printf("Voici le message %s", message);
			//Si on d�tecte une connexion on passe dans l'�tat connexion
			if(UART_data_ready(UART2_ID))
			{
				printf("Connect�");
				message = "";
				etat_cadena = CONNEXION;
			}
			//Si on d�tecte un badge NFC on d�verouille le cadena
			card = CADENA_NFC();
			if(card != NULL)
			{
				printf("Badge D�tect�");
				etat_cadena = DEVERROUILLAGE;
			}


			break;

		case CONNEXION :
			printf("Connexion");
			message = CADENA_recuperation_message();
			//Si on re�oit le message "verrouille" on verouille le cadena
			if(message == "verrouille")
			{
				//Action sur la pin responsable de la gache
				message = "";
			}
			//Si on re�oit le message "badge" on passe dans l'etat BADGE
			else if(message == "badge")
			{
				printf(message);
				etat_cadena = BADGE;
				message = "";
			}
			//Si on re�oit le message "gps" on envoie les coordonn�es GPS � l'application
			else if(message == "gps")
			{
				//On se met � r�ceptionner les trames qui arrivent dans le GPS
				while(UART_data_ready(UART3_ID))
				{
					// On essaie de d�tecter la fin de la trame
					if((result == TRAME_GPRMC) || (result == TRAME_GPGGA))
					{
						//on envoie les coordon�es GPS sur l'application
						printf("Le cadena se situe aux coordonn�es suivantes : %lf, %lf\n", coord.latitude_deg, coord.longitude_deg);
						break;
					}
					else
					{
						//
						result = GPS_process_rx(UART_get_next_byte(UART3_ID), &coord);
					}
				}

			result = NO_TRAME_RECEIVED;
			}
			//On v�rifie si la connexion Bluetooth fonctionne toujours, si non on repasse dans l'�tat WAIT_CONNEXION
			if(!UART_data_ready(UART2_ID))
			{
				message = "";
				etat_cadena = WAIT_CONNEXION;
			}
			break;

		case BADGE :
			//On laisse 20 secondes � l'utilisateur pour placer un badge valide sur le capteur NFC

			while(t > 0)
			{
				printf("etat badge");
				//On enregistre le badge de sorte � ce qu'il puisse d�verrouiller le cadena.
				//Si plus de deux badges sont enregistr�s on supprime le plus ancien (� voir)
				//Envoie d'un message � l'application pour confirmer l'enregistrement du badge
				if(numero_badge_ancien == 1)
				{
					numero_badge_ancien = 2;
					NFC03A1_get_ISO14443A_infos(&badge_1);
					break;
				}
				else if(numero_badge_ancien == 2)
				{
					numero_badge_ancien = 1;
					NFC03A1_get_ISO14443A_infos(&badge_2);
					break;
				}
				else
				{
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
					HAL_Delay(1000);
					t--;
				}
			}

			etat_cadena = CONNEXION;
			break;

		case DEVERROUILLAGE :
			//On v�rifie si le badge est autoris� � d�verrouiller le cadena
			NFC03A1_get_ISO14443A_infos(&card);

			if((badge_1.UID == card.UID) || (badge_2.UID == card.UID))
			{
				//Si le badge est correct on d�verrouille et on fait clignoter la LED verte
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
				//Action sur la pin responsable de la gestion de la gache �lectrique
			}
			else
			{
				//Si le badge n'est pas valide on fait clignoter la LED rouge
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
			}
			break;

		default :
			break;
	}

}


char CADENA_recuperation_message(void)
{
	//D�finition de notre variable de r�cup�ration
	char info = 0;

	//Tant que la liaison UART re�oit des informations on continue de les r�cup�rer
	while(UART_data_ready(UART2_ID))
	{
		//r�cup�ration des donn�es de la liaison UART
		info = info + UART_getc_blocking(UART2_ID, 1000);
		printf(info);
		HAL_Delay(500);
	}
	return info;

}
//Il s'agit de la m�me fonction que la fonction d�mo propos� dans le fichier nfc03a1.c
//La fonction a �t� modifi� pour �tre utiliser de mani�re plus efficace
//Dans cette version nous renvoyons les informations contenu dans le badge vers le programme

ISO14443A_CARD CADENA_NFC(void)
{
	uint8_t tag;
	ISO14443A_CARD infos;
		while(1)
		{
			tag = ConfigManager_TagHunting(TRACK_ALL);
			switch(tag)
			{
				case TRACK_NFCTYPE4A:
				{
					NFC03A1_get_ISO14443A_infos(&infos);
					uint8_t i;
					printf("uid = ");
					for(i=0; i<infos.UIDsize;i++)
						printf("%02x ",infos.UID[i]);
					printf("\n");
					break;}
				default:
					break;
			}
		}
		return infos;
}

