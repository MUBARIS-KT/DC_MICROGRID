/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BI_MPPT.h
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

#ifndef RTW_HEADER_BI_MPPT_h_
#define RTW_HEADER_BI_MPPT_h_
#ifndef BI_MPPT_COMMON_INCLUDES_
#define BI_MPPT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "IQmathLib.h"
#endif                                 /* BI_MPPT_COMMON_INCLUDES_ */

#include "BI_MPPT_types.h"
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
  real_T INPUTVOLTAGESENSE;            /* '<Root>/INPUT VOLTAGE SENSE' */
  real_T INPUTCURRENTSENSE;            /* '<Root>/INPUT CURRENT SENSE' */
} B_BI_MPPT_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Dprev;                        /* '<S2>/P&O Algorithm ' */
  real_T Pprev;                        /* '<S2>/P&O Algorithm ' */
  real_T Vprev;                        /* '<S2>/P&O Algorithm ' */
} DW_BI_MPPT_T;

/* Parameters (default storage) */
struct P_BI_MPPT_T_ {
  real_T Gain8_Gain;                   /* Expression: 120/4095
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T Gain1_Gain;                   /* Expression: 3.3/4095
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: 2.388
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/66e-3
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 0.9
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0.1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Gain6_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain6'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BI_MPPT_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_BI_MPPT_T BI_MPPT_P;

/* Block signals (default storage) */
extern B_BI_MPPT_T BI_MPPT_B;

/* Block states (default storage) */
extern DW_BI_MPPT_T BI_MPPT_DW;

/* Model entry point functions */
extern void BI_MPPT_initialize(void);
extern void BI_MPPT_step(void);
extern void BI_MPPT_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BI_MPPT_T *const BI_MPPT_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 */

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
 * '<Root>' : 'BI_MPPT'
 * '<S1>'   : 'BI_MPPT/MPPT 1'
 * '<S2>'   : 'BI_MPPT/MPPT 1/Subsystem'
 * '<S3>'   : 'BI_MPPT/MPPT 1/Subsystem/P&O Algorithm '
 */
#endif                                 /* RTW_HEADER_BI_MPPT_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
