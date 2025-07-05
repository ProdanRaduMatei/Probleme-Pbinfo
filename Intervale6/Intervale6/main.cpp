#include <fstream>
#include <queue>
#include <vector>

using namespace std;
#define Inf 0x3f3f3f3f

ifstream fin("intervale6.in");
ofstream fout("intervale6.out");

int n;
int x, y;

int cautbin(int x,int y,int a[]){
    int st = 1, dr = n, mij;
    while (st <= dr) {
        mij = (st + dr) / 2;
        if (a[mij] >= x && a[mij] <= y)
            return -1;
        else if (a[mij] < x)
            st = mij + 1;
        else 
            dr = mij - 1;
    }
    return 1;
}

int main() {
    fin >> n;
    int a[n + 1];
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    while (fin >> x >> y)
        if (cautbin(x, y, a) == 1)
            cnt++;
    fout << cnt;
    return 0;
}