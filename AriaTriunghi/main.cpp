#include <bits/stdc++.h>
using namespace std;
ifstream fin("ariatriunghi.in");
ofstream fout("ariatriunghi.out");
int main() {
    int x1 , x2 , x3 , y1 , y2 , y3;
    fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    double b = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
    double c = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
    double s = (a+b+c) / 2;
    double A = sqrt((s - a) * (s - b) * (s - c) * s);
    fout << fixed << setprecision(1) << A;
    return 0;
}
