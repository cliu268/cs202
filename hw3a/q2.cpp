// B. Joseph Question
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6382&fragments=11890&problemId=9229&pattern=0
/*
Time: 1 second Space: 256M
There are n people sitting in a circle, numbering 1 to n clockwise. One by one the people are counted all the way up to some number m. 
When the mth person is reached, this person leaves the circle and the counting starts back again from 1. 
Your task is to list the people in the order they leave the circle.  

Input
Two numbers in one line, indicating n, m.

Output
A row of n numbers, indicating the sequence of the team.

Sample Input
3 2
 
Sample Output
2 1 3
 
Note: 1 ≤ n, m ≤ 20
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    queue <int> q;
    int counter=1;

    for(int i=1; i<n+1; i++){
        q.push(i);
    }

    while(q.empty()==false){

        if(counter==m){
            cout << q.front() << " ";
            q.pop();
            counter=1;
        }

        else{
            counter++;
            int f= q.front();
            q.pop();
            q.push(f);
        }
    }
    
}