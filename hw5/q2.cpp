// Q2 Multiple of N https://xjoi.net/contest/3917
/*
Description:
Write a program to find a minimum positive multiple of N for a given natural number N (1 ≤ N ≤ 4999) and M different decimal 
numbers X1, X2, ..., XM (at least one) so that there are no numbers other than X1, X2, ..., XM in this multiple.

Input format:
1st line: N
2nd line: M
Followed by M lines: the M digits that can be in the multiple.

Output :
Output this multiple, if there is no solution output 0.

Sample input:
4999
4
7
6
9
0

Sample output:
60007996

Sample input 2:
2047
2
9
0

Sample output 2:
9000099999099

Data range:
1≤N≤4999

Time limit:
1000

Memory limit:
65536

Restrictions:
The answer will not exceed 500 digits in all test data.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n, m;
set<int> digits;
struct node {
    string num;
    int remainder;
};
queue<node> q;

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        digits.insert(x);
    }
    for (auto x : digits) {
        if (x) {
            q.push({string(1, x + '0'), x % n});
        }
    }
    while (!q.empty()) {
        node curr = q.front();
        q.pop();
        if (curr.num.length() > 500) {
            break;
        }
        if (curr.remainder % n == 0) {
            cout << curr.num << endl;
            return 0;
        }
        for (auto x : digits) {
            node next = curr;
            next.num += x + '0';
            next.remainder = (next.remainder * 10 + x) % n; 
            q.push(next);
        }
    }
    cout << 0 << endl;
    return 0;
}


// Brute Force solution, that will TLE but good first try
/*
int n, m;
set<int> digits;

bool solve(long long num) {
    while (num) {
        int x = num % 10;
        if (!digits.count(x)) return false;
        num = num/10;
    }
    return true;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        digits.insert(x);
    }
    long long ans = n;
    while (true) {
        if (solve(ans)) break;
        ans += n;
    }
    cout << ans << endl;
    return 0;
}
*/