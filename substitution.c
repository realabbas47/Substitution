#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int get_index(char c);

char ALPHBT[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, string argv[])
{
    // check if it followes format
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if there were 26 charactors
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check if key was alphabets
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    // Making sure the key does not have duplicates
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            int a = argv[1][i];
            int b = argv[1][j];
            int x = a - b;
            if (x == 0)
            {
                printf("Key must contain 26 unique characters.\n");
                return 1;
            }
        }
    }

    // Prompting user for plaintext
    string p = get_string("plaintext: ");

    // Roating characters if letters
    printf("ciphertext: ");
    for (int i = 0; i < strlen(p); i++)
    {
        // if not an alphabet printing as is.
        if (isdigit(p[i]) || (isalnum(p[i]) == 0))
        {
            printf("%c", p[i]);
        }
        else
        {
            int ecrp = get_index(p[i]);
            if (islower(p[i]))
            {
                printf("%c", tolower(argv[1][ecrp]));
            }
            else if (isupper(p[i]))
            {
                printf("%c", toupper(argv[1][ecrp]));
            }
        }
    }
    printf("\n");
}

int get_index(char c)
{
    for (int i = 0; i < 26; i++)
    {
        if (toupper(c) == ALPHBT[i])
        {
            return i;
        }
    }
    return 0;
}