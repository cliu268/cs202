// Q3 Parentheses, bracket, brace check https://xjoi.net/contest/3790
/*
Given an expression string exp consisting of parentheses characters "(" and ")", bracket characters "[" and "]", and brace 
characters "{" and }", check whether the pairs and the orders of these characters are matched in expr.

Examples:

expr = "([]())", output: OK
expr = "[({}[])]", output: OK
exp = “[()]{}{[()()]()}”, output: OK
exp = “[(])”, output: Wrong
expr = "([]()", output: Wrong
expr = "(()))", output: Wrong
*/
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main(void) {
    string input;
    stack<char> paren;
    bool ans = true;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            paren.push(input[i]);
        } else {
            if (paren.empty()) {
                ans = false;
                break;
            } else {
                switch (input[i]) {
                    case ')':
                        if (paren.top() != '(') {
                            ans = false;
                        } else {
                            paren.pop();
                        }
                        break;
                    case ']':
                        if (paren.top() != '[') {
                            ans = false;
                        } else {
                            paren.pop();
                        }
                        break;                    
                    case '}':
                        if (paren.top() != '{') {
                            ans = false;
                        } else {
                            paren.pop();
                        }
                        break;                    
                    default:
                        break;
                }
            }
        }
    }
    if (!paren.empty()) {
        ans = false;
    }
    if (ans) {
        cout << "OK";
    } else {
        cout << "Wrong";
    }

    return 0;
}