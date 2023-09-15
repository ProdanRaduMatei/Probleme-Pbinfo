#include <iostream>
using namespace std;
int n,a,b,i,j,zona,m[61][61];
int main()
{
    cin >> n;
    for (a=0; a<n; a++)
    {
        i=3*a;
        for (b=0; b<n; b++)
        {
            ++zona; j=3*b;
            m[i+1][j+1]=m[i+1][j+3]=m[i+3][j+1]=m[i+3][j+3]=m[i+2][j+2]=zona;
        }
    }
    for (i=1; i<=3*n; i++)
    {
        for (j=1; j<=3*n; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}
