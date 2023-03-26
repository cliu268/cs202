// https://xjoi.net/contest/3850
// Bonus - Mathematical expression 
/*
Calculate the value of a mathematical expression with a length not exceeding 100. All intermediate operations will 
within the range of the basic type; the operation rules are parentheses, powers, multiplications, divisions, additions 
and subtractions,from top to bottom,and in the same level ,from left to right. The result is rounded off to retain 
2 decimal places.

Input :
One line character, the carriage return ends. Guaranteed to be a legal arithmetic expression.

Output :
An answer.

Sample input:
2^3+5/3*(231-130)+10000
Sample output:
10,176.33

Sample input2:  (test ability to handle negative numbers like 1-2-3)
1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1*1*1*1*1*2*2*2*2*1-2-2-2-2-3-3-3-3-3-3-3-3-3-3-3-3-3-100
Sample output2:
-109

Sample input3:  (test the ability to handle decimals like 2.9)
-2.9^5+4*3+(5+(3-2)*6.6)^2-(4/(2-(2-((5.5/2+2)-2))))
Sample output3:
-60.01

Sample input4:  (test the ability to handle '-' followed by '()')
00000000*0000000-(0000-00000)*0000000+(60000^1^1^1^1^1^1^1^1)/1111111
Sample output4:
0.05

Hint:
Review the use of recursion and stack
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

int main(void) {
    stack<double> operand;
    stack<char> op;
    string input;
    cin >> input;
    double current = 0;
    bool number = false;
    int decimal = 0;
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i]) || input[i] == '.') {
            number = true;
            if (input[i] == '.') {
                decimal = 1;
                continue;
            }
            if (decimal != 0) {
                current = current + (double)(input[i] - '0')*pow(0.1,decimal);                
                decimal += 1;
            } else {
                current = current * 10 + input[i] - '0';
            }
        } else {
            if (number) {
                if (!op.empty() && op.top() == '-') {
                    current *= -1;
                    op.pop();
                    op.push('+');   
                }
                operand.push(current);
                current = 0;
                number = false;
                decimal = 0;
            }
            if (input[i] == '(' || input[i] == '^') {
                op.push(input[i]);
            }
            if (input[i] == '*' || input[i] == '/') {
                while (!op.empty() && (op.top() == '^' || op.top() == '*' || op.top() == '/')) {
                    double a = operand.top();
                    operand.pop();
                    double b = operand.top();
                    operand.pop();
                    switch(op.top()) {
                        case '^':
                            operand.push(pow(b,a));
                            break;
                        case '*':
                            operand.push(b*a);
                            break;
                        case '/':
                            operand.push(b/a);
                            break;
                    }
                    op.pop();
                }
                op.push(input[i]);
            }            
            if (input[i] == '+' || input[i] == '-') {
                while (!op.empty() && (op.top() == '^' || op.top() == '*' || op.top() == '/')) {
                    double a = operand.top();
                    operand.pop();
                    double b = operand.top();
                    operand.pop();
                    switch(op.top()) {
                        case '^':
                            operand.push(pow(b,a));
                            break;
                        case '*':
                            operand.push(b*a);
                            break;
                        case '/':
                            operand.push(b/a);
                            break;
                    }
                    op.pop();
                }              
                op.push(input[i]);
            }
            if (input[i] == ')') {
                while (op.top() != '(') {
                    double a = operand.top();
                    operand.pop();
                    double b = operand.top();
                    operand.pop();
                    switch(op.top()) {
                        case '^':
                            operand.push(pow(b,a));
                            break;
                        case '*':
                            operand.push(b*a);
                            break;
                        case '/':
                            operand.push(b/a);
                            break;
                        case '+':
                            operand.push(b+a);
                            break;
                        case '-':
                            operand.push(b-a);
                            break;                            
                    }
                    op.pop();                    
                }
                op.pop();
                if (!op.empty() && op.top() == '-') {
                    op.pop();
                    op.push('+');
                    double temp = operand.top();
                    temp *= -1;
                    operand.pop();
                    operand.push(temp);
                }
            }
        }
    }
    if (number) operand.push(current);
    while (op.empty() == false) {
        double a = operand.top();
        operand.pop();
        double b = 0;
        if (!operand.empty()) {
            b = operand.top();
            operand.pop();
        }
        switch(op.top()) {
            case '^':
                operand.push(pow(b,a));
                break;
            case '*':
                operand.push(b*a);
                break;
            case '/':
                operand.push(b/a);
                break;
            case '+':
                operand.push(b+a);
                break;
            case '-':
                operand.push(b-a);
                break;                            
        }
        op.pop();                    
    }
    cout << fixed << setprecision(2) << operand.top();
    return 0;
}