// A. 8-connected
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6613&fragments=12074&problemId=1227
/*
Time Limit：1s   Memory Limit：256M
Description
In a 8-connected zone, you can go from each position to any position in one of 8 directions (up, down, left, right, up left, up right, 
down left, down right) without going over the zone (the blue color).

The picture above contains one 8-connected zone, where you can go from one blue point to any other blue point. 
Given n*m character matrix(the character is no more than two kinds), please calculate how many 8-connected zones are there in the matrix? 

Input
The first line contains two integers n,m.  1<=n,m<=100
The next n lines,each line contains m characters. Character 'W' marks a tile that you can go to.

Output
An integer. 

Sample Input
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

​Sample Output
3
*/
#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main(){
    int n,m;
    cin >> n >> m;
    int ans=0;

    vector<vector<int>> maze;
    vector<vector<bool>> visited;

    for(int i=0; i<n; i++){
        vector<int> row(m);
        string s;
        cin >> s;
        vector<bool> v(m, 0);
        for(int j=0; j<m; j++){
            if(s[j]=='W'){
                row[j]=0;
            }
            if(s[j]=='.'){
                row[j]=1;
            }
        }
        maze.push_back(row);
        visited.push_back(v);
    }

// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//         cout << maze[i][j] << ' ';
//     }
//     cout << endl;
// }

    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]==0 && maze[i][j]==0){
                q.push(make_pair(i,j));
                visited[i][j]=1;
                while(!q.empty()){
                    pair<int, int> pp =q.front();
                    q.pop();
                    for(int k=0; k<8; k++){
                        int x = pp.first + dx[k];
                        int y = pp.second + dy[k];
                        if(x>=0 && x<n && y>=0 && y<m && maze[x][y]==0 && visited[x][y]==0){
                            visited[x][y]=1;
                            q.push(make_pair(x,y));
                        }
                    }
                }
                ans++;
            }
        }
    }

    cout << ans << endl;
}