// B. Battleship
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6608&fragments=12065&problemId=9431
/*
In the famous game Battleship, a fixed number and shape of ships are placed on a rectangular board, each of which cannot touch the others. 
In this problem, we only consider that boats are rectangular, all boats are rectangles composed of figures. Write a program to find the total 
number of ships placed on the board.

Input
The first line of the input file consists of two integers R and C separated by spaces, 1<=R, C<=1000, these two numbers represent the number 
of rows and columns of the game board respectively. The next R lines each contain C characters, each of which can be either "#" or ".", where 
"#" represents a part of a boat, and "." represents water.

Output
Output one line. If the position of the ships is correct (that is, there are only rectangles on the board that cannot touch each other), 
output the sentence "There are S ships.", where S is the number of ships. If two "#" numbers are adjacent to each other up and down or left 
and right but belong to two different ships, the two ships are said to be in contact with each other, and "Bad placement." is output.

Sample Input 1
6 8
.....#.#
##.....#
##.....#
.......#
#......#
#..#...#

Sample Output 1
There are 5 ships.

Sample Input 2
6 8
......##
##.....#
##.....#
.......#
#......#
#..#...#

Sample Output 2
Bad placement.
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> maze;
vector<vector<bool>> visited;
queue <pair<int,int>> q;
int ans=0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool bfs(int sx, int sy, int ex, int ey){
    int nodes=1;
    while(!q.empty()){
        pair<int, int> pair = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int x= pair.first + dx[i];
            int y= pair.second + dy[i];

            if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==0 && maze[x][y]==0){
                visited[x][y]=1;
                nodes++;
                sx=min(sx, x);
                sy=min(sy,y);
                ex=max(ex, x);
                ey=max(ey,y);
                q.push(make_pair(x,y));
            }
        }
    }
    if((ex-sx+1) * (ey-sy+1) != nodes){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        vector<int> row(m);
        string s;
        cin >> s;
        vector<bool> v(m, 0);
        for(int j=0; j<m; j++){
            if(s[j]=='#'){
                row[j]=0;
            }
            if(s[j]=='.'){
                row[j]=1;
            }
        }
        maze.push_back(row);
        visited.push_back(v);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j]==0 && visited[i][j]==0){
                q.push(make_pair(i,j));
                visited[i][j]=1;
                if(bfs(i, j, i, j)==false){
                    cout << "Bad placement." << endl;
                    return 0;
                }
                ans++;
            }
        }
    }

    cout << "There are " << ans << " ships." << endl;
}