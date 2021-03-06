/* { dg-do run } */
/* { dg-require-effective-target cilkplus_runtime } */
/* { dg-options "-fcilkplus" } */

#if HAVE_IO
#include <stdio.h>
#endif

int fib        (int);
int fib_serial (int);

#define FIB_ITERATION  30

int main(void)
{
  int ii = 0;
  int fib_result[FIB_ITERATION+1], fib_serial_result[FIB_ITERATION+1];
#if HAVE_IO

  for (ii = 0; ii <= FIB_ITERATION; ii++)
    printf("fib (%2d) = %10d\n", ii, fib (ii));
#else
  for (ii = 0; ii <= FIB_ITERATION; ii++)
    {
      fib_result[ii]        = fib (ii);
    }

  fib_serial_result[0] = 0;
  fib_serial_result[1] = 1;
  for (ii = 2; ii <= FIB_ITERATION; ii++)
    fib_serial_result[ii] = fib_serial_result[ii-1] + fib_serial_result[ii-2];
  
  for (ii = 0; ii <= FIB_ITERATION; ii++)
    {
      if (fib_result[ii] != fib_serial_result[ii])
	__builtin_abort ();
    }
#endif
  return 0;
}

int fib(int n)
{
  int x = 0, y = 0;
  if (n < 2) 
    return n;
  else
  {
    x = _Cilk_spawn fib(n-1);
    y = fib(n-2);
    _Cilk_sync;
    return (x+y);
  }
}
