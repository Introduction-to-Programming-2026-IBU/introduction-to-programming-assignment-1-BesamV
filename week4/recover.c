#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[512];
    int count = 0;

    FILE *output = NULL;

    char filename[8];

    while (fread(buffer, 1, 512, input) == 512)
    {
        // Check JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous file
            if (output != NULL)
            {
                fclose(output);
            }

            // Create new file
            sprintf(filename, "%03i.jpg", count);
            output = fopen(filename, "w");
            count++;
        }

        // Write to file if already opened
        if (output != NULL)
        {
            fwrite(buffer, 1, 512, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);
}
