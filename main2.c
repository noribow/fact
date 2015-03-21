#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <gmp.h>

#include "number.h"

int prime_test_trial_div(mpz_t n)
{
    int nn, r, p;
    int i;

    for (i = 0; i < prime_table_size; i++) {
        p = prime_table[i];
        r = mpz_cdiv_ui(n, p);
        if (r == 0) {
            if (mpz_cmp_ui(n, p) == 0) {
                return NUMBER_PRIME;
            } else {
                return NUMBER_NOT_PRIME;
            }
        }
    }

    return NUMBER_UNKNOWN;
}

int prime_test(mpz_t n)
{
    return 0;
}

int main(int argc, char* argv[])
{
    int i;

    make_prime_table();
    for (i = 0; i < prime_table_size; i++)
        printf("prime[%d] : %d\r\n", i, prime_table[i]);

    return 0;
}
