#include <fstream>
#include <algorithm>
#define RUP                      \
    ios::sync_with_stdio(false); \
    fin.tie(0);                  \
    fout.tie(0);
#define TOT       \
    fin.close();  \
    fout.close(); \
    return 0;
using namespace std;

ifstream fin("error.in");
ofstream fout("error.out");

int A[100001], B[100001], I[100001], n, x, y, ncif2;

void Impartire(int A[], int a, int b)
{
    for (int i = 30; i > 0; i--)
    {
        a = a % b;
        a = a * 10;
        A[i] = a / b;
    }
}
void Adunare(int A[], int &n, int B[], int m)
{
    int r = 0;
    for (int i = 1; i <= 30; i++)
    {
        int x = A[i] + B[i] + r;
        A[i] = x % 10;
        r = x / 10;
    }
    while (r)
    {
        A[++n] = r % 10;
        r /= 10;
    }
}
void Afisare(int A[], int n)
{
    for (int i = n; i > n - 20; i--)
        fout << A[i] << " ";
}
int main()
{
    RUP int l = 30;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> x >> y;
        Impartire(I, x, y);
        Adunare(A, l, I, 30);
    }
    Afisare(A, 30);
    TOT
}