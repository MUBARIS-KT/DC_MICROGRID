#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "f2802x_globalprototypes.h"
#include "rtwtypes.h"
#include "BI_BIDIRECTIONAL.h"
#include "BI_BIDIRECTIONAL_private.h"

void config_ADC_SOC5(void)
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 0U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0U;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN4 = 0U;/* Single sample mode set for SOC5.*/
  AdcRegs.ADCSOC5CTL.bit.CHSEL = 2U;   /* Set SOC5 channel select to ADCINA2*/
  AdcRegs.ADCSOC5CTL.bit.TRIGSEL = 0U;
  AdcRegs.ADCSOC5CTL.bit.ACQPS = (uint16_T)6.0;
                                /* Set SOC5 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC5 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0U ; /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}
