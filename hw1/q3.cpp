// Q3 Get Water
/*
Time limit：1s   Memory limit：128M
Description：
n people are lining in front of a tap to get some water. Suppose it takes Ti time for each person to get water. Please design a program 
to find out the sequence of those people in the line, so the average waiting time for those n people would be minimal.

Input：
The first line contains n.
The second line contains n integers, T1，T2，…，Tn (separated by space), which means the time it taks for people from 1 to n to take water.

Output：
The first line contains the sequence of those people in the line, an arrangement from 1 to n.
The second line is the average waiting time in this sequence (accurate to two decimal places).

Sample input 1：
10
56 12 1 99 1000 234 33 55 99 812

Sample output 1：
3 2 7 8 1 4 9 6 10 5
291.90

Note：
n<=1000
ti<=1e6，ti can repeat
When ti is repeated, see the input order (sort is available).
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(void) {
    // freopen("q3.in", "r", stdin);
    // freopen("q3.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        input[i] = {i, t};
    }
    sort(input.begin(), input.end(), cmp);
    int sum = 0;
    double total = 0;
    for (int i = 0; i < n; i++) {
        cout << input[i].first + 1 << ' ';
        if (i > 0) {
            sum += input[i-1].second;
        }
        total += sum;
    }
    cout << '\n' << fixed << setprecision(2) << total/n;  // use fixed and setprecision to cout decimals and #include <iomanip>
    return 0;
}