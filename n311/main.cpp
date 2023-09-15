#include <bits/stdc++.h>
using namespace std;

ifstream fin("n311.in");
ofstream fout("n311.out");

int a[1000];

int main ()
{
    int n, i = 0;
    fin >> n;
    while (n > 1) {
        if (n % 3 == 0) {
            n /= 3;
            a[++i] = 3;
        }
        else if(n % 3 == 1 && n != 0) {
            n--;
            a[++i] = 1;
        }
        if (n % 3 == 2) {
            n++;
            a[++i] =- 1;
        }
    }
    for (int j = i; j >= 1; --j)
        fout << a[j] << " ";
    return 0;
}
