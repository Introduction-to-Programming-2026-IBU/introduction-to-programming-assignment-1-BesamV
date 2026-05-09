#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

#pragma pack(push, 1)
typedef struct
{
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

typedef struct
{
    BYTE blue;
    BYTE green;
    BYTE red;
} RGBTRIPLE;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./filter input.bmp output.bmp\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *outptr = fopen(argv[2], "w");
    if (outptr == NULL)
    {
        printf("Could not create output file.\n");
        return 1;
    }

    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    fread(&bf, sizeof(bf), 1, inptr);
    fread(&bi, sizeof(bi), 1, inptr);

    fwrite(&bf, sizeof(bf), 1, outptr);
    fwrite(&bi, sizeof(bi), 1, outptr);

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    for (int i = 0; i < abs(bi.biHeight); i++)
    {
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE pixel;
            fread(&pixel, sizeof(RGBTRIPLE), 1, inptr);

            BYTE avg = (pixel.red + pixel.green + pixel.blue) / 3;

            pixel.red = avg;
            pixel.green = avg;
            pixel.blue = avg;

            fwrite(&pixel, sizeof(RGBTRIPLE), 1, outptr);
        }

        fseek(inptr, padding, SEEK_CUR);

        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    fclose(inptr);
    fclose(outptr);
}
