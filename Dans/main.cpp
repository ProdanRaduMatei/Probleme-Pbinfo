#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("dans.in");
ofstream fout("dans.out");

int main() {
    int n, t, c, T = 0, C = 0, mi = 16, ma = 4;
    fin >> n;
    while(n--) {
        fin >> t >> c;
        T += t;
        C += c;
        if (t > ma)
            ma = t;
        if (t < mi)
            mi = t;
    }
    if (T > 90)
        fout << "NU";
    else
        fout << "DA";
    fout << endl;
    int dif = 90 - T;
    if (dif < 0)
        dif *= -1;
    fout << dif << endl << C << endl << ma << " " << mi;
    return 0;
}