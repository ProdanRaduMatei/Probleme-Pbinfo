#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("nrdiv.in");
ofstream fout("nrdiv.out");
int main()
{
    int n, d, cnt = 0;
    fin >> n;
    for (d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            if (d * d == n)
                ++cnt;
            if (n % d == 0 && d * d != n)
                cnt = cnt + 2;
        }
    }
    fout << cnt;
    return 0;
}
