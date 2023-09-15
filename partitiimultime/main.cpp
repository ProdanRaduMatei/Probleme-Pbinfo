#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("partitiimultime.in");
ofstream fout("partitiimultime.out");

char sp3[]="               ";

int x3[20], n3, nrsol3, max[20], maxim;

int DeterminareMaxim(int k) {
    int maxim = 0,i;
    for(i = 1; i <= k; i++)
        if (x3[i] > maxim)
            maxim = x3[i];
    return maxim;
}

void Afisare3() {
    maxim = DeterminareMaxim(n3);
    for(int j = 1; j <= maxim; j++) {
        for(int i = 1; i <= n3; i++)
            if (x3[i] == j)
                fout << i;
       fout << "*";
    }
    fout << endl;
}

void BackRec3(int k) {
    for(int i = 1; i <= DeterminareMaxim(k - 1) + 1; i++) {
        x3[k] = i;
        if (k == n3)
            Afisare3();
        else BackRec3(k + 1);
    }
}

int main()
{
    fin >> n3;
    BackRec3(1);
    return 0;
}
