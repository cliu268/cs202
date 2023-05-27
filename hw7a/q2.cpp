// B. Machine Translation
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6610&fragments=12068&problemId=7652
/*
We have a machine translation software that translates English articles into Chinese. The way this translation software works is very simple. 
It scans an English article word by word, from beginning to the end.

For each English word, the translation software first looks up a memory cache. If the English word (and its Chinese translation) is in 
the memory cache, the translation software will use it.

If the English word (and its Chinese translation) is not in the memory cache, the translation software will look it up in a dictionary. 
Because memory cache lookup is significantly faster than dictionary lookup, the translation software will try to store this English word 
(and its Chinese translation) into the memory cache, so that subsequent lookups for the same English word will be faster. If the memory cache 
is full, the English word (and its Chinese translation) that was earliest added to the memory cache will be removed, to make room to store the 
new English word (and its Chinese translation).

The memory cache can store up to M English words (and their Chinese translations), and is initially empty. To translate a given English article 
of N, how many times the translation software has to lookup the dictionary?

Input format: a total of 2 lines
- The first line has two integers, M and N, separated by a space. 0<=M<=100，0<=N<=1000.
- The second line has a total number of N non-negative integers, separated by spaces. Each integer represents an English word to translate. 
Different integers represents different English words, and vice versa.

Output format:
An integer, the number of times the software has to lookup the dictionary.

Sample input
3 7
1 2 1 5 4 4 1 

sample output
5
*/
// see midterm q1.cpp