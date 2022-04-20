// Q3 Shortest Path of Pawn
/*
Description:
Please calculate the least number of steps a pawn moves from one position to another, using the fact that a pawn can 
move north, south, east or west with either 1 or two steps.

Input:
The first line is an integer n, representing one n*n chess board (x is 0 to n-1, y is 0 to n-1). 1 <= n <= 300.
For the next two lines, each line contains two integers representing the start position and the end position. 

Output:
A single integer representing the fewest number of moves.

Sample input:
100
0 0
1 1

Sample output:
2
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dx[8] = {0, 0, 1, -1, 0, 0, 2, -2};
int dy[8] = {1, -1, 0, 0, 2, -2, 0, 0};

int main(void) {
    int n;
    cin >> n;
    pair<int, int> start_pos, end_pos;
    map<pair<int, int>, int> fwd_visited, bkw_visited;
    queue<pair<int,int>> fq, bq;
    cin >> start_pos.first >> start_pos.second >> end_pos.first >> end_pos.second;
    if (start_pos == end_pos) {
        cout << 0 << endl;
        return 0;
    }
    fwd_visited[start_pos] = 0;
    bkw_visited[end_pos] = 0;
    fq.push(start_pos);
    bq.push(end_pos);

    while (!fq.empty() && !bq.empty()) {
        // fwd BFS
        pair<int, int> curr_pos = fq.front(), next_pos;
        fq.pop();
        for (int i = 0; i < 8; i++) {
            next_pos = curr_pos;
            next_pos.first += dx[i];
            next_pos.second += dy[i];
            if (next_pos.first < 0 || next_pos.first >= n || next_pos.second < 0 || next_pos.second >= n) continue;
            if (fwd_visited.count(next_pos) != 0) continue;
            if (bkw_visited.count(next_pos) != 0) {
                cout << fwd_visited[curr_pos] + 1 + bkw_visited[next_pos] << endl;
                return 0;
            }
            fwd_visited[next_pos] = fwd_visited[curr_pos] + 1;
            fq.push(next_pos);
        }

        // bkw BFS
        curr_pos = bq.front();
        bq.pop();
        for (int i = 0; i < 8; i++) {            
            next_pos = curr_pos;
            next_pos.first += dx[i];
            next_pos.second += dy[i];
            if (next_pos.first < 0 || next_pos.first >= n || next_pos.second < 0 || next_pos.second >= n) continue;
            if (bkw_visited.count(next_pos) != 0) continue;
            if (fwd_visited.count(next_pos) != 0) {
                cout << bkw_visited[curr_pos] + 1 + fwd_visited[next_pos] << endl;
                return 0;
            }
            bkw_visited[next_pos] = bkw_visited[curr_pos] + 1;
            bq.push(next_pos);
        }        
    }
    cout << "CANNOT REACH THE END!!!" << endl;
    return 0;
}