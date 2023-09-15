#include <iostream>
#include <fstream>

using namespace std;

ifstream in("pachete.in");
ofstream out("pachete.out");

int v[1005];

struct rasp
{
    int poz1,poz2;
} m[1005];

int main()
{
    int n,pozg,c=0;
    in >> n;
    for (int i = 1; i<=n; i++)
        in >> v[i];
    pozg = n+1;
    v[pozg] = 0;
    for (int i = 1; i<=n; i++)
    {
        if (v[i]!=i)
        {
            if (i!=pozg)
            {
                c++;
                swap(v[i],v[pozg]);
                m[c].poz1 = i;
                m[c].poz2 = pozg;
                pozg = i;
            }
            for (int j = 1; j<=n+1; j++)
                if (v[j] == i)
                {
                    c++;
                    m[c].poz1 = j;
                    m[c].poz2 = pozg;
                    swap(v[pozg],v[j]);
                    pozg = j;
                    break;
                }
        }
    }
    out << c << "\n";
    for (int i = 1; i<=c; i++)
        out << m[i].poz1 << " " << m[i].poz2 << "\n";
}
