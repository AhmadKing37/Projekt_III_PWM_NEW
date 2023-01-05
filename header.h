#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL // 16 MHz

#include <avr/io.h>        
#include <avr/interrupt.h> 
#include <util/delay.h>    

#define LED1 PORTD6  // Lysdiod 1 ansluten till pin 6 
#define LED2 PORTD7  // Lysdiod 2 ansluten till pin 7
#define LED3 PORTB0  // Lysdiod 3 ansluten till pin 8 
#define LED4 PORTB1  // Lysdiod 4 ansluten till pin 9 
#define LED5 PORTB2  // Lysdiod 5 ansluten till pin 10

#define BUTTON1 PORTD2 // Tryckknapp ansluten till pin 2 
#define BUTTON2 PORTD3 // Tryckknapp ansluten till pin 3 
#define BUTTON3 PORTB3 // Tryckknapp ansluten till pin 13 
#define BUTTON4 PORTB4 // Tryckknapp ansluten till pin 13 
#define BUTTON5 PORTB5 // Tryckknapp ansluten till pin 13  

#define POT1 PORTC0    // Potentiometer ansluten till analog pin A0




/* clr: Nollställer bit i angivet register. */
#define clr(reg, bit) reg &= ~(1 << bit)


/* set: Ettställer bit i angivet register. */
#define set(reg, bit) reg |= (1 << bit)

/* read: Läser av angiven pin och returnerar ifall denna är hög eller låg. */
#define read(reg, bit) (reg & (1 << bit))

typedef enum { false, true } bool; // Realiserar datatypen bool, false = 0, true = 1.


/* setup: Initierar mikrodatorns I/O-portar, PCI-avbrott samt AD-omvandlare. */
void setup(void);


/* adc_read: Läser av insignalen på angiven analog pin och returnerar motsvarande  
            digitala värde mellan 0 - 1023.  */

uint16_t adc_read(const uint8_t pin);



void adc_get_pwm_values(const uint8_t pin,
const uint16_t pwm_period_us,
uint16_t* pwm_on_us,
uint16_t* pwm_off_us);


/* pwm_run: Kontrollerar ljusstyrkan på en lysdiod med PWM-generering under en
*          period via avläsning av angiven potentiometer. */
void pwm_run(const uint8_t pot_pin, const uint16_t period_us);


/* delay_us: Genererar fördröjning mätt i mikrosekunder. */
void delay_us(const volatile uint16_t* delay_time_us);


extern volatile bool led1_enabled; // Anger om lysdioden är aktiverad eller inte. 
extern volatile bool led2_enabled; // Anger om lysdioden är aktiverad eller inte. 
extern volatile bool led3_enabled; // Anger om lysdioden är aktiverad eller inte. 
extern volatile bool led4_enabled; // Anger om lysdioden är aktiverad eller inte. 
extern volatile bool led5_enabled; // Anger om lysdioden är aktiverad eller inte.

#endif /* HEADER_H_ */