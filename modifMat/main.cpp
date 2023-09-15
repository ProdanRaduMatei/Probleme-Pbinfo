#include <fstream>
using namespace std;
ifstream in("matrice.in");
ofstream out("matrice.out");
bool ciur[10005];
int v[55][55];
int p10(int n){
    int p = 1;
    for (int i = 1; i<=n; i++)
        p*=10;
        return p;
    }
int nrcif(int n){
    int c = 1;
    while (n>9){
        n/=10;
        c++;
    }
    return c;
}
bool superprim(int n){
    if (ciur[n])
        return 1;
    int nr = nrcif(n);
    for (int i = 1; i<nr; i++){
        int pr = p10(nr-1);
        int pc = n/pr;
        n = (n%pr)*10+pc;
        if (ciur[n])
            return 1;
    }
    return 0;
}
int main(){
    for (int i = 2; i<=9999; i++)
        ciur[i] = 1;
    for (int i = 2; i<=9999; i++)
        if (ciur[i])
            for (int j = i+i; j<=9999; j+=i)
                ciur[j] = 0;
    int n;
    in >> n;
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            in >> v[i][j];
    for (int i = 1; i<=n/2+1; i++)
        for (int j = i+1; j<=n-i; j++)
            swap(v[i][j],v[n-i+1][j]);
    for (int j = 1; j<=n/2+1; j++)
        for (int i = j+1; i<=n-j; i++)
            if (v[i][j]!=v[i][n-j+1] && superprim(v[i][j]) && superprim(v[i][n-j+1]))
                swap(v[i][j],v[i][n-j+1]);
    for (int i = 1; i<=n; i++, out << "\n")
        for (int j = 1; j<=n; j++)
        out << v[i][j] << " ";
    return 0;
}
