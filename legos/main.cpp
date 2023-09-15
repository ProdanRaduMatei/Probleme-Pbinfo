/*
Un joc de lego are P piese care sunt cuburi identice. Dorel se joacă cu ele pentru a construi diverse jucării, dar pentru aceasta are nevoie de ajutorul vostru.

Cerințe
Cunoscându-se numărul de piese P pe care le are, Dorel vrea să știe:
1) Numărul de piese din care poate să construiască cea mai mare fundație. O fundație are forma unui pătrat și are latura formată din cel puțin 3 piese (ca în figura 1).
2) Numărul de piese din cel mai înalt turn care se poate construi. Un turn din piese de lego Dorel îl construiește astfel: la început va face un pătrat pe care îl numește parter (sau etajul 0). Peste acesta va pune 4 piese în colțuri pe care le numește piloni. Apoi, peste piloni, va pune un nou pătrat pe care îl numește etaj 1. Peste acesta va pune din nou piloni, peste care va pune etajul 2. Și va continua, până la ultimul etaj. Peste ultimul etaj nu pune piloni. Toate etajele construite au același număr de piese și au forma de pătrat cu latura de cel puțin 3 piese. Înălțimea unui turn este dată de numărul de etaje. Pilonii nu sunt considerați etaje, aceștia fac parte din structura turnului. Dacă se pot construi mai multe turnuri având aceeași înălțime, atunci Dorel vrea să știe numărul de piese al turnului cu cele mai multe piese.(Vezi figura 2).
3) Numărul de terenuri de legoball care se pot construi folosind toate piesele de lego. Un teren de legoball are forma unui dreptunghi în care fiecare latură este formată din cel puțin 3 piese (ca în figura 3).







Date de intrare
Fișierul de intrare legos.in conține două numere naturale nenule C și P, separate printr-un singur spațiu liber, reprezentând cerința respectiv numărul de piese de lego pe care le are Dorel.

Date de ieșire
Pentru fiecare din cele 3 cerințe fișierul legos.out va conține un singur număr care reprezintă răspunsul la acea cerință.

Restricții și precizări
1 ≤ C ≤ 3
1 ≤ P ≤ 1.000.000.000
Pentru cerința 2 un turn poate fi format doar din parter, dar nu poate fi format din parter și piloni (deoarece ar
avea piloni peste ultimul etaj).
Pentru 31 de puncte, C = 1
Pentru 33 de puncte, C = 2
Pentru 36 de puncte, C = 3
Exemplul 1:
legos.in

1 29
legos.out

25
Explicație
Se rezolvă cerința 1. Sunt 29 piese de lego. Cea mai mare fundație ce poate fi construită are dimensiunea 5 x 5, este formată din 25 de piese.

Exemplul 2:
legos.in

2 19
legos.out

16
Explicație
Se rezolvă cerința 2. Sunt 19 piese de lego. Cel mai înalt turn care poate fi făcut este format doar din parter. Există două astfel de turnuri, unul are 9 piese iar celălalt 16. Dintre acestea mai multe sunt în turnul de 16 piese.

Exemplul 3:
legos.in

3 18
legos.out

2
Explicație
Se rezolvă cerința 3. Sunt două moduri de a construi un teren de legoball. Acestea au dimensiunile 3 x 6, respectiv 6 x 3.
*/


