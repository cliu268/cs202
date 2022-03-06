// Q1 Friendship Circle
/*
Problem Statement:
There are n students in class. Some of them are friends, and some of them are not. Friendship has transitivity. For example, if A is B's 
friend, and B is C's friend, and A will be C's friend as a result of transitivity. So-called social circle, means a set of people who are 
all friends to each other. Note that there could be multiple social circles.

Given a n by n matrix M, representing the friendships in class. If M[i][j] = 1, i-th student and j-th student are friends to each other; 
otherwise their relationship is unknown (with transitivity students could be friends even they are not friends directly). Please compute the 
number of social circles in total.

Input Format
The first line is n.
Over the next n lines, we will have n integer each line, and each integer is 1 or 0.

Output Format
One integer representing total number of social circles.

Sample Input：
3
1 1 0
1 1 1
0 1 1

Sample Output：
1

Sample Input:
5        
1 1 1 0 0
1 1 0 1 0
1 0 1 0 0
0 1 0 1 0
0 0 0 0 1

Sample Output:
2
Limitation: 1<=n<=200
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void dfs(vector<bool> &visited, vector<vector<int>>friendships, int index) {
    for (int i = 0; i < visited.size(); i++) {
        if (i == index || visited[i]) continue;
        if (friendships[index][i]) {
            visited[i] = true;
            dfs(visited, friendships, i);
        }
    }
}

int circles(vector<vector<int>> friendships) {
    int ans = 0;
    vector<bool> visited(friendships.size(), false);
    for (int i = 0; i < friendships.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            ans++;
            dfs(visited, friendships, i);
        }
    }
    return ans;
}

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> friendships(n);
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (int j = 0; j < n; j++) {
            cin >> row[j];
        }
        friendships[i] = row;
    }
    cout << circles(friendships);
    return 0;
}