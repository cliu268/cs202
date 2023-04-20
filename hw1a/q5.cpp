// E. Friendship Circle
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6335&fragments=10853&problemId=9561&pattern=0
/*
Description:
There are n students in class. Some of them are friends, and some of them are not. Friendship has transitivity. For example, if A is B's 
friend, and B is C's friend, and A will be C's friend as a result of transitivity. So-called social circle, means a set of people who are 
all friends to each other. Note that there could be multiple social circles.

Given a n by n matrix M, representing the friendships in class. If M[i][j] = 1, i-th student and j-th student are friends to each other; 
otherwise their relationship is unknown (with transitivity students could be friends even they are not friends directly). Please compute 
the number of social circles in total.

Input:
The first line is n.
Over the next n lines, we will have n integer each line, and each integer is 1 or 0.

Output:
One integer representing total number of social circles.

Sample Input：
3
1 1 0
1 1 1
0 1 1

Sample Output：
1 

Constraints:
1<=n<=200
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> friends;
vector<bool> visited;
int ans = 0, n = 0;

void dfs(int index) {
    for (int i = 0; i < n; i++) {
        if (friends[index][i] && visited[i] == false) {
            visited[i] = true;
            dfs(i);
        }
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> row(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> row[j];
        }
        friends.push_back(row);
        visited.push_back(false);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            ans++;
            dfs(i);
        }
    }

    cout << ans << endl;
}