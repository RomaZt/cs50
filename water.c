#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int min;
    do 
    {
    printf("Minutes: ");
    min = get_int();
    
    }
    while ( min < 1);
    printf("Your result is %i\n", min * 12);
}