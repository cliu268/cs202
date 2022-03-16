// Q3 Word Ladder
/*
Description:
You have a dictionary with N words. There are one start word and one target word (the target word is the also last word). 
For each step, you can choose to delete, add, or modify one letter in your existing word, to form a new word if the new word 
exist in the dictionary. and then start from that word to move forward. Please Find out the minimum steps required to go from 
start word to the target word. Output -1 if this cannot be done.

Input format:
First two lines represent start word and end word respectively.
Then it's a number N representing number of words in the dictionary. (1 << N << 100)
After that, it's N lines representing N words in the dictionary.

Output format:
One integer representing min number of steps.

Sample Input:                                              
hello
world
6
hello
hollo
worls
wollo
wolld
world

Sample Output:
4
*/