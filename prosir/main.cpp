#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("prosir.in");
ofstream fout("prosir.out");

int main()
{
    char s[201];
    fin.getline(s, 201);
    for (int i = 1; s[i]; ++i)
        if (s[i] == ' ' && isalpha(s[i - 1]))
            s[i - 1] = '5';
    s[strlen(s) - 2] = '5';
    fout << s;
    return 0;
}
