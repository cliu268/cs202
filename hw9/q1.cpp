// Q1: Topological Sequence https://xjoi.net/contest/4064/problem/1
/*
Time Limit: 1s  Memory Limit: 256M
Description :
Give you a directed acyclic graph (DAG) and asks for its minimal lexicographic topological sequence.

Input :
In the first line enter two integers n,m, indicating the number of points and the number of edges in the graph.
Next m lines contain two integers a, b per line to indicate an edge from a to b

Output :
Output lexicographically smallest topology sequence

Sample input:
6 8
1 3
2 3
2 4
2 5
3 4
3 6
4 6
5 4

Sample output:
1 2 3 5 4 6

Sample input2:
10 12
1 2
1 8
2 10
3 5
3 9
4 8
4 7
5 8
8 10
7 6
7 10
9 10

Sample ouput2:
1 2 3 4 5 7 6 8 9 10

Note: 1<=n<=1000,1<=m<=10000
Hint: use std::set or std::priority_queue to implement an output order other than FIFO.
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

// Helper function for debug
void Print2DVector(vector<vector<int>> &vec2d) {
    for (auto &vec : vec2d) {
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// Helper function for debug
void PrintVector(vector<int> &vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void TopologicalSort(vector<vector<int>> &graph) {
    vector<int> indegree(graph.size(), 0);
    priority_queue <int, vector<int>, greater<int>> q; 
    //queue<int> q;
    vector<int> solution;

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            // iterate over all edges, find the degrees
            indegree[j] += graph[i][j];
        }
    }

    // enqueue all nodes with indegree 0
    for (int i = 0; i < graph.size(); i++) {
        // 202B exercise
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // remove one node after the other
    while (q.size() > 0) {
        int currentNode = q.top();
        q.pop();
        solution.push_back(currentNode);
        for (int j = 0; j < graph[currentNode].size(); j++) {
            if (graph[currentNode][j] == 0) continue;
            // Decrement the degress of all connected nodes, and push
            // the node into the queue if the node degree reaches 0
            // 202B exercise
            indegree[j]--;
            if (indegree[j] == 0) {
                q.push(j);
            }
        }
    }

    for (int i : solution) {
        cout << i + 1 << " ";
    }
}

int main() {
    int n, m, v1, v2;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 1; i <= m; i++) {
        cin >> v1 >> v2;
        graph[v1 - 1][v2 - 1] = 1;
    }

    TopologicalSort(graph);

    return 0;
}