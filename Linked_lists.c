/*********************************************
Student One (GIRIES ABU AYOUB + 318156171)
Student Two (SAMEER HABIB + 315844753)
Assignment number: 7
Exercise number: 1
********************************************/

#include <stdio.h>
#include <stdlib.h>



typedef struct cell *CellPtr;
typedef struct cell
{

    int contents;
    CellPtr next;

} Cell;


/*This function inserts and sorts the list in an ascending order*/
CellPtr insert (int input, CellPtr list)
{
    CellPtr p,q;

    /* allocate memory for new record */
    if ((p = (CellPtr )malloc (sizeof (Cell))) == NULL)
    {
        printf ("Cannot allocate memory\n");
        exit (1);
    }
    p->contents = input; /* store input in new record */
    /* first, handle the case where input should be first element */
    if (list == NULL || /* this is the first element */
            list->contents > input)   /* input should be first element */
    {
        p->next = list;
        return p;
    }
    else     /* search list for the right location */
    {
        q = list;
        while (q->next != NULL &&
                q->next->contents < input)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        return list;
    }
}


/*Sums the content of the list*/
int SumOfList(CellPtr list)
{
    int sum=0;
    CellPtr p;

    for(p=list; p != NULL; p = p->next)
        sum = sum + p->contents;

    return sum;
}


/*Counts the cells of the list*/
int CountList(CellPtr list)
{
    int count=0;
    CellPtr p;

    for(p=list; p != NULL; p = p->next)
        count++;

    return count;
}

/*frees all the lists that we have dynamically allocated*/
void free_list(CellPtr list)
{
    CellPtr p;

    while(list != NULL)
        {
        p = list->next;
        free(list);
        list = p;
    }
}


/*Prints the list*/
void print_list(CellPtr list)
{

    CellPtr p;

    for(p=list; p != NULL; p = p->next)
        printf("%d    ", p->contents);
}


/*Computing the length of the Short and Long lists*/
int CheckLength(CellPtr list,int AllSum,int ListLength)
{
    int indexCounter=1,CurrentSum=0;
    CellPtr p;

    for(p=list; p != NULL; p=p->next)
    {
        CurrentSum = CurrentSum + p->contents;
        if(CurrentSum > (AllSum - CurrentSum)) return indexCounter - 1;
        indexCounter++;
    }
    return ListLength - 1;
}



int main()
{
    int input,TotalSum=0,ListLength=0,LongListLength=1;
    CellPtr list = NULL;

    printf("Enter list elements:\n");

    if(scanf("%d",&input) != 1){
        printf("invalid input!");
        exit(1);
    }

    if(input == 0)
    {
    printf("Short list:\nLength: 0\nLong list:\nLength: 0\n\n");

    printf("All elements:\n");

    print_list(list);
    return 0;
    }

    while(input != 0)
    {
        list=insert(input,list);
        if(scanf("%d",&input) != 1){
        printf("invalid input!");
        exit(1);
    }
    }
    TotalSum = SumOfList(list);
    ListLength=CountList(list);

    LongListLength = CheckLength(list,TotalSum,ListLength);

    printf("Short list:\nLength: %d\nLong list:\nLength: %d\n\n", ListLength-LongListLength,LongListLength);

    printf("All elements:\n");

    print_list(list);

    free_list(list);

    return 0;
}





















