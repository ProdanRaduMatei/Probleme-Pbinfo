/*
Cerința
Avem la dispoziție un chenar dreptunghiular format din oglinzi. O rază de lumină pornește din colțul stânga jos al dreptunghiului sub un unghi de 45 de grade față de latura de jos a dreptunghiului și lovește latura de sus sau latura din dreapta. Aici se reflectă (pornește spre o altă latură tot sub un unghi de 45 de grade față de latura de care s-a lovit). Își continuă drumul până când ajunge într-un colț al dreptunghiului.



Date de intrare
Programul citește de la tastatură dimensiunile chenarului a și b.

Date de ieșire
Programul va afișa pe ecran numărul de atingeri ale marginilor chenarului. Punctul de pornire și cel final nu se numără.

Restricții și precizări
1 ≤ a ≤ 2000000000
1 ≤ b ≤ 2000000000
Exemple:
Intrare

3 8
Ieșire

9
Intrare

8 4
Ieșire

1
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

long long cmmdc(long long  a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

    
int main () {
    long long a, b;
    cin >> a >> b;
    long long M = a * b /cmmdc(a, b);
    cout << M / a + M / b - 2;
        return 0;
}