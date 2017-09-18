#include <stdlib.h>
#include <string.h>
#include "tvm.h"
#include "tword.h"
#include "tryte.h"

int init_tvm(Tvm *tvm, unsigned int size) {
    tvm->mem = malloc(sizeof(trit) * NUM_TRITS_IN_TRYTE * size);
    tvm->mem_max = tword_from_int(size - 1);
    reset_tvm(tvm);
    return 1;
}

int start_tvm(Tvm *tvm) {
    while (step_tvm(tvm));
    return 1;
}

int step_tvm(Tvm *tvm) {
    if (tvm->pc_reg == tvm->mem_max);
    tvm->pc_reg = tword_add(tvm->pc_reg, tword_from_int(1)).value;
    return 1;
}

int reset_tvm(Tvm *tvm) {
    int i;
    for (i = 0; i < NUM_GEN_REG; i++) {
        memcpy(tvm->gen_reg[i], zero_tryte, NUM_TRITS_IN_TRYTE);
    }
    for (i = 0; i < NUM_ARG_REG; i++) {
        memcpy(tvm->ino_reg[i], zero_tryte, NUM_TRITS_IN_TRYTE);
    }
    for (i = 0; i < NUM_ARG_REG; i++) {
        memcpy(tvm->arg_reg[i], zero_tryte, NUM_TRITS_IN_TRYTE);
    }
    memcpy(tvm->pc_reg, zero_tword, NUM_TRITS_IN_TRYTE * NUM_TRYTES_IN_TWORD);
    memcpy(tvm->sp_reg, tvm->mem_max, NUM_TRITS_IN_TRYTE * NUM_TRYTES_IN_TWORD);
    memcpy(tvm->fl_reg, zero_tryte, NUM_TRITS_IN_TRYTE);
    return 1;
}

int destroy_tvm(Tvm *tvm) {
    free(tvm->mem);
    return 1;
}

int load_tvm(Tvm *tvm, tryte *blob, size_t size) {
    memcpy(tvm->mem, blob, size);
    return 1;
}