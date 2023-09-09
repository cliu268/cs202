// C. Catch the Cow
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6613&fragments=12074&problemId=8115
/*
Description:
Farmer John has been informed of the location of the escaped cow and hopes to catch it. He starts at point N (0≤N≤100,000) on the number 
axis, and the cow is at point K (0≤K≤100,000) on the same number axis. Farmer John has two modes of transportation: walking and teleportation.

*Walking: John can move from any point X to X-1 or X+1 point in one minute

*Transport: John can move from any point X to point 2*X in one minute.

If the cow doesn't move at all, how long will it take for Farmer John to catch the cow (get to the cow's location)?

Input format:
One line: Two integers separated by a space: N and K.

Output format:
One line: The minimum time (in minutes) required for Farmer John to catch the cow.

Sample input:
5 17

Sample output:
4

Hint:
Solution for sample data is: 5-10-9-18-17. Thus it needs 4 minutes by minium.
*/
#include<bits/stdc++.h>
using namespace std;

int w[2] = {-1, 1};
int t[1] = {2};

int main(){
    int n, k;
    cin >> n >> k;

    set<int> visited;
    queue<pair<int, int>> q;

    q.push(make_pair(n,0));
    visited.insert(n);

    while(!q.empty()){
        pair<int, int> pp = q.front();
        q.pop();
        for(int i=0; i<2; i++){
            if(visited.count(pp.first+w[i])!=1 && pp.first+w[i]>=0 && pp.first+w[i]<=100000){
                if(pp.first+w[i]==k){
                    cout << pp.second +1 << endl;
                    return 0;
                }
                visited.insert(pp.first+w[i]);
                q.push(make_pair(pp.first+w[i], pp.second+1));
            }
        }
        for(int i=0; i<1; i++){
            if(visited.count(pp.first*t[i])!=1 && pp.first*t[i]>=0 && pp.first*t[i]<=100000){
                if(pp.first*t[i]==k){
                    cout << pp.second +1 << endl;
                    return 0;
                }
                visited.insert(pp.first*t[i]);
                q.push(make_pair(pp.first*t[i], pp.second+1));
            }
        }
    }
}