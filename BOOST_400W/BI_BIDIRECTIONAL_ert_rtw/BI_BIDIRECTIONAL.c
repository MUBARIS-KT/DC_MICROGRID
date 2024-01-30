/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BI_BIDIRECTIONAL.c
 *
 * Code generated for Simulink model 'BI_BIDIRECTIONAL'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jan 10 14:53:07 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BI_BIDIRECTIONAL.h"
#include "rtwtypes.h"
#include "BI_BIDIRECTIONAL_private.h"
#include <string.h>

/* Block signals (default storage) */
B_BI_BIDIRECTIONAL_T BI_BIDIRECTIONAL_B;

/* Block states (default storage) */
DW_BI_BIDIRECTIONAL_T BI_BIDIRECTIONAL_DW;

/* Real-time model */
static RT_MODEL_BI_BIDIRECTIONAL_T BI_BIDIRECTIONAL_M_;
RT_MODEL_BI_BIDIRECTIONAL_T *const BI_BIDIRECTIONAL_M = &BI_BIDIRECTIONAL_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcInitFlag = 0;

#endif

/* Model step function */
void BI_BIDIRECTIONAL_step(void)
{
  real_T rtb_DeadZone;
  real_T rtb_IntegralGain;
  real_T rtb_Saturation;
  int16_T tmp;
  int16_T tmp_0;

  /* S-Function (c2802xadc): '<Root>/OUTPUT VOLTAGE SENSE_CL' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC5 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #22|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    float wait_index;
    for (wait_index= 3; wait_index > 0; wait_index--)
      __mnop();

#endif

    BI_BIDIRECTIONAL_B.OUTPUTVOLTAGESENSE_CL = (AdcResult.ADCRESULT5);
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Voltage Ref'
   *  Gain: '<Root>/Gain2'
   */
  rtb_IntegralGain = BI_BIDIRECTIONAL_P.VoltageRef_Value -
    BI_BIDIRECTIONAL_P.Gain2_Gain * BI_BIDIRECTIONAL_B.OUTPUTVOLTAGESENSE_CL;

  /* Sum: '<S44>/Sum' incorporates:
   *  DiscreteIntegrator: '<S35>/Integrator'
   *  Gain: '<S40>/Proportional Gain'
   */
  rtb_DeadZone = BI_BIDIRECTIONAL_P.PIDController_P * rtb_IntegralGain +
    BI_BIDIRECTIONAL_DW.Integrator_DSTATE;

  /* Saturate: '<S42>/Saturation' */
  if (rtb_DeadZone > BI_BIDIRECTIONAL_P.PIDController_UpperSaturationLi) {
    rtb_Saturation = BI_BIDIRECTIONAL_P.PIDController_UpperSaturationLi;
  } else if (rtb_DeadZone < BI_BIDIRECTIONAL_P.PIDController_LowerSaturationLi)
  {
    rtb_Saturation = BI_BIDIRECTIONAL_P.PIDController_LowerSaturationLi;
  } else {
    rtb_Saturation = rtb_DeadZone;
  }

  /* End of Saturate: '<S42>/Saturation' */

  /* S-Function (c2802xpwm): '<Root>/ePWM1' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)((uint32_T)EPwm1Regs.TBPRD *
      rtb_Saturation * 0.01);
  }

  /* DeadZone: '<S28>/DeadZone' */
  if (rtb_DeadZone > BI_BIDIRECTIONAL_P.PIDController_UpperSaturationLi) {
    rtb_DeadZone -= BI_BIDIRECTIONAL_P.PIDController_UpperSaturationLi;
  } else if (rtb_DeadZone >= BI_BIDIRECTIONAL_P.PIDController_LowerSaturationLi)
  {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= BI_BIDIRECTIONAL_P.PIDController_LowerSaturationLi;
  }

  /* End of DeadZone: '<S28>/DeadZone' */

  /* Gain: '<S32>/Integral Gain' */
  rtb_IntegralGain *= BI_BIDIRECTIONAL_P.PIDController_I;

  /* Switch: '<S26>/Switch1' incorporates:
   *  Constant: '<S26>/Clamping_zero'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant2'
   *  RelationalOperator: '<S26>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > BI_BIDIRECTIONAL_P.Clamping_zero_Value) {
    tmp = BI_BIDIRECTIONAL_P.Constant_Value;
  } else {
    tmp = BI_BIDIRECTIONAL_P.Constant2_Value;
  }

  /* Switch: '<S26>/Switch2' incorporates:
   *  Constant: '<S26>/Clamping_zero'
   *  Constant: '<S26>/Constant3'
   *  Constant: '<S26>/Constant4'
   *  RelationalOperator: '<S26>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain > BI_BIDIRECTIONAL_P.Clamping_zero_Value) {
    tmp_0 = BI_BIDIRECTIONAL_P.Constant3_Value;
  } else {
    tmp_0 = BI_BIDIRECTIONAL_P.Constant4_Value;
  }

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Clamping_zero'
   *  Constant: '<S26>/Constant1'
   *  Logic: '<S26>/AND3'
   *  RelationalOperator: '<S26>/Equal1'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  Switch: '<S26>/Switch1'
   *  Switch: '<S26>/Switch2'
   */
  if ((BI_BIDIRECTIONAL_P.Clamping_zero_Value != rtb_DeadZone) && (tmp == tmp_0))
  {
    rtb_IntegralGain = BI_BIDIRECTIONAL_P.Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S35>/Integrator' incorporates:
   *  Switch: '<S26>/Switch'
   */
  BI_BIDIRECTIONAL_DW.Integrator_DSTATE += BI_BIDIRECTIONAL_P.Integrator_gainval
    * rtb_IntegralGain;
}

/* Model initialize function */
void BI_BIDIRECTIONAL_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BI_BIDIRECTIONAL_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &BI_BIDIRECTIONAL_B), 0,
                sizeof(B_BI_BIDIRECTIONAL_T));

  /* states (dwork) */
  (void) memset((void *)&BI_BIDIRECTIONAL_DW, 0,
                sizeof(DW_BI_BIDIRECTIONAL_T));

  /* Start for S-Function (c2802xadc): '<Root>/OUTPUT VOLTAGE SENSE_CL' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC5 ();

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM1' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x32U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 1500U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm1Regs.CMPA.half.CMPA = 750U;   // Counter Compare A Register
    EPwm1Regs.CMPB = 32000U;           // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 96U;// Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 144U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm1Regs.DBRED = 100U;
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 100U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1U;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x1101U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303U) | 0x1101U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 192U;        // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 1U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 1U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 2U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 2U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xA5FU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 0U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;
    EDIS;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Integrator' */
  BI_BIDIRECTIONAL_DW.Integrator_DSTATE =
    BI_BIDIRECTIONAL_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void BI_BIDIRECTIONAL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
