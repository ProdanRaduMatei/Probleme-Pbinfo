#include <iostream>
#include <cstring>
#define N 100001
using namespace std;
typedef int Huge[N + 3];

void Shl(Huge H, int Count)
{
    memmove(&H[Count + 1], &H[1], sizeof(int) * H[0]);
    memset(&H[1], 0, sizeof(int) * Count);
    H[0] += Count;
}

int Sgn(Huge H1, Huge H2)
{
    while (H1[1] && !H1[H1[0]])
        H1[0]--;
    while (H2[0] && !H2[H2[0]])
        H2[0]--;
    if (H1[0] < H2[0])
        return -1;
    else if (H1[0] > H2[0])
        return +1;
    for (int i = H1[0]; i > 0; --i)
    {
        if (H1[i] < H2[i])
            return -1;
        else if (H1[i] > H2[i])
            return +1;
    }
    return 0;
}

void Substract(Huge A, Huge B)
{
    int i, T = 0;
    for (i = B[0] + 1; i <= A[0];)
        B[i++] = 0;
    for (i = 1; i <= A[0]; ++i)
        A[i] += (T = (A[i] -= B[i] + T) < 0) ? 10 : 0;
    while (!A[A[0]] && A[0] > 1)
        A[0]--;
}

void DivideHuge(Huge A, Huge B, Huge C, Huge R)
{
    int i;
    R[0] = 0;
    C[0] = A[0];
    for (i = A[0]; i; --i)
    {
        Shl(R, 1);
        R[1] = A[i];
        C[i] = 0;
        while (Sgn(B, R) != 1)
        {
            C[i]++;
            Substract(R, B);
        }
    }
    while (!C[C[0]] && C[0] > 1)
        C[0]--;
}

void MultHuge(Huge A, Huge B)
{
    Huge C;
    int i, j, T = 0;
    C[0] = A[0] + B[0] - 1;
    for (i = 1; i <= A[0] + B[0];)
        C[i++] = 0;
    for (i = 1; i <= A[0]; ++i)
        for (j = 1; j <= B[0]; ++j)
            C[i + j - 1] += A[i] * B[j];
    for (i = 1; i <= C[0]; ++i)
    {
        T = (C[i] += T) / 10;
        C[i] %= 10;
    }
    if (T)
        C[++C[0]] = T;
    for (int i = 0; i <= C[0]; ++i)
        A[i] = C[i];
}

void ExpLog(Huge H, int n)
{
    Huge P;
    P[0] = P[1] = 1;
    while (n)
    {
        if (n & 1)
        {
            MultHuge(P, H);
            --n;
        }
        MultHuge(H, H);
        n >>= 1;
    }
    for (int i = 0; i <= P[0]; ++i)
        H[i] = P[i];
}

void Afis(Huge H)
{
    for (int i = H[0]; i >= 1; --i)
        cout << H[i];
    cout << '\n';
}

int main()
{
    char x[N], a[N], b[N];
    int n;
    cin >> x >> a >> b >> n;
    Huge X, A, B;
    X[0] = strlen(x), A[0] = strlen(a), B[0] = strlen(b);
    for (int i = 1; i <= X[0]; ++i)
        X[i] = x[X[0] - i] - '0';
    for (int i = 1; i <= A[0]; ++i)
        A[i] = a[A[0] - i] - '0';
    for (int i = 1; i <= B[0]; ++i)
        B[i] = b[B[0] - i] - '0';
    Huge C, R;
    DivideHuge(A, B, C, R);
    ExpLog(C, n - 1);
    MultHuge(X, C);
    Afis(X);
    return 0;
}