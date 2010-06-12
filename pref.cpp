#include "pref.h"
#include "functions.h"
#include <stdio.h>
#include <math.h>

Pref::Pref(int ccand) {
  offset = bitsCand(ccand);
  cand_por_int = 32/offset;
  float temp = (float)ccand/(float)cand_por_int;
  printf("Se necesitan %i bits para guardarlos\n",(int)ceil(temp));
  int prefs[int(temp)];
}

