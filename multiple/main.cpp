#include <fstream>

using namespace std;
ifstream fin("multiple.in");
ofstream fout("multiple.out");


int main()
{
    int T, i;
    unsigned long long int n, k;
    fin >> T;
    for (i = 1; i <= T; ++i)
    {
        fin >> n >> k;
        g << n + k - n % k << "\n";
    }
    return 0;
}
