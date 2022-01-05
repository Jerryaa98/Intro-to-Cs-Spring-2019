/*********************************************
Student One (GIRIES ABU AYOUB + 318156171)
Student Two (SAMEER HABIB + 315844753)
Assignment number: 3
Exercise number: 1
********************************************/


#include <stdio.h>
#include <limits.h>
#define ar_len 100


int BunnyHop(int n)
{
    int total;
    if (n==0)
    {
        return 1;
    }
    total=0;

    if(n-1>=0)
    {
        total += BunnyHop(n-1);
    }
    if(n-2>=0)
    {
        total += BunnyHop(n-2);
    }
    if(n-3>=0)
    {
        total += BunnyHop(n-3);
    }
    return total;
}

int main()
{
    printf("%d", BunnyHop(2));

    return 0;
}

