//hbscount.cpp
// Brandon Forsythe
// 10/3/22
// CS 301

// this is hbscount.cpp, which uses hbscount.h in order to satisfy the requirements for HW4. It unfortunately also runs into an issue I can't solve.
#include "hbscount.h"


int hbsCount(const int& squareX, 
             const int& squareY,
             const int& holyXbatman, 
             const int& holyY,
             const int& startX, 
             const int& startY,
             const int& finishX, 
             const int& finishY)
{
    // Set all values to goose egg (0)

Board board(squareX, vector<int>(squareY, 0));

    int remaining = squareX * squareY;

    // set hole variable
    board[holyXbatman][holyY] = 1;
    --remaining;

    // set start variable
    board[startX][startY] = 1;
    --remaining;

    int curr_x = startX;
    int curr_y = startY;


    return hbsCount_recurse(board, squareX, squareY, finishX, finishY, curr_x, curr_y, remaining);
}


int hbsCount_recurse(Board& board,
    const int& squareX, const int& squareY,
    const int& finishX, const int& finishY,
    int& curr_x, int& curr_y,
    int& squaresLeft)
{
    // BASE CASE
    if (squaresLeft == 0 && curr_x == finishX && curr_y == finishY)
    {
        return 1;
    }


    // RECURSIVE CASE
    int total = 0; 



    // Check X square
    for (int i = -1; i < 2; ++i)
    {
        // Check Y square
        for (int j = -1; j < 2; ++j)
        {
            // Holey beetles can't look down (ignore space stood on)
            if (i == 0 && j == 0)
            {
                continue;
            }
           
            if (curr_x + i < 0 || curr_x + i >(squareX - 1) || curr_y + j < 0 || curr_y + j >(squareY - 1))
            {
                continue;
            }

            	
            if (board[curr_x + i][curr_y + j] == 0)
            {
                // Square Handling
                curr_x += i;
                curr_y += j;

                board[curr_x][curr_y] = 1;
                --squaresLeft;

                total += hbsCount_recurse(board, squareX, squareY, finishX, finishY, curr_x, curr_y, squaresLeft);

                board[curr_x][curr_y] = 1;
                curr_x -= i;
                curr_y -= j;
                ++squaresLeft;

            }
        }
    }
    return total;


}
