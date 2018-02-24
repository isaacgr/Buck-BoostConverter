/**
 * File: adc.cpp
 * Author: Isaac Rowell
 * Date:
 */
#include <avr/io.h>
#include "adc.h"

int adc_init(void)
{
  // adc will run in free running single conversion mode
  // a new conversion will have to be started after one finishes

  ADMUX = 0;  // use ADC0
  DIDR0 |= (1<<ADC0D) | (1<<ADC1D); // disable the digial inputs on the adc
  ADMUX |= (1<<REFS0);  // AVcc as the reference
  ADMUX |= (0<<ADLAR);  // left justified, 10bit resolution

  ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // 128 prescaler
  //ADCSRA |= (1<<ADATE); // enable auto trigger

  ADCSRB = 0; // free running mode

  ADCSRA |= (1<<ADIE); // enable interrupts
  ADCSRA |= (1<<ADEN); // enable adc
  ADCSRA |= (1<<ADSC); // start conversion

  return 0;
}
