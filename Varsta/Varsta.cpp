#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    float a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(2) << (double) int((b * c - a * d) / (d - c) * 100) / 100.0;
    return 0;
}