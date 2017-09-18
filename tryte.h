#ifndef TRYTE_H
#define TRYTE_H

#include "trit.h"

#define NUM_TRITS_IN_TRYTE 6
typedef trit * tryte;
typedef struct {
    trit value[6];
    trit carry;
} Tryte_op_ret;

Tryte_op_ret tryte_add(tryte, tryte);
tryte tryte_neg(tryte);
int tryte_to_int(tryte);
char* tryte_to_string(tryte);
tryte tryte_from_int(int);
tryte tryte_from_string(const char*);

trit zero_tryte[6];

#endif


// TODO: Replace all data types with structs for easy of copying