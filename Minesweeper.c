/*********************************************
Student One (GIRIES ABU AYOUB)
Assignment number: 6
Exercise number: 1
********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/* updating the board for the current situation and making it ready to be printed*/
void steadyBoard(char **board,int size,char** bombs,char **openedSquares,char **flags)
{
    int i,j;
    for (i=0; i<size; i++)
        for(j=0; j<size; j++)
            board[i][j] = (char)35;

    for (i=0; i<size; i++)
        for(j=0; j<size; j++)
            if(flags[i][j] == 'F') board[i][j] = 'F';

    for (i=0; i<size; i++)
        for(j=0; j<size; j++)
            if(openedSquares[i][j] == '1') board[i][j] = bombs[i][j];


}

/*opens the square according to the instructions (recursively if it contains zero)*/
void OpenSquare(char** bombs, char** flags,char **opened, int n, int i, int j)
{
    if(i>=n)return;
    if(j>=n)return;
    if(i<0)return;
    if(j<0)return;
    if (opened[i][j] == '1') return;
    if (flags[i][j] == 'F') return;
    if (bombs[i][j] != '0')
    {
        opened[i][j] = '1';
        return;
    }
    if (bombs[i][j] == '0')
    {
        opened[i][j] = '1';
        OpenSquare(bombs,flags,opened,n,i-1,j-1);
        OpenSquare(bombs,flags,opened,n,i-1,j+1);
        OpenSquare(bombs,flags,opened,n,i-1,j);
        OpenSquare(bombs,flags,opened,n,i,j+1);
        OpenSquare(bombs,flags,opened,n,i+1,j+1);
        OpenSquare(bombs,flags,opened,n,i+1,j);
        OpenSquare(bombs,flags,opened,n,i+1,j-1);
        OpenSquare(bombs,flags,opened,n,i,j-1);
    }


}

/*prints the board that has been sent*/
void printBoard(char **board,int size)
{
    int i,j;
    for (i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}


/*counts the opened squares in the board*/
int CountOpenSquares(char** opened, int size)
{
    int count=0,i,j;

    for (i=0; i<size; i++)
        for(j=0; j<size; j++)
            if (opened[i][j] == '1') count ++;

    return count;
}


/*initializes all boards according to the chosen play style*/
int InitBoards(char** board,char** flags,char** bombs,int M,int size,char** opened)
{
    int i,j,playStyle,xCoordinate=0,yCoordinate=0;

    for (i=0; i<size; i++)
        for(j=0; j<size; j++)
            flags[i][j] = '0';

    for (i=0; i<size; i++)
        for(j=0; j<size; j++)
            opened[i][j] = '0';

    for (i=0; i<size; i++)
        for(j=0; j<size; j++)
            board[i][j] = (char)35;

    for (i=0; i<size; i++)
        for(j=0; j<size; j++)
            bombs[i][j] = '0';

    printf("would you like to play the random or the deterministic version?\n1.random 2.deterministic\n>");

    if(scanf("%d", &playStyle) != 1) exit(0);

    while (playStyle != 1 && playStyle != 2)
    {
        printf("you should enter 1(random) or 2(deterministic)\nplease try again\n");
        if(scanf("%d", &playStyle) != 1) exit(0);
    }
    if(playStyle == 1)
    {
        srand(time(NULL));
        xCoordinate = rand() % size;
        yCoordinate = rand() % size;

        for (i=1; i<=M; i++)
        {
            while(bombs[xCoordinate][yCoordinate] == 'X')
            {
                xCoordinate = rand() % size;
                yCoordinate = rand() % size;
            }
            bombs[xCoordinate][yCoordinate]= 'X';
        }


    }

    if (playStyle == 2)
    {
        for (i=0; i<M; i++)
        {
            printf("There are %d unselected mines left\nPlease enter row and column numbers (i,j)\n>",(M-i));
            if (scanf("%d %d", &xCoordinate, &yCoordinate) != 2) exit(0);

            while(bombs[xCoordinate][yCoordinate]=='X' || xCoordinate>=size || yCoordinate>=size || xCoordinate<0 || yCoordinate<0)
            {
                if(bombs[xCoordinate][yCoordinate]=='X')
                {
                    printf("This square includes a mine, try another one\n");
                    if (scanf("%d", &xCoordinate) != 1) exit(0);
                    if (scanf("%d", &yCoordinate) != 1) exit(0);
                }
                if(xCoordinate>=size || yCoordinate>=size || xCoordinate<0 || yCoordinate<0)
                {
                    printf("Coordinates out of range! Please try again\n");
                    if (scanf("%d", &xCoordinate) != 1) exit(0);
                    if (scanf("%d", &yCoordinate) != 1) exit(0);
                }
            }
            bombs[xCoordinate][yCoordinate]= 'X';
        }
    }

    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(bombs[i][j] == 'X')
            {

                if(i-1<size && j-1<size && i-1>=0 && j-1>=0)
                    if(bombs[i-1][j-1] != 'X')
                        bombs[i-1][j-1]++;

                if(i-1<size && j<size && i-1>=0 && j>=0)
                    if(bombs[i-1][j] != 'X')
                        bombs[i-1][j]++;

                if(i-1<size && j+1<size && i-1>=0 && j+1>=0)
                    if(bombs[i-1][j+1] != 'X')
                        bombs[i-1][j+1]++;

                if(i<size && j+1<size && i>=0 && j+1>=0)
                    if(bombs[i][j+1] != 'X')
                        bombs[i][j+1]++;

                if(i<size && j-1<size && i>=0 && j-1>=0)
                    if(bombs[i][j-1] != 'X')
                        bombs[i][j-1]++;

                if(i+1<size && j+1<size && i+1>=0 && j+1>=0)
                    if(bombs[i+1][j+1] != 'X')
                        bombs[i+1][j+1]++;

                if(i+1<size && j<size && i+1>=0 && j>=0)
                    if(bombs[i+1][j] != 'X')
                        bombs[i+1][j]++;

                if(i+1<size && j-1<size && i+1>=0 && j-1>=0)
                    if(bombs[i+1][j-1] != 'X')
                        bombs[i+1][j-1]++;

            }
        }

    }
    return 1;
}

