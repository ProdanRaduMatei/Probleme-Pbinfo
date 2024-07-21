#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("dreptunghiuri.in");
ofstream fout("dreptunghiuri.out");

int a[1001], b[1001];

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> a[i] >> b[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
            if (b[i] > b[j])
                swap(b[i], b[j]);
        }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
            cnt1++;
        if (b[i] != b[i - 1])
            cnt2++;
    }
    fout << (cnt1) * (cnt2);
    return 0;
}