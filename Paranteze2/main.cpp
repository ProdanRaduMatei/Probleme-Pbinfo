#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("paranteze2.in");
ofstream fout("paranteze2.out");

char sir[300];
int n, ad, am = 0;

int main()
{
    fin >> sir;
    for (int i = 0; i < strlen(sir); ++i) {
        if (sir[i] == '(')
            ++ad;
        else
            --ad;
        if (ad > am)
            am = ad;
    }
    fout << am;
    return 0;
}
