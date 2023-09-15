/*
Cerința
Pe un cerc se află N poziții, consecutiv așezate și notate cu 1,2,3,...,N. Distanțele între oricare două poziții vecine sunt egale cu un pas. Un robot se află inițial la poziția 1. În una dintre poziții se află un depozit cu cantitatea X de energie, de la care robotul se poate alimenta. Robotul se poate deplasa pe cerc numai în sensul acelor de ceas. Robotul poate păstra o cantitate maximă W de energie, iar inițial este alimentat la capacitate maximă. Pentru fiecare pas robotul cheltuiește o unitate de energie.

1) Precizându-se numărul de poziții N, energia inițială a robotului W, poziția P a depozitului și cantitatea X de energie existentă inițial în depozit, se cere să se precizeze numărul de pași pe care îi poate efectua robotul.
2) Precizându-se numărul de poziții N, energia inițială a robotului W și cantitatea X de energie existentă inițial în depozit, se vor determina și afișa numărul maxim de pași pe care îi poate efectua robotul și cea mai mică poziție, convenabil aleasă, unde se poate instala depozitul pentru obținerea numărului maxim de pași.

Date de intrare
Pe primul rând al fișierului text robot5.in se află numărul natural C reprezentând cerința.
Dacă C=1, atunci pe al doilea rând și separate prin câte un spațiu se vor afla scrise numerele naturale N, W, X și P.
Dacă C=2, atunci pe al doilea rând și separate prin câte un spațiu se vor afla scrise numerele naturale N, W și X.

Date de ieșire
Dacă C=1, atunci în fișierul de ieșire robot5.out se va scrie un număr natural reprezentând numărul de pași pe care îi poate efectua robotul, iar dacă C=2, atunci în fișierul text robot5.out se vor scrie două numere naturale separate prin spațiu reprezentând numărul maxim de pași pe care îi poate efectua robotul și cea mai mică poziție a depozitului, convenabil aleasă pentru obținerea numărului maxim de pași.

Restricții și precizări
Când ajunge la depozit robotul se alimentează cu maximul de energie posibil, iar cantitatea de energie din depozit scade corespunzător.
2 ≤ N ≤ 10.000
1 ≤ W ≤ 1.000.000.000
1 ≤ X ≤ 1.000.000.000
1 ≤ P ≤ N
Exemplul 1:
robot5.in

1
6 3 3 3
robot5.out

5
Explicație
Avem cerința 1, câți pași va putea face robotul. El are inițial 3 unități de energie și se află la poziția 1 și deci va putea ajunge la poziția 3 din 2 pași folosind 2 unități de energie. Când ajunge la poziția 3 mai are 1 unitate de energie și se alimentează din depozit cu 2 unități, refăcând cele 3 unități de energie maxim posibile. Mai poate face 3 pași și astfel ajunge la poziția 6 cu 0 unități de energie și se oprește. În total a efectuat 5 pași.

Exemplul 2:
robot5.in

2
6 3 3
robot5.out

6 4
Explicație
Depozitul se va instala la poziția 4 și robotul va putea efectua 6 pași, care este maxim.
*/

#include<bits/stdc++.h>
using namespace std;

ifstream fin("robot5.in");
ofstream fout("robot5.out");

int t,n,w,x,p,poz,i,k,maxi;

int main(){
    fin>>t;
    if(t==1){
        fin>>n>>w>>x>>p;
        if(w<p-1)
            fout<<w;
        if(w>=p-1 && p>=x+1)
            fout<<w+x;
        if(w>=p-1 && p<x+1 && w<=n-1)
            fout<<p-1+w;
        if(w>=p-1 && p<x+1 && w>=n)
            fout<<p-1+((x-(p-1))/n + 1)*n + (w-n)+(x-(p-1))%n;
    }
    else{
       fin>>n>>w>>x;
       for(i=1;i<=n;i++){
            p=i;
            if(w<p-1)
                k=w;
            if(w>=p-1 && p>=x+1)
                k=w+x;
            if(w>=p-1 && p<x+1 && w<=n-1)
                k=p-1+w;
            if(w>=p-1 && p<x+1 && w>=n)
                k=p-1+((x-(p-1))/n + 1)*n + (w-n)+(x-(p-1))%n;
            if(k>maxi){
                maxi=k;
                poz=i;
            }
       }
       fout<<maxi<<" "<<poz;
    }
    return 0;
}