#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("lgmax.in");
ofstream fout("lgmax.out");

int main()
{
    int n, l, m = 0;
    char s[256], lg[256];
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin.getline(s, 256);
        l = strlen(s);
        if (l > m) {
            m = l;
            for (int i = 0; i <= l; ++i)
                lg[i] = s[i];
        }
    }
    fout << lg;
    return 0;
}
