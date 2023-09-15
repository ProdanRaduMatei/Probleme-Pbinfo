#include <bits/stdc++.h>
using namespace std;
ifstream fin("bifrunze1.in");
ofstream fout("bifrunze1.out");
int n, rez[1001], c;
bool ok = false;
void citire(int nod, int val){
    int x;
    fin >> x;
    if(nod % 2 == 0){
        if(x == 0)
            ok = true;
        else
            ok = false;
    }
    else{
        if(x == 0 && ok){
            ok = false;
            rez[++c] = val;
        }
        else
            ok = false;
    }
    if(x){
        citire(nod * 2, x);
        citire(nod * 2 + 1, x);
    }
}
int main(){
    citire(1, 0);
    sort(rez + 1, rez + c + 1);
    for(int i = 1; i <= c; ++i)
        fout << rez[i] << ' ';
    return 0;
}
