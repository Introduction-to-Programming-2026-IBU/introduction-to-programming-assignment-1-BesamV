#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check for exactly 1 command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Check key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
{
    if (!isalpha(key[i]))
    {
        printf("Key must only contain letters.\n");
        return 1;
    }

    for (int j = i + 1; j < 26; j++)
    {
        if (tolower(key[i]) == tolower(key[j]))
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
}

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
{
    if (isupper(plaintext[i]))
    {
        int index = plaintext[i] - 'A';
        printf("%c", toupper(key[index]));
    }
    else if (islower(plaintext[i]))
    {
        int index = plaintext[i] - 'a';
        printf("%c", tolower(key[index]));
    }
    else
    {
        printf("%c", plaintext[i]);
    }
}

    printf("\n");
}
