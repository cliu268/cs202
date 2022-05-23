// Q2 Log analysis for a Warehouse https://xjoi.net/contest/3790
/*
M Shipping Company recently has to make statistics on the goods entering and leaving its warehouses. At present, the only 
record they have is a log of container entry and exit. The log records two kinds of operations: the first type is the 
container storage operation, and the weight of the container in the storage; the second type is the container outgoing 
operation. These records are arranged strictly in chronological order. The rule of container inbound and outbound is 
"first in, last out". That is to say, each outbound container is the latest one in all the containers currently in the 
warehouse.

For analysis purposes, analysts randomly insert a number of third types of operations in their logs - query operations. 
When analyzing logs, the weight of the largest container in the current warehouse is reported for every query operation.

Input format:
Contains N + 1 rows:
The first action is a positive integer N, which corresponds to the total number of operations contained in the log.

The next N lines belong to one of the three formats:
Format 1: 0 X  // Primary Container Input Operation, Positive Integer Xindicates the weight of the container in storage.
Format 2: 1  // One-time Container Out-of-Storage Operation (for that time) The Last Container Out of Storage
Format 3: 2  // A query operation, requiring the analyzer to output the weight of the largest container in the current warehouse
When the warehouse is empty, you should ignore the out-of-warehouse operation. When the warehouse is empty, you should output 0.

Output format:
The number of output rows is equal to the number of queries in the log. Each action has a positive integer representing 
the query results.

Sample input
13
0 1
0 2
2
0 4
0 2
2
1
2
1
1
2
1
2

Sample output
2
4
4
1
0

Data range
N≤200000,X≤108
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    stack<int> s;
    vector<int> ans;
    int maxi = 0;
    int n = 0;
    cin >> n;
    while(n--) {
        int op = 0;
        cin >> op;
        if (op == 0) {
            int w = 0;
            cin >> w;
            if (w <= maxi) {
                s.push(w);
            } else {
                s.push(2*w - maxi); // push 2w - max to the stack
                maxi = w;
            }
        } else if (op == 1) {
            if (s.empty()) continue;
            int top = s.top();
            if (s.top() > maxi) {
                maxi = 2*maxi - top; // reset maxi to 2*max - top
            }
            s.pop();
        } else {
            if (s.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(maxi);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}

// ETAW solution using printf and scanf instead of cin and cout
/*
#include <bits/stdc++.h>
using namespace std;
   
int main() {
  int n; scanf("%d", &n);
  stack<int> maxi;
  for (int i=0; i<n; i++) {
    int x; scanf("%d", &x);
    if (x==0) {
      int y; scanf("%d", &y);
      if (!maxi.empty()) {
        maxi.push(max(maxi.top(), y));
      }
      else if (maxi.empty()) {
        maxi.push(y);
      }
    }
    if (x==1) {
      if (!maxi.empty()) {
        maxi.pop();
      }
    }
    if (x==2) {
      if (maxi.empty()) {
        cout<<0<<"\n";
        continue;
      }
      printf("%d", maxi.top());
      printf("\n");
    }
  }
}
*/