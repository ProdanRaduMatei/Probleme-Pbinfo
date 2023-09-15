#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sir147.in");
ofstream fout("sir147.out");

int main()
{
    int x, a, b, c;
    while (fin >> x) {
        if (x == 1 || x == 4)
            fout << x << " ";
        else {
            a = 1;
            b = 4;
            c = b * 2 - a;
            a = b;
            b = c;
            while (c < x) {
                c = b * 2 - a;
                a = b;
                b = c;
            }
            if (c == x)
                fout << x << " ";
        }
    }
    return 0;
}
