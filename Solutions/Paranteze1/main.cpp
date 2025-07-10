#include <iostream>
#include <string.h>
#include <stack>
#include <fstream>

using namespace std;

ifstream fin("paranteze1.in");
ofstream fout("paranteze1.out");

int n, ok;
char c[256];

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> c;
        stack<char>s;
        ok = 1;
        for (int cn = 0; cn < strlen(c); ++cn) {
            if (c[cn] == '(')
                s.push(c[cn]);
            else {
                if (s.empty() && cn != strlen(c) - 1) {
                    ok = 0;
                    cn = strlen(c);
                }
                else
                    s.pop();
            }
        }
        if (!s.empty())
            fout << 0 << endl;
        else
            fout << ok << endl;

    }
    return 0;
}
