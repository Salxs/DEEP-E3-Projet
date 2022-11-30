/*
 * WS2812B.c
 *
 *  Created on: 3 mai 2016
 *      Author: Samuel Poiraud modifi� par Xavier Mah� le 11 janvier 2021
 *
 *
 *      les envois de pixels sont sous-trait�s � la fonction assembleur WS2812S_send_pixel
 *      	https://github.com/Daedaluz/stm32-ws2812/tree/master/src
 *
 */

 /*	Sur la matrice de 64 WS2812, les leds sont chain�es ligne apr�s ligne.
 */


#include "config.h"
#if USE_MATRIX_LED

#include "stm32f1xx_hal.h"
#include "WS2812B.h"
#include "config.h"
#include "macro_types.h"
#include "stm32f1_gpio.h"
#include <math.h>

#define OUTPUT(x)	HAL_GPIO_WritePin(LED_MATRIX_PORT_DATA, LED_MATRIX_PIN_DATA, x)

void LED_MATRIX_init(void)
{
	BSP_GPIO_PinCfg(LED_MATRIX_PORT_DATA, LED_MATRIX_PIN_DATA, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);
}

//fonction asm modifi�e par Xavier Mah� le 11 janvier 2021
extern void WS2812B_send_pixel(uint32_t pixel, uint32_t gpio_pin_x, uint32_t * gpiox_bsrr);

/*
extern void send_pixel(uint32_t pixel, uint32_t * gpiox_bsrr, uint32_t * gpiox_brr);

//Cette fonction est cod�e en assembleur et respecte les d�lais des bits impos�s par le fabricant.
void send_pixel(uint32_t pixel, uint32_t * gpiox_bsrr, uint32_t * gpiox_brr)
{
	uint32_t bit;
	uint32_t i;
	i = 0;
	do
	{
		bit = (pixel >> i) & 1;
		if(bit)
			*gpiox_bsrr = 1;
		else
			*gpiox_brr = 1;
	}while(i<32);
}
*/


void LED_MATRIX_send_pixel(uint32_t pixel)
{
	WS2812B_send_pixel(pixel, LED_MATRIX_PIN_DATA, (uint32_t *)&LED_MATRIX_PORT_DATA->BSRR);
}

void LED_MATRIX_demo(void)
{
	static uint8_t j = 0;
	uint8_t i;

	uint32_t pixels[MATRIX_SIZE];
	for(i=0;i<MATRIX_SIZE;i++)
	{
		if(i < MATRIX_SIZE/3)
			pixels[i] = COLOR_RED;
		else if(i < (2*MATRIX_SIZE)/3)
			pixels[i] = COLOR_GREEN;
		else
			pixels[i] = COLOR_BLUE;
	}
	pixels[j] = COLOR_BLACK;
	j = (j+1)%MATRIX_SIZE;
	LED_MATRIX_display(pixels, MATRIX_SIZE);
	//HAL_Delay(100);
}

/*
 * @brief	Cette fonction envoie 64 pixels vers la matrice de leds.
 * @note	les envois de pixels sont sous-trait�s � la fonction assembleur WS2812S_send_pixel
 * 			Cette fonction est r�dig�e en assembleur pour respecter scrupuleusement les d�lais de production des signaux pour les leds de la matrice.
 * 			Remarque : les interruptions sont d�sactiv�es temporairement pendant l'ex�cution de cette fonction pour �viter qu'elles provoquent des 'pauses' lors de la production des signaux.
 * 			La dur�e d'ex�cution de cette fonction est de l'ordre de 2,5ms. Dur�e pendant laquelle aucune interruption ne peut survenir !!!
 * @param 	pixels est un tableau de 64 cases absolument...
 * @note	attention, le tableau de pixels correspond aux leds dans l'ordre o� elles sont c�bl�es. Sur la matrice 8x8, elles sont reli�es en serpentin ! (et non en recommancant � gauche � chaque nouvelle ligne)...
 */
void LED_MATRIX_display(uint32_t * pixels, uint16_t size)
{
	uint16_t i;
	__disable_irq();
	//Envoi d'un train de size pixels x 24 bits
	for(i=0;i<size;i++)
		WS2812B_send_pixel(pixels[i], LED_MATRIX_PIN_DATA, (uint32_t *)&LED_MATRIX_PORT_DATA->BSRR);
	//Envoi d'un reset sup�rieur � 50�s
	LED_MATRIX_reset();
	__enable_irq();
}

void LED_MATRIX_display_only_one_pixel(uint32_t pixel, uint8_t rank, uint16_t size)
{
	uint8_t i;
	__disable_irq();
	//Envoi d'un train de size pixels x 24 bits
	for(i=0;i<size;i++)
		WS2812B_send_pixel((i==rank)?pixel:COLOR_BLACK, LED_MATRIX_PIN_DATA, (uint32_t *)&LED_MATRIX_PORT_DATA->BSRR);
	//Envoi d'un reset sup�rieur � 50�s
	LED_MATRIX_reset();
	__enable_irq();
}

void LED_MATRIX_display_full(uint32_t pixel, uint16_t size)
{
	uint8_t i;
	__disable_irq();
	//Envoi d'un train de size pixels x 24 bits
	for(i=0;i<size;i++)
		WS2812B_send_pixel(pixel, LED_MATRIX_PIN_DATA, (uint32_t *)&LED_MATRIX_PORT_DATA->BSRR);
	//Envoi d'un reset sup�rieur � 50�s
	LED_MATRIX_reset();
	__enable_irq();
}

void LED_MATRIX_reset(void)
{
	//OUTPUT(0);
	HAL_GPIO_WritePin(LED_MATRIX_PORT_DATA, LED_MATRIX_PIN_DATA, GPIO_PIN_RESET);

	//r�gler RES pour obtenir un RESET = 100�s entre 2 pixels
	uint16_t compteur = 0;
	uint16_t RES = 200;
	while(compteur<RES)
		compteur ++;
}

void LED_MATRIX_Test_XM(uint8_t offset)
{
	LED_MATRIX_init();
	uint32_t tab_Neo_Matrix[MATRIX_SIZE];

	//Extinction de toutes les LED du tableau
	for(uint8_t i=0; i<MATRIX_SIZE; i++)
		tab_Neo_Matrix[i] = COLOR_BLACK;

	//D�finition des couleurs de chaque pixel du tableau tab_Neo_Matrix

	for (uint8_t i = 0; i<MATRIX_LINE_SIZE; i++)
	{
		tab_Neo_Matrix[i+(offset*8)] = COLOR_BLUE;
	}

	LED_MATRIX_display(tab_Neo_Matrix, MATRIX_SIZE);
}


#endif
