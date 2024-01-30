#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "f2802x_globalprototypes.h"
#include "rtwtypes.h"
#include "BI_BIDIRECTIONAL.h"
#include "BI_BIDIRECTIONAL_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;

  /*-- Configure pin assignments for ePWM1 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1U; /* Configure GPIOGPIO0 as EPWM1A*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1U; /* Configure GPIOGPIO1 as EPWM1B*/
  EDIS;
}

void config_ePWM_TBSync (void)
{
  /* Enable TBCLK within the EPWM*/
  /* Enable TBCLK after the ePWM configurations */
  EALLOW;
  SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1U;
  EDIS;
}

void config_ePWMSyncSource (void)
{
}
