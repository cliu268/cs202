// Q2: Building Roads https://xjoi.net/contest/4235
// see cs302 hw1 qd.cpp https://www.xinyoudui.com/ac/contest/7740019EE0002E10119DCD/problem/14116
/*
Time limit: 1.00 s
Memory limit: 512 MB
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.

Your task is to find out the minimum number of roads required, and also determine which roads should be built.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,...,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.

Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.

Constraints
1 <= n <= 10^5
1 <= m <= 2 x 10^5
1 <= a,b <= n
Example

Input:
4 2
1 2
3 4

Output:
1
2 3
*/