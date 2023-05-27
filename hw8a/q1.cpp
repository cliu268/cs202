// A. Knight Moves
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=12430&fragments=28880&problemId=3330
/*
Time Limit：0.2s   Memory Limit：32M
Description
Please calculate the minimum number of moves needed for a knight to reach one point from another on a n*n chessboard.

Input
The first line is an integer n, representing a n*n chess board. (1≤n≤300)
The next two lines, each line contains two integers x and y, representing the start position and the end position. (0≤x,y≤n−1)
 
Output
The minimum number of moves.
 
Sample Input
100
0 0
30 50

​Sample Output
28
*/
#include<bits/stdc++.h>
using namespace std;

struct point{
    int x, y, s;
};

int dx[8] = { 1,  2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2,  2,  1, -1, -2};

int main(){
    int n;
    int sx, sy, ex, ey;
    cin >> n;
    cin >> sx >> sy;
    cin >> ex >> ey;

    queue<point> q;
    q.push({sx, sy, 0});

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    visited[sx][sy]=true;

    while(!q.empty()){
        point pp = q.front();
        q.pop();
        for(int i=0; i<8; i++){
            int a = pp.x + dx[i];
            int b= pp.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= n || visited[a][b]) continue;
            if(a==ex && b==ey){
                cout << pp.s + 1 << endl;
                return 0;
            }
            visited[a][b] = true;
            q.push({a, b, pp.s+1});
        }
    }
    return 0;

}