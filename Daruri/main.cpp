#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("daruri.in");
ofstream fout("daruri.out");

int main()
{
    int a, b;
    fin >> a >> b;
    int c = a, d = b;
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    if (a == 1)
        fout << 0 << '\n' << 0 << " " << 0;
    else
        fout << a << '\n' << c / a << " " << d / a;
    return 0;
}
