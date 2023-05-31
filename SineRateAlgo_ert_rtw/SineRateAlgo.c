/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SineRateAlgo.c
 *
 * Code generated for Simulink model 'SineRateAlgo'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 31 02:03:09 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "SineRateAlgo.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void SineRateAlgo_step(void)
{
  real_T lastSin_tmp;

  /* Sin: '<Root>/Sine Wave' */
  if (rtDW.systemEnable != 0) {
    lastSin_tmp = ((rtM->Timing.clockTick0) * 1.0);
    rtDW.lastSin = sin(lastSin_tmp);
    rtDW.lastCos = cos(lastSin_tmp);
    rtDW.systemEnable = 0;
  }

  /* Outport: '<Root>/WaitTime' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sin: '<Root>/Sine Wave'
   */
  rtY.WaitTime = (((rtDW.lastSin * 0.54030230586813977 + rtDW.lastCos *
                    -0.8414709848078965) * 0.54030230586813977 + (rtDW.lastCos *
    0.54030230586813977 - rtDW.lastSin * -0.8414709848078965) *
                   0.8414709848078965) * 0.2 + 0.25) * 1000.0;

  /* Update for Sin: '<Root>/Sine Wave' */
  lastSin_tmp = rtDW.lastSin;
  rtDW.lastSin = rtDW.lastSin * 0.54030230586813977 + rtDW.lastCos *
    0.8414709848078965;
  rtDW.lastCos = rtDW.lastCos * 0.54030230586813977 - lastSin_tmp *
    0.8414709848078965;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
}

/* Model initialize function */
void SineRateAlgo_initialize(void)
{
  /* Enable for Sin: '<Root>/Sine Wave' */
  rtDW.systemEnable = 1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
