/*
Se dă un șir format din N numere naturale nenule. Elementele șirului sunt numerotate de la stânga la dreapta începând cu poziția 1.

Cerința
Scrieți un program care să determine răspunsul pentru întrebări de următoarele tipuri:
1. Care este cea mai din stânga poziție care conține o valoare strict mai mare decât toate cele din dreapta sa? – întrebare de tipul 1
2. Care sunt pozițiile care conțin valori strict mai mari decât toate cele din stânga lor? – întrebare de tipul 2
3. Dacă fiecărui element aflat între prima și ultima apariție a maximului i-am mări valoarea pentru a ajunge egal cu maximul, care este suma totală a valorilor adăugate? – întrebare de tipul 3

Date de intrare
Fișierul de intrare sir.in conține pe prima linie un număr C (care poate fi 1, 2 sau 3), indicând tipul întrebării. Pe linia a doua se află un număr natural N, reprezentând numărul de elemente din șir. Pe a treia linie a fișierului de intrare se află N numere naturale, reprezentând elementele șirului, date de la stânga la dreapta (cel mai din stânga are poziția 1 și cel mai din dreapta are poziția N). Numerele de pe această linie sunt separate prin câte un spațiu.

Date de ieșire
Dacă C = 1, fișierul de ieșire sir.out trebuie să conțină un număr natural ce reprezintă răspunsul la o întrebare de tipul 1. Dacă C = 2, fișierul de ieșire trebuie să conțină, separați prin câte un spațiu și în ordine crescătoare, indicii determinați ca răspuns la o întrebare de tipul 2. Dacă C = 3, fișierul de ieșire trebuie să conțină un număr ce reprezintă răspunsul la o întrebare de tipul 3.

Restricții și precizări
1 ≤ C ≤ 3
1 ≤ N ≤ 100.000
Numerele din șirul dat sunt cuprinse între 1 și 10.000, inclusiv.
Pentru teste în valoare de 24 de puncte avem C = 1.
Pentru teste în valoare de 32 de puncte avem C = 2.
Pentru teste în valoare de 44 de puncte avem C = 3.
Exemplul 1:
sir.in

1
7
3 2 2 5 3 5 4
sir.out

6
Explicație
Cea mai din stânga poziție a unei valori care este mai mare decât toate cele din dreapta sa este 6 (acolo unde se află valoarea 5)

Exemplul 2:
sir.in

2
7
3 2 2 5 3 5 4
sir.out

1 4
Explicație
1 și 4 sunt pozițiile unde se află valori mai mari decât toate cele din stânga lor.

Exemplul 3:
sir.in

3
8
3 2 2 5 3 1 5 4
sir.out

6
Explicație
Maximul fiind 5, conform explicației de la întrebarea de tipul 3, trebuie mărite două elemente pentru a ajunge egale cu 5. Acestea sunt cel aflat pe poziția 5 (de mărit cu 2) precum și cel de pe poziția 6 (de mărit cu 4). Suma valorilor cu care avem de mărit este 2 + 4 = 6.

Exemplul 4:
sir.in

3
5
3 2 7 5 3
sir.out

0
Explicație
Maximul este 7 și apare o singură dată, deci nu se mai mărește nicio valoare.
*/

#include    <iostream>
#include    <fstream>
#include    <cmath>
#include    <bits/stdc++.h>
#include    <algorithm>

using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");


int main() {

    int n, cer;
    long long sir[100000], x = -999, maxima = -9, maximb = -9;

    fin >> cer >> n;

    for(long long i = 1; i <= n; i++){
        fin >> sir[i];
        if (x < sir[i]){
            x = sir[i];
            maxima = i;
            maximb = i;
        }
        else if (x == sir[i]){
            maximb = i;
        }
    }

    if (cer == 1){
        for(long long i = 1; i <= n; i++){
            bool ver = 0;
            for(long long j = i + 1; j <= n; j++){
                if (sir[i] <= sir[j]){
                    ver = 1;
                    break;
                }
            }
            if (ver == 0){
                fout << i;
                break;
            }
        }
    }
    else if (cer == 2){
        for(long long i = 1; i <= n; i++){
            bool ver = 0;
            for(long long j = i - 1; j >= 1; j--){
                if (sir[i] <= sir[j]){
                    ver = 1;
                    break;
                }
            }
            if (ver == 0){
                fout << i << " ";
            }
        }
    }
    else{
        //cout << maxima << " " << maximb;

        if (maxima == maximb){
            fout << "0";
        }
        else{
            long long s = 0;
            for(int i = maxima; i <= maximb; i++){
                if (sir[i] <= x)
                    s = s + (x - sir[i]);
            }
            fout << s;
        }
    }
    return 0;
}