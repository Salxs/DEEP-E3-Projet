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
		position = (position > 99)?0:(position+5); //de 0 � 100%, par pas de 5%
		SERVO_set_position(position);
	}

	previous_button = current_button; //sauvegarde pour le prochain passage
	HAL_Delay(10); //anti-rebond "de fortune" en cadencant la lecture du bouton
}

void SERVO_init(void)
{
	//initialisation et lancement du timer4 � une p�riode de 10 ms
	TIMER_run_us(TIMER4_ID, PERIOD_TIMER*1000, FALSE); //10000us = 10ms

	//activation du signal PWM sur le canal 1 du timer 4 (broche PB6)
	TIMER_enable_PWM(TIMER4_ID, TIM_CHANNEL_1, 150,0,0);

	//rapport cyclique regl� pour une position servo de 50%
	SERVO_set_position(50);
}

//position est exprim�e de 0 � 100.
void SERVO_set_position(uint16_t position)
{
	uint16_t Duty_cycle;

	current_position = position;

	if(position > 100)
		position = 100; //�cretage si l'utilisateur demande plus de 100%

	Duty_cycle = 100 + position;
	//TODO : mise � jour du rapport cyclique.
	//duty doit �tre exprim� ici de 100 � 200 (sur 1000) (pour un rapport cyclique
	//de 10% � 20%, c�est-�-dire une dur�e de pulse de 1 � 2ms dans la p�riode de 10ms)
	//Donc on additionne 100 � position.
	TIMER_set_duty(TIMER4_ID, TIM_CHANNEL_1, Duty_cycle);
}

uint16_t SERVO_get_position(void)
{
	return current_position;
}


