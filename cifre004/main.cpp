#include <iostream>
using namespace std;
int main()
{
    int n,cif, sumacifn=0, n9, r9, i, j;
    char num[91];
    cin >> n;
    int copie=n;
    while (copie) {cif=copie%10; copie/=10; sumacifn+=cif; }
    n9=sumacifn/9; r9=sumacifn%9;
    int numar [91];
    for (j=1; j<=n9; ++j) numar[j]=9;
    if (n9==0) { j=1; numar[j]=r9; }
    else {numar[j]=r9; }
    for (i=j+1; i<=sumacifn; ++i)numar[i]=0;
    for (i=1; i<=sumacifn; ++i)
    {
        num[i]=numar[i]+'0';
    }
    for (i=1; i<=sumacifn; ++i) cout << num[i];
    cout << "\n";
    return 0;
}
