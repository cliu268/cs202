// Q2 Chess Eight
/*
Time：1s.   Memory：512M

Description：
There are 8 chesses on a 3x3 chessboard, each marked with a number from 1 to 8. There's one space on the chessboard marked as 0. 
The chess around the space can be moved to the space.

Given an initial layout (initial configuration) and target layout (to simplify, fix it to 123804765, will explain in the next 
paragraph), find the least number of the moves required to change the configuration from the initial state to the end state.

The state 123804765 means the following layout on the chessboard
123
804
765

Input format:
A string of 9 digits representing the initial state

Output format:
One line, the least number of moves required to change from the initial state to the end state. If there's no way, output 0.

Sample input:
283104765

Sample output:
4

Sample input 2:
837465120

Sample output 2:
26
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(void) {
    string chessboard;
    cin >> chessboard;
    string target = "123804765";
    if (chessboard == target) {
        cout << 0 << endl;
        return 0;
    }
    int dx[4] = {-3, -1, 1, 3};
    map<string, int> fwd_visited, bkw_visited;
    queue<string> fq, bq;

    fq.push(chessboard);
    bq.push("123804765");
    fwd_visited[chessboard] = 0;
    bkw_visited["123804765"] = 0;

    while (!fq.empty() && !bq.empty()) {
        // fwd BFS
        string current_state = fq.front();
        fq.pop();
        int zero_pos = current_state.find('0');
        for (int i = 0; i < 4; i++) {
            if (dx[i] == -3 && zero_pos < 3) continue;
            if (dx[i] ==  3 && zero_pos > 5) continue;
            if (dx[i] == -1 && (zero_pos == 0 || zero_pos == 3 || zero_pos == 6)) continue;
            if (dx[i] ==  1 && (zero_pos == 2 || zero_pos == 5 || zero_pos == 8)) continue;
            string next_state = current_state;
            swap(next_state[zero_pos], next_state[zero_pos+dx[i]]);
            if (fwd_visited.count(next_state) != 0) continue;
            if (bkw_visited.count(next_state) != 0) {
                cout << fwd_visited[current_state] + 1 + bkw_visited[next_state] << endl;
                return 0;
            }
            fwd_visited[next_state] = fwd_visited[current_state] + 1;
            fq.push(next_state);
        }

        // bkw BFS
        current_state = bq.front();
        bq.pop();
        zero_pos = current_state.find('0');
        for (int i = 0; i < 4; i++) {
            if (dx[i] == -3 && zero_pos < 3) continue;
            if (dx[i] ==  3 && zero_pos > 5) continue;
            if (dx[i] == -1 && (zero_pos == 0 || zero_pos == 3 || zero_pos == 6)) continue;
            if (dx[i] ==  1 && (zero_pos == 2 || zero_pos == 5 || zero_pos == 8)) continue;
            string next_state = current_state;
            swap(next_state[zero_pos], next_state[zero_pos+dx[i]]);
            if (bkw_visited.count(next_state) != 0) continue;
            if (fwd_visited.count(next_state) != 0) {
                cout << bkw_visited[current_state] + 1 + fwd_visited[next_state] << endl;
                return 0;
            }
            bkw_visited[next_state] = bkw_visited[current_state] + 1;
            bq.push(next_state);
        }        
    }
    cout << 0 << endl;
    return 0;
}