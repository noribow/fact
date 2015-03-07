#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME_TABLE_SIZE (10 * 1000 * 1000)

void write_prime_table(char *buff, int prime_count)
{
    FILE *fp;
    int p, i;
    int ver = 0xfffe0001;

    fp = fopen("prime.dat", "wb");
    if(fp == NULL)
	return;

    fwrite(&ver, 1, 4, fp);
    fwrite(&prime_count, 1, 4, fp);
    for(i=0;i<PRIME_TABLE_SIZE;i++)
	if(buff[i] == 1){
	    p = i * 2 + 3;
	    fwrite(&p, 1, 4, fp);
	}

    fclose(fp);
}

int main(int argc, char *argv[])
{
    char *buff;
    int i, j, n, count;

    buff = (char *)malloc(PRIME_TABLE_SIZE);
    if(buff == NULL)
	return -1;

    memset(buff, 1, PRIME_TABLE_SIZE);

    for(i=0;i<PRIME_TABLE_SIZE;i++){
	if(buff[i] == 0)
	    continue;

	n = 2 * i + 3;
	//	printf("p = %d\r", n);
	for(j = i + n;j < PRIME_TABLE_SIZE;j+=n)
	    buff[j] = 0;
    }

    count = 0;
    for(i=0;i<PRIME_TABLE_SIZE;i++)
	if(buff[i] == 1)
	    count++;

    printf("prime count = %d\n", count);

    write_prime_table(buff, count);

    free(buff);



    return 0;
}
