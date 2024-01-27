#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("nrdiv9.in");
ofstream fout("nrdiv9.out");

unsigned int n, ans = 0;
int prim[25202] = {0};

int main()
{
    fin>>n;
    for (int i = 2; i <= 25201; i++)
        for (int j = 2 * i; j <= 25201; j+=i)
            prim[j] = 1;
    for (unsigned long long i = 2; i <= 25201; i++)
        if (prim[i] == 0)
            for (unsigned long long j = i + 1; j <= 25201; j++)
                if (prim[j] == 0)
                    if (i * i * j * j <= n && i * i * j * j > 0)
                        ans++;
    for (unsigned long long i = 2; i <= 15; i++)
        if (prim[i] == 0)
        {
            long long x = i * i * i * i * i * i * i * i;
            if (x <= n && x > 0)
                ans++;
        }
    fout<<ans;
}