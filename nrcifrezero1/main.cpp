#include <iostream>

using namespace std;

int nr_cif_zero(int n, int & nr){
    if (n == 0)
        return nr;
    if(n % 10 == 0)
        nr = 1;
    nr_cif_zero(n / 10, nr);
}

int n, nr;
int main()
{
    cin >> n;
    nr_cif_zero(n, nr);
    cout << nr;
    return 0;
}
