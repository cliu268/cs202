// Q2 Pioneers
/*
Time limit：1s   Memory limit：512M

Description：
There is an army group represented by a N*M matrix. Each unit contains a member of the army. Some of them were infected 
with the plague, and every hour they spread the plague to people around them until all the people are infected. Now you 
know the exact location of the infection source and your task is to calculate the time it takes for the army leaders to 
get infected.

Input：
The first line：four integers N，M，A，B --- the N*M matrix, the number of infection sources and the number of army leaders.
The next A lines: each line contaisn two integers x and y, which means the infection source is in the x row y column.
The next B lines: each line contaisn two integers x and y, which describe the location of the leaders.

Output：
The first to the B-th line: each line contains an integer, which is the time for the leader to get infected. The sequence 
of output should be the same as input. If someone is the infection source, then his time to get infected should be 0.

Sample input 1：
5 4 2 3
1 1
5 4
3 3
5 3
2 4

Sample output 1：
3
1
3

Note：
1<=M,N<=500
1<=A,B<=100000
*/