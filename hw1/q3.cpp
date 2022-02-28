// Q3 Get Water
/*
Time limit：1s   Memory limit：128M
Description：
n people are lining in front of a tap to get some water. Suppose it takes Ti time for each person to get water. Please design a program 
to find out the sequence of those people in the line, so the average waiting time for those n people would be minimal.

Input：
The first line contains n.
The second line contains n integers, T1，T2，…，Tn (separated by space), which means the time it taks for people from 1 to n to take water.

Output：
The first line contains the sequence of those people in the line, an arrangement from 1 to n.
The second line is the average waiting time in this sequence (accurate to two decimal places).

Sample input 1：
10
56 12 1 99 1000 234 33 55 99 812

Sample output 1：
3 2 7 8 1 4 9 6 10 5
291.90

Note：
n<=1000
ti<=1e6，ti can repeat
When ti is repeated, see the input order (sort is available).
*/