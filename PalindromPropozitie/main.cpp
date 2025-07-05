#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("palindrom.in");
ofstream fout("palindrom.out");

int main()
{
    int n;
    char s[200], s1[200];
    fin >> n;
    fin.get();
    for (;n;--n) {
        fin.getline(s, 200);
        int nr = 0, ok = 1;
        s1[0] = '\0';
        for (int i = 0; i < strlen(s); ++i)
            if (!isspace(s[i]))
                s1[nr++] = s[i];
        for (int i = 0; i < nr; ++i)
            if (s1[i] != s1[nr - 1 - i])
                ok = 0;
        if (ok)
            fout << 1 << endl;
        else
            fout << 0 << endl;
    }
    return 0;
}
