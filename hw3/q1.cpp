// Q1 Merge Two Ordered Linear Lists https://xjoi.net/contest/3847
/*
Ordered linear table merge (n, m<=10^5)

Input :
The first line of two positive integers n, m
The second line of n integers
The third line of m integers, to ensure that the two rows are ordered

Output :
Merged series

Sample input:
4 5
1 4 7 8
2 4 6 9 10

Sample output:
1 2 4 4 6 7 8 9 10

data range:
n,m<=10^5

time limit:
2s

Memory limit:
64M
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v1(n);
    vector<int> v2(m);
    vector<int> v3(n+m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &v2[i]);
    }
    int i = 0, j = 0;
    while (true) {
        if (i == n || j == m) break;
        if (v1[i] < v2[j]) {
            v3[i+j] = v1[i];
            i++;
            continue;
        } else {
            v3[i+j] = v2[j];
            j++;
            continue;
        }
    }
    if (i == n) {
        for (int x = j; x < m; x++) {
            v3[i+x] = v2[x];
        }
    } else {
        for (int x = i; x < n; x++) {
            v3[j+x] = v1[x]; 
        }
    }
    for (int x = 0; x < n+m; x++) {
        printf("%d ", v3[x]);
    }
    return 0;
}