#include <bits/stdc++.h>
using namespace std;
ifstream fin("punctsegment.in");
ofstream fout("punctsegment.out");
struct andra {
    int i , j;
};
int main() {
    andra x1 , x2 , x3;
    fin >> x1.i >> x1.j >> x2.i >> x2.j >> x3.i >> x3.j;
    int seg1 = (x1.i - x2.i) * (x1.i - x2.i) + (x1.j - x2.j) * (x1.j - x2.j);
    int seg2 = (x3.i - x1.i) * (x3.i - x1.i) + (x3.j - x1.j) * (x3.j - x1.j);
    int seg3 = (x3.i - x2.i) * (x3.i - x2.i) + (x3.j - x2.j) * (x3.j - x2.j);
    double a = sqrt(seg1) * 10 ;
    double b = sqrt(seg2) * 10 ;
    double c = sqrt(seg3) * 10 ;
    if((int)a + (int)b == (int)c)
        fout << "DA";
    else
        fout << "NU";
    return 0;
}
