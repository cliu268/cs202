// A. Distinct Numbers
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6377&fragments=10923&problemId=14078&pattern=0
/*
Time limit: 1.00 s​  Memory limit: 512 MB
Description:
You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

Input:
The first input line has an integer n: the number of values.
The second line has n integers x_1, x_2, ...... , x_n.

Output:
Print one integers: the number of distinct values.

Sample Input:
5
2 3 2 2 3

Sample Output:​
​2

Constraints:
1 <= n <= 2 ........ 10^5
1 <= x_i < =10^9
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> s;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << endl;
}