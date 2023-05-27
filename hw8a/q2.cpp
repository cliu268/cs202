// B. Pioneers
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=12430&fragments=28880&problemId=8119
/*
Time limit：0.1s   Memory limit：512M 
Description：
There is an army group represented by a N*M matrix. Each unit contains a member of the army. Some of them were infected with the plague, 
and every hour they spread the plague to people around them until all the people are infected. Now you know the exact location of the 
infection source and your task is to calculate the time it takes for the army leaders to get infected.

Input：
The first line：four integers N，M，A，B --- the N*M matrix, the number of infection sources and the number of army leaders.
The next A lines: each line contaisn two integers x and y, which means the infection source is in the x row y column.
The next B lines: each line contaisn two integers x and y, which describe the location of the leaders.

Output：
The first to the B-th line: each line contains an integer, which is the time for the leader to get infected. The sequence of output should 
be the same as input. If someone is the infection source, then his time to get infected should be 0.

Sample input 1：
5 4 2 3
1 1
5 4
3 3
5 3
2 4

Sample output 1：
3
1
3

Note：
1<=M,N<=500
1<=A,B<=100000

Time for leaders to get infected is marked in below picture, using sample input
*/
// also see hw3 q2.cpp
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,  0, 1, -1};
int dy[4] = {1, -1, 0,  0};

int main(void){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    queue<pair<int, int>> q;
    vector<pair<int, int>> leader(b);
    vector<vector<int>> global(n, vector<int>(m, -1));

    for(int i=0; i<a; i++){
        int e, f;
        cin >> e >> f;
        e--;
        f--;
        q.push(make_pair(e, f));
        global[e][f] = 0;
    }

    for(int i=0; i<b; i++){
        pair<int, int> army;
        cin >> army.first >> army.second;
        army.first--;
        army.second--;
        leader[i] = army;
    }
    
    while(!q.empty()){
        pair<int, int> pp = q.front();
        q.pop();
        int steps = global[pp.first][pp.second];
        steps += 1;
        for(int i=0; i<4; i++){
            int u= pp.first + dx[i];
            int v= pp.second + dy[i];
            if (u < 0 || u >= n || v < 0 || v >= m || global[u][v] != -1) continue;
            global[u][v] = steps;
            q.push(make_pair(u, v));
        }
    }

    for(int i=0; i<b; i++){
        //cout << global[leader[i].first][leader[i].second] << endl;
        printf("%d\n", global[leader[i].first][leader[i].second]);
    }

    return 0;

}