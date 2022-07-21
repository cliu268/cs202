// Q4 Labyrinth https://xjoi.net/contest/3888
/*
The mouse walks the labyrinth, the labyrinth is the square of the side N, from the upper left corner(entrance )to the 
lower right corner ( exit), it is not allowed to go back, ask for the length of the shortest path and the number of the 
shortest path(N<50)

Input :
The first line is a positive integer n
After n rows per row n number, 1 or 0, 0 can pass, 1 can not

Output:
The number of the shortest path
Shortest path length

Sample input:
5
0 0 0 0 0
0 1 1 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0

Sample output:
1
9

Sampel input2:
15
0 0 0 0 0 1 0 0 0 0 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 1 1 1 1 0 1 1 1 1 1 1 0
0 0 1 1 1 1 1 0 0 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 1 1 0 0 1 1 1 1
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 0

Sample output2:
12
29

time limit: 1000  memory limit: 65536
*/
// DFS solution can be found in cs201 hw4 q1.cpp
// https://github.com/cliu268/cs201/blob/main/hw4/q1.cpp
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int numpath = 0;
int shortest = 0;

void solve(vector<vector<int>> &maze, int row, int col, int len) {
    maze[row][col] = 1;
    if (row == maze.size() - 1 && col == maze.size() - 1) {
        if (len == shortest) {
            numpath += 1;
        } else if (shortest == 0 || len < shortest) {
            shortest = len;
            numpath = 1;
        }
        maze[row][col] = 0;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int x = row + dx[i];
        int y = col + dy[i];
        if (x < 0 || y < 0 || x >= maze.size() || y >= maze.size() || maze[x][y] == 1) {
            continue;
        }
        solve(maze, x, y, len+1);
    }
    maze[row][col] = 0;
}

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> maze(n);
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (int j = 0; j < n; j++) {
            cin >> row[j];
        }
        maze[i] = row;
    }
    solve(maze, 0, 0, 1);
    cout << numpath << '\n';
    cout << shortest << '\n';
    return 0;
}