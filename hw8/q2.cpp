// Q2 Biggest Reachable Vertex https://xjoi.net/contest/4036
/*
A directed graph has N vertices and M directed edges. 1<= N, M<=100,000. Each vertex has an integer ID v s.t. 1<=v<=N. 
For each vertex v, output the biggest vertex ID among all vertices reachable from vertex v.

Input:
There are M+1 lines. The first line gives two integers, N and M, separated by a space. Each of the following M lines 
represents a directed edge from the first integer to the second integer.

Output:
A single line of N integers. The ith integer is the biggest ID of the vertex reachable from vertex i.

Sample input:
4 3
1 2
2 4
4 3

Sample output:
4 4 3 4
Hint: consider reversing the direction of all edges.
*/