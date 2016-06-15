/* { dg-require-effective-target vect_int } */

#include <stdarg.h>
#include "tree-vect.h"

#define N 8 

unsigned short out[N*8];
unsigned short in[N*8] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63};
unsigned short in2[N*8] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63};
unsigned short out2[N*8];

int
main1 ()
{
  int i;

  for (i = 0; i < N*2; i++)
    {
      out[i*2] = in[i*2] + 5;
      out[i*2 + 1] = in[i*2 + 1] + 6;

      out2[i*4] = in2[i*4] + 2;
      out2[i*4 + 1] = in2[i*4 + 1] + 2;
      out2[i*4 + 2] = in2[i*4 + 2] + 1;
      out2[i*4 + 3] = in2[i*4 + 3] + 3;
    }

  /* check results:  */
  for (i = 0; i < N*2; i++)
    {
      if (out[i*2] != in[i*2] + 5
         || out[i*2 + 1] != in[i*2 + 1] + 6
         || out2[i*4] !=  in2[i*4] + 2
         || out2[i*4 + 1] != in2[i*4 + 1] + 2
         || out2[i*4 + 2] != in2[i*4 + 2] + 1
         || out2[i*4 + 3] != in2[i*4 + 3] + 3)
        abort ();
    }

  return 0;
}

int main (void)
{
  check_vect ();

  main1 ();

  return 0;
}

/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 1 "vect" } } */
/* { dg-final { scan-tree-dump-times "vectorizing stmts using SLP" 2 "vect"  } } */
  
