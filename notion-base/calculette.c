#include <stdlib.h>
#include <stdio.h>


int add(int x, int y)
{
    return(x + y);
}

int sub(int x, int y)
{
    return(x - y);
}

int divi(int x, int y)
{
    return(x / y);
}

int mul(int x, int y)
{
    return(x * y);
}


int is_operand(const char *operand)
{
    int i = 0;
    while (operand[i])
    {
        if (i > 0)
            return (0);

        else if (operand[i] != '+' && operand[i] != '*' && operand[i] != '-' && operand[i] != '/')
            return (0);
        
        i++;       
    }
    return (1);    
}

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        printf("Error, no arguments !\n");
        return EXIT_SUCCESS;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[3]);

    if (!(is_operand(argv[2])))
    {
        printf("Error, operand not valid !\n");
        return EXIT_SUCCESS;
    }

    char ope = argv[2][0];

    if (ope == '+')
        printf("%i + %i = %i\n", x, y, add(x, y));
    else if (ope == '-')
        printf("%i - %i = %i\n", x, y, sub(x, y));
    else if (ope == '*')
        printf("%i * %i = %i\n", x, y, mul(x, y));
    else if (ope == '/')
    {
        if (y == 0)
            printf("Error, division by zero !\n");
        else
            printf("%i / %i = %i\n", x, y, divi(x, y));    
    }

    return EXIT_SUCCESS;

}
