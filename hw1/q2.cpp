// Q2 Numbers of 0 and 1
/*
Time：1s   Memory：32M
Description：
Consider N binary numbers (N<=31). They are already sorted in assending order, and include all binary numbers of length N (meaning the sum 
of numbers of 0 and 1 is N). The total number of '1' for each of these binary numbers is <= L (L<=N). 
Your job is now to find and output the i-th binary number (1<=i<=N) which has number of 1 less or equal to L. 
For an instance, 100101 (N=6) includes 3 '1's.
Please output the i-th number.

Input format：
3 integers N, L and i in one line.

Output format：
One binary number, which is the i-th number satisfying the requirements

Sample input 1：
5 3 19

Sample output 1：
10011

Example explanation：
00000
00001
00010
00011
00100
00101
00110
00111
01000
01001
01010
01011
01100
01101
01110
10000
10001
10010
10011
Explanation: All binary numbers listed above have length 5, and total number of '1' in each binary number is not greater than 3. In the 
assending order, the last one 10011 is the 19th number. Thus it is the answer. 

Notes：
1<=n<=31
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, idx;

bool ones(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            count++;
        }
        if (count > L) {
            return false;
        }
    }
    return true;
}

int main(void) {
    cin >> N >> L >> idx; 
    string s = string(N,'0');
    for (int i = 0;; i++) {
        if (ones(s)) {
            idx--;
        }
        if (idx == 0) {
            break;
        }
        // compute next binary number
        for (int j = N-1; j >= 0; j--) {
            if (s[j] == '0') {
                s[j] = '1';
                break;
            } else {
                s[j] = '0';
            }
        }
    }
    cout << s;
    return 0;
}