#include <fstream>
using namespace std;

int main()
{
    int n;
    ifstream fin("halfsort3.in");
    fin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    fin.close();
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if ((a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j]) || (a[i] % 2 && a[j] % 2 && a[i] < a[j]))
                swap(a[i], a[j]);
    ofstream fout("halfsort3.out");
    for (int i = 1; i <= n; ++i)
        fout << a[i] << ' ';
    fout.close();
    return 0;
}