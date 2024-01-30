/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BI_BIDIRECTIONAL.h
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

#ifndef RTW_HEADER_BI_BIDIRECTIONAL_h_
#define RTW_HEADER_BI_BIDIRECTIONAL_h_
#ifndef BI_BIDIRECTIONAL_COMMON_INCLUDES_
#define BI_BIDIRECTIONAL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "IQmathLib.h"
#endif                                 /* BI_BIDIRECTIONAL_COMMON_INCLUDES_ */

#include "BI_BIDIRECTIONAL_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  real_T OUTPUTVOLTAGESENSE_CL;        /* '<Root>/OUTPUT VOLTAGE SENSE_CL' */
} B_BI_BIDIRECTIONAL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S35>/Integrator' */
} DW_BI_BIDIRECTIONAL_T;

/* Parameters (default storage) */
struct P_BI_BIDIRECTIONAL_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S32>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S35>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by:
                               *   '<S42>/Saturation'
                               *   '<S28>/DeadZone'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S40>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by:
                               *   '<S42>/Saturation'
                               *   '<S28>/DeadZone'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 120/4095
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T VoltageRef_Value;             /* Expression: 24
                                        * Referenced by: '<Root>/Voltage Ref'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S35>/Integrator'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S26>/Clamping_zero'
                                        */
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S26>/Constant'
                                        */
  int16_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S26>/Constant2'
                                        */
  int16_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S26>/Constant3'
                                        */
  int16_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S26>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BI_BIDIRECTIONAL_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_BI_BIDIRECTIONAL_T BI_BIDIRECTIONAL_P;

/* Block signals (default storage) */
extern B_BI_BIDIRECTIONAL_T BI_BIDIRECTIONAL_B;

/* Block states (default storage) */
extern DW_BI_BIDIRECTIONAL_T BI_BIDIRECTIONAL_DW;

/* Model entry point functions */
extern void BI_BIDIRECTIONAL_initialize(void);
extern void BI_BIDIRECTIONAL_step(void);
extern void BI_BIDIRECTIONAL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BI_BIDIRECTIONAL_T *const BI_BIDIRECTIONAL_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BI_BIDIRECTIONAL'
 * '<S1>'   : 'BI_BIDIRECTIONAL/PID Controller'
 * '<S2>'   : 'BI_BIDIRECTIONAL/PID Controller/Anti-windup'
 * '<S3>'   : 'BI_BIDIRECTIONAL/PID Controller/D Gain'
 * '<S4>'   : 'BI_BIDIRECTIONAL/PID Controller/Filter'
 * '<S5>'   : 'BI_BIDIRECTIONAL/PID Controller/Filter ICs'
 * '<S6>'   : 'BI_BIDIRECTIONAL/PID Controller/I Gain'
 * '<S7>'   : 'BI_BIDIRECTIONAL/PID Controller/Ideal P Gain'
 * '<S8>'   : 'BI_BIDIRECTIONAL/PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'BI_BIDIRECTIONAL/PID Controller/Integrator'
 * '<S10>'  : 'BI_BIDIRECTIONAL/PID Controller/Integrator ICs'
 * '<S11>'  : 'BI_BIDIRECTIONAL/PID Controller/N Copy'
 * '<S12>'  : 'BI_BIDIRECTIONAL/PID Controller/N Gain'
 * '<S13>'  : 'BI_BIDIRECTIONAL/PID Controller/P Copy'
 * '<S14>'  : 'BI_BIDIRECTIONAL/PID Controller/Parallel P Gain'
 * '<S15>'  : 'BI_BIDIRECTIONAL/PID Controller/Reset Signal'
 * '<S16>'  : 'BI_BIDIRECTIONAL/PID Controller/Saturation'
 * '<S17>'  : 'BI_BIDIRECTIONAL/PID Controller/Saturation Fdbk'
 * '<S18>'  : 'BI_BIDIRECTIONAL/PID Controller/Sum'
 * '<S19>'  : 'BI_BIDIRECTIONAL/PID Controller/Sum Fdbk'
 * '<S20>'  : 'BI_BIDIRECTIONAL/PID Controller/Tracking Mode'
 * '<S21>'  : 'BI_BIDIRECTIONAL/PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'BI_BIDIRECTIONAL/PID Controller/Tsamp - Integral'
 * '<S23>'  : 'BI_BIDIRECTIONAL/PID Controller/Tsamp - Ngain'
 * '<S24>'  : 'BI_BIDIRECTIONAL/PID Controller/postSat Signal'
 * '<S25>'  : 'BI_BIDIRECTIONAL/PID Controller/preSat Signal'
 * '<S26>'  : 'BI_BIDIRECTIONAL/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S27>'  : 'BI_BIDIRECTIONAL/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S28>'  : 'BI_BIDIRECTIONAL/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S29>'  : 'BI_BIDIRECTIONAL/PID Controller/D Gain/Disabled'
 * '<S30>'  : 'BI_BIDIRECTIONAL/PID Controller/Filter/Disabled'
 * '<S31>'  : 'BI_BIDIRECTIONAL/PID Controller/Filter ICs/Disabled'
 * '<S32>'  : 'BI_BIDIRECTIONAL/PID Controller/I Gain/Internal Parameters'
 * '<S33>'  : 'BI_BIDIRECTIONAL/PID Controller/Ideal P Gain/Passthrough'
 * '<S34>'  : 'BI_BIDIRECTIONAL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S35>'  : 'BI_BIDIRECTIONAL/PID Controller/Integrator/Discrete'
 * '<S36>'  : 'BI_BIDIRECTIONAL/PID Controller/Integrator ICs/Internal IC'
 * '<S37>'  : 'BI_BIDIRECTIONAL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S38>'  : 'BI_BIDIRECTIONAL/PID Controller/N Gain/Disabled'
 * '<S39>'  : 'BI_BIDIRECTIONAL/PID Controller/P Copy/Disabled'
 * '<S40>'  : 'BI_BIDIRECTIONAL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S41>'  : 'BI_BIDIRECTIONAL/PID Controller/Reset Signal/Disabled'
 * '<S42>'  : 'BI_BIDIRECTIONAL/PID Controller/Saturation/Enabled'
 * '<S43>'  : 'BI_BIDIRECTIONAL/PID Controller/Saturation Fdbk/Disabled'
 * '<S44>'  : 'BI_BIDIRECTIONAL/PID Controller/Sum/Sum_PI'
 * '<S45>'  : 'BI_BIDIRECTIONAL/PID Controller/Sum Fdbk/Disabled'
 * '<S46>'  : 'BI_BIDIRECTIONAL/PID Controller/Tracking Mode/Disabled'
 * '<S47>'  : 'BI_BIDIRECTIONAL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S48>'  : 'BI_BIDIRECTIONAL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S49>'  : 'BI_BIDIRECTIONAL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S50>'  : 'BI_BIDIRECTIONAL/PID Controller/postSat Signal/Forward_Path'
 * '<S51>'  : 'BI_BIDIRECTIONAL/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_BI_BIDIRECTIONAL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
