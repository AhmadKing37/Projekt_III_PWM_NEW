#include "header.h"

/*
* main: Initierar mikrodatorn vid start. Om lysdioden är aktiverad styrs denna
*       med PWM-generering. Då läses potentiometern av, där PWM-värden, alltså
*       on- och off-tid för aktuell PWM-period, beräknas. Dessa värden används
*       för att köra PWM-generering en period, alltså en blinkning med on- och
*       off-tiden som blinkhastighet.
*/
int main(void)
{
	setup();

	while (1)
	{
		pwm_run(POT1, 1000);
		
	}

	return 0;
}
