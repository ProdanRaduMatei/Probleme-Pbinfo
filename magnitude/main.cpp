#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;

string nume = "magnitudine";

ifstream fin(nume + ".in");
ofstream fout(nume + ".out");

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ull n, k;
    ull v[20], st = 1, dr = 0, len = 0;
    fin >> n >> k;

    while (n)
    {
        v[++len] = n % 10;
        n /= 10;
    }
    dr = len;
    sort(v + 1, v + 1 + len);
    while (k)
    {
        if (v[st + 1] - v[st] < v[dr] - v[dr - 1])
            dr--;
        else
            st++;
        k--;
    }
    fout << v[dr] - v[st];
}
