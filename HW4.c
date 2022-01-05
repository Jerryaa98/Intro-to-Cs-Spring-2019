/*********************************************
Student One (GIRIES ABU AYOUB + 318156171)
Student Two (SAMEER HABIB + 315844753)
Assignment number: 4
Exercise number: 1
********************************************/


#include <stdio.h>
#include <string.h>



void ReverseArray(int a[],int Low,int High)
{
    int tmp;
    if (Low<High)
    {
        tmp=a[Low];
        a[Low]=a[High];
        a[High]=tmp;
        ReverseArray(a,Low+1,High-1);
    }
}



int ArraySum(int a[],int n)
{
    if (n==0)
        return 0;
    return (ArraySum(a,n-1) + a[n-1]);
}



int TakeNumbers(int a[])
{
    int n,i;
    scanf("%d", &n);
    printf("Please insert %d numbers: \n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    return n;
}



void PrintArray(int a[],int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ", a[i]);
}




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


int secondmax(int data[],int n, int ind, int max1, int max2)
{int temp;
    if(ind==n)
        return max2;

    if(data[ind]>=max1)
    {
        temp = max1;
        max1 = data[ind];
        max2 = temp;
    }
    else {
        if(data[ind]>max2)
        {
            max2 = data[ind];
        }
    }


    return secondmax(data,n, ind+1, max1, max2);

}

int calc(char a[], int n)
{
    int i;
    if (n==1)
    {
        return a[0];
    }

    for(i=0; i<n; i++)
    {
        if(a[i] == '(')
            calc(a+i+1, n);
        if(a[i] == ')')
            i=n;
        if(a[i] == '1')
            return 1 +calc(a+1,n);
        if(a[i] == '0')
            return 0+calc(a+1,n);
    }
    return 0;
}


int main()
{
    char ch[100];
    int n,SumNum,a[100],stairs;
    printf("Please enter the length of the array:\n");
    n=TakeNumbers(a);
    printf("Please enter how many numbers to sum:\n");
    scanf("%d", &SumNum);
    printf("The sum of the first %d numbers is: %d\n", SumNum,ArraySum(a,SumNum));
    printf("The second greatest is: %d\n", secondmax(a,n,1,a[0],a[1]));
    printf("The reverse of the array is:\n");
    ReverseArray(a,0,n-1);
    PrintArray(a,n);
    printf("\nPlease enter the number of stairs:\n");
    scanf("%d", &stairs);
    printf("The bunny can climb the stairs in %d ways.\n", BunnyHop(stairs));
    printf("Enter logical expression:\n");
    scanf("%s", ch);
    n= strlen(ch);
    printf("%d", calc(ch,n)%2);


    return 0;
}
