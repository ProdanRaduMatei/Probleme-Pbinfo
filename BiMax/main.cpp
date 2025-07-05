#include <bits/stdc++.h>
using namespace std; ifstream fin("bimax.in"); ofstream fout("bimax.out"); int maxi; void citire(int nod){ int x; fin >> x; if(x > maxi) maxi = x; if(x != 0){ citire(2 * nod); citire(2 * nod + 1); } } int main(){ int x; fin >> x; citire(2); int s = maxi; maxi = 0; citire(3); int s1 = maxi; fout << s << ' ' << s1; return 0; }
