#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>

using namespace std;

#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream fin("ciocolata.in");
ofstream fout("ciocolata.out");

int op, n, x;
long long sp[100005], maxi, mini = Inf;

int main() {
    fin >> op >> n;
    if (op == 1) {
        for (int i = 1 ; i <= n ; ++i) {
            fin >> x;
            sp[x]++;
        }
        for (int i = 1 ; i <= 10000 ; ++i)
            if (sp[i] > maxi) {
                maxi = sp[i];
                mini = i;
            }
        fout << mini;
    }
    else {
        for (int i = 1 ; i <= n ; ++i) {
            fin >> x;
            sp[i] = 1ll * sp[i - 1] + x;
        }
        int i = 1, j = n;
        while (i <= j) {
            if (sp[i] - (sp[n] - sp[j - 1]) < mini && sp[i] - (sp[n] - sp[j - 1]) >= 0)
                mini = sp[i] - (sp[n] - sp[j - 1]);
            if(sp[i] > (sp[n] - sp[j - 1]))
                j--;
            else
                i++;
        }
        fout << mini;
    }
    return 0;
}