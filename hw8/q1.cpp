// Q1 Number of connected blocks https://xjoi.net/contest/4036
/*
Time limit: 1s  Memory limit: 512M
Description:
Given an undirected graph, output the number of connected blocks of this graph.

Input:
M+1 lines
The 1st line contains 2 positive integers N，M，which means there are N nodes and M edges.
The 2～M+1 line: each contains  2 positive integers u,v （separated by space），which is an undirected path from u to v. 
There might be repeated edges and self-loops.

Output:
an integer, which is the number of connected blocks of this graph

Sample input:
5 6
1 2
3 4
5 2
5 1
1 5
4 4

Sample output:
2

Note: N，M≤200000
*/