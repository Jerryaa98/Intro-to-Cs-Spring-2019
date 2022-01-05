/*********************************************
Student One (GIRIES ABU AYOUB + 318156171)
Student Two (SAMEER HABIB + 315844753)
Assignment number: 5
Exercise number: 1
********************************************/
#define LENGTH 31
#define NAME_LENGTH 32
#include <stdio.h>
#include <stdlib.h>

/*the following function takes the boom number as input and checks if it's valid*/
void get_boom_number(int *boom_number)
{
    printf("Enter Boom number\n");
    if(scanf("%d",boom_number) != 1 || *boom_number<=0)
    {
        printf("Input error\n");
        exit(0);
    }
}

/*this function swaps between 2 elements in the given array using pointer substitution*/
void swap(char **str1, char **str2)
{
    char *tmp;

    tmp = *str1;
    *str1= *str2;
    *str2 = tmp;
}

/*the following function plays the algorithm on the given array,
  it takes out the chosen element, pushes the entire array one block forward
  then throws the chosen element at the end, and then replays itself using
  recursion*/
void play(char *arr[],int length,int boom_number,int index)
{
    int new_index,i;
    if (length == 1) return;
    new_index = (index + boom_number - 1) % length;
    for(i=new_index;i<=length-2;i++)
        swap((arr + i), (arr +i + 1));
    play(arr,length -1,boom_number,new_index);

}




int main()
{
    char * players[LENGTH]= {"Tyrion Lannister","Daenerys Targaryen","Jon Snow",
                             "Arya Stark","Theon Greyjoy", "Joffrey Baratheon",
                             "Khal Drogo","Ted Mosby","Marshall Eriksen",
                             "Robin Scherbatsky","Barney Stinson", "Lily Aldrin",
                             "Tracy McConnell", "Ted Mosby", "Leonard Hofstadter",
                             "Sheldon Cooper", "Penny", "Howard Wolowitz",
                             "Raj Koothrappali", "Bernadette Rostenkowski-Wolowitz","Amy Farrah Fowler",
                             "Gregory House", "Lisa Cuddy", "James Wilson",
                             "Eric Foreman", "Allison Cameron", "Robert Chase",
                             "Lawrence Kutner", "Chris Taub","Remy 13 Hadley", "Amber Volakis"
                            };
    int boom_number, i;
    get_boom_number(&boom_number);
    play(players, LENGTH,boom_number,0);
    printf("The order after the game is: \n");
    for(i=0; i<LENGTH-1; i++)
    {
        printf("%s, ",players[i]);
    }
    printf("%s.",players[LENGTH-1]);
    return 0;
}

