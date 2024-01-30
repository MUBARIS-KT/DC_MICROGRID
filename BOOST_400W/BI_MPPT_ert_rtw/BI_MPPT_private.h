/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BI_MPPT_private.h
 *
 * Code generated for Simulink model 'BI_MPPT'.
 *
 * Model version                  : 3.1
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jan 10 14:55:15 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BI_MPPT_private_h_
#define RTW_HEADER_BI_MPPT_private_h_
#include "rtwtypes.h"
#include "BI_MPPT_types.h"

void InitAdc (void);
void config_ADC_SOC1 (void);
void config_ADC_SOC2 (void);
extern uint16_T MW_adcInitFlag;

#endif                                 /* RTW_HEADER_BI_MPPT_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */