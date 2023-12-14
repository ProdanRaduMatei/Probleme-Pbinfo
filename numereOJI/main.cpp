#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define Inf 0x3f3f3f3f
#define mod 1000000007

ifstream cin("numereoji.in");
ofstream cout("numereoji.out");

int a[11];
int sol;
int v1[11];
int v2[11];
int afis1[11];
int afis2[11];

int main() {
    int summax = 0;
    for (int i = 1 ; i <= 10 ; ++i)
        cin >> a[i];
    int poow = (1 << 10);
    for (int i = 1 ; i < poow - 1 ; ++i) {
        for (int j = 0 ; j < 10 ; ++j)
            if (i & (1 << j))
                v1[j + 1] = 1;
        for (int ii = i + 1 ; ii < poow - 1 ; ++ii) {
            for (int k = 0 ; k < 10 ; ++k)
                if (ii & (1 << k))
                    v2[k + 1] = 1;
            bool ok = true;
            for (int l = 1 ; l <= 10 ; ++l)
                if (v1[l] == 1 && v2[l] == 1)
                    ok = false;
            if (ok) {
                int sum1 = 0;
                int sum2 = 0;
                for (int l = 1 ; l <= 10 ; ++l)
                    if (v1[l] == 1)
                        sum1 += a[l];
                    else if (v2[l] == 1)
                        sum2 += a[l];
                if(sum1 == sum2)
                    sol++;
                if (sum1 == sum2 && sum1 > summax) {
                    summax = sum1;
                    for (int l = 1 ; l <= 10 ; ++l) {
                        if (v1[l] == 1)
                            afis1[l] = 1;
                        if (v1[l] == 0)
                            afis1[l] = 0;
                        if (v2[l] == 1)
                            afis2[l] = 1;
                        if (v2[l] == 0)
                            afis2[l] = 0;
                    }
                }
            }
            for (int l = 1 ; l <= 10 ; ++l)
                v2[l] = 0;
        }
        for(int l = 1 ; l <= 10 ; ++l)
            v1[l] = 0;
    }
    cout << sol << ' ' << summax << '\n';
    for (int i = 1 ; i <= 10 ; ++i)
        if (afis1[i])
            cout << a[i] << ' ';
    cout << '\n';
    for (int i = 1 ; i <= 10 ; ++i)
        if (afis2[i])
            cout << a[i] << ' ';
    return 0;
}