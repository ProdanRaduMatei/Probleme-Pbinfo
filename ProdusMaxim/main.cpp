#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("produsmaxim.in");
ofstream fout("produsmaxim.out");
int main()
{
    int n, a, b, c;
    while (fin >> n) {
        a = n / 3;
        if (n % 3 == 0) {
            b = a;
            c = a;
        }
        if (n % 3 == 1) {
            b = a;
            c = a + 1;
        }
        if (n % 3 == 2) {
            b = a + 1;
            c = a + 1;
        }
        fout << n << " " << a << " " << b << " " << c << endl;
    }
}
