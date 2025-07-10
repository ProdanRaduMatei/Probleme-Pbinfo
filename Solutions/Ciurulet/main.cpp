#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ciurulet.in");
ofstream fout("ciurulet.out");

const int limit = 1 + 1000000;

char row[limit], sieve[limit];
bool hasDiv[limit];

int main()
{
    int n, i, p, result = 0;
    fin >> n;
    for (i = 2; i <= n; i++)
        fin >> row[i];
    for (p = 2; p <= n; p++)
    {
        if (hasDiv[p])
        {
            sieve[p] = '1';
            result++;
        }
        else
        {
            if (row[p] == '0')
                sieve[p] = '0';
            else
            {
                for (i = p * 2; i <= n; i += p)
                    if (row[i] == '1')
                        break;
                if (i <= n)
                    sieve[p] = '0';
                else
                {
                    sieve[p] = '1';
                    result++;
                    for (i = p * 2; i <= n; i += p)
                        hasDiv[i] = true;
                }
            }
        }
    }
    fout << result << endl;
    for (i = 2; i <= n; i++)
        fout << sieve[i];
    return 0;
}