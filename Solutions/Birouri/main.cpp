#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, m, k, c, level = 0, b = 0, p;
    ifstream fin("birouri.in");
    ofstream fout("birouri.out");
    fin >> c >> n;
    m = n;
    do {
        ++level;
        if (level % 2)
            b += n * m;
        else {
            k = n > m ? m : n;
            p = k * k / 2 - k;
            b += p;
            if (!p)
                --level;
            if (k % 4 == 0)
                n = m = k /= 2;
            else {
                n = n / 2 - 1;
                m = n + 2;
            }
        }
    } while (n && n % 2 == 0);
    if (c == 1)
        fout << level << endl;
    else
        fout << b << endl;
    return 0;
}
