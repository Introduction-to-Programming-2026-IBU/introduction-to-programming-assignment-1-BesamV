#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./speller dictionary\n");
        return 1;
    }

    if (!load(argv[1]))
    {
        printf("Could not load dictionary.\n");
        return 1;
    }

    printf("Dictionary loaded.\n");

    printf("Size: %u\n", size());

    unload();
}
