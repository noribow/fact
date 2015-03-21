#include <stdlib.h>

#define GLOBAL_HERE
#include "number.h"

char* prime_sieve_table;

int make_prime_table(void)
{
    int prime_count = 1;
    int i, j, p;

    prime_sieve_table = (char*)malloc(MAX_PRIME_SIEVE_SIZE);
    if (prime_sieve_table == NULL)
        return 0;

    for (i = 0; i < MAX_PRIME_SIEVE_SIZE; i++)
        prime_sieve_table[i] = 1;

    for (i = 0; i < MAX_PRIME_SIEVE_SIZE; i++) {
        if (prime_sieve_table[i] == 0)
            continue;

        prime_count++;
        p = 2 * i + 3;
        for (j = i + p; j < MAX_PRIME_SIEVE_SIZE; j += p)
            prime_sieve_table[j] = 0;
    }

    prime_table = (int*)malloc(sizeof(int) * prime_count);
    if (prime_table == NULL)
        return 0;

    prime_table[0] = 2;
    prime_count = 0;
    for (i = 0; i < MAX_PRIME_SIEVE_SIZE; i++) {
        if (prime_sieve_table[i] == 0)
            continue;

        p = 2 * i + 3;
        prime_count++;
        prime_table[prime_count] = p;
    }
    prime_table_size = prime_count + 1;
    free(prime_sieve_table);

    return 0;
}
