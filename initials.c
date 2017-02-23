#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // prompt a user name
    string s = get_string();
    //change first sign to uppercase
    printf("%c", toupper(s[0]));
    for (int i=0, n=strlen(s); i < n; i++ ){
        if ( s[i] == ' ') 
        {
            //change 1st sign next word to uppercase
            printf("%c", toupper(s[i+1]));
        }
    }
    printf("\n");
   
}