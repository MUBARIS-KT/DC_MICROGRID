/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BI_BIDIRECTIONAL_data.c
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

/* Block parameters (default storage) */
P_BI_BIDIRECTIONAL_T BI_BIDIRECTIONAL_P = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S32>/Integral Gain'
   */
  5.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S35>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by:
   *   '<S42>/Saturation'
   *   '<S28>/DeadZone'
   */
  0.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S40>/Proportional Gain'
   */
  0.05,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by:
   *   '<S42>/Saturation'
   *   '<S28>/DeadZone'
   */
  85.0,

  /* Expression: 0
   * Referenced by: '<S26>/Constant1'
   */
  0.0,

  /* Expression: 120/4095
   * Referenced by: '<Root>/Gain2'
   */
  0.029304029304029304,

  /* Expression: 24
   * Referenced by: '<Root>/Voltage Ref'
   */
  24.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S35>/Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S26>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S26>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S26>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S26>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S26>/Constant4'
   */
  -1
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
