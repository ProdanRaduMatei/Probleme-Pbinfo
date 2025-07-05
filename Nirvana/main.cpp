/*
Cerința
Se dau două șiruri de numere întregi a
 și b
 de lungime n
. Găsește un șir crescător de numere întregi c
, tot de lungime n
 astfel încât ai≤ci≤bi
 pentru orice 1≤i≤n
. Dacă un astfel de șir nu există, afișează −1
.

Date de intrare
Pe prima linie se va afla numărul natural n
. Pe a doua linie se vor afla cele n
 elemente ale șirului a
. Pe a treia linie se vor afla cele n
 elemente ale șirului b
.

Date de ieșire
În cazul în care există soluție, pe prima linie se vor afișa cele n
 elemente ale șirului c
. În caz contrar, se va afișa −1
. Dacă există mai multe soluții, se poate afișa oricare dintre ele.

Restricții și precizări
Pentru toate testele, se respectă 2≤n≤105
 și 1≤ai≤bi≤n
 pentru orice 1≤i≤n
Subtask 1, 30p: Șirul a
 este crescător
Subtask 2, 30p: bi=n
 pentru orice 1≤i≤n
Subtask 3, 40p: restricțiile inițiale
Exemplu 1:
Intrare

3
1 4 2
2 5 6
Ieșire

2 4 4
Explicație
Șirul [2,4,4]
 este crescător și respectă condițiile: 1≤2≤2
, 4≤4≤5
, 2≤4≤6
. Alte exemple de șiruri posibile sunt [2,4,5]
, [1,5,5]
, etc.

Exemplu 2:
Intrare

2
2 1
2 1
Ieșire

-1
Explicație
Știm că 2≤c1≤2
 și 1≤c2≤1
. Putem deduce că nu este posibil ca c1
 să fie mai mic sau egal cu c2
, deci nu există un astfel de șir și se afișează −1
.


*/