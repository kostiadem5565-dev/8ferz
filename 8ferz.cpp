#include <iostream>

using namespace std; 

bool cell(int arr[8][8], int i0, int j0)
{
    for (int col = 0; col < 8; col ++)
    {
        if (arr[i0][col] == 1) return false;
    }

    for (int row = 0; row < 8; row ++)
    {
        if (arr[row][j0] == 1) return false;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (((i-j) == (i0-j0)) && arr[i][j] == 1) return false;
            else if (((i+j) == (i0+j0)) && arr[i][j] == 1) return false;
        }
    }
    return true;
}

bool solve(int arr[8][8], int row)
{
    if (row == 8) return true;

    for (int col = 0; col < 8; col ++)
    {
        if (cell(arr, row, col)) 
        {
        arr[row][col] = 1;

        if (solve(arr, row+1)) return true;

        arr[row][col] = 0;
        }
    }

    return false;
}

void game()
{
    int arr[8][8] = {0}; 

    if (solve(arr, 0))
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++) cout << arr[i][j] << " ";
            cout << endl;
        }
    }
}
int main()
{
    game();
    return 0;
}