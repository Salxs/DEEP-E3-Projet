/*
 * servo.h
 *
 *  Created on: 28 juil. 2020
 *      Author: xmahe
 */

#ifndef SERVO_H_
#define SERVO_H_

//Constantes priv�es
#define PERIOD_TIMER 10 //ms

//D�pendances
#include "config.h"
#include "macro_types.h"
#include "stm32f1_timer.h"
#include "stm32f1_gpio.h"

//Fonctions publiques :
void SERVO_init(void);
void SERVO_set_position(uint16_t position);
void SERVO_process_test(void);
uint16_t SERVO_get_position(void);

//Fonctions priv�es :
//(aucune)

#endif /* SERVO_H_ */
