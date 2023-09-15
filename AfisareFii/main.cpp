#include <bits/stdc++.h>
using namespace std;
ifstream fin("afisarefii.in");
ofstream fout("afisarefii.out");
vector<int> G[101];
int n , x , k , T[101];
int main() {
    fin >> n;
    for(int i = 1 ; i <= n ; i++) {
        fin >> T[i];
        if(T[i] != 0)
            G[T[i]].push_back(i);
    }
    fin >> k;
    for(int i = 1 ; i <= k ; i++) {
        int rez[101] = {0} , cnt = 0;
        fin >> x;
        for(auto i:G[x])
            cnt++ , rez[cnt] = i;
        fout << cnt << " ";
        for(int i = 1 ; i <= cnt ; i++)
            fout << rez[i] << " ";
        fout << '\n';
    }
}
