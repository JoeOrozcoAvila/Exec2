/*Excercise 2: using 2 Raspberry´s gpio as inputs (gpio14 and gpio15)
turn on a led connected on gpio05 only if gpio14=on and gpio15=off*/

#include<stdio.h>
#include<pigpio.h>

int main()
{
	if(gpioInitialise()<0) return -1;
	
	gpioSetMode(14, PI_INPUT);
	gpioSetMode(15, PI_INPUT);
	gpioSetMode(05, PI_OUTPUT);
	
	for(;;)
	{ if((gpioRead(14))&&(!gpioRead(15)))
		gpioWrite(05, 1);
	else
		gpioWrite(05, 0);
	}
	
	gpioTerminate();
	return 0;
}
