// Q3 Graph 2 - Unordered letter pairs https://xjoi.net/contest/4036
/*
Time limit:1s  Memory limit:128M
Description:
Given n distinct unordered letter pairs (case sensitive. Unordered means letters in pairs can change their position), 
please find a string whose length is n+1, such that each letter pair appears in this string.

Input:
The first line contains a positive integer n. 
The next n lines each contains two letters, which means those two letters should be adjacent. 

Output:
Output the string that satisfies the condition.
If there is no such strin, output“No Solution".
If there is more than one solution, please output the solution whose front letter's lexicographic order is the smallest.

Sample input 1:
4
aZ
tZ
Xt
aX

Sample output 2:
XaZtX

Note: The number of distinct unordered letter pairs is limited. The size of n can be calculated.
*/