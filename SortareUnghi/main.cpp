#include <bits/stdc++.h>
using namespace std;
ifstream fin("sortareunghi.in");
ofstream fout("sortareunghi.out");
struct elem {
    int x , y;
};
int dist(elem a) {
    return a.x * a.x + a.y * a.y;
}
void citire(elem a[] , int &n) {
    fin >> n;
    for(int i = 1 ; i <= n ; i++)
        fin >> a[i].x >> a[i].y;
}
void afisare(elem a[] , int n) {
    for(int i = 1 ; i <= n ; i++)
        fout << a[i].x << ' ' << a[i].y << '\n';
}
double unghi(elem a) {
    if(a.x > 0 && a.y > 0)
        return 1.0 * a.y / a.x;
    if(a.x < 0 && a.y > 0)
        return 10000 + 1.0 * (-a.x) / a.y;
    if(a.x < 0 && a.y < 0)
        return 20000 + 1.0 * a.y / a.x;
    if(a.x > 0 && a.y < 0)
        return 30000 + 1.0 * a.x / (-a.y);
    if(a.x == 0)
        if(a.y > 0)
            return 10000;
        else
            return 30000;
    else if(a.y == 0)
        if(a.x > 0)
            return 0;
        else
            return 20000;
}
int comp(elem a , elem b) {
    return unghi(a) < unghi(b) || (unghi(a) == unghi(b) && dist(a) < dist(b));
}
int main() {
    elem a[1001];
    int n;
    citire(a , n);
    sort(a + 1 , a + n + 1 , comp);
    afisare(a , n);
    return 0;
}
