#include <bits/stdc++.h>
using namespace std;

ifstream fin("cifre_romane.in");
ofstream fout("cifre_romane.out");

char cif_rom[1001] , rez[256];
int n , cnt = 1 , t;

int main()
{
    cin >> n;
    cif_rom[1] = 'I';
    cif_rom[5] = 'V';
    cif_rom[10] = 'X';
    cif_rom[50] = 'L';
    cif_rom[100] = 'C';
    cif_rom[500] = 'D';
    cif_rom[1000] = 'M';
    while(n != 0) {
        int cif = n % 10;
        if(cif == 1)
            rez[++t] = cif_rom[cif * cnt];
        else if(cif == 2) {
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[cnt];
        }
        else if(cif == 3) {
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[cnt];
        }
        else if(cif == 4) {
            rez[++t] = cif_rom[5 * cnt];
            rez[++t] = cif_rom[cnt];
        }
        else if(cif == 5) {
            rez[++t] = cif_rom[5 * cnt];
        }
        else if(cif == 6) {
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[5 * cnt];
        }
        else if(cif == 7) {
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[5 * cnt];
        }
        else if(cif == 8) {
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[cnt];
            rez[++t] = cif_rom[5 * cnt];
        }
        else if(cif == 9) {
            rez[++t] = cif_rom[10 * cnt];
            rez[++t] = cif_rom[cnt];
        }
        n /= 10;
        cnt *= 10;
    }
    for(int i = t ; i >= 1 ; i--)
        cout << rez[i];
    return 0;
}
