#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("paranteze1.in");
ofstream fout("parenteze1.out");

char sir[300];
int n, k, ok;

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> sir;
        k = 0;
        ok = 1;
        for (int j = 0; j < strlen(sir) && ok; ++j)
            if (sir[j] == '(')
                ++k;
            else
                if (sir[j] == ')' && k == 0)
                    ok = 0;
                else
                    --k;
        if (ok && k == 0)
            fout << 1 << endl;
        else
            fout << 0 << endl;
    }
    return 0;
}
