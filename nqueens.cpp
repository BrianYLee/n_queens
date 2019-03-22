/**
 * nqueens.cpp
 * c++ implementation to solve the n-queens problem using a 1 dimensional array
 * Brian Lee <brian.l33ee@gmail.com>
 * March 21, 2019
 * set board size in main.
 */

#include <iostream>
using std::cout;
using std::endl;

/**
 * Precondition: b is initialized, n represents the size of array b.
 */
void printBoard(int b[], int n) {
    cout << "[ ";
    for(int i = 0; i < n; i++)  {
        cout << b[i] << " ";
    }
    cout << "]\n";
}

/**
 * @return true if b[col] is a valid spot for a queen
 * precondition: 
 *  col < n, col >= 0. 
 *  n represents the size of array b. 
 *  b[col] >= 0, b[col] < n.
 */
bool isSafe(int col, int b[], int n)    {
    for(int i = 0; i < col; i++)  {
        if(b[i] == b[col])  {
            return false;
        }
        if( b[i] == ( b[col] - (col-i)) )  {
            return false;
        }
        if( b[i] == ( b[col] + (col-i)) )  {
            return false;
        }
    }
    return true;
}   // isSafe

/**
 * finds a single solution to n-queens problem
 */
bool nQueens(int b[], int n, int col)   {
    if(col >= n)    {
        return true;
    }
    for(int i = 0; i < n; i++)  {
        b[col] = i;
        if(isSafe(col, b, n))   {
            if(nQueens(b, n, col+1))    {
                return true;
            }
            b[col + 1] = -1;
        }
    }
    return false;
}   // nQueens

/**
 * finds all solutions to n-queens problem
 */
bool nQueens_All(int b[], int n, int col)   {
    if(col >= n)    {
        printBoard(b,n);
        return false;
    }
    for(int i = 0; i < n; i++)  {
        b[col] = i;
        if(isSafe(col, b, n))   {
            if(nQueens_All(b, n, col+1))    {
                return true;
            }
            b[col + 1] = -1;
        }
    }
    return false;
}   // nQueens_All

void resetBoard(int b[], int n) {
    for(int i = 0; i < n; i++)  {
        b[i] = -1;
    } 
}

/**
 * set n accordingly to board size. board will simulate an n*n chest board.
 * Precondition: n > 0.
 * Assume theres enough memory on the heap
 * let i represent column # of b, let b[i] represent row # of b.
 */
int main()  {
    int n = 6;
    int b[n];
    resetBoard(b,n);
    if(nQueens(b, n, 0))    {
        cout << "single solution: " << endl;
        printBoard(b,n);
        resetBoard(b,n);
        cout << "all solutions: " << endl;
        nQueens_All(b,n,0);
    }
    else    {
        cout << "no solution" << endl;
    }
    return 0;
}