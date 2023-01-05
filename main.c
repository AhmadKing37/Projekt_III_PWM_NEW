#include "header.h"

/*
* main: Initierar mikrodatorn vid start. Om lysdioden �r aktiverad styrs denna
*       med PWM-generering. D� l�ses potentiometern av, d�r PWM-v�rden, allts�
*       on- och off-tid f�r aktuell PWM-period, ber�knas. Dessa v�rden anv�nds
*       f�r att k�ra PWM-generering en period, allts� en blinkning med on- och
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
