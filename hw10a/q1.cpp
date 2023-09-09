// A. The number of Child nodes of the tree nodes
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6611&fragments=12073&problemId=9522
/*
Description：
Given a tree with n nodes numbered from 1 to N, among which 1 is for the root. Please find out the number of child nodes for each node.

Input：
The first line contains a number N
The next N lines, each line contains N numbers (each could be either 1 or 0). when the i-th row and j-th column is 1, 
it means nodes i and j have an edge. Otherwise, there is no edge. 

Output：
the number of vertices' children of the tree.

Sample Input：
10
0110000000
1001000000
1000110001
0100000000
0010000000
0010001000
0000010110
0000001000
0000001000
0010000000 

Sample Output：
2 1 3 0 0 1 2 0 0 0
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string row;
        cin >> row;
        int ans=0;
        if(i==0){
            for(int j=0; j<n; j++){
                if(row[j]=='1'){
                    ans++;
                }
            }
            cout << ans << " ";
        }
        else{
            for(int j=0; j<n; j++){
                if(row[j]=='1'){
                    ans++;
                }
            }
            cout << ans-1 << " ";
        }
    }
}