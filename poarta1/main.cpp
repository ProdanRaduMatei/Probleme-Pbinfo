#include <fstream>

#define MaxC 10005

using namespace std;

ifstream fin("poarta.in");
ofstream fout("poarta.out");

int nr[MaxC], k, n, nc, start, pr, pasi = 1, potiune;

void read()
{
    char cif;
    fin >> pr >> n;
    while (fin >> cif)
        nr[++k] = cif - '0';
    int aux = n;
    while (aux)
    {
        aux /= 10;
        ++nc;
    }
}

void drum()
{
    int c[MaxC] = {0}, kc, rest = 0, i, val;
    while (k > nc)
    {
        kc = 0;
        pasi++;
        if (nr[k] % 2 == 0)
        {
            potiune += 2;
            if (nr[1] < 2)
            {
                kc = 1;
                c[kc] = (nr[1] * 10 + nr[2]) / 2;
                rest = (nr[1] * 10 + nr[2]) % 2;
                i = 3;
            }
            else
            {
                i = 1;
                rest = 0;
            }
            for (; i <= k; ++i)
            {
                rest = rest * 10 + nr[i];
                c[++kc] = rest / 2;
                rest %= 2;
            }
            for (i = 1; i <= kc; ++i)
                nr[i] = c[i];
            k = kc;
        }
        else
        {
            ++potiune;
            nr[k]--;
        }
    }
    val = 0;
    for (i = 1; i <= k; ++i)
        val = val * 10 + nr[i];
    while (val > n)
    {
        if (val == n + 1)
        {
            pasi++;
            potiune++;
            start = val - 1;
            break;
        }
        if (val % 2 == 0)
        {
            pasi++;
            potiune += 2;
            val /= 2;
        }
        else
        {
            pasi++;
            potiune++;
            val--;
        }
        if (val <= n)
            start = val;
    }
}

void write()
{
    if (pr == 1)
        fout << pasi << endl;
    else
        fout << potiune << endl;
}

int main()
{
    read();
    drum();
    write();
    return 0;
}