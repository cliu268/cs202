// Q3 Traversal
/*
Time limit：1s   Space limit：128M

Problem description：
Given the starting cell of a knight on a chess board, compute the minimum number of steps for the knight to traverse each 
chessboard cell.

Input format：
n, m, r, c
Four numbers in a line. First two represent board's dimsnions in numbers of cells. Last two integers are the coordinates 
of the knight's starting cell. The cell coordinate starts from 1.

Output format：
An matrix, n rows and m columns, of integers. Each integer represents the minimum number of steps for the knight to reach 
the chessboard cell. Print out -1 if there's no way for the knight to reach the cell.

The print out format of each number is left-justified, of width 5. In C++, you can use

printf("%-5d", integer_to_print);

where "-" in the format string ("%-5d") means being left justified.

Sample input：
3 3 1 1

Sample output：
0    3    2    
3    -1   1    
2    1    4    

Note that in this example, the horse's starting cell is (1,1), therefore it takes 0 steps to reach the starting cell.
*/
// same as cs201 hw4 q3 https://github.com/cliu268/cs201/blob/main/hw4/q3.cpp
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dx[8] = {1, 2, -1, -2, 1, -2, -1, 2};
int dy[8] = {2, 1, -2, -1, -2, 1, 2, -1};
vector<vector<int>> chessboard;
struct point {
    int x, y, l;
    point(int a, int b, int c) : x(a), y(b), l(c) {}
};
queue<point> q;

int main(void) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++) {
        vector<int> row(m, -1);
        chessboard.push_back(row);
    }
    chessboard[r-1][c-1] = 0;
    q.push(point(r-1, c-1, 0));
    while (!q.empty()) {
        point current = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            point next = current;
            next.x += dx[i];
            next.y += dy[i];
            next.l += 1;
            if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;
            if (chessboard[next.x][next.y] != -1) continue;
            chessboard[next.x][next.y] = next.l;
            q.push(next);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%-5d", chessboard[i][j]);
        }
        printf("\n");
    }
    return 0;
}