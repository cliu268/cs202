// D. Weights of Subtrees
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6611&fragments=12073&problemId=9501
/*
Time Limit: 1s    Memory Limit: 500M
Description:
With a tree whose root is 1, output the weight of each node. Weight of a node is defined as the total number of nodes of the subtree that 
take the node as the root.

Input format:
The first line contains n, it represents the number of nodes. (1≤n≤100000)
Following by n-1 lines, each containing 2 integers x and y, represents that x and y are connected.

It's guaranteed that the input is a valid tree.

Output Format:
Output n lines. Each line has one integer. the i-th line represents the weight of the i-th node.

Sample Input:
6
2 1
2 3
2 4
2 5
6 5

Sample Output:
6
5
1
1
2
1
*/
// #include <bits/stdc++.h>
// using namespace std;

// int n;
// vector<vector<int>> adj(1E5+1);
// vector<bool> visited(1E5+1);
// vector<int> ans(1E5+1, 1);
// void dfs(int x, int prev) {
//     int bruh=0;
//     visited[x]=true;
//     for (auto i : adj[x]) {
//         if (visited[i]) {
//             if (i==prev) {
//                 continue;
//             }
//             bruh+=ans[i];
//             continue;
//         }
//         visited[i]=true;
//         dfs(i, x);
//         bruh+=ans[i];
//     }
//     ans[x]=bruh+1;
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
//     dfs(1, 1);
//     for (int i=1; i<=n; i++) {
//         cout<<ans[i]<<"\n";
//     }
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> nodes[100001];
vector<int> answer(100001, 0);
vector<bool> visited(100001, false);

void dfs(int x) {
    for (int i : nodes[x]) {            
        if(visited[i] == false) {
            visited[i] = true;
            dfs(i);
            answer[x] += answer[i];
        }
    }   
    answer[x] += 1;
}

int main(void){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("q11.in", "r", stdin);
    //freopen("q11.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    visited[1] = true;
    dfs(1);

    for(int i=1; i <= n; i++){
        cout << answer[i] << "\n";
    }
    return 0;
}