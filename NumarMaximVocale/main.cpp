#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("vocmax.in");
ofstream fout("vocmax.out");

int main()
{
    int n, l, nr, maxx;
    char s[255], t[255];
    fin >> n;
    fin.getline(s, 255);
    for (int j = 1; j <= n; ++j) {
        fin.getline(s, 255);
        nr = 0;
        l = strlen(s);
        for (int i = 0; i < l; ++i)
            if (strchr("aeiou", s[i]))
                ++nr;
        if (nr > maxx) {
            maxx = nr;
            strcpy(t, s);
        }
    }
    fout << t;
    return 0;
}
