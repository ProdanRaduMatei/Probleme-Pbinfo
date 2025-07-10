#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ciffrev.in");
ofstream fout("ciffrev.out");

int main()
{
    int a, c = 0, m = 0;
    while (fin>>a) {
        if (a == m)
            ++c;
        else if (a == 2 || a == 3 || a == 5 || a == 7)
                if (a > m) {
                    m = a;
                    c = 1;
            }
    }
    fout << m << " " << c;
    return 0;
}
