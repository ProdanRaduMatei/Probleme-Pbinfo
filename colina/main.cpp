#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

ifstream fin("colina.in");
ofstream fout("colina.out");

int n, q;
set <int> indici;
struct teren {
    int h;
    int index;
}v[100001];

bool cmp(teren a, teren b) {
    if (a.h < b.h)
        return 1;
    return 0;
}

void read() {
    fin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fin >> v[i].h;
        v[i].index = i;
    }
    sort(v + 1, v + 1 + n, cmp);
}

void afisare() {
    for (int i = 1; i <= n; i++) 
        fout << v[i].h << " " << v[i].index << "\n";
}


void cb(int x) {
    int st = 1, dr = n, mid;
    while (st <= dr) {
        mid = (st + dr) / 2;
        if (v[mid].h >= x)
            dr = mid - 1;
        else
            st = mid + 1;
    }
    bool found = 0;
    if (v[st].h == x) {
        found = 1;
        fout << "DA ";
        while (v[st].h == x) {
            indici.insert(v[st].index);
            st++;
        }
        for (auto e : indici)
            fout << e << " ";
        indici.clear();
        fout << "\n";
    }
    if(!found)
        fout << "NU\n";
}

void solve() {
    int h_dorit;
    for (int i = 1; i <= q; i++) {
        fin >> h_dorit;
        cb(h_dorit);
    }
}


int main(){
    read();
    solve();
}