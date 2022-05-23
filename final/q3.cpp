// Q3: 8-connected https://xjoi.net/contest/4235
/*
Time Limit：1s   Memory Limit：256M
Description
8-connected zone:in a 8-connected zone,you can go from each position to any position in one of 8 directions
(up,down,left,right,up left,up right,down left,down right) without going over the zone.

ACZ1pbdT2tg6gAAAABJRU5ErkJggg==

The former picture contains one 8-connected zone,you can go from one blue point to any other blue point. 
Given n*m character matrix(the character is no more than two kinds),please calculate how many 8-connected zones are there 
in the matrix? 

Input
The first line contains two integers n,m.  1<=n,m<=100
The next n lines,each line contains m characters. Character 'W' marks a tile that you can go to.

Output
An integer.

Sample Input
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

​Sample Output
3
*/