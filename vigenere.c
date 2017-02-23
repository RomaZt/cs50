#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main( int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }
    
    else 
    {
        for ( int i = 0, n = strlen(argv[1]); i < n; i++ )
        {
            if ( !isalpha(argv[1][i]))
            {
                printf("You can entered only alphabetic chars");
                return 1;
            }
        }
    }
    string k = argv[1];
    int kLength = strlen(k);
    printf("plaintext: ");
    string code = get_string();
    printf("ciphertext: ");
    for ( int i = 0, j = 0, n = strlen(code); i < n; i++ )
    {
        int key = tolower(k[j % kLength]) - 'a';
        if ( isupper(code[i]))
        {
            printf("%c", 'A' + (code[i] - 'A' + key) % 26);
            j++;
        }
        else if ( islower(code[i]))
        {
            printf("%c", 'a' + (code[i] - 'a' + key) % 26);
            j++;
        }
        else 
        {
            printf("%c", code[i]);
        }
    }
    
    printf("\n");
    return 0;
}
    