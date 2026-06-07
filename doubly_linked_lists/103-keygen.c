#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    unsigned int hash;
    size_t i, len;

    if (argc != 2)
        return (1);
    hash = 1337;
    len = strlen(argv[1]);
    for (i = 0; i < len; i++)
        hash = ((hash << 5) + hash) ^ argv[1][i];
    printf("%u\n", hash);
    return (0);
}
