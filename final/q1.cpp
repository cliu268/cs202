// Q1: Relatives https://xjoi.net/contest/4235
/*
Background: if a family is too big, it's really not easy to know if 2 persons are relatives. 
Now you are given a map of relative relationships, find if 2 given persons are relatives. 

Description: the relative relationship is transitive, meaning that if x and y are relatives, and y and z are relatives, 
then x and z are relatives. the relatives of y are also the relatives of x.

Input format:
First line: 3 integers n, m, p (n, m, p≤5000), meaning there are n persons, and m relationships, and p queries.
Next m lines: each line has 2 integers Mi, Mj, 1≤Mi​, Mj​≤n, meaning Mi and Mj are relatives.
Next p lines: each line has 2 integers Pi, Pj, asking if Pi and Pj are relatives. 

Output format:
p lines: each line Yes or No, answer to the query i

Samples
Input:
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6

Output
Yes
Yes
No
*/