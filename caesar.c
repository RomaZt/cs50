#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

 int main(int argc, string argv[])
 {
    // check for 2 arguments only
    if (argc != 2)
    {
        printf("Nope\n");
        return 1;
    }
    
    // convert string value to an int
    int k = atoi(argv[1]);

    // check if the integer is non-negative
    if (k < 0)
    {
        printf("Nope\n");
        return 1;
    }
    else
    {
        // prompt the text to encrypt
        printf("plaintext: ");
        string code = get_string();
        printf("ciphertext: ");
        for (int i = 0, n = strlen(code); i < n; i++)
            {
                //check if the letter is uppercase
                if islower(code[i])
                {
                    printf("%c", (((code[i] - 97) + k) % 26) + 97);
                }
                //check if the letters is lowercase
                else if isupper(code[i])
                {
                    printf("%c", (((code[i] - 65) + k) % 26) + 65);
                }
                else
                {
                    printf("%c", code[i]);
                }
            }
            printf("\n");
            return 0;
    }
    
 }