// C. Don't Be Last!
// https://www.xinyoudui.com/contest?courses=459&books=252&pages=6377&fragments=10923&problemId=15289&pattern=0
/*
Farmer John owns 7 dairy cows: Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta. He milks them every day and keeps detailed 
records on the amount of milk provided by each cow during each milking session. Not surprisingly, Farmer John highly prizes cows that 
provide large amounts of milk.

Cows, being lazy creatures, don't necessarily want to be responsible for producing too much milk. If it were up to them, they would each 
be perfectly content to be the lowest-producing cow in the entire herd. However, they keep hearing Farmer John mentioning the phrase 
"farm to table" with his human friends, and while they don't quite understand what this means, they have a suspicion that it actually may 
not be the best idea to be the cow producing the least amount of milk. Instead, they figure it's safer to be in the position of producing 
the second-smallest amount of milk in the herd. Please help the cows figure out which of them currently occupies this desirable position.

INPUT FORMAT (file notlast.in):
The input file for this task starts with a line containing the integer N (1≤N≤100), giving the number of entries in Farmer John's milking log.
Each of the N following lines contains the name of a cow (one of the seven above) followed by a positive integer (at most 100), indicating the 
amount of milk produced by the cow during one of its milking sessions.
Any cow that does not appear in the log at all is assumed to have produced no milk.

OUTPUT FORMAT (file notlast.out):
On a single line of output, please print the name of the cow that produces the second-smallest amount of milk. More precisely, if M is the 
minimum total amount of milk produced by any cow, please output the name of the cow whose total production is minimal among all cows that 
produce more than M units of milk. If several cows tie for this designation, or if no cow has this designation (i.e., if all cows have 
production equal to M), please output the word "Tie". Don't forget to add a newline character at the end of your line of output. Note that 
M=0 if one of the seven cows is completely absent from the milking log, since this cow would have produced no milk.

SAMPLE INPUT:
10
Bessie 1
Maggie 13
Elsie 3
Elsie 4
Henrietta 4
Gertie 12
Daisy 7
Annabelle 10
Bessie 6
Henrietta 5

SAMPLE OUTPUT:
Henrietta

In this example, Bessie, Elsie, and Daisy all tie for the minimum by each producing 7 units of milk. The next-largest production, 9 units, 
is due to Henrietta.
Problem credits: Brian Dean
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> cows;
    set<int> milk;
    string ans;
    
    cows["Bessie"]=0;
    cows["Elsie"]=0;
    cows["Daisy"]=0;
    cows["Gertie"]=0;
    cows["Annabelle"]=0;
    cows["Maggie"]=0;
    cows["Henrietta"]=0;

    for(int i=0; i<n; i++){
        string a;
        int b;
        cin >> a >> b;
        cows[a]+=b;
    }

    for(auto& x:cows){
        milk.insert(x.second);
    }

    bool found=false;
    set<int>::iterator it = milk.begin();
    advance(it, 1);
    int m = *it;

    for(auto& x:cows){
        if(x.second==m){
            if(found==true){
                ans= "Tie";
                break;
            }
            ans= x.first;
            found=true;
        }
    }

    cout << ans << endl;
}