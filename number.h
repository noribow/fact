#ifndef _NUMBER_H_
#define _NUMBER_H_

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

#if defined(GLOBAL_HERE)
#define EXT
#define DEF(x) = (x)
#else
#define EXT extern
#define DEF(x)
#endif

EXT int* prime_table;
EXT int prime_table_size;

/*number.c*/
int make_prime_table(void);

#endif /* _NUMBER_H_ */
