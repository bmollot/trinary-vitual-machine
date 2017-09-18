#include "trit.h"

Trit_op_ret trit_add(trit t1, trit t2) {
    Trit_op_ret ret;
    switch (t1 + t2) {
        case TRIT_P + TRIT_P:
            ret.value = TRIT_M;
            ret.carry = TRIT_P;
            break;
        case TRIT_M + TRIT_M:
            ret.value = TRIT_P;
            ret.carry = TRIT_M;
            break;
        default:
            ret.value = t1 + t2;
            ret.carry = TRIT_Z;
    }
    return ret;
}

/*
int trit_to_int(trit t) {
    switch (t) {
        case TRIT_P: return 1;
        case TRIT_Z: return 0;
        case TRIT_M: return -1;
    }
}
*/
int trit_to_int(trit t) {
    return ((int8_t) (t));
}

char trit_to_char(trit t) {
    switch (t) {
        case TRIT_P: return '+';
        case TRIT_Z: return '0';
        case TRIT_M: return '-';
    }
}

trit trit_from_int(int i) {
    trit ret = TRIT_M;
    if (!i) ret = TRIT_Z;
    else if (i > 0) ret = TRIT_P;
    return ret;
}

trit trit_from_char(char c) {
    trit ret = TRIT_Z;
    if (c == '+') ret = TRIT_P;
    else if (c == '-') ret = TRIT_M;
    return ret;
}