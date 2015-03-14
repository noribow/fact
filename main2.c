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

#define 
int *prime_table;
int prime_table_size;


int prime_test(mpz_t n)
{
    return 0;
    test();
}

int main(int argc, char* argv[])
{
    return 0;
}
