#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

string nume = "date";

ifstream fin(nume + ".in");
ofstream fout(nume + ".out");

typedef unsigned long long ull;
typedef long long ll;
#define MOD 666013

int main()
{
    int n, m;
    cin >> n >> m;
    int v[1001], frecv[1001] = {0};
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v + 1, v + 1 + n - m);
    int ratie = (v[n - m] - v[1]) / (n - 1);
    for (int i = 1; i <= n - m; ++i)
        frecv[(v[i] - v[1]) / ratie + 1]++;
    for (int i = 2; i < n; ++i)
        if (frecv[i] == 0)
            cout << v[1] + ratie * (i - 1) << ' ';
    return 0;
}