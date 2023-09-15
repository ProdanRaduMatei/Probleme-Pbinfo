#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("zoom.in");
ofstream fout("zoom.out");

int a[1002][1002] , v[20][20];

int main() {
    int x , y , z , cnt = 0;
    fin >> x >> y >> z;
    for (int i = 0 ; i < x ; ++i)
        for (int j = 0 ; j < x ; ++j)
            fin >> v[i][j];
    for (int i = 0 ; i < y ; ++i)
        for (int j = 0 ; j < z ; ++j)
            fin >> a[i][j];
    for (int i = 0 ; i <= y - x ; ++i)
        for (int j = 0 ; j <= z - x ; ++j) {
            int ok = 0;
            for (int h = i , hi = 0 ; h < i + x ; ++h , ++hi)
                for (int g = j , gj = 0 ; g < j + x ; ++g , ++gj)
                    if (a[h][g] != v[hi][gj])
                        ok = 1;
            if (ok == 0)
                cnt++;
        }
    fout << cnt;
    return 0;
}
