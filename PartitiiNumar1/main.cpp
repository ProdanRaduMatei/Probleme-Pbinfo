#include <cstdio>
#include <algorithm>
using namespace std;
int n, x[50], s;
int afisare(int k)
{
    for(int i = 1; i <= k; i ++)
        printf("%d ", x[i]);
    printf("\n");
}
bool cont(int k)
{
    s = 0;
    if(x[k] < x[k - 1])
        return 0;
    if (x[k]==x[k-1])
        return 0;
    for(int i = 1; i <= k; i ++)
        s = s + x[i];
    if(s <= n)
        return 1;
    return 0;
}
int backtracking(int k)
{
    if(s == n)
        afisare(k - 1);
    for(int i = 1; i <= n - k + 1; i ++) {
        x[k] = i;
        if(cont(k))
            backtracking(k + 1);
    }
}
int main()
{
    freopen("partitiinumar1.in", "r", stdin);
    freopen("partitiinumar1.out", "w", stdout);
    scanf("%d", &n);
    backtracking(1);
    return 0;
}
