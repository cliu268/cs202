// Q5: Chores https://xjoi.net/contest/4235
/*
John's farm had a lot of chores to complete before milking cows, and each chores needed a certain amount of time to complete it. 
For example: They will gather cows, drive them into the cowshed, clean the breasts for the cows, and do some other work. 
It is necessary to complete all chores as soon as possible because it will have more time to squeeze out more milk. Of course, 
some chores must be carried out when some other chores are completed. For example, only when the cows are driven into the cowshed 
can they begin to clean their breasts, and they must not milk their cows until they have cleaned the breasts. 
We refer to these tasks as preparations for the completion of this work. At least one chore does not require preparatory work. 
The work that can be done first is marked as chore 1 . John has a list of n chores that need to be completed, and this list is in 
a certain order. Preparations for chores k (k>1) are only possible in chores 1..k-1.

Write a program to read the job description for each chore from 1 to n. Calculate the minimum time for all chores to be completed. 
Of course, chores that do not matter to each other can work at the same time, and you can assume that John's farm has enough 
workers to perform any number of tasks at the same time.

Input：
Line 1: An integer n, the number of chores that must be completed (3<=n<=10,000);
Lines 2 ~ n+1: There are a total of n lines, each line has some integers separated by one space, respectively:
* Job number (1..n, ordered in the input file);
* Time required to complete the work len (1<=len<=100);
* Some preparations that must be completed, totaling no more than 100, ending with a number 0. Some chores do not need to prepare 
work that describes only a single zero, and no extra spaces appear in the entire input file.

Output：
An integer that represents the minimum time required to complete all chores.

Sample input：
7
1 5 0
2 2 1 0
3 3 2 0
4 6 1 0
5 1 2 4 0
6 8 2 4 0
7 4 3 5 6 0

Sample output：
23

Time limit：1000
Memory limit：65536
Hint: Pay attention to the claim that "Preparations for chores k (k>1) are only possible in chores 1..k-1."
*/