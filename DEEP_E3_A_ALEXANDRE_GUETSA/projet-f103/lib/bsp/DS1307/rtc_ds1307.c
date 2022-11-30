/**
 * @filename rtc_ds1307.c
 * @description DS1307 I2C Real Time Clock Driver for stm32f4 boards
 * @author Nicholas Shrake, <shraken@gmail.com>
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include "stm32f1_i2c.h"
#include "rtc_ds1307.h"

uint8_t g_return_value;

uint8_t ds1307_bcd2bin (uint8_t bcd_value)
{
	uint8_t bin_value = (bcd_value&0x0F) + (bcd_value>>4)*10;
	//printf("bcd_value = 0x%2x\t bin_value = %d\n", bcd_value, bin_value);
	return bin_value;
}

uint8_t ds1307_bin2bcd (uint8_t binary_value)
{
	uint8_t diz = (binary_value/10);
	uint8_t unit = binary_value%10;
	uint8_t bcd_value = (diz<<4) + unit;
	//printf("binary_value = %d\t bcd_value = 0x%2x\n", binary_value, bcd_value);
	return bcd_value;
}

rtc_ds1307_state_e ds1307_set_rtc_data (uint8_t register_value, uint8_t data)
{
	HAL_StatusTypeDef status;

    I2C_Init(I2C1, 100000);

	//printf("ds1307_set_rtc_data entered\r\n");
	status = I2C_Write(I2C1,(DS1307_ADDRESS << 1), register_value, data);

    if(status == HAL_OK)
        return RTC_DS1307_OK;
    else
    	return RTC_DS1307_BAD;
}

rtc_ds1307_state_e ds1307_get_rtc_data (uint8_t register_value, uint8_t register_mask, uint8_t *return_value)
{
    uint8_t in_buff;
    HAL_StatusTypeDef status;

    I2C_Init(I2C1, 100000);

    //printf("ds1307_get_rtc_data entered\r\n");
    status = I2C_Read(I2C1, (DS1307_ADDRESS << 1), register_value, &in_buff);
    
    if(status == HAL_OK)
    {
    	*return_value = ds1307_bcd2bin(in_buff & register_mask);
    	return RTC_DS1307_OK;
    }
    else
    	return RTC_DS1307_BAD;
}

void ds1307_set_rtc_second (uint8_t value) {
    ds1307_set_rtc_data(SECOND_REGISTER, (ds1307_bin2bcd(value) & SECOND_MASK));
}

void ds1307_set_rtc_minute (uint8_t value) {
    ds1307_set_rtc_data(MINUTE_REGISTER, (ds1307_bin2bcd(value) & MINUTE_MASK));
}

void ds1307_set_rtc_hour (uint8_t value) {
    ds1307_set_rtc_data(HOUR_REGISTER, (ds1307_bin2bcd(value) & HOUR_MASK));
}

void ds1307_set_rtc_day (uint8_t value) {
    ds1307_set_rtc_data(DAY_REGISTER, (ds1307_bin2bcd(value) & DAY_MASK));
}

void ds1307_set_rtc_date (uint8_t value) {
    ds1307_set_rtc_data(DATE_REGISTER, (ds1307_bin2bcd(value) & DATE_MASK));
}
void ds1307_set_rtc_month (uint8_t value) {
    ds1307_set_rtc_data(MONTH_REGISTER, (ds1307_bin2bcd(value) & MONTH_MASK));
}

void ds1307_set_rtc_year (uint8_t value) {
    ds1307_set_rtc_data(YEAR_REGISTER, (ds1307_bin2bcd(value) & YEAR_MASK));
}

rtc_ds1307_state_e ds1307_set_rtc_datetime (rtc_ds1307_datetime_t* datetime)
{
	HAL_StatusTypeDef status;

	status = I2C_WriteMulti(I2C1, (DS1307_ADDRESS << 1), SECOND_REGISTER, (uint8_t*)datetime, 7);

	if(status == HAL_OK)
	{
		//printf("ds1307_set_rtc_datetime passed\r\n");
		return RTC_DS1307_OK;
	}
	else
	{
		//printf("ds1307_set_rtc_datetime NOT passed\r\n");
		return RTC_DS1307_BAD;
	}
}


rtc_ds1307_state_e ds1307_get_rtc_second (void) {
    return ds1307_get_rtc_data(SECOND_REGISTER, SECOND_MASK, &g_return_value);
}

rtc_ds1307_state_e ds1307_get_rtc_minute (void) {
    return ds1307_get_rtc_data(MINUTE_REGISTER, MINUTE_MASK, &g_return_value);
}

rtc_ds1307_state_e ds1307_get_rtc_hour (void) {
    return ds1307_get_rtc_data(HOUR_REGISTER, HOUR_MASK, &g_return_value);
}

rtc_ds1307_state_e ds1307_get_rtc_day (void) {
    return ds1307_get_rtc_data(DAY_REGISTER, DAY_MASK, &g_return_value);
}

rtc_ds1307_state_e ds1307_get_rtc_date (void) {
    return ds1307_get_rtc_data(DATE_REGISTER, DATE_MASK, &g_return_value);
}

rtc_ds1307_state_e ds1307_get_rtc_month (void) {
    return ds1307_get_rtc_data(MONTH_REGISTER, MONTH_MASK, &g_return_value);
}

rtc_ds1307_state_e ds1307_get_rtc_year (void) {
    return ds1307_get_rtc_data(YEAR_REGISTER, YEAR_MASK, &g_return_value);
}

rtc_ds1307_state_e ds1307_get_rtc_datetime (rtc_ds1307_datetime_t *datetime)
{
    // seconds
    if (ds1307_get_rtc_second() != RTC_DS1307_OK)
        return RTC_DS1307_BAD;
    else
        datetime->seconds = g_return_value;

    // minutes
    if (ds1307_get_rtc_minute() != RTC_DS1307_OK)
        return RTC_DS1307_BAD;
    else
        datetime->minutes = g_return_value;

    // hours
    if (ds1307_get_rtc_hour() != RTC_DS1307_OK)
        return RTC_DS1307_BAD;
    else
        datetime->hour = g_return_value;

    // day
    if (ds1307_get_rtc_day() != RTC_DS1307_OK)
        return RTC_DS1307_BAD;
    else
        datetime->day = g_return_value;

    // date
    if (ds1307_get_rtc_date() != RTC_DS1307_OK)
        return RTC_DS1307_BAD;
    else
        datetime->date = g_return_value;

    // month
    if (ds1307_get_rtc_month() != RTC_DS1307_OK)
        return RTC_DS1307_BAD;
    else
        datetime->month = g_return_value;

    // year
    if (ds1307_get_rtc_year() != RTC_DS1307_OK)
        return RTC_DS1307_BAD;
    else
        datetime->year = g_return_value;

    // otherwise, success
    return RTC_DS1307_OK;
}

rtc_ds1307_state_e ds1307_init_rtc (bool_e first_run_flag)
{
    // build the default (zero) starting state for the RTC
    // datetime structure.
    rtc_ds1307_datetime_t init_datetime =
    {
        .seconds = ds1307_bin2bcd(46),
		.minutes = ds1307_bin2bcd(03),
		.hour = ds1307_bin2bcd(15),
		.day = ds1307_bin2bcd(5),
		.date = ds1307_bin2bcd(26),
		.month = ds1307_bin2bcd(02),
		.year = ds1307_bin2bcd(21)
    };

    //printf("ds1307_init_rtc entered\r\n");
    if (ds1307_set_rtc_data(CONTROL_REGISTER, 0) == RTC_DS1307_BAD)
    	return RTC_DS1307_BAD;

    //printf("ds1307_set_rtc_data passed\r\n");
    if (first_run_flag)
    {
        return ds1307_set_rtc_datetime(&init_datetime);
    }

    // otherwise return 0 to indicate success
    return RTC_DS1307_OK;
}
