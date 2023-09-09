// C. Find the father
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6611&fragments=12073&problemId=9500
/*
Description：
Given a tree whose root is 1. Output the father of each non-root vertex.

Input：
The 1st line: an integer n, which is the number of vertices
The next n-1 line: each line contains two integers x and y, which means an edge that connects x and y. It is guaranteed that the input graph 
is a tree.

Output：
Output n-1 lines. Each line contains an integer. The i-th line is the father of vertex i+1.

Sample input 1：
6
2 1
2 3
2 4
2 5
6 5

Sample output 1：
1
2
2
2
5

Note：1<=n<=100000
*/
// DFS version
// #include <bits/stdc++.h>
// using namespace std;

// int n;
// vector<vector<int>> adj(1E5+1);
// vector<int> p(1E5+1);
// vector<bool> visited(1E5+1);
// void dfs(int x, int prev) {
//     p[x]=prev;
//     for (auto i : adj[x]) {
//         if (visited[i]) {
//             continue;
//         }
//         visited[i]=true;
//         dfs(i, x);
//     }
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n;
//     for (int i=0; i<n-1; i++) {
//         int a, b; cin>>a>>b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     visited[1]=true;
//     dfs(1, 1);
//     for (int i=2; i<=n; i++) {
//         cout<<p[i]<<"\n";
//     }
// }

// BFS version
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> node[n+1];
    vector<int> answer(n+1, 0);

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    answer[1]=-1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        //int s = node[x].size();
        //for(int i=0; i<s; i++){
        for (auto i : node[x]) {            
            if(answer[i]==0){
                answer[i] = x;
                q.push(i);
            }  
        }
    }

    for(int i=2; i<n+1; i++){
        cout << answer[i] << "\n";
    }
}