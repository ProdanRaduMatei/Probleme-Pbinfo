#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>
#include <string>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream cin("inima.in");
ofstream cout("inima.out");

int n, a[1000005], maxi;

int main() {
    cin >> n;
    int st = 0, poz = 0;
    for (int i = 1 ; i <= n ; ++i)
        cin >> a[i];
    int i = 1, j = n;
    while (i < j) {
        if (min(a[i], a[j]) * (j - i) > maxi)
            maxi = min(a[i], a[j]) * (j - i);
        if (a[i] < a[j])
            i++;
        else
            j--;
    }
    cout << maxi;
    return 0;
}