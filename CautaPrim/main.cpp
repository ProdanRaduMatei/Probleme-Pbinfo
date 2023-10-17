#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("cautaprim.in");
    ofstream fout ("cautaprim.out");
    int n, x, d, i;
    fin >> n;
    int numere[101] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0};
    while (n--) {
        fin >> x;
        numere[x] += 1;
    }
    for (i = 99; i >= 11; i -= 2) {
        if (numere[i] != 0)
            continue;
        for (d = 2; d * d < i; ++d)
            if (i % d == 0)
                break;
        if (d * d < i) {}
        else {
            fout << i;
            break;
        }
    }
    return 0;
}