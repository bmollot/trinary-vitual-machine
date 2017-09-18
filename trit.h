#ifndef TRIT_H
#define TRIT_H

#include <stdint.h>

typedef uint8_t trit;
typedef struct {
    trit value;
    trit carry;
} Trit_op_ret;
/* 
Trits are stored as bytes, or chars in C terminology. They have been given the
following representations, 8 bit two's complement representations, so that two's
complement transforms TRIT_P to TRIT_M and vice versa, while TRIT_Z is
transformed to TRIT_Z.
*/
#define TRIT_P 0x01 /* 00000001 */
#define TRIT_Z 0x00 /* 00000000 */
#define TRIT_M 0xFF /* 11111111 */

#define TRIT_NEG(trit) ((char) (~(trit) + 1))

Trit_op_ret trit_add(trit, trit);
int trit_to_int(trit);
char trit_to_char(trit);
trit trit_from_int(int);
trit trit_from_char(char);

#endif