// Q1: Disjoint Set Union
// https://xjoi.net/contest/4208/problem/1
// https://www.xinyoudui.com/contest?courses=519&books=255&pages=6460&fragments=12040&problemId=8214
// see cs300 hw9 qa.cpp for Ev answer
/*
Time limit：1s   Memory limit：512MB
Description：
This problem is simply the classic disjoin set union algorithm. There are N elements, and there will be M operations to be applied. 
Each element starts in its own set, i.e., there are N sets to start with. You are required to perform these M operations, 
and optionally you may be asked to output whether two elements are in the same set. See input format for more details.

Input：
The first line contains two integers N and M, which means there are N elements and M operations.
The next M lines, each line contains three integers Zi、Xi、Yi.
When Zi=1，merge the two sets which contain Xi and Yi.
When Zi=2，if Xi and Yi belong to the same set, output Y. Otherwise output N.

Output：
As described above, for each Zi=2, there is a line of output. Each line contains a capital letter, Y or N.

Sample input 1：
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4

Sample output 1：
N
Y
N
Y

Note：N<=10000，M<=200000
Hint: to avoid timeout you need to (1) use scanf/printf, (2) apply path compression, and (3) submit with "g++ with -std=c++11" option.
*/
#include <bits/stdc++.h>
using namespace std;
 
int parents[10001];
int GetParents(int x) {
  if (parents[x]==x) {
    return x;
  }
  int ans=GetParents(parents[x]);
  parents[x]=ans;
  return ans;
}
int main() {
  int n,m;
  scanf("%d %d", &n, &m);
   
  for (int i=0; i<n+1; i++) {
    parents[i]=i;
  }
  for (int i=0; i<m; i++) {
    int z, x, y; scanf("%d %d %d", &z, &x, &y);
    if (z==1) {
      parents[GetParents(x)]=GetParents(y);
    }
    if (z==2) {
      if (GetParents(x)==GetParents(y)) {
        printf("Y\n");
      }
      else {
        printf("N\n");
      }
    }
  }
}