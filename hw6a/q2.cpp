// B. Word Ladder
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6609&fragments=12067&problemId=12608
/*
Time Limit: 1s    Memory Limit: 512M
 
Description:
You have a dictionary with N words. There are one start word and one target word (the target word is the also last word). For each step, 
you can choose to delete, add, or modify one letter in your existing word, to form a new word if the new word exist in the dictionary. 
and then start from that word to move forward. Please Find out the minimum steps required to go from start word to the target word. 
Output -1 if this cannot be done.

Input:
First two lines represent start word and end word respectively.

Then it's a number N representing number of words in the dictionary. (1≤N<100)
After that, it's N lines representing N words in the dictionary.

Output:
One integer representing min number of steps.

Sample Input:   
hello
world
5
hollo
worls
wollo
wolld
world

Sample Output:
4
*/
// also see hw3 q3.cpp
#include <bits/stdc++.h>
using namespace std;

int n;
queue<string> q, rq;
map<string, int> visited, visitedrev;
string startw;
string endw;
set<string> dict;

bool is_neigh(string s, string b){
    int dif=0;
    if(s.length() == b.length()){
        for(int i=0; i<s.length(); i++){
            if(s[i] != b[i]){
                dif++;
            }
        }
        if(dif>1){
            return false;
        }
        return true;
    }
    else if(abs(int(s.length()) - int(b.length())) != 1){
        return false;
    }
    else{
        for(int i=0; i<min(s.length(), b.length()); i++){
            if(s[i] != b[i]){
                if(s.length() > b.length()){
                    if(s.substr(i+1) != b.substr(i)){
                        return false;
                    }
                    else{
                        return true;
                    }
                }
                else{
                    if(b.substr(i+1) != s.substr(i)){
                        return false;
                    }                        
                    else{
                        return true;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> startw;
    cin >> endw;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        dict.insert(s);
    }

    q.push(startw);
    visited[startw] = 0;
    rq.push(endw);
    visitedrev[endw] = 0;

    while(!q.empty() && !rq.empty()){
        string pp = q.front();
        q.pop();
        for(auto& x : dict){
            if(visited.find(x)!=visited.end()){
                continue;
            }
            else{
                // if not neigh --> continue
                if(is_neigh(x, pp) == false){
                    continue;
                }
                // otherwise check in rev queue
                else if(visitedrev.find(x)!=visitedrev.end()){
                    cout << visited[pp] + visitedrev[x] + 1 << endl;
                    return 0;
                }
                // if not push into queue
                else{
                    visited[x] = visited[pp] + 1;
                    q.push(x);
                }
            }
        }

        string rp = rq.front();
        rq.pop();
        for(auto& x : dict){
            if(visitedrev.find(x)!=visitedrev.end()){
                continue;
            }
            else{
                // if not neigh --> continue
                if(is_neigh(x, rp) == false){
                    continue;
                }
                // otherwise check in rev queue
                else if(visited.find(x)!=visited.end()){
                    cout << visited[x] + visitedrev[rp] + 1 << endl;
                    return 0;
                }
                // if not push into queue
                else{
                    visitedrev[x] = visitedrev[rp] + 1;
                    rq.push(x);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}