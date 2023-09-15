#include <bits/stdc++.h>
using namespace std;
ifstream fin("xyz.in");
ofstream fout("xyz.out");
int main() {
    int x,y,z;
    fin>>x>>y>>z;
    fout<<y;
    for(int i=1; i<x; i++)
        fout<<z;
    return 0;
}
