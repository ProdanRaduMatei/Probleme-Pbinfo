#include <bits/stdc++.h>

#define N_MAX 100000
#define PRIME_MAX 250
#define DIG_MAX 1500

using namespace std;

ifstream fin("fuziune.in");
ofstream fout("fuziune.out");

struct prime_list
{
    int len;
    int primes[PRIME_MAX + 5];
};

int C, N;
prime_list primes;
prime_list prime_d[N_MAX + 5];
int parent[N_MAX + 5];
bool used[N_MAX + 5];
int ans[DIG_MAX + 5];
int len_ans;

prime_list prime_decomp(int X)
{
    int last = primes.len;
    prime_list ret;
    ret.len = 0;
    for (int d = 1; d <= primes.len; d++)
        if (X % primes.primes[d] == 0)
        {
            ret.primes[++ret.len] = primes.primes[d];
            while (X % primes.primes[d] == 0)
                X /= primes.primes[d];
        }
    for (int d = 2; 1ll * d * d <= X; d++)
        if (X % d == 0)
        {
            primes.primes[++primes.len] = d;
            ret.primes[++ret.len] = d;
            while (X % d == 0)
                X /= d;
        }
    if (X > 1)
    {
        ret.primes[++ret.len] = X;
        primes.primes[++primes.len] = X;
    }
    if (last != primes.len)
        sort(primes.primes + 1, primes.primes + primes.len + 1);
    sort(ret.primes + 1, ret.primes + ret.len + 1);
    return ret;
}

bool intersect(int a, int b)
{
    int j = 1;
    for (int i = 1; i <= prime_d[a].len && j <= prime_d[b].len; i++)
    {
        while (j <= prime_d[b].len && prime_d[b].primes[j] < prime_d[a].primes[i])
            j++;
        if (j <= prime_d[b].len && prime_d[b].primes[j] == prime_d[a].primes[i])
            return true;
    }
    return false;
}

int unite(int a, int b)
{
    int j = 1;
    prime_list ret;
    ret.len = 0;
    for (int i = 1; i <= prime_d[a].len; i++)
    {
        while (j <= prime_d[b].len && prime_d[b].primes[j] < prime_d[a].primes[i])
            ret.primes[++ret.len] = prime_d[b].primes[j++];
        if (j <= prime_d[b].len && prime_d[b].primes[j] == prime_d[a].primes[i])
            j++;
        ret.primes[++ret.len] = prime_d[a].primes[i];
    }
    for (; j <= prime_d[b].len; j++)
        ret.primes[++ret.len] = prime_d[b].primes[j];
    prime_d[a] = ret;
    return a;
}

int main()
{
    fin >> C >> N;
    int last_N = N;
    for (int i = 1; i <= N; i++)
    {
        int x;
        fin >> x;
        prime_d[i] = prime_decomp(x);
        parent[i] = i;
    }
    int L = 0;
    for (int i = 1; i <= N; i++)
    {
        int idx = i;
        while (L > 0 && intersect(parent[L], idx))
            idx = unite(parent[L--], idx);
        parent[++L] = idx;
    }
    N = L;
    if (C == 1)
    {
        fout << N << "\n";
        return 0;
    }
    for (int i = 1; i <= last_N; i++)
        reverse(prime_d[i].primes + 1, prime_d[i].primes + prime_d[i].len + 1);
    ans[1] = 1;
    len_ans = 1;
    int cnt = 0;
    while (cnt < N)
    {
        int mi = INT_MAX;
        for (int i = 1; i <= N; i++)
        {
            if (prime_d[parent[i]].len == 0)
                continue;
            mi = min(mi, prime_d[parent[i]].primes[prime_d[parent[i]].len]);
        }
        int L = 0;
        for (int i = 1; i <= N; i++)
        {
            if (prime_d[parent[i]].len == 0)
                continue;
            if (mi == prime_d[parent[i]].primes[prime_d[parent[i]].len])
            {
                cnt += used[i] == false;
                used[i] = true;
                prime_d[parent[i]].len--;
            }
        }
        long long t = 0;
        for (int i = 1; i <= len_ans; i++, t /= 10)
            ans[i] = (t += 1ll * ans[i] * mi) % 10;
        while (t)
        {
            ans[++len_ans] = t % 10;
            t /= 10;
        }
    }
    for (int i = len_ans; i >= 1; i--)
        fout << ans[i];
    fout << "\n";
    return 0;
}