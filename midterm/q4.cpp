// Q4 Catch the Cow https://xjoi.net/contest/3944
/*
Description:
Farmer John has been informed of the location of the escaped cow and hopes to catch it. He starts at point N (0≤N≤100,000) 
on the number axis, and the cow is at point K (0≤K≤100,000) on the same number axis. Farmer John has two modes of 
transportation: walking and teleportation.

*Walking: John can move from any point X to X-1 or X+1 point in one minute

*Transport: John can move from any point X to point 2*X in one minute.

If the cow doesn't move at all, how long will it take for Farmer John to catch the cow (get to the cow's location)?

Input format:
One line: Two integers separated by a space: N and K.

Output format:
One line: The minimum time (in minutes) required for Farmer John to catch the cow.

Sample input:
5 17

Sample output:
4

Hint: Solution for sample data is: 5-10-9-18-17. Thus it needs 4 minutes by minium.
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct point {
    int x, c;
    point(int a, int b) : x(a), c(b) {}
};
queue<point> q;

int main(void) {
    int n, k;
    vector<bool> visited(100000, false);
    cin >> n >> k;
    visited[n] = true;
    q.push(point(n, 0));
    while (!q.empty()) {
        point current = q.front();
        q.pop();
        if (current.x == k) {
            cout << current.c << endl;
            return 0;
        }
        // check 3 transition types: +1, -1 and x2
        for (int i = 0; i < 3; i++) {
            point next = current;
            next.c += 1;
            if (i == 0) next.x += 1;
            if (i == 1) next.x -= 1;
            if (i == 2) next.x *= 2;
            if (next.x < 0 || next.x > 100000 || visited[next.x]) continue;
            visited[next.x] = true;
            q.push(next);
        }
    }
    return 0;
}