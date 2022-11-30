/*
 * servo.c
 *
 *  Created on: 28 juil. 2020
 *      Author: xmahe
 */

#include "servo.h"

static uint16_t current_position;

void SERVO_process_test(void)
{
	static uint16_t position = 50;
	static bool_e previous_button = FALSE;
	bool_e current_button;

	//lecture du bouton bleu
	current_button = !HAL_GPIO_ReadPin(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN);

	if(current_button && !previous_button) //si appui bouton
	{
		position = (position > 99)?0:(position+5); //de 0 à 100%, par pas de 5%
		SERVO_set_position(position);
	}

	previous_button = current_button; //sauvegarde pour le prochain passage
	HAL_Delay(10); //anti-rebond "de fortune" en cadencant la lecture du bouton
}

void SERVO_init(void)
{
	//initialisation et lancement du timer4 à une période de 10 ms
	TIMER_run_us(TIMER4_ID, PERIOD_TIMER*1000, FALSE); //10000us = 10ms

	//activation du signal PWM sur le canal 1 du timer 4 (broche PB6)
	TIMER_enable_PWM(TIMER4_ID, TIM_CHANNEL_1, 150,0,0);

	//rapport cyclique reglé pour une position servo de 50%
	SERVO_set_position(50);
}

//position est exprimée de 0 à 100.
void SERVO_set_position(uint16_t position)
{
	uint16_t Duty_cycle;

	current_position = position;

	if(position > 100)
		position = 100; //écretage si l'utilisateur demande plus de 100%

	Duty_cycle = 100 + position;
	//TODO : mise à jour du rapport cyclique.
	//duty doit être exprimé ici de 100 à 200 (sur 1000) (pour un rapport cyclique
	//de 10% à 20%, c’est-à-dire une durée de pulse de 1 à 2ms dans la période de 10ms)
	//Donc on additionne 100 à position.
	TIMER_set_duty(TIMER4_ID, TIM_CHANNEL_1, Duty_cycle);
}

uint16_t SERVO_get_position(void)
{
	return current_position;
}


