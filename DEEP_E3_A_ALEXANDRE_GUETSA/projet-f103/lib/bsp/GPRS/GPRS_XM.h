/*
 * GPRS_XM.h
 *
 *  Created on: 18 janv. 2021
 *      Author: xmahe
 */

#ifndef BSP_GPRS_GPRS_XM_H_
#define BSP_GPRS_GPRS_XM_H_



#define BUFFER_SIZE	200
#define SHORT_TIME_OUT	1000
#define LONG_TIME_OUT	5000
#define VERY_LONG_TIME_OUT	10000

void GPRS_XM_Send_SMS_OLD(void);
void GPRS_XM_Send_SMS(char * mobile, char * message);
void GPRS_receive(uint8_t * receive_frame);
void GPRS_XM_TEST(void);

#endif /* BSP_GPRS_GPRS_XM_H_ */
