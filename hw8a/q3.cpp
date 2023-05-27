// C. Minimum Turns
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=12430&fragments=28880&problemId=8121
/*
Time Limit: 1s    Memory Limit: 512M
Description：
Given a matrix, please find the minimum number of turns (change of direction) to get from the start position to the end position, 
if no available path, output -1.

Input：
The first line contains n and m, indicating the number of rows and columns.
Next is the n*m matrix. 0 means you can walk on that tile, 1 means that you cannot.
The last line is the position of the starting point and end point.

Output：
The answer (minimum number of turns).

Sample input
5 7
1 0 0 0 0 1 0
0 0 1 0 1 0 0  
0 0 0 0 1 0 1  
0 1 1 0 0 0 0  
0 0 0 0 1 1 0
1 3 1 7

Sample output
5 

Note： 2≤n,m≤100
*/
// Same question found in cs201 final-a q3.cpp