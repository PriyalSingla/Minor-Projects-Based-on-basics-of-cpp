// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;
// // UNASSIGNED is used for empty cells in sudoku grid
// #define UNASSIGNED 0

// // N is used for the size of Sudoku grid.
// // Size will be NxN
// #define N 9

// // } Driver Code Ends
// class Solution
// {
// public:
//     // Function to find a solved Sudoku.

//     bool isSafe(int grid[9][9], int row, int col, int val)
//     {
//         for (int i = 0; i < 9; i++)
//         {
//             if (grid[i][col] == val)
//                 return false;

//             if (grid[row][i] == val)
//                 return false;

//             if (grid[3 * (row / 3) + (i / 3)][3 * (col / 3) + i % 3] == val)
//                 return false;
//         }

//         int r = 3 * (row / 3);
//         int c = 3 * (col / 3);
//         for (int i = 0; i < 3; i++)
//         {
//             if (grid[r + i][c] == val || grid[r + i][c + 1] == val || grid[r + i][c + 2] == val)
//                 return false;
//         }

//         return true;
//     }

//     bool solve(int grid[N][N])
//     {
//         for (int r = 0; r < N; r++)
//         {
//             for (int c = 0; c < N; c++)
//             {
//                 if (grid[r][c] == 0)
//                 {
//                     for (int i = 1; i <= 9; i++)
//                     {
//                         if (isSafe(grid, r, c, i))
//                         {

//                             grid[r][c] = i;

//                             // recursion
//                             if (solve(grid))
//                             {
//                                 return true;
//                             }

//                             else
//                             {
//                                 grid[r][c] = 0;
//                             }
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     bool SolveSudoku(int grid[N][N])
//     {
//         return solve(grid);
//     }

//     // Function to print grids of the Sudoku.
//     void printGrid(int grid[N][N])
//     {
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 cout << grid[i][j] << " ";
//             }
//         }
//     }
// };

// //{ Driver Code Starts.

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int grid[N][N];

//         for (int i = 0; i < 9; i++)
//             for (int j = 0; j < 9; j++)
//                 cin >> grid[i][j];

//         Solution ob;

//         if (ob.SolveSudoku(grid) == true)
//             ob.printGrid(grid);
//         else
//             cout << "No solution exists";

//         cout << endl;
//     }

//     return 0;
// }
// // } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution
{
public:
    bool p = false;

    vector<vector<int>> g;

    int check(vector<vector<int>> &grid, int num, int a, int b, int e, int r)
    {
        for (int i = a; i <= b; i++)
        {
            for (int j = e; j <= r; j++)
            {
                if (grid[i][j] == num)
                    return 0;
            }
        }
        return 1;
    }

    int is_safe(vector<vector<int>> &grid, int num, int c, int r)
    {
        // column check
        for (int i = 0; i < N; i++)
        {
            if (grid[i][c] == num)
                return 0;
        }

        // row check
        for (int i = 0; i < N; i++)
        {
            if (grid[r][i] == num)
                return 0;
        }

        // box check

        if (r <= 2 && c <= 2) // 1st box
            return check(grid, num, 0, 2, 0, 2);

        if (r <= 2 && c >= 3 && c <= 5) // 2nd box
            return check(grid, num, 0, 2, 3, 5);

        if (r <= 2 && c >= 6) // 3rd box
            return check(grid, num, 0, 2, 6, 8);

        if (r >= 3 && r <= 5 && c <= 2) // 4th box
            return check(grid, num, 3, 5, 0, 2);

        if (r >= 3 && r <= 5 && c >= 3 && c <= 5) // 5th box
            return check(grid, num, 3, 5, 3, 5);

        if (r >= 3 && r <= 5 && c >= 6) // 6th box
            return check(grid, num, 3, 5, 6, 8);

        if (r >= 6 && c <= 2) // 7th box
            return check(grid, num, 6, 8, 0, 2);

        if (r >= 6 && c >= 3 && c <= 5) // 8th box
            return check(grid, num, 6, 8, 3, 5);

        if (r >= 6 && c >= 6) // 9th box
            return check(grid, num, 6, 8, 6, 8);
    }

    void solve(vector<vector<int>> &grid, int c, int r, int flag)
    {

        if (c == N)
        {
            p = true;
            return;
        }

        if (grid[r][c] != 0)
        {
            flag = 1;

            if (r == 8)
                solve(grid, c + 1, 0, 0);

            else
                solve(grid, c, r + 1, 0);
        }

        else
        {
            for (int num = 1; num <= 9; num++)
            {
                if (is_safe(grid, num, c, r))
                {
                    grid[r][c] = num;

                    if (r == 8)
                        solve(grid, c + 1, 0, 0);

                    else
                        solve(grid, c, r + 1, 0);
                }
                if (p == true)
                    return;
            }
        }

        if (flag == 0)
            grid[r][c] = 0;
    }

    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            g.push_back(vector<int>());
            for (int j = 0; j < N; j++)
            {
                g[i].push_back(grid[i][j]);
            }
        }

        solve(g, 0, 0, 0);
        return p;
        // Your code here
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << g[i][j] << " ";
            }

        } // Your code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends