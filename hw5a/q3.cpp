// C. UP and DOWN
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6608&fragments=12065&problemId=8114
/*
Time Limit: 1s    Memory Limit: 128M
Description:
There is a strange elevator. It can stop at every floor and every floor has a Ki（0 <= Ki <= N) . The elevator has only two buttons: 
up and down. When you are in floor i and press "UP", you will go up Ki floors and reach the  i+Ki floor. If you press "DOWN", you will go 
down Ki floors and reach the i-Ki floor. For example, in a five-floor building, k1 = 3，k2 = 3，k3 = 1，k4 = 2，k5 = 5. On floor 1, if you 
press "UP", you will reach the 4-th floor. If you press "DOWN", the elevator cannot do this task, because there is no -2 floor.

Based on those information, please solve this problem: when you are on floor A and want to go to floor B, at least how many times do you 
have to press the "UP" or "DOWN " buttons?

Input Format:
The first line contains three integers N，A，B（1 <= N，A，B <= 200）
The second line contains N integers k1，k2，...... kn
A single 0 means the end of input

Output Format:
Output the least time you press the buttons. If it can not be achieved, print -1.

Sample Input:
5 1 5
3 3 1 2 5
0

Sample Output:
3
*/
/*
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    while (n) {
        int a, b;
        cin >> a >> b;
        vector<int> k;
        vector<bool> visited;
        queue <pair<int,int>> q;
        bool found = false;

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            k.push_back(temp);
            visited.push_back(false);
        }
        if (a == b) {
            cout << 0 << endl;
            cin >> n;
            continue;
        } else {        
            q.push(make_pair(a, 0));
            visited[a-1] = true;
        }

        while(!q.empty()){
            pair<int, int> cf = q.front();
            q.pop();
            int nextf = 0;
            for (int i = 0; i < 2; i++) {
                // Move UP (i == 0)
                if (i == 0) nextf = cf.first + k[cf.first - 1];
                // Move DOWN (i == 1)
                else nextf = cf.first - k[cf.first - 1];
                
                if (nextf == b) {
                    found = true;
                    cout << cf.second+1 << endl;
                    break;
                } else {
                    if (nextf > 0 && nextf <= n && !visited[nextf-1]) {
                        visited[nextf-1] = true;
                        q.push(make_pair(nextf, cf.second+1));
                    }
                }
            }
        }
        if (!found) cout << -1 << endl;
        cin >> n;
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> maze;
vector<bool> visited;
queue<pair<int, int>> q;
int ans=-1;
int dx[2] = {-1, 1};

void bfs(){
    while(!q.empty()){
        pair<int, int> m = q.front();
        q.pop();  
        for(int i=0; i<2; i++){
            int nf= m.first + dx[i] * maze[m.first-1];
            if(nf>0 && nf<=n && visited[nf-1]==false){              
                if(nf==b){
                    ans = m.second + 1;
                    visited[nf-1] = true;
                }
                else{
                    visited[nf-1]=true;
                    q.push(make_pair(nf, m.second +1));
                }
            }
        }
    }
}

int main(){
    cin >> n;

    while(n){
        cin >> a >> b;     
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            maze.push_back(temp);
            visited.push_back(false);
        }
        if (a == b) cout << 0 << endl;
        else {
            q.push(make_pair(a, 0));
            visited[a-1]=1;
            bfs();
            cout << ans << endl;
        }
        cin >> n;
    }
}