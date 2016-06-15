/* Test the `vreinterpretQs16_p16' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

void test_vreinterpretQs16_p16 (void)
{
  int16x8_t out_int16x8_t;
  poly16x8_t arg0_poly16x8_t;

  out_int16x8_t = vreinterpretq_s16_p16 (arg0_poly16x8_t);
}

