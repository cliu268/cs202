// D. Cities and States
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6377&fragments=10923&problemId=15225&pattern=0
/*
To keep his cows intellectually stimulated, Farmer John has placed a large map of the USA on the wall of his barn. Since the cows spend 
many hours in the barn staring at this map, they start to notice several curious patterns. For example, the cities of Flint, MI and Miami, 
FL share a very special relationship: the first two letters of "Flint" give the state code ("FL") for Miami, and the first two letters of 
"Miami" give the state code ("MI") for Flint.

Let us say that two cities are a "special pair" if they satisfy this property and come from different states. The cows are wondering how 
many special pairs of cities exist. Please help them solve this amusing geographical puzzle!

INPUT FORMAT (file citystate.in):
The first line of input contains N (1≤N≤200,000), the number of cities on the map.
The next N lines each contain two strings: the name of a city (a string of at least 2 and at most 10 uppercase letters), and its two-letter 
state code (a string of 2 uppercase letters). Note that the state code may be something like ZQ, which is not an actual USA state. Multiple 
cities with the same name can exist, but they will be in different states.

OUTPUT FORMAT (file citystate.out):
Please output the number of special pairs of cities.

SAMPLE INPUT:
6
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL

SAMPLE OUTPUT:
1

Problem credits: Brian Dean
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans=0;
    map<string, int> citystate;

    for(int i=0; i<n; i++){
        string a, b;
        cin >> a >> b;
        if(a.substr(0, 2)!=b){
            citystate[a.substr(0,2) + b] += 1;
        }
    }

    for(auto& x : citystate){
        string rev = x.first.substr(2,2) + x.first.substr(0,2);
        if(citystate.count(rev)>0){
            ans += x.second * citystate[rev];
        }
        x.second = 0;
    }

    cout << ans << endl;
}