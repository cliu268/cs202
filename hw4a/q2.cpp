// B. Pool Counting
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6607&fragments=12064&problemId=8014&pattern=0
/*
Time limit：1   Memory limit：32M
Description
Farmer John has a rectangular field of land with dimensions N×M. Each cell in the land can either be dry land (represented by '0') or 
covered in water (represented by '1'). A cell is considered to be part of a pool if it is completely surrounded by water (including diagonals). 
Pools can be formed by grouping together any connected cells that are surrounded by water. Farmer John needs your help to determine the number 
of distinct pools in his land. Given the grid representation of his land, you must output the number of distinct pools.

Input
The input consists of two integers, N and M, on the first line separated by a single space. Following this are N lines, each containing a 
string of M characters representing the cells of the grid. Each character in the string is either '0' or '1', with no delimiters between 
characters in each line.

Output
The output should consist of a single integer representing the number of distinct pools in the grid.

Sample input：
5 5
10011
10010
11011
01000
11010

Sample output：
3

Constraints: 1 <= N <= 100; 1 <= M <= 100)
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> maze;
vector<vector<bool>> visited;
queue <pair<int,int>> q;
int ans=0;
int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void bfs(){
    while(!q.empty()){
        pair<int, int> pair = q.front();
        q.pop();
        for(int i=0; i<8; i++){
            int x = pair.first + dx[i];
            int y = pair.second + dy[i];

            if(x >= 0 && x < n && y >= 0 && y < m){
                if(visited[x][y] == 0 && maze[x][y] == 1){
                    visited[x][y] = 1;
                    q.push(make_pair(x,y));
                }
            }
        }
    }
}


int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        vector<int> row(m);
        vector<bool> v(m, false);
        string s; cin >> s;
        for(int j=0; j<m; j++){
            if (s[j] == '0') row[j] = 0;
            else row[j] = 1;
        }
        maze.push_back(row);
        visited.push_back(v);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j] == 1 && visited[i][j] == false){
                q.push(make_pair(i,j));
                visited[i][j] = true;
                bfs();
                ans++;
            }
        }
    }

    cout << ans << endl;
}