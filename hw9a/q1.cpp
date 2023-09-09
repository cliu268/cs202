// A. Message Route
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6612&fragments=12072&problemId=14117
/*
Time limit: 1.00 s
Memory limit: 512 MB
Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, 
what is the minimum number of computers on such a route.

Input
The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,…,n. Uolevi's computer 
is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.

Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such 
a route. You can print any valid solution. If there are no routes, print "IMPOSSIBLE".

Constraints: 2≤n≤10^5, 1≤m≤2⋅10^5, 1≤a,b≤n

Example Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("q11.in", "r", stdin);
    // freopen("q11.out", "w", stdout);
    int n, m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for (int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1, false);
    vector<int> p(n+1, 0);
    p[1]=1; visited[1]=true;
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        if (curr==n) {
            break;
        }
        for (auto i : adj[curr]) {
            if (!visited[i]) {
                p[i]=curr;
                q.push(i);
                visited[i]=true;
            }
        }
    }
    vector<int> ans;
    int curr=n;
    while (curr!=0) {
        ans.push_back(curr);
        if (p[curr]==0) {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if (curr==1) {
            break;
        }
        curr=p[curr];
    }
    cout<<ans.size()<<"\n";
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
        cout<<i<<" ";
    }
}
// #include<bits/stdc++.h>
// #include <iostream>
// #include <stdio.h>
// using namespace std;

// vector<int> nodes[100000];
// vector<bool> visited(100000, false);

// struct point{
//     vector<int> path;
//     int s;
// };

// int main(void){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     // freopen("q1.in", "r", stdin);
//     // freopen("q1.out", "w", stdout);    
//     int n, m;
//     cin >> n >> m;

//     for(int i=0; i<m; i++){        
//         int a, b;
//         cin >> a >> b;
//         nodes[a].push_back(b);
//         nodes[b].push_back(a);
//     }

//     queue<point> q;
//     vector<int> path;
//     path.push_back(1);
//     q.push({path, 1});
//     visited[1]=true;

//     while(!q.empty()){
//         point pp = q.front();
//         q.pop();
//         int curr= pp.path[pp.path.size()-1];
// // cout << "whaaaa curr " << curr << endl;       
// // for (int x: nodes[curr]) cout << x << " ";
// // cout << endl; 
//         for(int i=0; i<nodes[curr].size(); i++){
//             if(visited[nodes[curr][i]] == false){
//                 if(nodes[curr][i]==n){
//                     cout << pp.s + 1 << endl;
//                     for(int j=0; j<pp.path.size(); j++){
//                         cout << pp.path[j] << " ";
//                     }
//                     cout << n << endl;
//                     return 0;
//                 }
//                 visited[nodes[curr][i]] = true;
//                 vector<int> temp = pp.path;
//                 temp.push_back(nodes[curr][i]);
// // for (int x: temp) cout << x << " ";
// // cout << endl;                
//                 q.push({temp, pp.s + 1});
//             }
//         }
//     }
//     cout << "IMPOSSIBLE" << endl;
// }