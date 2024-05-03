#include <bits/stdc++.h>

#define N_MAX 400002
#define Q_MAX 10002
#define ll long long
#define BUFFER_SIZE 1000002

using namespace std;

FILE *fin = fopen("dss.in", "r");
ofstream fout("dss.out");

char buffer[BUFFER_SIZE];
int pos = -1;

void read_buffer()
{
    fread(buffer, sizeof(char), BUFFER_SIZE, fin);
}

char read_char()
{
    pos++;
    if (pos == BUFFER_SIZE)
    {
        read_buffer();
        pos = 0;
    }
    return buffer[pos];
}

int read_int()
{
    char c;
    while (!isdigit(c = read_char()))
        ;
    int ans = 0;
    while (isdigit(c))
    {
        ans = ans * 10 + c - '0';
        c = read_char();
    }
    return ans;
}

const int MOD = 1e9 + 7;

int pwr(int a, int b)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return 1LL * pwr(a, (b ^ 1)) * a % MOD;
    int p = pwr(a, (b >> 1));
    return 1LL * p * p % MOD;
}

int inv[N_MAX], opp[N_MAX], opm[N_MAX], n, q, bucketCount, bucketSize, v[N_MAX];

struct Query
{
    int l, r;
    int index;
};

bool operator<(const Query &a, const Query &b)
{
    return make_pair(a.l / bucketSize, a.r) < make_pair(b.l / bucketSize, b.r);
}

Query queries[Q_MAX];
int freq[N_MAX], ans[N_MAX];

int main()
{
    read_buffer();
    n = read_int();
    q = read_int();
    for (int i = 1; i <= n + 1; i++)
        inv[i] = pwr(i, MOD - 2);
    for (int i = 1; i <= n + 1; i++)
        opp[i] = 1LL * inv[i] * (i + 1) % MOD;
    for (int i = 0; i <= n; i++)
        opm[i] = 1LL * inv[i + 2] * (i + 1) % MOD;
    bucketCount = sqrt(q);
    bucketSize = n / bucketCount;
    for (int i = 1; i <= n; i++)
        v[i] = read_int();
    for (int i = 1; i <= q; i++)
    {
        queries[i].l = read_int();
        queries[i].r = read_int();
        queries[i].index = i;
    }
    sort(queries + 1, queries + q + 1);
    int l = 1, r = 0;
    int answer = 1;
    for (int i = 1; i <= q; i++)
    {
        while (l > queries[i].l)
        {
            l--;
            freq[v[l]]++;
            answer = 1LL * answer * opp[freq[v[l]]] % MOD;
        }
        while (r < queries[i].r)
        {
            r++;
            freq[v[r]]++;
            answer = 1LL * answer * opp[freq[v[r]]] % MOD;
        }
        while (l < queries[i].l)
        {
            freq[v[l]]--;
            answer = 1LL * answer * opm[freq[v[l]]] % MOD;
            l++;
        }
        while (r > queries[i].r)
        {
            freq[v[r]]--;
            answer = 1LL * answer * opm[freq[v[r]]] % MOD;
            r--;
        }
        ans[queries[i].index] = (1LL * answer - 1 + MOD) % MOD;
    }
    for (int i = 1; i <= q; i++)
        fout << ans[i] << "\n";
    return 0;
}