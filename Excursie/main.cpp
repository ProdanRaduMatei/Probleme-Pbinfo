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
    int n;
    cin >> n;
    int A[1001], B[1001];
    for (int i = 0; i < n; ++i)
        cin >> A[i] >> B[i];
    for (int i = 0; i < n; ++i)
    {
        int energie = 0;
        energie = B[i] - A[i];
        for (int j = i + 1; j <= n + i && energie >= 0; ++j)
            energie += B[j % n] - A[j % n];
        if (energie >= 0)
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}