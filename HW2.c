/*********************************************
Student One (GIRIES ABU AYOUB + 318156171)
Student Two (SAMEER HABIB + 315844753)
Assignment number: 2
Exercise number: 1
********************************************/


#include <stdio.h>


int main()
{
    int input,n,factorial=1,i,is_prime=1;
    do
    {
        is_prime=1;
        factorial = 1;
        printf ("Menu:\n0. Exit\n1. n-Boom\n2. Prime number\n3. factorial\n");
        if (scanf("%d", &input) != 1 )
        {
            printf("Illegal input");
            return 1;
        }
        do
        {
            if (input<0 || input>3)
            {
                printf("invalid option, try again\n");
                printf ("Menu:\n0. Exit\n1. n-Boom\n2. Prime number\n3. factorial\n");
                if (scanf("%d", &input) != 1 )
                {
                    printf("Illegal input");
                    return 1;
                }
            }
            else
                break;
        }
        while (1);

        switch (input)
        {
        case 0 :
            printf("Goodbye");
            return 0;
        case 1:
            printf("Please enter a positive boom number between 1 and 9\n");
            if (scanf("%d", &n) != 1 )
            {
                printf("Illegal input");
                return 1;
            }
            if (n<1 || n>9)
            {
                printf("input out of range\n");
                break;
            }
            for ( i=1; i<=100; i++)
            {
                if (i % n == 0 || i % 10 == n || (i/10)%10 == n || (i/100)%10 == n)
                {
                    printf("BOOM ");
                    continue;
                }
                printf("%d ", i);
            }
            break;
        case 2:
            printf("Please enter a positive number\n");
            if (scanf("%d", &n) != 1 )
            {
                printf("Illegal input");
                return 1;
            }
            if(n == 1)
            {
                printf("This is NOT a prime number\n");
                break;
            }
            for( i = 2; i<n; i++)
            {
                if (n%i==0)
                {
                    is_prime=0;
                }
            }
            if(is_prime==1)
                printf("This is a prime number\n");
            else
                printf("This is NOT a prime number\n");
            break;
        case 3:
            printf("Please enter a number between 0 and 12\n");
            if (scanf("%d", &n) != 1 )
            {
                printf("Illegal input");
                return 1;
            }
            if (n<0 || n>12)
            {
                printf("input is out of range\n");
                break;
            }
            if (n == 0)
            {
                printf("Factorial of 0 = 1\n");
                break;
            }
            for ( i=1; i<=n; i++)
            {
                factorial*=i;
            }
            printf("Factorial of %d = %d\n", n, factorial);
            break;
        }

    }
    while (1);

    return 0;
}
