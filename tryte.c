#include <stdlib.h>
#include "tryte.h"
#include "trit.h"

trit zero_tryte[6] = {0};

Tryte_op_ret tryte_add(tryte t1, tryte t2) {
    Trit_op_ret sum1, sum2;
    Tryte_op_ret ret;
    int i;

    sum1 = trit_add(t1[5], t2[5]);
    ret.value[5] = sum1.value;
    for (i = 4; i >= 0; i--) {
        sum2 = trit_add(t1[i], t2[i]);
        sum1 = trit_add(sum1.carry, sum2.value);
        ret.value[i] = sum1.value;
        sum1.carry = trit_add(sum2.carry, sum1.carry).value;
    }
    ret.carry = sum1.carry;
    return ret;
}

tryte tryte_neg(tryte t) {
    trit ret[6];
    int i;
    for (i = 0; i < 6; i++) {
        ret[i] = TRIT_NEG(t[i]);
    }
    return ret;
}

int tryte_to_int(tryte t) {
    int ret = 0, i = 5, m = 1;
    for (; i >= 0; i--, m *= 3) {
        ret += m * trit_to_int(t[i]);
    }
    return ret;
}

char* tryte_to_string(tryte t) {
    int i;
    char* ret = malloc(sizeof(*ret) * 6 + 1);
    for (i = 0; i < 6; i++) {
        ret[i] = trit_to_char(t[i]);
    }
    ret[6] = '\0';
    return ret;
}

tryte tryte_from_int(int x) {
    tryte ret;
    int i, m = 243; /* 3^5 */
    x += 364; /* Change i to unbalanced ternary equivalent */
    for (i = 0; i < 6; i++, m /= 3) {
        if (x >= m*2) {
            ret[i] = TRIT_P;
            x -= m*2;
        }
        else if (x >= m) {
            ret[i] = TRIT_Z;
            x -= m;
        }
        else {
            ret[i] = TRIT_M;
        }
    }
    return ret;
}

/* s must be 0 padded */
tryte tryte_from_string(const char* s) {
    tryte ret;
    int i;
    for (i = 0; i < 6; i++) {
        ret[i] = trit_from_char(s[i]);
    }
}
