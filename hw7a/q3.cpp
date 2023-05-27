// C. A Strange Auction
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6610&fragments=12068&problemId=8468
/*
A strange auction starts from the highest price w. If no one bids, the price will be dropped by either a or b. Count the total number of 
ways a price can drop from w to p.

Input format
The first line has two positive integers w and p, and the second line has two positive integers a and b.
1≤w, p≤10^6, 2≤a, b≤10000, a is not equal to b.

Output format
The total number of ways.

Input sample
10 3
2 3

Sample output
3

Note: the 3 ways are:
10 - 8 - 6 - 3
10 - 8 - 5 - 3
10 - 7 - 5 - 3
*/
// see midterm q5.cpp
#include <bits/stdc++.h> 
using namespace std;
// typedef long long ll;
int w, p, a, b;
queue<int> q;
map <int, int> visited;
int dx[2];

void dfs(int n){
    if(n==p){
        visited[n] ++;
        return;
    }

    for(int i=0; i<2; i++){
        int next = n - dx[i];
        if(next<p){
            continue;
        }
        else{
            if(visited.count(next)!=0){
                continue;
            }
            else{
                dfs(next);
            }
        }
    }

    visited[n]=visited[n-a] + visited[n-b];
}

int main(){
    cin >> w >> p;
    cin >> a >> b;
    dx[0] = a; dx[1] = b;
    dfs(w);
    cout << visited[w] << endl;
    return 0;
}