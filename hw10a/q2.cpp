// B. The number of leaf nodes
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6611&fragments=12073&problemId=9524
/*
Description：
Given a tree with n vertices numbered from 1 to N, among which 1 is the root. Please find out the number of leaf vertices of the tree.

Input：
The first line contains a number N
The next N lines, each line contains N 1 or 0. The i-th row and j-th column are 1, which means vertex i and j have edges. Otherwise, 
there is no edge. 

Output：
First line: The total number of leaf vertices in the tree.
Second line: The id of each leaf vertex in the ascending order.

Sample input：
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

Sample output：
5
4 5 8 9 10

Explanation:
There are 5 leaf vertices in the tree. The id of the leaf vertex is 4, 5, 8, 9, and 10 respectively.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num=0;
    vector<int> leaves;

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
            if(ans==0){
                num++;
                leaves.push_back(i);
            }
        }
        else{
            for(int j=0; j<n; j++){
                if(row[j]=='1'){
                    ans++;
                }
            }
            if(ans==1){
                num++;
                leaves.push_back(i);
            }
        }
    }

    cout << num << endl;
    int k= leaves.size();
    for(int i=0; i<k; i++){
        cout << leaves[i] + 1 << " ";
    }

}