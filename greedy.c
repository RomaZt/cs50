#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    int coinsReturned = 0;
    
    printf("How much change is owed? \n");
    float change = GetFloat();
    while (change < 0) {
        printf("How much change is owed? \n");
        change = GetFloat();
    }
    
    // round amount to 2 decimals and
    // convert entirely to cents (float -> int)
    int amount =  round(change * 100);
    
    while (amount > 0) {
        if ((amount - 25) >= 0) 
        { 
            amount = amount - 25;
            coinsReturned++;
        }
        else if ((amount - 10) >= 0) 
        { 
            amount = amount - 10; 
            coinsReturned++;
        }
        else if ((amount - 5) >= 0)
        { 
            amount = amount - 5; 
            coinsReturned++;
        }
        else if ((amount - 1) >= 0) 
        { 
            amount = amount - 1; 
            coinsReturned++;
        }
    }
    
    printf("%d\n", coinsReturned);
}