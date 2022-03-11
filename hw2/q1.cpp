// Q1 The Number Game of Little Fish
/*
Title Description
Fish was recently asked to play a number game, asking him to remember a string of numbers he saw (The length is not 
necessarily 0, the maximum length is not more than 1000000, and the number is not more than 2 ^ 32-1), and then read 
them back (the number 0 for the end should not be read out). It's too hard for the little fish to remember. You don't 
want to think about how big the whole head of the little fish is. Some of them are delicious meat! So please help the 
fish program to solve this problem.

Input format
Enter a series of integers in a row, end with 0, spaced by spaces.

Output format
Output the series of integers in one line backwards, spaced by spaces.

sample input
3 65 23 5 34 1 30 0

sample output
30 1 34 5 23 65 3
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main(void) {
    stack<int> s;
    int input = 0;
    cin >> input;
    while (input) {
        s.push(input);
        cin >> input;
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}