// A. Chess Eight
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6609&fragments=12067&problemId=8122
/*
Time：1s.   Memory：512M
Description：
There are 8 chess pieces on a 3x3 chessboard, each marked with a number from 1 to 8. There's one space on the chessboard marked as 0. 
The chess pieces around the space can be moved to the space.

Given an initial layout (initial configuration) and target layout (to simplify, fix it to 123804765, will explain in the next paragraph), 
find the least number of the moves required to change the configuration from the initial state to the end state.

The state 123804765 means the following layout on the chessboard
123
804
765

Input
A string of 9 digits representing the initial state

Output
One line, the least number of moves required to change from the initial state to the end state. If there's no way, output 0.

Sample Input
283104765

Sample Output
4
*/
// see hw4 q2.cpp