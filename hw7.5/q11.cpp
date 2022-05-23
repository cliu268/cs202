// https://xjoi.net/contest/4034/problem/12
// Q11: Censoring (Bronze)
/*
Farmer John has purchased a subscription to Good Hooveskeeping magazine for his cows, so they have plenty of material to 
read while waiting around in the barn during milking sessions. Unfortunately, the latest issue contains a rather inappropriate 
article on how to cook the perfect steak, which FJ would rather his cows not see (clearly, the magazine is in need of better 
editorial oversight).

FJ has taken all of the text from the magazine to create the string S of length at most 10^6 characters. From this, he would 
like to remove occurrences of a substring T of length <= 100 characters to censor the inappropriate content. To do this, 
Farmer John finds the _first_ occurrence of T in S and deletes it. He then repeats the process again, deleting the first 
occurrence of T again, continuing until there are no more occurrences of T in S. Note that the deletion of one occurrence 
might create a new occurrence of T that didn't exist before.

Please help FJ determine the final contents of S after censoring is complete.

INPUT FORMAT: (file censor.in)
The first line will contain S. The second line will contain T. The length of T will be at most that of S, and all characters 
of S and T will be lower-case alphabet characters (in the range a..z).

OUTPUT FORMAT: (file censor.out)
The string S after all deletions are complete. It is guaranteed that S will not become empty during the deletion process.

SAMPLE INPUT:
whatthemomooofun
moo

SAMPLE OUTPUT:
whatthefun

[Problem credits: Mark Gordon, 2015]
*/