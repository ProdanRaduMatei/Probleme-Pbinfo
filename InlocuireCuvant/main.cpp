#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("inlocuirecuvant.in");
ofstream fout("inlocuirecuvant.out");

int main()
{
    char s[101], a[11], b[11], *p, aux[101];
    fin >> a >> b;
    fin.get();
    fin.get(s, 101);
    while (p = strstr(s, a)) {
        strcpy(aux, b);
        strcat(aux, p + strlen(a));
        strcpy(p, aux);
    }
    fout << s;
    return 0;
}
