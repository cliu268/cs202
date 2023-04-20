// B. Where Am I?
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6377&fragments=10923&problemId=15361&pattern=0
/*
Farmer John has gone out for a walk down the road and thinks he may now be lost!
Along the road there are N farms (1≤N≤100) in a row. Farms unfortunately do not have house numbers, making it hard for Farmer John to 
figure out his location along the road. However, each farm does have a colorful mailbox along the side of the road, so Farmer John hopes 
that if he looks at the colors of the mailboxes nearest to him, he can uniquely determine where he is.

Each mailbox color is specified by a letter in the range A..Z, so the sequence of N mailboxes down the road can be represented by a string 
of length N containing letters in the range A..Z. Some mailboxes may have the same colors as other mailboxes. Farmer John wants to know what 
is the smallest value of K such that if he looks at any sequence of K consecutive mailboxes, he can uniquely determine the location of that 
sequence along the road.

For example, suppose the sequence of mailboxes along the road is 'ABCDABC'. Farmer John cannot set K=3, since if he sees 'ABC', there are 
two possible locations along the road where this consecutive set of colors might be. The smallest value of K that works is K=4, since if he 
looks at any consecutive set of 4 mailboxes, this sequence of colors uniquely determines his position along the road.

INPUT FORMAT (file whereami.in):
The first line of input contains N, and the second line contains a string of N characters, each in the range A..Z.

OUTPUT FORMAT (file whereami.out):
Print a line containing a single integer, specifying the smallest value of K that solves Farmer John's problem.

SAMPLE INPUT:
7
ABCDABC

SAMPLE OUTPUT:
4

Problem credits: Brian Dean
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string street;
    cin >> street;
    set<string> s;
    int ans=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<= n-i; j++){
            if(s.count(street.substr(j, i))==1){
                ans++;
                break;
            }
            else{
                s.insert(street.substr(j, i));
            }
        }
    }

    cout << ans << endl;
}
// A better answer can be seen in https://github.com/cliu268/usaco/blob/3b30cf4f5111bac9ea196c8ed2823c1f85385e1d/bronze/hw2/q2.cpp