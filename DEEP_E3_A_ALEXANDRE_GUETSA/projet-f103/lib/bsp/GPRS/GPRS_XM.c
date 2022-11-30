/*
 * GPRS_XM.c
 *
 *  Created on: 18 janv. 2021
 *      Author: xmahe
 */

#include <string.h>
#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
#include "GPRS/GPRS_XM.h"


// Appel de la fonction du type : GPRS_XM_Send_SMS("06xxxxxxxx","Message à envoyer");
void GPRS_XM_Send_SMS(char * mobile, char * message)
{
	uint8_t str_AT_CMGF[] = "AT+CMGF=1\n";
	uint8_t str_MESSAGE[BUFFER_SIZE]={0};

	static uint8_t datas[BUFFER_SIZE] = {0};

	// sets the GSM modem in SMS Text Mode
	//printf("%s",(char*)str_AT_CMGF);
	UART_puts(UART2_ID, str_AT_CMGF, strlen((char*)str_AT_CMGF));

	// ATTENTE DE LA REPONSE "OK"
	GPRS_receive(datas);

	// envoi du numéro de téléphone à contacter
	sprintf((char*)str_MESSAGE,"AT+CMGS=\"%s\"\n",mobile);
	//printf("%s",(char*)str_MESSAGE);
	UART_puts(UART2_ID, str_MESSAGE, strlen((char*)str_MESSAGE));

	// envoi du message
	sprintf((char*)str_MESSAGE,"%s",message);
	//printf("%s",(char*)str_MESSAGE);
	UART_puts(UART2_ID, str_MESSAGE, strlen((char*)str_MESSAGE));

	// ENVOI DU <CTRL-Z> ... ASCII character 26
	char CTRL_Z = 26;
	UART_putc(UART2_ID, CTRL_Z);

	//printf("ATTENTE DE LA REPONSE \"+CMGS: ...\"\n");
	GPRS_receive(datas);
}


void GPRS_XM_Send_SMS_OLD(void)
{
	uint8_t str_AT_CMGF[] = "AT+CMGF=1\n";
	uint8_t str_AT_CMGS[] = "AT+CMGS=\"06xxxxxxxx\"\n"; //numéro de portable du destinataire à préciser
	uint8_t str_MESSAGE[] = "Essai du matin";

	static uint8_t datas[BUFFER_SIZE] = {0};

	// sets the GSM modem in SMS Text Mode
	UART_puts(UART2_ID, str_AT_CMGF, sizeof(str_AT_CMGF)-1);

	// Attente de la réponse "OK"
	GPRS_receive(datas);

	// Envoi du numéro de téléphone à contacter
	UART_puts(UART2_ID, str_AT_CMGS, sizeof(str_AT_CMGS)-1);

	// Attente de la réponse ">"
	GPRS_receive(datas);

	// Envoi du message "coucou"
	UART_puts(UART2_ID, str_MESSAGE, sizeof(str_MESSAGE)-1);

	// Envoi <CTRL-Z> ... ASCII character 26
	char CTRL_Z = 26;
	UART_putc(UART2_ID, CTRL_Z);

	// Attente de la réponse "+CMGS: ..."
	GPRS_receive(datas);
}

void GPRS_receive(uint8_t * receive_frame)
{
	while(UART_data_ready(UART2_ID))
	{
		//static uint8_t buffer[BUFFER_SIZE] = {0};
		static uint8_t index = 0;

		//on récupère chaque octet reçu
		uint8_t c = UART_get_next_byte(UART2_ID);

		if(c == 'A')
			index = 0;

		receive_frame[index] = c;

		if(c=='\n')
		{
			receive_frame[index] = '\0';
			UART_puts(UART3_ID, receive_frame, index);
			index = 0;
		}

		else if(index<BUFFER_SIZE-1)
			index++;
	}
}

