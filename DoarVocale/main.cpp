#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("doarvocale.in");
ofstream fout("doarvocale.out");

int main()
{
    char s[31], v[] = "aeiou";
    int n, k = 0, c = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> s;
        k = 0;
        for (int j = 0; j < strlen(s); ++j)
            if (!strchr(v, s[j])) {
                k = 1;
                break;
            }
        if (k == 0)
            ++c;
    }
    fout << c;
    return 0;
}
