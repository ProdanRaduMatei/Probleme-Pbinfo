#include <bits/stdc++.h>
using namespace std; ifstream fin("knivel1.in"); ofstream fout("knivel1.out"); int s[1001]; void citire(int nod, int ad){ int x; fin >> x; s[ad] += x; if(x){ citire(2 * nod, ad+1); citire(2 * nod + 1, ad+1); } } int main(){ citire(1, 0); int k; fin >> k; fout << s[k]; return 0; }
