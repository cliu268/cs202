// Q4 Labyrinth
/*
The mouse walks the labyrinth, the labyrinth is the square of the side N, from the upper left corner(entrance )to the 
lower right corner ( exit), it is not allowed to go back, ask for the length of the shortest path and the number of the 
shortest path(N<50)

Input :
The first line is a positive integer n
After n rows per row n number, 1 or 0, 0 can pass, 1 can not

Output:
The number of the shortest path
Shortest path length

Sample input:
5
0 0 0 0 0
0 1 1 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0

Sample output:
1
9

time limit: 1000  memory limit: 65536
*/
// DFS solution can be found in cs201 hw4 q1.cpp
// https://github.com/cliu268/cs201/blob/main/hw4/q1.cpp
// BFS solution will be implemented below
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dx[8] = {0, 0, 1, -1, 0, 0, 2, -2};
int dy[8] = {1, -1, 0, 0, 2, -2, 0, 0};

int main(void) {
    return 0;
}