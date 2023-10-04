#include <fstream>
#include <cassert>

using namespace std;

ifstream fin("cartita.in");
ofstream fout("cartita.out");

const int NMAX = 1e5 + 1, LOGMAX = 17;
const long long INF = 1LL * 1e18;

int N, U, Q;

long long A[NMAX];

long long Sum_X = 0, Sum_K = 0;
long long Diff = 0;
int Log2[NMAX];
long long rmq[LOGMAX][NMAX];

void Read() {
    fin >> N;
    assert(1 <= N && N <= 1e5);
    for (int i = 1; i <= N; ++i)
        fin >> A[i], assert(1 <= A[i] && A[i] <= N);
    return;
}

void Update() {
    int i = 0, x = 0, K = 0;
    fin >> i >> x >> K;
    assert(1 <= i && i <= N);
    assert(1 <= x && x <= 400);
    assert(-21 <= K && K <= 21 && K);
    Sum_X += 1LL * x, Sum_K += 1LL * K;
    Diff += 1LL * i * K;
    return;
}

long long my_min(long long a, long long b) {
    return ((a < b) ? a : b);
}

void Initialize() {
    Log2[1] = 0;
    for(int i = 1; i <= N; ++i) {
        if (i > 1)
            Log2[i] = 1 + Log2[(i >> 1)];
        rmq[0][i] = A[i];
    }
    for (int i = 1; i <= Log2[N]; ++i) {
        int Lg = (1 << i);
        for (int j = 1; j <= (N - Lg + 1); ++j)
            rmq[i][j] = my_min(rmq[i - 1][j], rmq[i - 1][j + (Lg >> 1)]);
    }
    return;
}

void Updates() {
    fin >> U;
    assert(1 <= U && U <= 3e5);
    while (U--)
        Update();
    for (int i = 1; i <= N; ++i)
        A[i] += 1LL * Sum_X + 1LL * i * Sum_K - Diff;
    Initialize();
    return;
}

long long Query_Min(int left, int right) {
    int k = Log2[(right - left + 1)];
    return my_min(rmq[k][left], rmq[k][right - (1 << k) + 1]);
}

void Query() {
    int left = 0, right = 0;
    fin >> left >> right;
    assert(1 <= left && left <= right && right <= N);
    fout << Query_Min(left, right) << '\n';
    return;
}

void Queries() {
    fin >> Q;
    assert(1 <= Q && Q <= 2e5);
    while (Q--)
        Query();
    return;
}

int main() {
    Read();
    Updates();
    Queries();
    return 0;
}