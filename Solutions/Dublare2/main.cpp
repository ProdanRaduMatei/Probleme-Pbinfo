/*
Cerința
Se dă un număr natural x
. Afișează numărul obținut prin dublarea fiecărei cifre a numărului x
.

Date de intrare
Pe prima linie se va afla numărul natural x
.

Date de ieșire
Pe prima linie se va afișa numărul obținut prin dublarea fiecărei cifre a numărului x
.

Restricții și precizări
Pentru toate testele, se respectă 1≤x≤109
Subtask 1, 70p: 1≤x≤104
Subtask 2, 30p: restricțiile inițiale
Exemplu 1:
Intrare

102
Ieșire

110022
Exemplu 2:
Intrare

1000000000
Ieșire

11000000000000000000
*/

///Mihai Daniel
#include <iostream>
#include <cstring>
using namespace std;
char x[10],i;
int main()
{
    cin>>x;
    for(i=0;i<strlen(x);i++)
        cout<<x[i]<<x[i];
    return 0;
}