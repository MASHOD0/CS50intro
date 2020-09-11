#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{ 
//taking the initial input
    float input ;
    do
    {
        input = get_float("Change owed:");
    }
    while (input < 0);

//getting the change in cents
    int cents = round(input * 100);
//counting 25cent coins
    int i = 0;
    while (cents >= 25)
    {
        cents = cents - 25 ;
        i++ ;
    }

//counting 10 cent coins
    while (cents >= 10)
    {
        cents = cents - 10 ;
        i++ ;
    }

//counting 5 cent coins
    while (cents >= 5)
    {
        cents = cents - 5 ;
        i++ ;
    }

//counting 1 cent coins
    while (cents >= 1)
    {
        cents = cents - 1 ;
        i++ ;
    }

//printing the number of coins
    printf("%i\n", i) ;

}        