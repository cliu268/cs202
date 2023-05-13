// A. Floodfill
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6607&fragments=12064&problemId=7421&pattern=0
/*
Description:
Count how many cells can be reached within a N by N maze, with a start point (x, y). You can move up, down, top-left, bottom-right for 
each one step. 

Input:
Three integers in the first line, representing N, and location of start point (x, y).

Next N lines: each line has N 0/1 separated by space, where 0 represents the position you may fill, and 1 represents the barrier.

Output:
Single integer representing number of cells you can reach.

Sample input:
3 0 0
0 0 0
0 1 0
1 0 1

Sample output:
3

Constraints: 1<=N<=500
*/
#include <bits/stdc++.h>
using namespace std;

int n, sx, sy;
vector<vector<int>> maze;
vector<vector<bool>> visited;
queue <pair<int,int>> q;
int ans=1;
int dx[4] = {-1, 1, -1, 1};
int dy[4] = {0, 0, -1, 1};

void bfs(void){
    while(!q.empty()){
        pair<int, int> pair = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int x = pair.first + dx[i];
            int y = pair.second + dy[i];

            if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == false && maze[x][y] == 0){
                visited[x][y]=1;
                ans++;
                q.push(make_pair(x,y));
            }
        }
    }
}


int main(){
    cin >> n >> sx >> sy;

    for(int i=0; i<n; i++){  
        vector<int> row(n);
        vector<bool> v(n, false);
        for(int j=0; j<n; j++){
            cin >> row[j];
        }
        maze.push_back(row);
        visited.push_back(v);
    }
    visited[sx][sy] = true;
    q.push(make_pair(sx,sy));
    bfs();
    cout << ans << endl;
}