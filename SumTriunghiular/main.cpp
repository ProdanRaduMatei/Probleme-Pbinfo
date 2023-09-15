#include <iostream>

using namespace std;

long long n, aux;

int main() {
    cin >> n;
    long long left = 1, right = n;
    for(int i = 1; i <= right; i++) {
        if(1LL * i * (i + 1) / 2 > n) {
            right = i;
            break;
        }
    }
    while(left <= right) {
        aux = left * (left + 1) / 2 + right * (right + 1) / 2;
        if(aux == n) {
            cout << left * (left + 1) / 2 << " " <<right * (right + 1) /2;
            return 0;
        }
        if(aux > n)
            right--;
        else if(aux < n)
            left++;
    }
    cout <<"NU";
    return 0;
}
