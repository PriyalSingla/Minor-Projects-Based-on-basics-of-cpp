// #include <bits/stdc++.h>
// using namespace std;
// bool isSafe(int **arr, int x, int y, int n)
// {
//     if (x < n && y < n && arr[x][y] == 1)
//     {
//         return true;
//     }
//     return false;
// }
// bool rat_in_maze(int **arr, int x, int y, int n, int **sol)
// {
//     if (x == (n - 1) && y == (n - 1))
//     {
//         sol[x][y] = 1;
//         return true;
//     }
//     if (isSafe(arr, x, y, n))
//     {
//         sol[x][y] = 1;
//         if (rat_in_maze(arr, x + 1, y, n, sol))
//         {
//             return true;
//         }
//         if (rat_in_maze(arr, x, y + 1, n, sol))
//         {
//             return true;
//         }
//         sol[x][y] = 0; // BACKTRACKING
//         return false;
//     }
//     return false;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     int **arr = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = new int[n];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     int **sol = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = new int[n];
//         for (int j = 0; j < n; j++)
//         {
//             sol[i][j] = 0;
//         }
//     }

//     rat_in_maze(arr, 0, 0, n, sol);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << sol[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
// // 1 0 1 0 1
// // 1 1 1 1 1
// // 0 1 0 1 0
// // 1 0 0 1 1
// // 1 1 1 0 1

// // 1 0 0 0 0
// // 0 1 1 1 0
// // 0 0 0 1 0
// // 0 0 0 1 1
// // 0 0 0 0 1

#include <bits/stdc++.h>
using namespace std;
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};
    if (solveMazeUtil(maze, 0, 0, sol) == false)
    {
        cout << "Solution doesn't exist";
        return false;
    }
    printSolution(sol);
    return true;
}
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y) == true)
    {
        if (sol[x][y] == 1)
            return false;
        sol[x][y] = 1;
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};
    solveMaze(maze);
    return 0;
}
