// https://xjoi.net/contest/4208
// Q1: Disjoint Set Union
/*
Time limit：1s   Memory limit：512MB
Description：
This problem is simply the classic disjoin set union algorithm. There are N elements, and there will be M operations to be applied. 
Each element starts in its own set, i.e., there are N sets to start with. You are required to perform these M operations, 
and optionally you may be asked to output whether two elements are in the same set. See input format for more details.

Input：
The first line contains two integers N and M, which means there are N elements and M operations.
The next M lines, each line contains three integers Zi、Xi、Yi.
When Zi=1，merge the two sets which contain Xi and Yi.
When Zi=2，if Xi and Yi belong to the same set, output Y. Otherwise output N.

Output：
As described above, for each Zi=2, there is a line of output. Each line contains a capital letter, Y or N.

Sample input 1：
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4

Sample output 1：
N
Y
N
Y

Note：N<=10000，M<=200000
*/