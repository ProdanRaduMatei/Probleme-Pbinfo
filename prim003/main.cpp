#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

typedef unsigned long long ull;

bool ciur[500001];

int main() {
    for (int i = 2; i <= 500000; i++)
        ciur[i] = 1;
    for (int i = 2; i * i <= 500000; i++)
        if (ciur[i])
            for (int j = i * i; j <= 500000; j += i)
                ciur[j] = 0;
    int sumeP[1000001] = { 0 };
    for (int i = 2; i * i <= 1000000; i++) {
        for (int j = i; i * j <= 1000000; j++)
            if (ciur[i] && ciur[j])
                if (i * j <=  1000000)
            sumeP[i * j] = 1;
            else
            break;
    }
    for (int i = 2; i <= 1000000; i++)
        sumeP[i] += sumeP[i - 1];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        cout << sumeP[b] - sumeP[a - 1] << " ";
    }
    return 0;
}