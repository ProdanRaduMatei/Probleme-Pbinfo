#include <fstream>

using namespace std;

ifstream fin("distincte.in");
ofstream fout("distincte.out");

int main()
{
    int n, A[10001];
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> A[i];
    for (int i = 1; i <= n; i++)
        if (A[i] != A[i + 1])
            fout << A[i] << ' ';
    return 0;
}