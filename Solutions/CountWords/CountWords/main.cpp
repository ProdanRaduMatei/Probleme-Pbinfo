#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct cuvant
{
    char cuv[101];
    int fr=0;
} a[1001];
 
char s[10001], *pc;
int n=0;
 
bool cmp (const cuvant &lhs, const cuvant &rhs)
{
    if (strcmp(lhs.cuv, rhs.cuv)<0) return 1;
    return 0;
}
 
int main()
{
    cin.getline(s, 10001);
    pc = strtok(s, " ,.!;:");
    while (pc)
    {
        int ok = 0;
        for (int i=0; i<n; i++)
            if (strcmp(a[i].cuv, pc)==0)
            {
                a[i].fr++;
                ok=1;
            }
 
        if (!ok)
        {
            strcpy(a[n].cuv, pc);
            a[n].fr=1;
            n++;
        }
        pc = strtok(NULL, " ,.!;:");
    }
 
    sort (a, a+n, cmp);
 
    for (int i=0; i<n; i++)
        cout<<a[i].cuv<<" "<<a[i].fr<<endl;
}
