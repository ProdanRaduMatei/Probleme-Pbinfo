#include <bits/stdc++.h>

#define maxLen 100005

using namespace std;

ifstream fin("pian.in");
ofstream fout("pian.out"), g("pian.txt");

int C, N, A[maxLen], gcdN, L, imin, jmin;
int ls, cnt;
int seg[3 * maxLen];

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int build(int l, int r, int in, int* arr) {
    if (l == r)
        return seg[in] = arr[l];
    int mid = l + (r - l) / 2;
    return seg[in] = gcd(build(l, mid, 2 * in + 1, arr), build(mid + 1, r, 2 * in + 2, arr));
}

int query(int l, int r, int l1, int r1, int in) {
    if (l1 <= l and r <= r1)
        return seg[in];
    if (l > r1 or r < l1)
        return 0;
    int mid = l + (r - l)/2;
    return gcd(query(l, mid, l1, r1, 2 * in + 1), query(mid + 1, r, l1, r1, 2 * in + 2));
}

int findLen(int* arr, int n) {
    build(0, n - 1, 0, arr);
    int i = 0, j = 0;
    int ans = INT_MAX;
    while (i < n) {
        while (j < n and query(0, n - 1, i, j, 0) != gcdN)
            j++;
        if (j == n)
            break;
        if (ans > j - i + 1) {
            ans = min((j - i + 1), ans);
            imin = i + 1;
            jmin = j + 1;
        }
        i++;
        j = max(j, i);
    }
    return ans;
}

int main() {
    fin >> C;
    fin >> N >> gcdN;
    A[0] = gcdN;
    for (int i = 1; i < N; ++i) {
        fin >> A[i];
        gcdN = gcd(gcdN, A[i]);
    }
    if (C == 1) {
        fout << N * gcdN;
        return 0;
    }
    L = findLen(A, N);
    if (L < 2) {
        fout << N + L - 2 << '\n';
        for (int i = jmin - 1; i > 0; --i)
            fout << i << " ";
        for (int i = jmin; i < N; ++i)
            fout << i << " ";
    }
    else {
        fout << N + L - 3 << '\n';
        for (int i = imin; i < jmin - 1; ++i) {
            fout << i << " ";
            cnt++;
        }
        for (int i = jmin - 1; i > 0; --i) {
            fout << i << " ";
            cnt++;
        }
        int i = jmin;
        while (cnt <= N + L - 3) {
            if (i < N)
            fout << i << " ";
            i++;
            cnt++;
        }
    }
    return 0;
}