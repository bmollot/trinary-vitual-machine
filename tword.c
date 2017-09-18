#include "tword.h"
#include "tryte.h"
#include "trit.h"

trit zero_tword[12] = {0};

/*
Tword_op_ret tword_add(tword t1, tword t2) {
    Tword_op_ret ret;
    Trit_op_ret tor1, tor2;
    tryte tmp = zero_tryte;
    tor1 = tryte_add(t1[1], t2[1]);
    ret.value[1] = tor1.value;
    tmp[5] = tor1.carry;
    tor2 = tryte_add(t1[0], t2[0]);
    tor1.value = tor2.value;
    ret.carry = tor2.carry;
    tor2 = tryte_add(tor1.value, tmp);
    ret.value[0] = tor2.value;
    ret.carry = trit_add(ret.carry, tor2.carry).value;
    return ret;
}
*/

Tword_op_ret tword_add(tword tw1, tword tw2) {
    Trit_op_ret sum1, sum2;
    Tword_op_ret ret;
    trit *val = ret.value, *t1 = tw1, *t2 = tw2;
    int i;

    sum1 = trit_add(t1[11], t2[11]);
    val[11] = sum1.value;
    for (i = 10; i >= 0; i--) {
        sum2 = trit_add(t1[i], t2[i]);
        sum1 = trit_add(sum1.carry, sum2.value);
        val[i] = sum1.value;
        sum1.carry = trit_add(sum2.carry, sum1.carry).value;
    }
    ret.carry = sum1.carry;
    return ret;
}

tword tword_neg(tword t) {
    trit ret[12];
    ret[0] = tryte_neg(t[0]);
    ret[1] = tryte_neg(t[1]);
    return ret;
}

int tword_to_int(tword t) {
    tryte *tr = t;
    int ret = 0, i = 11, m = 1;
    for (; i >= 0; i--, m *= 3) {
        ret += m * trit_to_int(tr[i]);
    }
    return ret;
}

char* tword_to_string(tword tw) {
    int i;
    trit *t = tw;
    char* ret = malloc(sizeof(*ret) * 6 * 2 + 1);
    for (i = 0; i < 12; i++) {
        ret[i] = trit_to_char(t[i]);
    }
    ret[12] = '\0';
    return ret;
}

tword tword_from_int(int x) {
    tword ret;
    int i, m = 177147; /* 3^11 */
    x += 265720; /* Change i to unbalanced ternary equivalent */
    for (i = 0; i < 12; i++, m /= 3) {
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
tword tword_from_string(const char* s) {
    tword ret;
    trit *t = ret;
    int i;
    for (i = 0; i < 12; i++) {
        t[i] = trit_from_char(s[i]);
    }
}
