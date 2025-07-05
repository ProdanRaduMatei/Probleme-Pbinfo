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

int main()
{
    int n, v[1001], ratie;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
        cin >> v[i];
    sort(v + 1, v + 1 + n - 2);
    ratie = (v[n - 2] - v[1]) / (n - 1);
    for (int i = 1; i < n - 2; ++i)
    {
        if (v[i + 1] - v[i] == 2 * ratie)
            cout << v[i] + ratie << " ";
        else if (v[i + 1] - v[i] == 3 * ratie)
            cout << v[i] + ratie << ' ' << v[i + 1] - ratie;
    }
    return 0;
}