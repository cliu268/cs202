// Q1 Machine Translation https://xjoi.net/contest/3944
/*
We have a machine translation software that translates English articles into Chinese. The way this translation software works is 
very simple. It scans an English article word by word, from beginning to the end.
For each English word, the translation software first looks up a memory cache. If the English word (and its Chinese translation) 
is in the memory cache, the translation software will use it.

If the English word (and its Chinese translation) is not in the memory cache, the translation software will look it up in a 
dictionary. Because memory cache lookup is significantly faster than dictionary lookup, the translation software will try to store 
this English word (and its Chinese translation) into the memory cache, so that subsequent lookups for the same English word will 
be faster. If the memory cache is full, the English word (and its Chinese translation) that was earliest added to the memory cache 
will be removed, to make room to store the new English word (and its Chinese translation).

The memory cache can store up to M English words (and their Chinese translations), and is initially empty. To translate a given 
English article of N, how many times the translation software has to lookup the dictionary?

Input format: a total of 2 lines
- The first line has two integers, M and N, separated by a space. 0<=M<=100，0<=N<=1000.
- The second line has a total number of N non-negative integers, separated by spaces. Each integer represents an English word to 
translate. Different integers represents different English words, and vice versa.

Output format:
An integer, the number of times the software has to lookup the dictionary.

Sample input
3 7
1 2 1 5 4 4 1

Sample output
5
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(void) {
    int n, m, answer = 0;
    cin >> m >> n;
    queue<int> q;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s.count(x) != 0) continue;
        answer++;
        if (q.size() == m) {
            s.erase(q.front());
            q.pop();            
        }
        q.push(x);
        s.insert(x);
    }
    cout << answer << endl;
    return 0;
}