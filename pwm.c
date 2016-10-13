#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#define PWM_FREQUENCY 250
void pwm(void)
{
volatile uint32_t ui32Load;
volatile uint32_t ui32PWMClock;
ui32PWMClock = SysCtlClockGet() / 64;
ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;
PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);
PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui32Load/2); //Before it was /1000 // For duty cycle
PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
PWMGenEnable(PWM1_BASE, PWM_GEN_0);

}
