#include <stdlib.h>
#include <stdio.h>




float celsius(float fahrenheit)
{

    float result;

    result = (5*(fahrenheit - 32))/9;

    return result;
}


int main(void)
{
    int number = 0;

    printf("-----------------------\nFahrenheit\tCelsius\n-----------------------\n");

    while(number <= 200)
    {
        printf("\t%i\t%f\n", number, celsius((float)number));
        number += 20;
    }    
	return EXIT_SUCCESS;
}