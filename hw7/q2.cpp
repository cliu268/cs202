// Q2 Chess Game
/*
Description：
There are 8 black chesses and 8 white chesses on a 4x4 chessboard. The 2 chesses are "neighboring" if their positions share a 
common edge. The rule to make a move is to swap the 2 "neighboring" chesses.
Given an initial chessboard state and an end state, please find out the minimum moves required to change the initial state to 
the end state.

Input format：
First 4 lines, 4 digits (1/0) per line, presenting the initial state;
Then an empty line;
Followed by 4 lines presenting the end state

Output format：
A integer, the minimum moves required to change the initial state to the end state.

Sample input 1：
1111
0000
1110
0010

1010
0101
1010
0101

Sample output 1：
4

Sample input 2：
1010
0010
1111
0010

0100
1011
0110
0101

Sample output 2：
6
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
using namespace std;

struct pos {
    bitset<16> chessboard;
    int counter;
};
int dx[4] = {-4, -1, 1, 4};
map<unsigned long, bool> visited;

int main() {
    string in, out;
    for (int i=0; i<4; i++) {    
        string s;
        cin>>s;
        in += s;
    }
    bitset<16> start = bitset<16>(in, 0, 16, '0', '1');

    for (int i=0; i<4; i++) {
        string s;
        cin>>s;
        out += s;
    }
    bitset<16> result = bitset<16>(out, 0, 16, '0', '1');

    // cout << start << endl;
    // cout << result << endl;

    queue<pos> q;
    visited[start.to_ulong()]=true;
    q.push({start, 0});

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();
        if (cur.chessboard == result) {
            cout << cur.counter << endl;
            return 0;
        }
        for (int i = 0; i < 16; i++) {
            if (cur.chessboard[i] == result[i]) continue;
            for (int j = 0; j < 4; j++) {
                pos next = cur;
                int index = i;
                index += dx[j];
                if (index < 0 || index >= 16) continue;
                if (i % 4 == 0 && index == i-1) continue;
                if (i % 4 == 3 && index == i+1) continue;                
                if (next.chessboard[index] == next.chessboard[i]) continue;
                next.chessboard.flip(i);
                next.chessboard.flip(index);
                if (visited.count(next.chessboard.to_ulong())) {
                    next.chessboard.flip(i);
                    next.chessboard.flip(index);
                    continue;
                } else {
                    visited[next.chessboard.to_ulong()] = true;
                    next.counter++;
                    q.push(next);
                }
            }
        }
    }
    return 0;
}