// D. Letters
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6335&fragments=10853&problemId=9397&pattern=0
/*
[Title Description]
Give a Row × Rol capital letter matrix, the starting position is the upper left corner. You can move up, down, left and right, and can't 
move to the letters that have passed. The question is how many letters you can go through at most.

[data format]
In the first row, enter the number of rows R and columns S of the alphabetic matrix (1 ≤ R, S ≤ 20). Then enter the letter matrix in row R 
and column S.

Output the maximum number of different letters that can be passed.

Sample input:
3 6
HFDFFB
AJHGDH
DGAGEH

Sample output:
6
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> maze;
vector<vector<bool>> visited;
vector<bool> alphabet(26, false);
int a=0, temp=0;
int n, m;

void floodfill(int x, int y){

    a = max(a, temp);
    
    if (x<0 || x>=n || y<0 || y>=m || visited[x][y]){ 
        return;
    }
    
    int index= maze[x][y]-'A';

    if (alphabet[index]){
        return;
    }

    visited[x][y] = true;
    alphabet[index] = true;
    temp++;

    floodfill(x-1, y); //up
    floodfill(x+1, y); //down
    floodfill(x, y-1); //left
    floodfill(x, y+1); //right

    visited[x][y] = false;
    alphabet[index] = false;
    temp--;
}

int main() {

    cin >> n >> m;
    for(int i=0; i<n; i++){
        vector<bool> row(m, false);
        string input;
        cin >> input;
        visited.push_back(row);
        maze.push_back(input);
    }
    
    floodfill(0,0);

    cout << a << endl;
}