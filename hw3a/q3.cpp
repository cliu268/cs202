// Waiting Time
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6382&fragments=11890&problemId=9195&pattern=0
/*
There are n people standing in a line that want to buy tickets. One by one they will be served by the ticket window and get their chance 
to make their purchase. Unfortunately, the machine at the window is broken and each customer is only allowed to buy 1 ticket at a time. 
Given a list of n people, where index 0 is the first person in line and index n - 1 is the last person in line, and the person list p[ i ] 
represents the amount of tickets that person wants to purchase, find the amount of time it will take for the person at position k to to 
finish buying tickets.

Each person will take precisely 1 second to purchase their ticket. Once they finish at the window they will instantaneously jump to the end 
of the line to purchase the next ticket. If they have finished buying the tickets they need, they will leave the line.

Input
The first line contains two integers, n and k that represent the number of people in line and the specific index of the person we wish to 
check how long it takes them to buy their tickets.
The next line contains n space separated integers, representing the number of tickets each person in line would like to purchase.

Output
One integer representing the amount of time it will take the person at position k to finish buying all their tickets.

Sample Input
4 0
4 1 1 1

Sample Output
7
Note: 1 ≤ n ≤ 100, 1 ≤ p[ i ] ≤ 100
Reasoning: Each person in line will be served for 1 ticket, but only the person at index 1 will return the line. 
This person will buy the remaining 3 tickets needed. 4 + 3 = 7.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int ans=0;
    int b;
    int counter=0;

    queue <int> q;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;

        if(i==k){
            b=a;
        }

        q.push(a);
    }

    while(b){
        if(counter==k){
            b--;
        }

        int f= q.front();
        q.pop();
        
        if(f > 0){
            ans++;
            q.push(f-1);
        }
        else{
            q.push(0);
        }

        counter++;
        if(counter==n){
            counter=0;
        }

    }

    cout << ans << endl;
    
}