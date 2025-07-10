/*
Un numar se numeste “alipit” daca se obtine prin lipirea a doua sau mai multe numere identice. Exemplu: 121212 sau 111.

Cerința
Să se verifice dacă un număr natural n este “alipit”.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran mesajul DA dacă n este “alipit”, sau mesajul NU în caz contrar .

Restricții și precizări
1 ≤ n ≤ 100.000.000.000
Exemplu:
Intrare

1212
Ieșire

DA
*/

// https://www.pbinfo.ro/probleme/4215/alipit
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string s;
  cin>>s;

  for (int i=1; i<s.size()-1; ++i) {
    if (s.size()%i==0) {
      string chk=s.substr(0,i);
      bool ok=true;
      for (int j=i; j<s.size() && ok; j+=i) {
        if (s.substr(j, i) != chk) ok = false;
      }

      if (ok) {
        cout<<"DA";
        return 0;
      }
    }
  }

  cout<<"NU";
}