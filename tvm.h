#ifndef TVM_H
#define TVM_H

#include <stddef.h>
#include "tword.h"

#define NUM_GEN_REG 12
#define NUM_ARG_REG 12

typedef struct {
    tryte *mem;
    tword mem_max;
    tryte gen_reg[NUM_GEN_REG];
    tryte ino_reg[NUM_ARG_REG];
    tryte arg_reg[NUM_ARG_REG];
    tword pc_reg;
    tword sp_reg;
    tryte fl_reg;
} Tvm;

int init_tvm(Tvm *tvm, unsigned int size);
int start_tvm(Tvm *tvm);
int step_tvm(Tvm *tvm);
int reset_tvm(Tvm *tvm);
int destroy_tvm(Tvm *tvm);
int load_tvm(Tvm *tvm, tryte *blob, size_t size);

#endif