#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream in("sumsec.in");
    ofstream out("sumsec.out");
    int n = 0, v[1000], prim1 = 0, prim2 = 0;
    long long s = 0;
    in >> n;
    for (int i=0; i<n; i++) {
        in >> v[i];
        int OK = 1;
        for (int j=2; j<=sqrt(v[i]) && OK; j++)
            if (v[i]%j==0)
                OK = 0;
        if (OK && v[i] != 0 && v[i] != 1) {
            if (!prim1) {
                prim1 = i;
                prim2 = i;
            }
            else
                prim2 = i;
        }
    }
    for (int i=prim1; i<=prim2; i++)
        s += v[i];
    out << s;
    return 0;
}
