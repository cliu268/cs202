// Q2 Pioneers
/*
Time limit：1s   Memory limit：512M

Description：
There is an army group represented by a N*M matrix. Each unit contains a member of the army. Some of them were infected 
with the plague, and every hour they spread the plague to people around them until all the people are infected. Now you 
know the exact location of the infection source and your task is to calculate the time it takes for the army leaders to 
get infected.

Input：
The first line：four integers N，M，A，B --- the N*M matrix, the number of infection sources and the number of army leaders.
The next A lines: each line contaisn two integers x and y, which means the infection source is in the x row y column.
The next B lines: each line contaisn two integers x and y, which describe the location of the leaders.

Output：
The first to the B-th line: each line contains an integer, which is the time for the leader to get infected. The sequence 
of output should be the same as input. If someone is the infection source, then his time to get infected should be 0.

Sample input 1：
5 4 2 3
1 1
5 4
3 3
5 3
2 4

Sample output 1：
3
1
3

Note：
1<=M,N<=500
1<=A,B<=100000
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
// 4 ways to traverse
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void) {
    // freopen("q2.in", "r", stdin);
    // freopen("q2.out", "w", stdout);
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    vector<vector<int>>  map(n, vector<int>(m, -1));
    vector<pair<int, int>> armyLeader(b);

    for (int i = 0; i < a; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        map[x][y] = 0;
        q.push({x, y});
    }
    for (int i = 0; i < b; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        armyLeader[i].first  = x-1;
        armyLeader[i].second = y-1;
    }

    // BFS here
    while (!q.empty()) {
        pair<int, int> p = q.front();
        int x = p.first, y = p.second, step = map[x][y];
        q.pop();
        step += 1;
        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] != -1) {
                continue;
            }
            map[nx][ny] = step;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < b; i++) {
        printf("%d\n", map[armyLeader[i].first][armyLeader[i].second]);
    }    
    return 0;
}