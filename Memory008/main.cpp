#include <fstream>

using namespace std;

ifstream fin("memory008.in");
ofstream fout("memory008.out");

int n;
unsigned long long rez, x;

int main()
{
    fin >> n;
    rez = 0;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        rez = rez ^ x;
    }
    fout << rez;
    return 0;
}
