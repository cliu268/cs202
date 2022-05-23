// Q2: Food Chain https://xjoi.net/contest/4207
/*
There are three kinds of animals A, B, and C in the animal kingdom. The food chains of these three kinds of animals form an 
interesting ring. A eats B, B eats C, C eats A.
There are currently N animals, numbered 1-N. Each animal is one of A, B, and C, but we don't know which one it is.
There are two ways to describe the relationship between the food chain formed by these N animals:
The first statement is "1 X Y", which means that X and Y are the same kind.
The second statement is "2 X Y", which means that X eats Y.
Some person speaks K sentences one sentence after another for the N animals. Some of these K sentences are true, and the others 
are false. When a sentence satisfies one of the following three terms, this sentence is a false one, otherwise it is a true one.
1) The conflict between the current sentence and some of the previous true sentences is false;
2) In current sentence, X or Y is greater than N, which is false;
3) Incurrent sentence, X eat X, is false.
Your task is to output the total number of false sentences based on the given N (1<=N<=50,000) and K sentences (0<=K<=100,000).

Input：
The first line has two integers N and K, separated by a space.
The following K lines each has three positive integers D, X, Y, and the neighboring numbers are separated by a space, where D 
represents the type of the statement.
If D=1, it means that X and Y are the same kind.
If D=2, it means that X eats Y.

Output：
Only one integer, indicating the number of false sentences.

Sample input：
100 7	
1 101 1   	
2 1 2     	
2 2 3     	
2 3 3     	
1 1 3     	
2 3 1     	
1 5 5     	

Sample output：
3

Time Limit：1000
Memory Limit：65536

Notes：
Analysis of 7 sentences
100 7
1 101 1 False
2 1 2 Truth
2 2 3 Truth
2 3 3 False
1 1 3 False
2 3 1 Truth
1 5 5 Truth
*/