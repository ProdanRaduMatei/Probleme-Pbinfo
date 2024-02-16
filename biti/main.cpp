#include <fstream>

using namespace std;

int main()
{
    ifstream fin("biti.in");
    ofstream fout("biti.out");
    int n, x, cnt = 0;
    fin >> n;
    while (n--)
    {
        fin >> x;
        if (x != 0)
        {
            ++x;
            if (32 - __builtin_clz(x) - __builtin_ctz(x) == 1)
                ++cnt;
        }
    }
    fout << cnt;
    return 0;
}