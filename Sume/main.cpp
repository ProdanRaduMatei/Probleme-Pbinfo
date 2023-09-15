#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sume.in");
ofstream fout("sume.out");

int main()
{
    int n, v[101], s = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        s = s + v[i];
    }
    for (int i = n; i >= 1; --i) {
        fout << s << endl;
        s = s - v[i];
    }
    return 0;
}
