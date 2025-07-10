#include <iostream>
#include <vector>

using namespace std;

void insumeaza(vector<long long>& F, long long x, long long D) {
    for(; x < F.size(); x |= x + 1)
        F[x] += D;
}

long long suma(vector<long long>& F, long long x) {
    long long total = 0;
    for(; x > 0; x &= x - 1)
        total += F[x - 1];
    return total;
}

long long contorizeaza(vector<long long>& F, long long x) {
    return suma(F, F.size()) - suma(F, x);
}

int main() {
    long long N;
    cin >> N;
    vector<long long> F1(N + 1, 0);
    vector<long long> F2(N + 1, 0);
    vector<long long> F3(N + 1, 0);
    for (long long i = 0; i < N; i++) {
        int numar;
        cin >> numar;
        long long S1 = contorizeaza(F1, numar + 1);
        long long S2 = contorizeaza(F2, numar + 1);
        insumeaza(F1, numar, 1);
        insumeaza(F2, numar, S1);
        insumeaza(F3, numar, S2);
    }
    cout << contorizeaza(F3, 0);
    return 0;
}
