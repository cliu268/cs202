// Q3 Minimum steps in maze
/*
There's a square-shape map, where 0 means an empty cell that you can pass by, and 1 means a blocker. You are at bottom-right 
corner. You want to go to top-left corner. You can go four directions, up, down, left, right. Please find out how many steps 
in minimum for you to get to top-left corner.

Input 
A total of N+1 rows, the first line is N, followed by a 0-1 matrix with N rows and N columns , 1 means that it can not pass, 
0 means that it can pass (the upper left corner and the lower right corner are 0).

Output :
A total of one number, the minimum number of walking grids.

Sample input:
5
0 1 1 1 1
0 0 1 1 1
1 0 0 0 1
1 1 1 0 1
1 1 1 0 0

Sample output:
9

Data range:
For 100% of the data, N<30.

Time limit:
1000

Memory limit:
65536
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n, ans;
vector<vector<int>> maze;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct point {
    int x, y, l;
    point(int a, int b, int c) : x(a), y(b), l(c) {}
};
queue<point> q;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (int j = 0; j < n; j++) cin >> row[j];
        maze.push_back(row);
    }
    q.push(point(n-1, n-1, 1));
    while (!q.empty()) {
        point current = q.front();
        q.pop();
        if (current.x == 0 && current.y == 0) {
            cout << current.l << endl;
            return 0;
        }        
        for (int i = 0; i < 4; i++) {
            point next = current;
            next.x += dx[i];
            next.y += dy[i];
            next.l += 1;
            //cout << "[x, y, l] == [" << next.x << "," << next.y << "," << next.l << "]" << endl;
            if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= n || maze[next.x][next.y] == 1) {
                continue;
            }
            maze[next.x][next.y] = 1;
            q.push(next);
        }
    }
    return 0;
}