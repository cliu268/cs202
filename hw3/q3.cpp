// Q3 Word Ladder https://xjoi.net/contest/3847
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
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

set<string> dict;
map<string, bool> fvisited;
map<string, bool> rvisited;
map<string, int> step;
queue<string> q;
queue<string> rq;

bool isNeighbor(string a, string b) {
    int alen = a.length(), blen = b.length();
    if (alen == blen) {
        int count = 0;
        for (int i = 0; i < alen; i++) {
            if (a[i] != b[i]) count++;
            if (count > 1) return false;
        }
        if (count != 1) return false;
        return true;
    } else if (alen - blen == 1) {
        for (int i = 0; i < blen; i++) {
            if (b[i] != a[i]) {
                if (b.substr(i) != a.substr(i+1)) return false;
                return true;
            }
        }
        return true;
    } else if (blen - alen == 1) {
        for (int i = 0; i < alen; i++) {
            if (a[i] != b[i]) {
                if (a.substr(i) != b.substr(i+1)) return false;
                return true;
            }
        }
        return true;
    } else {
        return false;
    }
}

int solve(string start, string end) {
    while (!q.empty() && !rq.empty()) {
        if (!q.empty()) { // fwd BFS
            string cur = q.front();
            q.pop();
            for (auto it = dict.begin(); it != dict.end(); it++) {
                if (fvisited.count(*it)) continue;
                if (!isNeighbor(cur, *it)) continue;
                if (rvisited.count(*it)) {
                    return step[cur] + 1 + step[*it];
                }
                fvisited[*it] = true;
                step[*it] = step[cur] + 1;
                q.push(*it);
            }
        }
        if (!rq.empty()) { // bkw BFS
            string cur = rq.front();
            rq.pop();
            for (auto it = dict.begin(); it != dict.end(); it++) {
                if (rvisited.count(*it)) continue;
                if (!isNeighbor(cur, *it)) continue;
                if (fvisited.count(*it)) {
                    return step[cur] + 1 + step[*it];
                }
                rvisited[*it] = true;
                step[*it] = step[cur] + 1;
                rq.push(*it);
            }            
        }
    }
    return -1;
}

int main(void) {
    string start, end;
    int n;
    cin >> start >> end >> n;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        dict.insert(word);
    }
    q.push(start);
    rq.push(end);
    fvisited[start] = true;
    rvisited[end] = true;
    step[start] = 0;
    step[end] = 0;
    //for (auto it = dict.begin(); it != dict.end(); it++) { cout << *it << '\n'; }    
    cout << solve(start, end);

    // if (step.count("FUFUFU")) cout << " really fucked!!" << step["FUFUFU"] << endl;
    // else cout << "NOT YET FUCKED" << endl;

    // if (step["FUFUFU"] == 3) cout << "FUFU is 3" << endl;  // once you reference the map key, the value is created!!!!!
    // else {
    //     if (step.count("FUFUFU")) cout << " really fucked!!" << step["FUFUFU"] << endl;
    // }

    return 0;
}