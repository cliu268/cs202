// A. Welcome to XJOI
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6335&fragments=10853&problemId=9474&pattern=0
/*
(NOT including quotation marks)
First, the computer asks: "Hello, what is your name?"
Then you enter your name.
Finally, the computer replies: "Nice to meet you, XXX" (XXX is the name you entered, no space after the XXX)

Input:
A string representing your name

Output: 
See sample output

Sample Output
Hello, what is your name?

Sample Input on the same line:
Lucy

Sample Output
Nice to meet you, Lucy
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Hello, what is your name?";
    string s;
    cin >> s;
    cout << "Nice to meet you, " << s << endl;
}