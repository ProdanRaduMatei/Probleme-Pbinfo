#include <bits/stdc++.h>
using namespace std; ifstream fin("inaltime1.in"); ofstream fout("inaltime1.out"); int c,x; void citire(int nod, int ad){ c = max(c, ad); fin >> x; if(x != 0){ citire(2 * nod, ad+1); citire(2 * nod + 1, ad+1); } } int main(){ citire(1, 0); fout << c; return 0; }
