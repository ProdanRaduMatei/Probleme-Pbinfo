/*
Un număr se numește bipătrat dacă este pătrat perfect și, în plus, prin inserarea unei singure cifre numărul obținut este de asemenea pătrat perfect. Inserarea unei cifre se poate face atât între două cifre deja existente ale numărului, cât și la finalul sau la începutul numărului.

De exemplu, din numărul 16, se pot obține prin inserarea unei cifre:

în fața primei cifre: [116, 216, 316, 416, 516, 616, 716, 816, 916]
între cifrele 1 și 6: [106, 116, 126, 136, 146, 156, 166, 176, 186, 196]
după ultima cifră: [160, 161, 162, 163, 164, 165, 166, 167, 168, 169]
Se observă că unele numere se pot obține în urma unei inserări în mai multe moduri. Deoarece numărul 16 este pătrat perfect și 169, 196 sunt și ele pătrate perfecte, numărul 16 este bipătrat.

Cerința
Fiind dată o secvență de numere naturale, să se verifice dacă numerele respective sunt bipătrate, iar pentru cele ce îndeplinesc condiția să se afișeze în ordine crescătoare toate pătratele perfecte care se pot obține prin inserarea unei cifre.

Date de intrare
Fișierul de intrare bipatrat.in conține mai multe numere naturale, câte un număr pe o linie.

Date de ieșire
Fișierul de ieșire bipatrat.out va conține pe linia i cifra 0, dacă numărul scris pe linia i în fișierul de intrare nu este bipătrat, iar în caz contrar, va conține o succesiune de numere naturale separate prin câte un spațiu, scrise în ordine strict crescătoare, reprezentând pătratele perfecte care se pot obține din numărul aflat pe linia i în fișierul de intrare, prin inserarea unei cifre.

Restricții și precizări
În fişierul de intrare sunt maximum 2000 de numere de cel mult 13 cifre.
Inserarea la începutul numărului se poate realiza doar dacă cifra inserată este diferită de 0.
Exemplu:
bipatrat.in

225
144
34
49
16
bipatrat.out

1225 2025 4225 7225
1444
0
0
169 196
Explicație
225 este pătrat perfect și în urma unei inserări se pot obține următoarele pătrate perfecte: 1225, 2025, 4225 și 7225, deci 225 este bipătrat. Similar, 144 este bipătrat, deoarece 1444 este pătrat perfect. 34 nu este pătrat perfect, deci nici bipătrat.
49 este pătrat perfect, dar nu este bipătrat.
16 este explicat în enunț.
*/

#include <fstream>
#include <queue>
#include <cmath>
#define ULL unsigned long long int
using namespace std;

bool patrat(ULL nr) /// Verific daca e patrat perfect
{
    if((int)sqrt(nr)==sqrt(nr))
        return true;
    return false;
}

int nr_cif(ULL n) /// Determin numarul de cifre ale lui n
{
    int nrc=0;
    while(n)
        ++nrc,n/=10;
    return nrc;
}

ULL nou(ULL vechi,int poz,int cif)
{
    if(poz==0)
        return vechi*10+cif;
    ULL rez=0,p=1;
    int i=0;
    while(vechi)
    {
        if(i==poz)
            rez=rez+p*cif,p*=10;
        else
            rez=rez+p*(vechi%10),p*=10,vechi/=10;
        ++i;
    }
    if(poz==i)
        rez=rez+p*cif;
    return rez;
}

int main()
{
    ifstream fin ("bipatrat.in");
    ofstream fout ("bipatrat.out");
    ULL nr;
    while(fin>>nr)
    {
        priority_queue <ULL,vector<ULL>,greater<ULL>> q;
        ULL NOU;
        if(!patrat(nr)) /// Daca numarul citit nu e patrat perfect
            fout<<0; /// afisam 0
        else /// altfel, e patrat perfect si inseram cifre
        {
            int NR_CIF=nr_cif(nr); /// Calculam numarul de cifre ale numarului
            for(int poz=0;poz<=NR_CIF;++poz) /// De exemplu, pentru 837, 7 e pe pozitia 1, 3 pe 2 si 8 pe 3
                for(int cifra=1;cifra<=9;++cifra) /// Inseram cifrele diferite de 0
                {
                    NOU=nou(nr,poz,cifra);
                    if(patrat(NOU))
                        q.push(NOU);
                }
            for(int poz=0;poz<NR_CIF;++poz) /// Pe pozitiile 0,1,2, ... ,NR_CIF
            {
                NOU=nou(nr,poz,0); /// inseram cifra 0
                if(patrat(NOU))
                    q.push(NOU);
            }
            if(q.empty())
                fout<<0;
            else
            {
                ULL nr2=99999999999999999; /// un numar cu mai mult de 13 cifre
                while(!q.empty())
                {
                    if(nr2==q.top()) /// Verificam sa nu se repete (de exemplu: 1444 1444 1444)
                    {
                        q.pop();
                        continue;
                    }
                    fout<<q.top()<<' ';
                    nr2=q.top();
                    q.pop();
                }
            }
        }
        fout<<'\n';
    }
    return 0;
}