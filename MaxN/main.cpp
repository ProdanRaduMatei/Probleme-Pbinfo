#include <fstream>

using namespace std;

ifstream fin("maxn.in");
ofstream fout("maxn.out");

int main()
{
    int n, x, mx = 0;
    fin >> n;
    while (n--) {
        fin >> x;
        if (x > mx)
            mx = x;
        fout << mx << " ";
    }
    return 0;
}
