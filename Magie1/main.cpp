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

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define mod 1000000007
#define lsb (i & -i)

ifstream cin("magie.in");
ofstream cout("magie.out");

int op,n;
int a[5005];
int v[100005];
int cnt;

int main(){
    cin >> op >> n;
    for (int i = 1 ; i <= n ; ++i)
        cin >> a[i];
    if (op == 1)
    {
        for (int i = 1 ; i <= n ; ++i)
            v [a[i]]++;
        for (int i = 1 ; i <= 5000 ; ++i)
            cnt = max(cnt, v[i]);
        cout << cnt;
    }    
    else if (op == 2)
    {
        for (int i = 1 ; i <= n ; ++i)
        {
            for (int d = 0 ; d <= a[i] ; ++d)
                if (d == 0 || a[i] % d == 0)
                    v[a[i] + d]++,cnt = max(cnt,v[a[i] + d]);
                else
                    v[a[i] + d] = 0;

            for (int d = 1 ; d < a[i] ; ++d)
                v[d] = 0;
            for (int d = a[i] + a[i] + 1 ; d <= 10000 ; ++d)
                v[d] = 0;
        }
        cout << cnt;
    }
    else
    {
        for (int i = 1 ; i <= n ; ++i){
            v[a[i]]++;
            for (int d = 1 ; d <= a[i] ; ++d)
                if (a[i] % d == 0)
                    v[a[i] + d]++;
        }
        for (int i = 1 ; i <= 10000 ; ++i)
            cnt = max(cnt,v[i]);
        cout << cnt;
    }
    return 0;
}