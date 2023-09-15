#include <fstream>

using namespace std;

ifstream fin("calcul3.in");
ofstream fout("calcul3.out");

int main()
{
    int e, x;
    char c;
    fin >> e;
    fout << e;
    while (fin >> c) {
        if (c != '=') {
            fin >> x;
            fout << c << x;
            if (c == '+')
                e = e + x;
            else
                e = e - x;
        }
    }
    fout << '=' << e;
    return 0;
}