void GPRS_XM_TEST(void)
{
	uint8_t str_AT[] = "AT\n";
	uint8_t str_ATI[] = "ATI\n";
	//uint8_t str_AT_CMEE[] = "AT+CMEE=2\n";
	uint8_t str_AT_CCID[] = "AT+CCID\n";
	uint8_t str_AT_COPS[] = "AT+COPS?\n";
	uint8_t str_AT_CSQ[] = "AT+CSQ\n";
	//uint8_t str_AT_CFUN[] = "AT+CFUN=1\n";
	uint8_t str_AT_CMGF[] = "AT+CMGF=1\n";
	uint8_t str_AT_CMGS[] = "AT+CMGS=\"+336xxxxxxxx\"\n"; //numéro de portable du destinataire à préciser
	uint8_t str_MESSAGE[] = "Coucou";

	static uint8_t datas[BUFFER_SIZE] = {0};

	printf("ENVOI DE LA COMMANDE \"AT\"\n");
	// initializing the auto-baud'er by sending AT and then return
	UART_puts(UART2_ID, str_AT, (sizeof(str_AT))-1);

	// ATTENTE DE LA REPONSE "OK"
	//recept_size = UART_gets_blocking(UART2_ID, datas,2,SHORT_TIME_OUT); //0);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);

	printf("ENVOI DE LA COMMANDE \"ATI\"\n");
	// Get the module name and revision
	UART_puts(UART2_ID, str_ATI, sizeof(str_ATI)-1);

	// ATTENTE DE LA REPONSE
	//recept_size = UART_gets_blocking(UART2_ID, datas, BUFFER_SIZE,SHORT_TIME_OUT); //0);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);

	printf("ENVOI DE LA COMMANDE \"AT+CMEE=2\"\n");
	// Turn on verbose errors
	UART_puts(UART2_ID, str_ATI, sizeof(str_ATI)-1);

	// ATTENTE DE LA REPONSE "OK"
	//recept_size = UART_gets_blocking(UART2_ID, datas, 2,SHORT_TIME_OUT); //0);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);

	printf("ENVOI DE LA COMMANDE \"AT+CCID\"\n");
	// get the SIM card number
	UART_puts(UART2_ID, str_AT_CCID, sizeof(str_AT_CCID));

	// ATTENTE DE LA REPONSE
	//recept_size = UART_gets_blocking(UART2_ID, datas, BUFFER_SIZE,LONG_TIME_OUT);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);

	printf("ENVOI DE LA COMMANDE \"AT+COPS?\"\n");
	// Check that you're connected to the network, in this case T-Mobile
	UART_puts(UART2_ID, str_AT_CCID, sizeof(str_AT_COPS));

	// ATTENTE DE LA REPONSE
	//recept_size = UART_gets_blocking(UART2_ID, datas, BUFFER_SIZE,LONG_TIME_OUT);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);

	printf("ENVOI DE LA COMMANDE \"AT+CSQ\"\n");
	// Check the 'signal strength' - the first # is dB strength,
	// it should be higher than around 5. Higher is better.
	// Of course it depends on your antenna and	location!
	UART_puts(UART2_ID, str_AT_CCID, sizeof(str_AT_CSQ));

	// ATTENTE DE LA REPONSE
	//recept_size = UART_gets_blocking(UART2_ID, datas, BUFFER_SIZE,LONG_TIME_OUT);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);

//	printf("ENVOI DE LA COMMANDE \"AT+CFUN=1\"\n);
//	// set Full functionality (Default)
//	UART_puts(UART2_ID, str_AT_CFUN, sizeof(str_AT_CFUN));
//
//	// ATTENTE DE LA REPONSE "OK"
//	recept_size = UART_gets_blocking(UART2_ID, datas,2,SHORT_TIME_OUT);
//	UART_puts(UART3_ID, datas, recept_size);

	printf("ENVOI DE LA COMMANDE \"AT+CMGF=1\"\n");
	// sets the GSM modem in SMS Text Mode
	UART_puts(UART2_ID, str_AT_CMGF, sizeof(str_AT_CMGF)-1);

	// ATTENTE DE LA REPONSE "OK"
	//recept_size = UART_gets_blocking(UART2_ID, datas, 2,SHORT_TIME_OUT); //0);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);

	printf("ENVOI DE LA COMMANDE \"AT+CMGS=+336xxxxxxxx\"\n");
	// envoi du numéro de téléphone à contacter
	UART_puts(UART2_ID, str_AT_CMGS, sizeof(str_AT_CMGS)-1);

	//HAL_Delay(5000);

	printf("ATTENTE DE LA REPONSE \">\"\n");
	//recept_size = UART_gets_blocking(UART2_ID, datas, 1,SHORT_TIME_OUT); //0);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);

	printf("ENVOI DU MESSAGE \"coucou\"\n");
	UART_puts(UART2_ID, str_MESSAGE, sizeof(str_MESSAGE)-1);

	// ENVOI DU <CTRL-Z> ... ASCII character 26
	char CTRL_Z = 26;
	UART_putc(UART2_ID, CTRL_Z);

	printf("ATTENTE DE LA REPONSE \"+CMGS: ...\"\n");
	//recept_size = UART_gets_blocking(UART2_ID, datas, BUFFER_SIZE,VERY_LONG_TIME_OUT); //0);
	//UART_puts(UART3_ID, datas, recept_size);
	GPRS_receive(datas);
}
