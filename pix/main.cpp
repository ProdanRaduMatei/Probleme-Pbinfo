#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream fin("pix.in");
ofstream fout("pix.out");

int n, l;
long long a[100005], nr[100005], rez, sum, cate, s;

int main() {
    fin >> n;
    for (int i = 1 ; i <= n ; ++i)
        fin >> a[i];
    fin >> s;
    nr[++l] = a[1];
    for (int i = 2 ; i <= n ; ++i) {
        if (a[i] == a[i - 1])
            continue;
        if (a[i] > s)
            break;
        nr[++l] = a[i];
    }
    nr[l + 1] = s + 1;
    rez = nr[2] - 1;
    sum = nr[2] - 1;
    for (int i = 2 ; i <= l ; ++i) {
        if (nr[i + 1] - 1 <= sum)
            continue;
        cate = (nr[i + 1] - 1 - sum) / nr[i];
        if (cate * nr[i] + sum < nr[i + 1] - 1)
            cate++;
        rez += cate;
        sum += cate * nr[i];
    }
    fout << rez;
    return 0;
}