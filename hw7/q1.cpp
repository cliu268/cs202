// Q1 Maze https://xjoi.net/contest/4007
/*
Description
Given a maze.There are some obstacles cannot be passed in the maze,please calculate the ways you can move from the top left 
corner to the bottom right.(One position can not go twice)

Input
The first line contains two integers n,m representing the size of the maze.  1<=n,m<=6
The next n lines,each line contains m characters,representing the maze.
# represents the obstacle
* represents the position which you can go
the top left corner and the bottom right is "*"

Output
An integer.

Sample Input1
5 6
*****#
*###*#
*###*#
*###*#
******

​Sample Output1
2

Sample Input2
6 6
******
******
******
******
******
******

​Sample Output2
1262816
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
using namespace std;

bitset<6> maze[6];
bitset<6> visited[6];
int n, m;
int sx, sy, ex, ey, answer = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    if (visited[x][y]) {
        return false;
    }
    if (maze[x][y]) {
        return false;
    }
    return true;
}

void dfs(int x, int y) {
    if (!isValid(x, y)) return;  // either check valid condition here or inside for loop below
    if (x == ex && y == ey) {
        answer++;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        // if (!isValid(nx, ny)) continue;  // either check valid condition here or outside in dfs()    
        dfs(nx, ny);
    }
    visited[x][y] = false;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        maze[i] = bitset<6>(s, 0, m, '*', '#');
    }
    sx = 0, sy = m-1, ex = n-1, ey = 0;
    dfs(sx, sy);
    cout << answer << endl;
    return 0;
}