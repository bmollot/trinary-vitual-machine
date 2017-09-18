#ifndef TWORD_H
#define TWORD_H

#include "tryte.h"

#define NUM_TRYTES_IN_TWORD 2
typedef tryte tword;
typedef struct {
    trit value[12];
    trit carry;
} Tword_op_ret;

Tword_op_ret tword_add(tword, tword);
tword tword_neg(tword);
int tword_to_int(tword);
char* tword_to_string(tword);
tword tword_from_int(int);
tword tword_from_string(const char*);

trit zero_tword[12];

#endif