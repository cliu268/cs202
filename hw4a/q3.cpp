// C. Shortest Path
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6607&fragments=12064&problemId=9191&pattern=0
/*
Description
Given an n×n binary matrix, with 0 representing an accessible cell and 1 representing a blocker, please find the shortest path from 
the top left corner with (0, 0) as coordination, to the bottom right corner with (n−1,n−1) as coordination. For each step, you are 
allowed to move only up, down, left, or right. If no path exists, output -1.

Input
The input consists of two parts:
The first line contains an integer n (1≤n≤10), which represents the size of the matrix.
The next n lines each have n numbers, either 0 or 1. A 0 means the cell can be passed through, while a 1 means the cell cannot be 
passed through.

Output
The output should consist of a single integer, representing the length of the shortest path from (0,0) to (n−1,n−1), i.e., the number of 
steps required to reach the destination cell along the shortest path. If no such path exists, output -1.

Sample Input
3
0 0 0
1 0 1
0 0 0

Sample Output
5
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> maze;
vector<vector<bool>> visited;
queue <pair<pair<int, int>,int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(void){
    while(!q.empty()){
        pair<pair<int, int>, int> node = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            pair<int, int> curr = node.first;
            int x= curr.first + dx[i];
            int y= curr.second + dy[i];

            if(x>=0 && x<n && y>=0 && y<n){
                if(visited[x][y]==0){
                    if(maze[x][y]==0){
                        visited[x][y]=1;
                        if(x== n-1 && y==n-1){
                            return node.second + 1;
                        }
                        q.push(make_pair(make_pair(x,y), node.second+1));
                    }
                }
            }
        }
    }
    return -1;
}

int main(void){
    cin >> n;

    for(int i=0; i<n; i++){
        vector<int> row(n);
        vector<bool> v(n, 0);
        for(int j=0; j<n; j++){
            cin >> row[j];
        }
        maze.push_back(row);
        visited.push_back(v);
    }

    q.push(make_pair(make_pair(0,0), 1));
    visited[0][0]=1;
    cout << bfs() << endl;;
}