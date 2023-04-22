// A. Eradicate the Virus
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6382&fragments=11890&problemId=8006&pattern=0
/*
Description:
There are n virus in a line, numbered from 1 to n from left to right.
The toxicity of the i-th virus is a[i].
As an OIer，you wants to eradicate the virus. You have K tons of anti-virus liquid, and you can kill virus with at most K toxicity.
You have to choose a segment of continuous virus and kill them. Find out at most how many virus you can kill.

Input：
The first line contains two positive integers n,k
The second line contains n positive integers. The i-th one is a[i] .

Output：
an integer which is the answer

Sample input 1：
5 5
3 2 1 2 3

Sample output 1：
3

Note：
1<=n<=30000
1<=a[i]<=10000
1<=k<=1e9 
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int ans=0, temp=0;

    queue <int> q;
    int sum=0;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        q.push(a);
        sum+=a;

        while(sum>k){
            int b= q.front();
            q.pop();
            sum -= b;
        }

        temp= q.size();
        ans= max(temp, ans);
    }

    cout << ans << endl;
}