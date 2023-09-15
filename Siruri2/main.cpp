#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("siruri2.in");
ofstream fout("siruri2.out");

int nrdiv(int x) {
    int nr = 0;
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0)
            if (i * i == x)
                ++nr;
            else
                nr = nr + 2;
    return nr;
}

int inv(int x) {
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x = x / 10;
    }
    return y;
}

int main()
{
    int n, p, a = 1, b = 1, c, i = 2;
    fin >> p >> n;
    if (p == 1) {
        if (n <= 2)
            fout << 1 << " " << 1;
        else {
            while (i < n) {
                c = a + b;
                a = b;
                b = c;
                ++i;
            }
            fout << c << " " << nrdiv(c);
        }
    }
    else {
        if (n <= 2)
            fout << 1 << " " << 1;
        else {
            while (i < n) {
                c = inv(a) + inv(b);
                a = b;
                b = c;
                ++i;
            }
            fout << c << " " << nrdiv(c);
        }
    }
    return 0;
}
