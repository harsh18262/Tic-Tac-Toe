#include <stdio.h>
#include <stdlib.h>

int winflagx = 0; // X winning flag
int winflago = 0; // O winning flag
int tie = 0;      //tieing flag

char grid[3][3] = {{'1', '2', '3'},
                   {'4', '5', '6'},
                   {'7', '8', '9'}};

char winning[8][3] = {{'1', '2', '3'}, //winning conditions
                      {'4', '5', '6'},
                      {'7', '8', '9'},
                      {'1', '5', '9'},
                      {'3', '5', '7'},
                      {'1', '4', '7'},
                      {'2', '5', '8'},
                      {'3', '6', '9'}};

void create_grid(); //grid creation
void human_turn();  //Human1 is X
void human_turn2(); //Human2 is O
void check();       //checks for winning and tieing
void comp_turn();   //Computer is O
//
//--------------
// 1 |  2 |  3 |
//--------------
// 4 |  5 |  6 |
//--------------
// 7 |  8 |  9 |
//--------------
//

int main()
{
    printf(" _____ _        _____            _____          \r\n|_   _(_) ___  |_   _|_ _  ___  |_   _|__   ___ \r\n  | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\\r\n  | | | | (__    | | (_| | (__    | | (_) |  __/\r\n  |_| |_|\\___|   |_|\\__,_|\\___|   |_|\\___/ \\___|\r\n                                                \r\n\r\n");
    /*printf is printing this
     _____ _        _____            _____        
    |_   _(_) ___  |_   _|_ _  ___  |_   _|__   ___ 
      | | | |/ __|   | |/ _` |/ __|   | |/ _ \ / _ \
      | | | | (__    | | (_| | (__    | | (_) |  __/
     |_| |_|\___|   |_|\__,_|\___|   |_|\___/ \___| */

    int z;
    printf("You want to play with \n1)AI\n2)Human\n");
    scanf("%d", &z);
    if (z == 1)
    {
        while (1)
        {

            create_grid();
            human_turn();
            check();
            comp_turn();
            check();
        }
    }
    if (z == 2)
    {
        while (1)
        {

            create_grid();
            human_turn();
            check();
            create_grid();
            human_turn2();
            check();
        }
    }
    else
    {
        {
            printf("invalid input\n");
        }
    }
}

void create_grid()
{

    for (int row = 0; row <= 2; row++)
    {
        printf("--------------\n");
        for (int col = 0; col <= 2; col++)
        {
            printf(" %c | ", grid[row][col]);
        }
        printf("\n");
    }
    printf("--------------\n");
}

void human_turn()
{
    int input;
    printf("enter turn player 1\n");
    scanf("%d", &input);
    if (input != ' ')
    {
        int row = (input / 3);
        int col = (input % 3) - 1;
        if (input % 3 == 0)
        {
            row = row - 1;
        }
        if (col == -1)
        {
            col = 2;
        }

        if (grid[row][col] == 'X' || grid[row][col] == 'O')
        {
            printf("that grid space is already taken\n");
            human_turn();
        }
        else if (input >= 1 && input <= 9)
        {
            grid[row][col] = 'X';
            tie++;
        }

        else
        {
            printf("invalid input\n");
        }
    }
}

void check()
{

    for (int i = 0; i <= 7; i++)
    {
        winflago = 0;
        winflagx = 0;

        for (int j = 0; j <= 2; j++)
        {
            int winmov = winning[i][j] - '0';
            int row = (winmov / 3);
            int col = (winmov % 3) - 1;
            if (winmov % 3 == 0)
            {
                row = row - 1;
            }
            if (col == -1)
            {
                col = 2;
            }
            if (grid[row][col] == 'X')
            {
                winflagx++;
            }
            if (winflagx == 3)
            {

                create_grid();
                printf("********X is the winnner********");
                exit(0);
            }

            if (grid[row][col] == 'O')
            {
                winflago++;
            }
            if (winflago == 3)
            {

                create_grid();
                printf("********O is the winnner********");
                exit(0);
            }
            if (tie >= 9)
            {
                create_grid();
                printf("********Tied********");
                exit(0);
            }
        }
    }
}

void comp_turn()
{

    int input = (rand() % 9 + 1);

    int row = (input / 3);
    int col = (input % 3) - 1;
    if (input % 3 == 0)
    {
        row = row - 1;
    }
    if (col == -1)
    {
        col = 2;
    }

    if (grid[row][col] == 'X' || grid[row][col] == 'O')
    {
        comp_turn();
    }

    else if (input >= 1 && input <= 9)
    {
        grid[row][col] = 'O';
        tie++;
    }
}

void human_turn2()
{
    int input;

    printf("enter turn player 2\n");
    scanf("%d", &input);
    if (input != ' ')
    {
        int row = (input / 3);
        int col = (input % 3) - 1;
        if (input % 3 == 0)
        {
            row = row - 1;
        }
        if (col == -1)
        {
            col = 2;
        }

        if (grid[row][col] == 'X' || grid[row][col] == 'O')
        {
            printf("that grid space is already taken\n");
            human_turn2();
        }
        else if (input >= 1 && input <= 9)
        {
            grid[row][col] = 'O';
            tie++;
        }

        else
        {
            printf("invalid input\n");
        }
    }
}
