#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <gmp.h>

#include "number.h"

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
