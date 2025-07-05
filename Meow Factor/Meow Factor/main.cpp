#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void rapid() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

map<long long, long long> factori(long long N) {
    map<long long, long long> M;
    for (long long i = 2; i <= min((ull)sqrt(N), (ull)100000); i++)
        while (N % i == 0) {
            M[i]++;
            N /= i;
        }
    if (N > 1)
        M[N]++;
    return M;
}

int main() {
    rapid();
    long long N;
    cin >> N;
    map<long long, long long> M = factori(N);
    long long rez = 1;
    for (auto& i : M)
        while (i.second >= 9) {
            i.second -= 9;
            rez *= i.first;
        }
    cout << rez;
    return 0;
}
