#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

ifstream fin ("cifra4.in");
ofstream fout ("cifra4.out");

using ll = long long;
int const nmax = 16;
ll const inf = 10000000000000000;

ll pow10[1 + nmax];

int extract(ll number, int k) {
    return number / pow10[k] % 10;
}

ll dp[1 + nmax][2][2];
int seen[1 + nmax][2][2];

bool valid(int isequal, int printed, int ban, int dig, int newdig) {
    if(isequal == 1 && dig < newdig)
        return 0;
    printed |= (0 < newdig);
    if(printed == 1 && newdig == ban)
        return 0;
    return 1;
}

ll dfs(ll number, int k, int isequal, int printed, int ban) {
    if(k == -1)
        return 0 < printed;
    if(seen[k][isequal][printed] == 1)
        return dp[k][isequal][printed];
    seen[k][isequal][printed] = 1;

    int dig = extract(number, k);
    ll result = 0;
    for(int newdig = 0; newdig < 10; newdig++) {
        if(valid(isequal, printed, ban, dig, newdig))
            result += dfs(number, k - 1, (isequal & (newdig == dig)), (printed | (0 < newdig)), ban);
    }
    dp[k][isequal][printed] = result;
    return result;
}

void resetall() {
    for(int i = 0; i <= nmax; i++)
        for(int h = 0; h < 2; h++)
            for(int h2 = 0; h2 < 2; h2++)
                dp[i][h][h2] = seen[i][h][h2] = 0;
}

ll lowerthan(ll number, int ban) {
    if(number < 0)
        return 0;
    resetall();
    ll result = dfs(number, nmax, 1, 0, ban);
    if(0 < ban)
        return result + 1;
    else
        return result;
}

ll binarysearch(ll from, ll to, ll target, int ban) {
    if(from < to) {
        ll mid = (from + to) / 2;
        if(lowerthan(mid, ban) < target)
            return binarysearch(mid + 1, to, target, ban);
        else
            return binarysearch(from, mid, target, ban);
    } else
        return from;
}

bool valid(ll number, int ban) {
    if(ban == 0 && number == 0)
        return 0;
    while(0 < number) {
        if(ban == number % 10 )
            return 0;
        number /= 10;
    }
    return 1;
}

int main() {
    pow10[0] = 1;
    for(int i = 1; i <= nmax; i++)
        pow10[i] = pow10[i - 1] * 10;
    int op;
    fin >> op;
    if(op == 1) {
        ll ban, n;
        fin >> ban >> n;
        fout << binarysearch(0, inf, n, ban);
    } else {
        ll ban, x, y;
        fin >> ban >> x >> y;
        if(y < x)
            swap(x, y);
        fout << (y - x + 1) - (lowerthan(y, ban) - lowerthan(x - 1, ban)) << '\n';
    }
    return 0;
}
