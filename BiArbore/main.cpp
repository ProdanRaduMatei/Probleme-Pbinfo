#include <bits/stdc++.h>
using namespace std; ifstream fin("biarbore.in"); ofstream fout("biarbore.out");
vector <int> a; int x , nod , rez1 , rez2; void citire(int t) { int tnod = nod; fin >> x; a[nod++] = x; a.push_back(0); if(x != 0) { if(t == 0) rez1 = nod; citire(tnod); if(t == 0) rez2 = nod; citire(tnod); } } int main() { a.push_back(0); a.push_back(0); nod = 1; citire(0); fout << a[rez1] << " " << a[rez2]; }
