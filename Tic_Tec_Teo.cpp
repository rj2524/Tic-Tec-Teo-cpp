#include<iostream>
#include<array>
#include<string>

using namespace std;

void printLayout();
void takeUserInput();
void check();

char board[3][3]{
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
    };
int inputCount = 0;
char currentPlayer;
bool gameStatus = true;

int main()
{
    printLayout();
    while (gameStatus)
    {
        takeUserInput();
        printLayout();
        check();
    }
    // printLayout();
    // cout << xoArray[3][3] << "Lala" << endl;
    return 0;
}

void printLayout()
{
    for (int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            cout << board[row][col];
            if (col < 2)
            {
                cout << "|";
            }
        }
        if (row < 2)
        {
            cout << endl << "-----" << endl;
        }  
    }
    cout << endl;
}

void takeUserInput()
{
    int row, col;
    bool update = true;

    if (inputCount%2 == 0)              //Checking for turn (X or O)
    {
        currentPlayer = 'x';
        cout << "X turn, please enter position for X." << endl << "Row No. (1 to 3) = ";
        cin >> row;
        cout << "Col No. (1 to 3) = ";
        cin >> col;
    }
    else if (inputCount%2 == 1)         //Checking for turn (X or O)
    {
        currentPlayer = 'o';
        cout << "O turn, please enter position for O." << endl << "Row No. (1 to 3) = ";
        cin >> row;
        cout << "Col No. (1 to 3) = ";
        cin >> col;
    }
    if (board[row-1][col-1] == ' ')       // Cheaking for empty space
    {
        board[row-1][col-1] = currentPlayer;
        update = false;
    }
    while (update)
    {
        if (row < 1 || row > 3 || col < 1 || col > 3)  // Cheack for invalide inpute
        {
            cout << "You enter invalide position for '" << currentPlayer << "' please enter correct position." << endl << "Row No. (1 to 3) = ";
            cin >> row;
            cout << "Col No. (1 to 3) = ";
            cin >> col;
        }
        else if (board[row-1][col-1] != ' ')  // Cheack for invalide inpute
        {
            cout << "The position is already aquired, please enter other position for '" << currentPlayer << "' please enter correct position." << endl << "Row No. (1 to 3) = ";
            cin >> row;
            cout << "Col No. (1 to 3) = ";
            cin >> col;
        }
        else
        {
            board[row-1][col-1] = currentPlayer;
            update = false;
        }
    }

    inputCount++;
}

void check()
{
    if((board[0][0] == currentPlayer && board[0][1] == currentPlayer && board[0][2] == currentPlayer) ||
       (board[1][0] == currentPlayer && board[1][1] == currentPlayer && board[1][2] == currentPlayer) ||
       (board[2][0] == currentPlayer && board[2][1] == currentPlayer && board[2][2] == currentPlayer) ||
       (board[0][0] == currentPlayer && board[1][0] == currentPlayer && board[2][0] == currentPlayer) ||
       (board[0][1] == currentPlayer && board[1][1] == currentPlayer && board[2][1] == currentPlayer) ||
       (board[0][2] == currentPlayer && board[1][2] == currentPlayer && board[2][2] == currentPlayer) ||
       (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
       (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)    )     // Check winning condition
    {
        cout << currentPlayer << " Wins the game." << endl;
        gameStatus = false;
    }
    else if (inputCount >= 9)
    {
        cout << "No one wins, Match Draw!!!" << endl;
        gameStatus = false;
    }
}