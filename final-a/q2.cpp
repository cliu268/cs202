// B. Chess game
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6613&fragments=12074&problemId=7906
/*
Time：1s   Memory：512M
Description：
There are 8 black chess pieces and 8 white chess pieces on a 4x4 chessboard. 2 pieces are "neighboring" if their positions share a common edge. 
You may sway any two neighboring pieces. 
Given an initial chessboard state and an end state, please find out the minimum moves required to change the initial state to the end state.

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
// also see hw7 q2.cpp
#include<bits/stdc++.h>
using namespace std;

int d[4] = {-4, -1, 1, 4};

int main(){
    string start;
    string end;

    for(int i=0; i<4; i++){
        string s;
        cin >> s;
        start +=s;
    }
    for(int i=0; i<4; i++){
        string s;
        cin >> s;
        end +=s;
    }

    queue<pair<string, int>> q;
    map<string, int> visited;
    q.push(make_pair(start, 0));
    visited[start]=1;

    while(!q.empty()){
        pair<string, int> pp = q.front();
        q.pop();
        string cur = pp.first;
        // cout << cur << " " << q.size() << endl;

        if(cur == end){
            cout << pp.second << endl;
            return 0;
        }

        for(int i=0; i<16; i++){
            if(cur[i]==end[i]){
                continue;
            }
            else{
                for(int j=0; j<4; j++){
                    if(d[j]+i < 0 || d[j]+i >15){
                        continue;
                    }
                    if((i==0 || i==1 || i==2 || i==3) && j==0){
                        continue;
                    }
                    else if((i==0 || i==4 || i== 8 || i==12) && j==1){
                        continue;
                    }
                    else if((i==3 || i==7 || i==11 || i==15) && j==2){
                        continue;
                    }
                    else if((i==12 || i==13 || i==14 || i==15) && j==3){
                        continue;
                    }
                    string next = cur;
                    if(next[i]==next[d[j]+i]){
                        continue;
                    }
                    swap(next[i], next[d[j]+i]);
                    // cout << next << endl;

                    if(visited.find(next)!=visited.end()){
                        continue;
                    }
                    else{
                        visited[next]=1;
                        q.push(make_pair(next, pp.second +1));
                    }
                    
                }
            }
            
        }
    }
}
