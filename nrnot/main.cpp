#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nrnot.in");
ofstream fout("nrnot.out");

int main()
{
    int n, s = 0, a, b, i = 1;
    fin >> n;
    while (fin >> a) {
        if (i == 1)
            s = s + n - a;
        else
            if (b - a > 0)
            s = s + b - a - 1;
        b = a;
        ++i;
    }
    s = s + a - 1;
    fout << s;
    return 0;
}
