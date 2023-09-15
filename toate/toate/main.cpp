#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("toate.in");
ofstream fout("toate.out");

int main() {
    int n, m = 0, x;
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> x;
        int c = x, y = 0, p = 1;
        while (c)
        {
            if (c % 10 != 9)
            {
                y = y + (c % 10) * p;
                p = p * 10;
            }
            c = c / 10;
        }
        if (y > m)
            m = y;
    }
    fout << m;
    fin.close();
    fout.close();
    return 0;
}