/*flags the coordinates that has been sent to the function*/
int FlagSquare(char **flags, int i, int j, int numBombs)
{

    if (flags[i][j] == 'F')
    {
        flags[i][j] = '0';
        numBombs ++;
    }
    else
    {
        numBombs--;
        flags[i][j] = 'F';
    }
    return numBombs;
}


/*checks if the player lost the game*/
int checkLoss(char** board, int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(board[i][j] == 'X') return 1;
        }
    }
    return 0;
}

/*checks if the player has won the game*/
int checkWin(char** board,int size,char** bombs,char** opened)
{
    int i,j,count1=0,count2=0,bombsCount=0,openedSquares=CountOpenSquares(opened,size);

    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
        if(bombs[i][j] == 'X')
        {   bombsCount++;
            if(board[i][j] == 'F')
                count1 ++;
        }

    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
            if(opened[i][j] == '1') count2 ++;

    if(openedSquares == (size * size - bombsCount)) return 1;
    if((count1 + count2) == (size * size)) return 1;

    return 0;
}


/*plays the game until the player has lost or won*/
int play(char** board,char** flags,char** bombs,char** opened,int size,int bombsnum)
{
    int remainingBombs= bombsnum;
    int playstyle,i,j,tmp=0;

    while(1)
    {
        tmp=0;

        printBoard(board,size);

        printf("There are %d mines left.\nWhat would you like to do next?\n  1.Open a new square.\n  2.Flag a square as a mine\n>", remainingBombs );

        if (scanf("%d", &playstyle) != 1) exit(0);

         while (playstyle != 1 && playstyle != 2)
        {
            printf("you should enter 1(Open a new square) or 2(Flag a square as a mine)\nplease try again\n");
            if(scanf("%d", &playstyle) != 1) exit(0);
        }

        if(playstyle == 2)
        {
            printf("Please insert row and column numbers: ");
            if (scanf("%d %d", &i,&j) != 2) exit(0);
            remainingBombs =FlagSquare(flags,i,j,remainingBombs);
        }

        if(playstyle == 1)
        {
            printf("Please insert row and column numbers: ");
            if (scanf("%d %d", &i,&j) != 2) exit(0);
            while ((opened[i][j] == '1' || i>=size || j>=size || i<0 || j<0) && tmp == 0 )
            {
                if ( i>=size || j>=size || i<0 || j<0)
                {
                    printf("Coordinates out of range! Please try again");
                    scanf("%d %d", &i,&j);
                }

                if (opened[i][j] == '1')
                {
                    printf("This square is already open\n");
                    tmp=1;
                }

            }
            if (flags[i][j] == 'F')

                remainingBombs=FlagSquare(flags,i,j,remainingBombs);

            else
                OpenSquare(bombs,flags,opened,size,i,j);
        }

        steadyBoard(board,size,bombs,opened,flags);

        if(checkLoss(board,size) == 1)return 1;
        if(checkWin(board,size,bombs,opened) == 1)return 0;

    }

    return -1; /*should not get here*/
}


int main()
{
    char **bombs,**flags,**board,**opened;
    int bombsNum,boardSize,input,i;

    printf("*****************************************************************\n");
    printf("\nWelcome to MineSweeper!\n");
    printf("\n*****************************************************************\n\n");

    printf("Please enter the size of the board and number of bombs: ");
    scanf("%d", &input);
    boardSize=input;
    scanf("%d", &input);
    bombsNum=input;

    bombs = (char **) malloc (boardSize*sizeof (char *));
    flags = (char **) malloc (boardSize*sizeof (char *));
    board = (char **) malloc (boardSize*sizeof (char *));
    opened = (char **) malloc (boardSize*sizeof (char *));

    if (bombs == NULL || flags == NULL || board == NULL) return -1;

    for (i=0; i<boardSize; i++)
    {
        bombs[i] = (char *) malloc (boardSize*sizeof (char *));
        flags[i] = (char *) malloc (boardSize*sizeof (char *));
        board[i] = (char *) malloc (boardSize*sizeof (char *));
        opened[i] = (char *) malloc (boardSize*sizeof (char *));
    }

    InitBoards(board,flags,bombs,bombsNum,boardSize,opened);

    printf("\n*****************************************************************\n");
    printf("\n The boards were initialized successfully! lets start the game\n");
    printf("\n**************************(flags[r][c]***************************************\n\n");

    if (play(board,flags,bombs,opened,boardSize,bombsNum) == 1)
    {
        printBoard(board,boardSize);
        printf("Boom!! You have lost");
        free(opened);
        free(bombs);
        free(board);
        free(flags);
        return 0;

    }

    printBoard(board,boardSize);
    printf("Congratulations!! You have won!!");
    free(opened);
    free(bombs);
    free(board);
    free(flags);
    return 0;
}
