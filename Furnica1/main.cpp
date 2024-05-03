#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("furnica.in");
ofstream fout("furnica.out");

int cerinta;
int t_u = 5, t_c = 2, t_o = 3, n, i;
long long s, x1, y1, x2, y2, t, l, maxi;

void timp()
{
    fin >> n >> x1 >> y1;
    s = y1 * t_u + x1 * t_o;
    l = y1 + x1;
    y2 = y1;
    maxi = l;
    for (i = 2; i <= n; i++)
    {
        fin >> x2 >> y2;
        if (y2 >= y1)
        {
            s = s + (y2 - y1) * t_u;
            l = l + y2 - y1;
        }
        else
        {
            s = s + (y1 - y2) * t_c;
            if (l > maxi)
                maxi = l;
            l = 0;
        }
        s = s + x2 * t_o;
        y1 = y2;
        l = l + x2;
    }
    s = s + y2 * t_c;
    if (l > maxi)
        maxi = l;
    if (cerinta == 1)
        fout << s;
    else
        fout << maxi;
}

void foaie()
{
    int ok = 0;
    fin >> n >> t >> x1 >> y1;
    s = y1 * t_u + x1 * t_o;
    if (s >= t)
        fout << 1;
    else
    {
        for (i = 2; i <= n; i++)
        {
            fin >> x2 >> y2;
            if (y2 > y1)
            {
                s = s + (y2 - y1) * t_u;
                if (s >= t)
                {
                    ok = 1;
                    fout << i;
                    break;
                }
            }
            else if (y1 > y2)
            {
                s = s + (y1 - y2) * t_c;
                if (s >= t)
                {
                    ok = 1;
                    fout << i - 1;
                    break;
                }
            }
            s = s + x2 * t_o;
            y1 = y2;
            if (s >= t)
            {
                fout << i;
                ok = 1;
                break;
            }
        }
        s = s + y2 * t_c;
        if (ok == 0)
            fout << n;
    }
}

int main()
{
    fin >> cerinta;
    if (cerinta == 1 || cerinta == 2)
        timp();
    else
        foaie();
    return 0;
}