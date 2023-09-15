#include <iostream>
using namespace std;
int main()
{
    long long n;
    int b;
    cin >> n;
    cin >> b;
    long long masca = 1;
    masca = masca << b;
    n = n | masca;
    cout << n;
    return 0;
}
