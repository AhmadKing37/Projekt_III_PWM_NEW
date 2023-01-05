#include "header.h"

uint16_t adc_read(const uint8_t pin)
{
	ADMUX = (1 << REFS0) | pin;
	ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	while ((ADCSRA & (1 << ADIF)) == 0);
	ADCSRA = (1 << ADIF);
	return ADC;
}



void adc_get_pwm_values(const uint8_t pin,
const uint16_t pwm_period_us,
uint16_t* pwm_on_us,
uint16_t* pwm_off_us)
{
	const double duty_cycle = adc_read(pin) / 1023.0;
	*pwm_on_us = (uint16_t)(pwm_period_us * duty_cycle + 0.5);
	*pwm_off_us = pwm_period_us - *pwm_on_us;
	return;
}




void pwm_run(const uint8_t pot_pin, const uint16_t period_us)
{
	uint16_t on_time_us;
	uint16_t off_time_us;

	adc_get_pwm_values(pot_pin, period_us, &on_time_us, &off_time_us);

	if (led1_enabled) set(PORTD, LED1);
	if (led2_enabled) set(PORTD, LED2);
	if (led3_enabled) set(PORTB, LED3);
	if (led4_enabled) set(PORTB, LED4);
	if (led5_enabled) set(PORTB, LED5);
	delay_us(&on_time_us);
	
	clr(PORTD, LED1);
	clr(PORTD, LED2);
	clr(PORTB, LED3);
	clr(PORTB, LED4);
	clr(PORTB, LED5);
	delay_us(&off_time_us);
	
	return;
}

/*
* delay_us: Genererar fördröjning mätt i mikrosekunder. Detta sker genom
*           uppräkning till angiven fördröjningstid, där 1 us fördröjning
*           genereras varje varv via anrop av funktionen _delay_us från
*           biblioteket util/delay.h
*
*           - delay_time_us: Pekare till fördröjningstiden i mikrosekunder.
*/
void delay_us(const volatile uint16_t* delay_time_us)
{
	for (uint16_t i = 0; i < *delay_time_us; ++i)
	{
		_delay_us(1);
	}

	return;
}