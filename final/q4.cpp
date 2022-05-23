// Q4: Roads of Caringness https://xjoi.net/contest/4235
/*
Time limit：1   
Memory limit：32M
Description：
John the farmer has N cows (1≤N≤10000) in his farm. He has to patrol the whole farm to make sure all cows are OK.
Each cow's position can be described in a coordinate (X,Y). John always starts from (0,0). Just for fun, he decides to only 
walk along the directions which are parallel to the two axes (east-west, north-south). He changes direction only where he meets 
a cow. Of course, if necessary, John can keep the direction after he meets a cow as well.
If John changes his direction, he will make a turn of 90° (or 270°) or 180°. 
His goal is to meet all the cows before he returns to (0,0).

Now please find out how many paths satisfy the condition that John examine all the N cows and changes his direction at each 
cow's place. The same path accessed from different directions should be counted twice.

Input：
The first line: an integer N
The second line to the N+1 line: the i+1-th line contains two integers x and y (separated by a space), which are the coordinates 
of the i-th cow（-1000 ≤x, y ≤1000）

Output：
One integer, which is the number of paths that satisfy the condition.
If there is no answer, print 0.

Sample input 1：
4
0 1
2 1
2 0
2 -5

Sample output 1：
2

Note：
1<=N<=12
For the sample case above, the two ways are 1 2 4 3 and 3 4 2 1. Note that at every cow, John makes a turn (90, 180 or 270 degree)
*/