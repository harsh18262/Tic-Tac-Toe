#include <iostream>
//#include <dos> //for delay
#include <string.h>
int winflag = 0;
char grid[3][3] = {{'1', '2', '3'},
                   {'4', '5', '6'},
                   {'7', '8', '9'}};

char winning[8][3] = {{'1', '2', '3'},
                      {'4', '5', '6'},
                      {'7', '8', '9'},
                      {'1', '5', '9'},
                      {'3', '5', '7'},
                      {'1', '4', '7'},
                      {'2', '5', '8'},
                      {'3', '6', '9'}};

void create_grid();
void human_turn(); //human is X
void check();
//
//--------------
// 1 |  2 |  3 |
//--------------
// 4 |  5 |  6 |
//--------------
// 7 |  8 |  9 |
//--------------
//

using namespace std;

int main()
{
    while (true)
    {

        create_grid();
        human_turn();
        check();
    }
}

void create_grid()
{

    for (int row = 0; row <= 2; row++)
    {
        puts("--------------");
        for (int col = 0; col <= 2; col++)
        {
            cout << " " << grid[row][col] << " | ";
        }
        cout << endl;
    }
    puts("--------------");
}

void human_turn()
{
    int input;
    cout << "enter turn" << endl;
    cin >> input;
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
            cout << "that grid space is already taken" << endl;
        }
        else if (input >= 1 && input <= 9)
        {
            grid[row][col] = 'X';
        }

        else
        {
            puts("invalid input");
        }
    }

    else if (cin.get() == '\n')
    {
        cout << "please give input";
    }
}

void check()
{

    for (int i = 0; i <= 7; i++)
    {
        winflag = 0;

        for (int j = 0; j <= 2; j++)
        {
            int winmov = winning[i][j] - '0';
            // cout << "winning move = " << winmov << endl;
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
            //cout << "row = " << row << "col =" << col << endl;
            if (grid[row][col] == 'X')
            {
                winflag++;
                //cout << "wiflag = " << winflag;
                // cout << " k=  " << k << endl;
            }
            if (winflag == 3)
            {

                cout << "winner";
                exit(0);
            }
        }
    }
}