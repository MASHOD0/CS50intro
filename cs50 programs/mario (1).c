//to get height of the pyramid
#include <stdio.h>
#include <cs50.h>


int main(void)
{
   int i;
   do
 {
 i = get_int("Height:\n")  ;

} while (i < 1 || i > 8 ) ;

int j;
for ( j = 0; j  < i ; j++)

{
  


int n;  
   
for ( n= -1 ; n < i - j ; n++) 
{
   printf(".") ;
}    

   
for( int k = -1; k  < j; k++)
{
   printf("#");
}    

printf("\n") ;

}
   }
