// A. Pouring Wine
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6610&fragments=12068&problemId=1032
/*
Time Limit：1s   Memory Limit：64M

Description:
Given the volume of three cups, but there is no scales/indices on the cups. The first cup is full and the other two are empty. 
Please judge whether you can pour equal amount (that is half of the first cup) of wine into two cups (they are initially empty).

Input:
The volumes of three cups (no more than 150).   

Output:
Output the least steps for you to evenly distribute wine from the first cup to the other two empty cups. Output "NO" if it is impossible 
to accomplish that.

Sample Input:
8 5 3

Sample Output:
7
*/
// also see hw4 q1.cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> cups(3);
    cin >> cups[0] >> cups[1] >> cups[2];
    int half = cups[0] / 2;

    struct point{
        vector<int> cc; int s;
    };

    queue<point> q;
    map<vector<int>, bool> visited;
    map<vector<int>, bool> targets;
    int df[6] = {0, 0, 1, 1, 2, 2};
    int dt[6] = {1, 2, 0, 2, 0, 1};
    targets[{half, half, 0}] = true;
    targets[{half, 0, half}] = true;
    targets[{0, half, half}] = true;

    q.push(point{{cups[0], 0, 0}, 0});
    visited[{cups[0], 0, 0}] = 1;

    while(!q.empty()){
        point pp = q.front();
        q.pop();
        for(int i=0; i<6; i++){
            vector<int> newpp = pp.cc;
            int pour = min(pp.cc[df[i]], cups[dt[i]]-pp.cc[dt[i]]);
            newpp[df[i]] -= pour;
            newpp[dt[i]] += pour;
            if(visited.count(newpp)!=0){
                continue;
            }
            else{
                if(targets.count(newpp)!=0){
                    cout << pp.s + 1 << endl;
                    return 0;
                }
                else{
                    q.push({newpp, pp.s+1});
                    visited[newpp] = 1;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}