#include <bits/stdc++.h>
using namespace std; ifstream fin("inordine1.in"); ofstream fout("inordine1.out"); struct nod { int info; nod *st, *dr; }; void RSD(nod *p) { if(p) {
    //cout << p -> info << " ";
    RSD(p->st); cout << p -> info << " "; RSD(p->dr);
    //cout << p -> info << " ";
    } } void read(nod * &p) { int x; fin >> x; if(x == 0) p = NULL; else { p = new nod; p->info = x; read(p -> st); read(p -> dr); } } int main() { nod *p = NULL; read(p); RSD(p); return 0; }
