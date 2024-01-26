#include <fstream>

using namespace std;

int crnt,n,vl,mt,i,m;
long int x;

ifstream f("numere.in");
ofstream g("numere.out");

bool val(long int a)
{
    if (a < 100)
        return 0;
    int b = a % 10;
    a /= 10;
    while (a)
    {
        if (a % 10 <= b)
            return 0;
        b = a % 10;
        a /= 10;
    }
    return 1;
}

bool munte(int x){
    int v[15], ct = 0;
    while (x)
    {
        ct++;
        v[ct] = x % 10;
        x /= 10;
    }
    int j = 1;
    while (j < ct && v[j] < v[j + 1]) j++;
    if (j == ct || j == 1)
        return 0;
    else
    {
        while (j < ct && v[j] > v[j + 1])
            j++;
        if (j != ct)
            return 0;
    }
    return 1;
}

int main()
{
    f >> n >> crnt;
    if (crnt == 1)
    {
        for (i = 1; i <= n; i++)
        {
            f >> x;
            if (val(x))
                vl++;
            else if (munte(x))
                mt++;
        }
        g << mt << ' ' << vl;
    }
    else
    {
        int vf[10] = {0};
        for (i = 1; i <=n; i++)
        {
            f >> x;
            if (munte(x))
            while (x)
            {
                vf[x % 10]++;
                x /= 10;
            }
        }
        for (i = 1; i <= 9; i++)
        {
            if (vf[i] >= 2)
            {
                g << i;
                m = i;
            }
        }
        if (m != 9)
        {
            for (i = m + 1; i <= 9; i++)
                if (vf[i] ==1 && vf[m] >= 2)
                {
                    g<<i;
                    m++;
                }
        }
        for (i = m - 1; i >= 1; i--)
        {
            if (vf[i] >= 2)
            g << i;
        }
    }
}