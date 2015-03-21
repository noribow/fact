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

FACTOR_ARRAY* alloc_factor_array(void)
{
    FACTOR_ARRAY* p;
    int i;

    p = (FACTOR_ARRAY*)malloc(sizeof(FACTOR_ARRAY));
    if (p == NULL)
        return NULL;

    p->fact = (mpz_t*)malloc(sizeof(mpz_t) * FACTOR_ARRAY_ELEMENT_MAX);
    if (p->fact == NULL) {
        free(p);
        return NULL;
    }

    p->fact_flag = (int*)malloc(sizeof(int) * FACTOR_ARRAY_ELEMENT_MAX);
    if (p->fact_flag == NULL) {
        free(p);
        free(p->fact);
        return NULL;
    }

    for (i = 0; i < FACTOR_ARRAY_ELEMENT_MAX; i++)
        mpz_init(p->fact[i]);
    mpz_init(p->n);

    return p;
}

void free_factor_array(FACTOR_ARRAY* p)
{
    int i;

    mpz_clear(p->n);
    for (i = 0; i < FACTOR_ARRAY_ELEMENT_MAX; i++)
        mpz_clear(p->fact[i]);
    free(p->fact_flag);
    free(p->fact);

    free(p);
}
