#include <bits/stdc++.h>

#define MAX 1000005

using namespace std;

ifstream fin("tema.in");
ofstream fout("tema.out");

int C, n, v[100005],nr,poz1,poz2;
long long sp, sc, p, K;
int minf[MAX], maxf[MAX], d, dmax, aux;
bool pr[MAX];

void build_tree(int* b, vector<int>&seg_tree, int l, int r, int vertex) {
    if (l == r) {
        seg_tree[vertex] = b[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(b, seg_tree, l, mid, 2 * vertex);
    build_tree(b, seg_tree, mid + 1, r, 2 * vertex + 1);
    seg_tree[vertex] = __gcd(seg_tree[2 * vertex], seg_tree[2 * vertex + 1]);
}

int range_gcd(vector<int>&seg_tree, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return seg_tree[v];
    int tm = (tl + tr) / 2;
    return __gcd(range_gcd(seg_tree, 2 * v, tl, tm, l, min(tm, r)), range_gcd(seg_tree, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main() {
    pr[0] = pr[1] = 1;
    minf[2] = 2;
    maxf[2] = 2;
    for (int i = 2; i + i < MAX; ++i)
        if (!pr[i]) {
            minf[i] = i;
            maxf[i] = i;
            for (int j = i + i; j <= 1000000; j += i) {
                pr[j] = 1;
                if (!minf[j])
                    minf[j] = i;
                maxf[j] = i;
            }
        }
    fin >> C >> n >> K;
    if (C == 1) {
        for (int i = 0; i < n; ++i)
            fin >> v[i];
        int i, j = 0, lgMax = 0;
        sc = 0;
        sp = 0;
        p = 1;
        for (i = 0; i < n; ++i) {
            if (pr[v[i]] && v[i] > 1)
                sc += v[i];
            else
                sp += v[i];
            p = sc * sp;
            while (p > K) {
                if (pr[v[j]] && v[j] > 1)
                    sc -= v[j];
                else
                    sp -= v[j];
                p = sc * sp;
                ++j;
            }
            lgMax = max(lgMax, i - j + 1);
        }
        fout << lgMax;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        fin>>nr;
        if(pr[nr]&&nr>1)
            nr=minf[nr]*maxf[nr];
        v[i]=nr;
    }
    vector<int> seg_tree(4*n+1,0);
    build_tree(v,seg_tree,0,n-1,1);
    int maxLen=0;
    int l=0,r=0;
    while(r<n&&l<n)
    {
        if(range_gcd(seg_tree,1,0,n-1,l,r)==1)
            l++;
        if(maxLen<r-l+1)
            maxLen=r-l+1,poz1=l+1,poz2=r+1;
        ++r;
    }
    fout<<poz1<<' '<<poz2;
    return 0;
}