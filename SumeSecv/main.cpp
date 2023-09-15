#include <fstream>

using namespace std;

ifstream fin("sumesecv.in");
ofstream fout("sumesecv.out");

int main()
{
    int n, m, v[101] = {0}, a, b;
    long long s[101] = {0};
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    fin >> m;
    for (int i = 1; i <= m; ++i) {
        fin >> a >> b;
        fout << s[b] - s[a - 1];
    }
    return 0;
}
