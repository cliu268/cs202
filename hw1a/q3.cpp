// C. Counting Rooms
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6335&fragments=10853&problemId=14066&pattern=0
/*
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×m squares, and each square 
is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

Output
Print one integer: the number of rooms.

Constraints 1≤n,m≤1000

Example Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> maze;
int a=0;
int n, m;

void floodfill(int x, int y){
  
  if (x<0 || x>=n || y<0 || y>=m){ 
    return;
  }
  
  if (maze[x][y] == 1 || maze[x][y] == -1){
    return;
  }

  maze[x][y] = -1;

  floodfill(x-1, y); //up
  floodfill(x+1, y); //down
  floodfill(x, y-1); //left
  floodfill(x, y+1); //right

}

int main() {

  cin >> n >> m;
  for(int i=0; i<n; i++){
    string input;
    cin >> input;
    vector<int> row(m);
    for(int j=0; j<m; j++){
      if(input[j]=='.'){
        row[j] = 0;
      }
      else if(input[j]=='#'){
        row[j] = 1;
      }
    }
    maze.push_back(row);
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(maze[i][j]==0){
            floodfill(i, j);
            a++;
        }
    }
  }

  cout << a << endl;
}