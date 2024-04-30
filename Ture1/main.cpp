#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
///__builtin_popcount(x)

int n;
pair<int, int> a[100005];
map<int, int> l, c;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        l[a[i].first]++;
        c[a[i].second]++;
    }
    int lin, col, linap = 0, colap = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (l[a[i].first] > linap)
            linap = l[a[i].first], lin = a[i].first;
        if (c[a[i].second] > colap)
            colap = c[a[i].second], col = a[i].second;
    }
    int pas = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].first == lin && a[i].second == col)
            continue;
        else if (a[i].first == lin && a[i].second != col)
            pas++;
        else if (a[i].first != lin && a[i].second == col)
            pas++;
        else if (a[i].first != lin && a[i].second != col)
            pas += 2;
    }
    cout << lin << ' ' << col << ' ' << pas;
    return 0;
}