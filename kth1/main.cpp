#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <map>
#include <cmath>
#include <chrono>
#include <set>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define mod 1000000007
#define lsb (i & -i)

ifstream cin("kth.in");
ofstream cout("kth.out");

int n,k,l,q;
int a[300005];
multiset<int> smin;
multiset<int> smax;
multiset<int>::iterator it,it2,it3;
multiset<int>::reverse_iterator rit;

int rez[300005];
int poz;

int main() {
    cin >> n >> k >> l;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= l; ++i)
        smax.insert(a[i]);
    for (int i = 1; i <= k; ++i)
    {
        it = smax.begin();
        smax.erase(it);
        smin.insert(*it);
    }
    rit = smin.rbegin();
    rez[++poz] = *rit;
    for (int i = l + 1; i <= n; ++i)
    {
        it = smax.find(a[i - l]);
        if (it != smax.end())
        {
            smax.erase(it);
            rit = smin.rbegin();
            if (a[i] > *rit)
                smax.insert(a[i]);
            else
            {
                it2 = smin.end();
                it2--;
                smax.insert(*it2);
                smin.erase(it2);
                smin.insert(a[i]);
            }
        }
        else if (it == smax.end())
        {
            it = smin.find(a[i - l]);
            smin.erase(it);
            it2 = smax.begin();
            if (a[i] < *it2)
                smin.insert(a[i]);
            else
            {
                it3 = smax.begin();
                smin.insert(*it3);
                smax.erase(it3);
                smax.insert(a[i]);
            }
        }
        rit = smin.rbegin();
        rez[++poz] = *rit;
    }
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> k;
        cout << rez[k] << '\n';
    }
    return 0;
}