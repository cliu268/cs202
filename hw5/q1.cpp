// Q1 Minimum turning path https://xjoi.net/contest/3917
/*
Time limit：1s  Memory limit：512M

Description：
Given a map, please find the least times of making turns from the starting point to the destination, if no accessible road,output -1.

Input：
The first line contains n and m，which are rows and columns.
Next describe the n*m matrix. 0 means ok to go, 1 means not.
Next input the position of the starting point and destination.

Output：
output the answer

Sample input 1：
5 7
1 0 0 0 0 1 0
0 0 1 0 1 0 0  
0 0 0 0 1 0 1  
0 1 1 0 0 0 0  
0 0 0 0 1 1 0
1 3 1 7

Sample output 1：
5

Sample input 2:
6 2
1 1 
1 1 
1 1 
0 1 
1 1 
0 1 
4 1 4 1

Sample output 2:
0

Note：
2<=n,m<=100
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n, m, sx, sy, ex, ey, ans = -1;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(vector<vector<int>> &maze, int x, int y, int count, int dir) {
    if (ans != -1 && count >= ans) return; // pruning here 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || maze[nx][ny] == 1) continue;
        if (dir != -1 && dir != i) count++;
        maze[nx][ny] = 1;       
        if (nx == ex && ny == ey) {
            if (ans == -1) ans = count;
            else ans = min(ans, count);
        }
        dfs(maze, nx, ny, count, i);
        if (dir != -1 && dir != i) count--;
        maze[nx][ny] = 0;
    }
}

int main(void) {
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;
    if (sx == ex && sy == ey) {
        ans = 0;
    } else {
        dfs(maze, sx, sy, 0, -1);
    }
    cout << ans << endl;
    return 0;
}

// BFS solution with min cost from week5 class is NOT a solution
// WHY ?? because we want to find min number of turns NOT distance
// this does not fit in to layer by layer analysis
// DO DFS to find one solution quickly as baseline and compare ALL
// and you can now do pruing that is important
