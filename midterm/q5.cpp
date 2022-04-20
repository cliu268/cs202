// Q5 A Strange Auction
/*
A strange auction starts from the highest price w. If no one bids, the price will be dropped by either a or b. Count the 
total number of ways a price can drop from w to p.

Input format:
The first line has two positive integers w and p, and the second line has two positive integers a and b.
1≤w, p≤10^6, 2≤a, b≤10000, a is not equal to b.

Output format:
The total number of ways.

Sample input:
10 3
2 3

Sample output:
3

Note: the 3 ways are:
10 - 8 - 6 - 3
10 - 8 - 5 - 3
10 - 7 - 5 - 3
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int w, p, a, b;
vector<int> counter(1000000, 0);

void dfs(int x) {
    //cout << "calling dfs with counter[" << x << "] : " << counter[x] << endl;
    if (x == p) {
        counter[x]++;
        return;
    }
    // two ways to move towards p
    for (int i = 0; i < 2; i++) {
        int next = x;
        if (i == 0) next-=a;
        if (i == 1) next-=b;
        if (next < p) continue;
        if (counter[next] > 0) continue;
        dfs(next);
    }
    counter[x] = counter[x-a] + counter[x-b];
}
 
int main(void) {
    cin >> w >> p >> a >> b;
    dfs(w);
    cout << counter[w] << endl;
    return 0;
}