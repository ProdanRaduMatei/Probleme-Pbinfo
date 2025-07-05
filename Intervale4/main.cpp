#include <bits/stdc++.h>
using namespace std;
ifstream fin("intervale4.in");
ofstream fout("intervale4.out");
struct perechi{
    int x , y;
};
perechi a[100001];
bool intersectie(int i) {
    return !(a[i].x > a[i-1].y || a[i].y < a[i-1].x);
}
int main() {
    int n;
    fin >> n;
    for(int i = 1 ; i <= n ; ++i) {
        fin >> a[i].x >> a[i].y;
        while(i > 1 && intersectie(i)) {
            a[i-1].x = min(a[i].x , a[i-1].x);
            a[i-1].y = max(a[i].y , a[i-1].y);
            i--;
            n--;
        }
    }
    fout << n;
    return 0;
}
