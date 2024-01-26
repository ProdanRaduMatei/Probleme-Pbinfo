#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream cin("loto.in");
ofstream cout("loto.out");

int op,k,c,m;
int a[100005];
int b[100005];
int fr[55];
int categorie[8];

bool check1()
{
    int cnt = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j)
            if (b[i] == a[j])
                cnt++;
    return cnt == k;
}

bool check2()
{
    int cnt = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= m; ++j)
            if (b[i] == a[j])
                cnt++;
    return cnt == k;
}

bool check3()
{
    int cnt = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k - 1; ++j)
            if (b[i] == a[j])
                cnt++;
    return cnt == k - 1;
}

bool check4()
{
    int cnt = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j)
            if (b[i] == a[j])
                cnt++;
    return cnt == k - 1;
}

bool check5()
{
    int cnt = 0;
    for(int i = 1; i <= k; ++i)
        for(int j = 1; j <= m; ++j)
            if(b[i] == a[j])
                cnt++;
    return cnt == k - 1;
}

bool check6()
{
    int cnt = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= m; ++j)
            if (b[i] == a[j])
                cnt++;
    return cnt == k - 2;
}

int main()
{
    cin >> op >> m >> k >> c;
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    int nr;
    cin >> nr;
    for (int i = 1; i <= nr; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            cin >> b[j];
            fr[b[j]]++;
        }
        if (check1())
            categorie[1]++;
        else if (check2())
            categorie[2]++;
        else if (check3())
            categorie[3]++;
        else if (check4())
            categorie[4]++;
        else if (check5())
            categorie[5]++;
        else if (check6())
            categorie[6]++;
        else
            categorie[7]++;
    }
    if (op == 1)
        cout << categorie[c];
    else
    {
        int maxi = 0;
        for (int i = 1; i <= 49; ++i)
            if (fr[i] > maxi)
                maxi = fr[i];
        for (int i = 1; i <= 49; ++i)
            if (fr[i] == maxi)
                cout << i << ' ';
    }
    return 0;
}