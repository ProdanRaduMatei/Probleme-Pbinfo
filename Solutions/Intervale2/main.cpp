#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

string nume = "intervale2";

ifstream fin(nume + ".in");
ofstream fout(nume + ".out");

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int n, left, right;
    int vst, vdr;
    fin >> n >> left >> right;
    for (int i = 2; i <= n; i++)
    {
        fin >> vst >> vdr;
        if (right < vst || vdr < left)
        {
            fout << 0;
            return 0;
        }
        left = max(left, vst);
        right = min(right, vdr);
    }
    fout << left << ' ' << right;
    return 0;
}