// D. The shortest path of the maze
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=12430&fragments=28880&problemId=9912
/*
Time Limit: 1s    Memory Limit: 64M
Problem description
Given a maze of size n * m, the maze is composed of '.' and '#'. You can move one step to the adjacent upper, lower, left and right grid.
Please find out the minimum number of steps required from the start grid "S" to the end grid "G". (It guarantees at least one path)

Input
The first line have two integers n and m. (2≤n,m≤200)
The next n lines represents the maze. (Including one 'S' and one 'G').

Output
An integer, indicating the minimum steps.

Sample input
6 7
#S#####
#...#.#
#.#.#.#
#.#...G
#...#.#
#######

Sample output
8
*/
#include<bits/stdc++.h>
using namespace std;

struct point{
    int x, y, s;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void){
    int n, m;
    int sx, sy, ex, ey;
    cin >> n >> m;
    vector<vector<int>> maze;
    vector<vector<bool>> visited(n, vector<bool>(m, 0));

    for(int i=0; i<n; i++){
        string row;
        cin >> row;
        vector<int> line(m);
        for(int j=0; j<m; j++){
            if(row[j]=='#'){
                line[j]=1;
            }
            if(row[j]=='.'){
                line[j]=0;
            }
            if(row[j]=='S'){
                line[j] = 0;
                sx = i;
                sy = j;
            }
            if(row[j]=='G'){
                line[j] = 0;
                ex=i;
                ey=j;
            }
        }
        maze.push_back(line);
    }

    queue<point> q;
    q.push({sx, sy, 0});
    visited[sx][sy] = 1;

    while(!q.empty()){
        point pp = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int a = pp.x + dx[i];
            int b = pp.y + dy[i];
            if(a>=0 && a<n && b>=0 && b<m && maze[a][b]==0 && visited[a][b]==0){
                if(a==ex && b==ey){
                    cout << pp.s + 1 << endl;
                    return 0;
                }
                else{
                    visited[a][b]=1;
                    q.push({a, b, pp.s+1});
                }
            }
        }
    }

}