#include <iostream>
using namespace std;

double r1, g1, b1, r2, g2, b2;
int n;
double q1, q2, q3;

int main(){
    cin >> r1 >> g1 >> b1;
    cin >> r2 >> g2 >> b2;
    cin >> n;
    cout << r1 << ", " << g1 << ", " << b1 << "\n";
    q1=r2-r1;
    q2=g2-g1;
    q3=b2-b1;
    for (int i=1; i<n; i++)
        cout << int(r1+q1*i/(n-1)) << ", " << int(g1+q2*i/(n-1)) << ", " << int(b1+q3*i/(n-1)) << "\n";
    return 0;
}
