#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"
#include "driverlib/uart.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "utils/uartstdio.h"
void adc(void)
{
uint32_t ui32ADC0Value[1];

volatile uint32_t ui32TempValueC;
volatile uint32_t ui32TempValueF;

	ADCIntClear(ADC0_BASE, 3);
	ADCProcessorTrigger(ADC0_BASE, 3);

	while(!ADCIntStatus(ADC0_BASE, 3, false))
	{
	}

	ADCSequenceDataGet(ADC0_BASE, 3, ui32ADC0Value);

	ui32TempValueC = (1475 - ((2475 * ui32ADC0Value[0])) / 4096)/10;

	ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;

	UARTprintf("\nTemperature in Celsius %d\r", ui32TempValueC);
	SysCtlDelay(2000000);
	/*SysCtlDelay(2000000);
    SysCtlDelay(2000000);
	SysCtlDelay(200000);
	SysCtlDelay(200000);*/
	UARTprintf("\nTemperature in Fahrenheit %d\r", ui32TempValueF);
	/*SysCtlDelay(2000000);
    SysCtlDelay(2000000);
    SysCtlDelay(2000000);
    SysCtlDelay(2000000);*/


	}


