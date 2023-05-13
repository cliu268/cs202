// A. KFC date
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6608&fragments=12065&problemId=3586
/*
Time Limit：0.2s  Memory Limit：32M
Description:
As the summer holiday draws near, you and your friend plan to eat at KFC. But on the map there are many KFC's so you should come up with a 
way to choose one. The way is: Calculate the distances from one KFC to your and your friend's home, if the sum of the distances is the least 
that KFC will be chosen. 

Input:
The first line contains two integers n, m.
The next are n lines. Each line has m characters represent the map. 1 <= n, m <= 200
'@' is your position
'#' means an obstacle
'.' means there is a way you can go
'F' means KFC
'&' means the position of your friend.
'.', 'F', '@' and '&': you can go through all these positions.

Output
If you can find a way to get some KFC sites, output the least distance in which you guys will tavele from each one's home to that KFC. 
Otherwise output "Meeting cancelled".

Sample Input1
4 4 
@.#F 
.... 
.#.. 
F..&

​Sample Output1
6
 
Sample Input2
4 4 
&.#F 
.... 
.#.. 
F#.@

​Sample Output2
8

Hint: Meeting Cancelled means that there is no KFC site satisfying the conditions.
*/
#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
    int s;
};

int n, m, mx, my, fx, fy;
vector<vector<int>> maze;
vector<vector<bool>> visited;
queue <point> q;
map <pair<int, int>, int> me;
map <pair<int, int>, int> fr;

int ans=0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(map<pair<int,int>, int> &pp){
    while(!q.empty()){
        point p = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int x= p.x + dx[i];
            int y= p.y + dy[i];

            if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==0 && maze[x][y]==0){
                visited[x][y]=1;
                if(pp.find(make_pair(x,y))!=pp.end()){
                    pp[make_pair(x,y)] += p.s +1;
                }
                q.push({x, y, p.s+1});
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string input;
        cin >> input;
        vector<int> row(m);
        vector<bool> v(m, false);
        for(int j=0; j<m; j++){
            if(input[j]=='@'){
                row[j] = 0;
                mx=i;
                my=j;
            }
            if(input[j]=='.'){
                row[j]=0;
            }
            if(input[j]=='#'){
                row[j]=1;
            }
            if(input[j]=='&'){
                row[j]=0;
                fx=i;
                fy=j;
            }
            if(input[j]=='F'){
                row[j]=0;
                me[make_pair(i,j)]= 0;
                fr[make_pair(i,j)]= 0;
            }
        }
        maze.push_back(row);
        visited.push_back(v);
    }

    q.push({mx, my, 0});
    visited[mx][my]=1;
    bfs(me);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }    

    q.push({fx, fy, 0});
    visited[fx][fy] = 1;
    bfs(fr);

    for(auto& x : me){      
        if(x.second!=0 && fr[x.first]!=0){
            if(ans==0){
                ans = x.second + fr[x.first];
            }
            else{
                ans = min(ans, x.second + fr[x.first]);
            }
        }
    }

    if(ans==0){
        cout << "Meeting cancelled" << endl;
    }
    else{
        cout << ans << endl;
    }
}