#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("paranteze3.in");
ofstream fout("paranteze3.out");

char sir[300];
int n, k, ok, st[300];

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> sir;
        k = 0;
        ok = 1;
        for (int j = 0; j < strlen(sir) && ok; ++j)
            if (sir[j] == '(') {
                ++k;
                st[k] = 1;
            }
            else
                if (sir[j] == ')' && k > 0 && st[k] == 1)
                    --k;
                else
                    if (sir[j] == '[') {
                        ++k;
                        st[k] = 2;
                    }
                    else
                        if (sir[j] == ']' && k > 0 && st[k] == 2)
                            --k;
                        else
                            ok = 0;
        if (ok && k == 0)
            fout << 1 << endl;
        else
            fout << 0 << endl;
    }
    return 0;
}
