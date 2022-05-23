// Q1 Pouring Wine https://xjoi.net/contest/3888
/*
Time Limit：1s   Memory Limit：64M
 
Description:
Given the volume of three cups, but there is no scales/indices on the cups. The first cup is full and the other two are empty. 
Please judge whether you can pour equal amount (that is half of the first cup) of wine into two cups (they are initially empty).

Input:
The volumes of three cups (no more than 150).   

Output:
Output the least steps for you to evenly distribute wine from the first cup to the other two empty cups. Output "NO" if it 
is impossible to accomplish that.

Sample Input:
8 5 3

Sample Output:
7

Sample In 2:
10 8 6
Sample Out 2:
NO
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
    int cups[3] = {0 ,0, 0};
    map<vector<int>, int> targets;
    map<vector<int>, int> visited_counts;
    queue<vector<int>> qu;

    cin >> cups[0] >> cups[1] >> cups[2];

    int from_cups[6] = {0, 0, 1, 1, 2, 2};
    int to_cups[6]   = {1, 2, 0, 2, 0, 1};

    if (cups[0] % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    int half = cups[0]/2;
    targets[{half, half, 0}] = 1;
    targets[{half, 0, half}] = 1;
    targets[{0, half, half}] = 1;

    qu.push({cups[0], 0, 0});
    visited_counts[{cups[0], 0, 0}] = 0;

    //BFS here
    while (!qu.empty()) {
        vector<int> current_wine_vol = qu.front();
        qu.pop();
        int current_counts = visited_counts[current_wine_vol];
        for (int i = 0; i < 6; i++) {
            vector<int> next_wine_vol = current_wine_vol;
            int pour_vol = min(current_wine_vol[from_cups[i]], 
                                (cups[to_cups[i]] - current_wine_vol[to_cups[i]] ));
            next_wine_vol[from_cups[i]] -= pour_vol;
            next_wine_vol[to_cups[i]] += pour_vol;
            // check if visited
            if (visited_counts.count(next_wine_vol) != 0) {
                continue;
            }
            // check if this is the target solution
            if (targets.count(next_wine_vol) != 0) {
                cout << current_counts + 1 << endl;
                return 0;
            }
            // push into the qu and continue BFS
            visited_counts[next_wine_vol] = current_counts+1;
            qu.push(next_wine_vol);
        }
    }
    cout << "NO" << endl;
    return 0;
}