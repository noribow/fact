#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <gmp.h>

typedef struct {
    int flag;
    int fact_count;
    mpz_t n;
    mpz_t* fact;
    int* fact_flag;
} FACTOR_ARRAY;

#define FACTOR_ARRAY_ELEMENT_MAX (100)

#define NUMBER_PRIME (0)
#define NUMBER_NOT_PRIME (1)
#define NUMBER_COMPOSITE (2)
#define NUMBER_NOT_COMPOSITE (3)
#define NUMBER_UNKNOWN (4)

#define MAX_PRIME_SIEVE_SIZE (10 * 1000 * 1000)
int* prime_table;
int prime_table_size;
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
            }
            else {
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
