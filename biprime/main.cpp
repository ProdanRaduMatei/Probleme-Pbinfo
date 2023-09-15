/*
Cerința
Se dă n un număr natural care este produsul a două numere prime distincte, şi m reprezentând numărul numerelor mai mici sau egale cu n, prime cu n. Aflaţi cele două numere prime din descompunerea lui n.

Date de intrare
Programul citește de la tastatură numerele n şi m.

Date de ieșire
Programul va afișa pe ecran numerele prime din descompunerea lui n, în ordine crescătoare, separate prin spaţiu.

Restricții și precizări
1 ≤ m ≤ n ≤ 1025
Exemplu:
Intrare

8777 8580
Ieșire

67 131
Explicație
Avem 8777=67•131
*/

#include <iostream>
#include <cstring>
using namespace std;
#define NMax 1000
typedef int Huge[NMax+3];
Huge n,m,UNU,D,RAD;

void AtribValue(Huge H, unsigned long X) {
  H[0] = 0;
  while (X) {
      ++H[0];
      H[H[0]] = X % 10;
      X /= 10;
  }
}

void CopyValue(Huge A,Huge B) /// A <- B
{
    for(int i=0;i<=B[0];++i)
        A[i]=B[i];
}

void Shl(Huge H, int Count)
/* H <- H*10ACount */
{
  /* Shifteaza vectorul cu Count pozitii */
  memmove(&H[Count+1],&H[1],sizeof(int)*H[0]);
  /* Umple primele Count pozitii cu 0 */
  memset(&H[1],0,sizeof(int)*Count);
  /* Incrementeaza numarul de cifre */
  H[0]+=Count;
}

void Shr(Huge H, int Count)
/* H <- H/10ACount */
{
  /* Shifteaza vectorul cu Count pozitii */
  memmove(&H[1],&H[Count+1],sizeof(int)*(H[0]-Count));
  /* Decrementeaza numarul de cifre */
  H[0]-=Count;
}

void Add(Huge A, Huge B)
/* A <- A+B */
{ int i,T=0;

  if (B[0]>A[0])
    { for (i=A[0]+1;i<=B[0];) A[i++]=0;
      A[0]=B[0];
    }
    else for (i=B[0]+1;i<=A[0];) B[i++]=0;
  for (i=1;i<=A[0];i++)
    { A[i]+=B[i]+T;
      T=A[i]/10;
      A[i]%=10;
    }
  if (T) A[++A[0]]=T;
}

void MultHuge(Huge A, Huge B, Huge C)
/* C <- A x B */
{ int i,j,T=0;

  C[0]=A[0]+B[0]-1;
  for (i=1;i<=A[0]+B[0];) C[i++]=0;
  for (i=1;i<=A[0];i++)
    for (j=1;j<=B[0];j++)
      C[i+j-1]+=A[i]*B[j];
  for (i=1;i<=C[0];i++)
    { T=(C[i]+=T)/10;
      C[i]%=10;
    }
  if (T) C[++C[0]]=T;
}

unsigned long Divide(Huge A, unsigned long X)
/* A <- A/X si intoarce A%X */
{ int i;
  unsigned long R=0;

  for (i=A[0];i;i--)
    { A[i]=(R=10*R+A[i])/X;
      R%=X;
    }
  while (!A[A[0]] && A[0]>1) A[0]--;
  return R;
}

int Sgn(Huge H1, Huge H2) {
  // Elimina zero-urile semnificative, daca exista.
  while (H1[0] && !H1[H1[0]]) H1[0]--;
  while (H2[0] && !H2[H2[0]]) H2[0]--;

  if (H1[0] < H2[0]) {
    return -1;
  } else if (H1[0] > H2[0]) {
    return +1;
  }

  for (int i = H1[0]; i > 0; --i) {
    if (H1[i] < H2[i]) {
      return -1;
    } else if (H1[i] > H2[i]) {
      return +1;
    }
  }
  return 0;
}

void Subtract(Huge x,Huge y) /// x <-- x-y
{
  int i,j;
  for (i = 1; i <= x[0]; i++)
    if(x[i]>=y[i])
      x[i]-=y[i];
    else
    {
      j=i+1;
      while(x[j]==0)
        x[j++]=9;
      x[j]--;
      x[i]=10+x[i]-y[i];
    }
  for (; x[0] > 1 && !x[x[0]]; x[0]--); /// sa n-am zerouri nesemnificative
}

void DivideHuge(Huge A,Huge B,Huge C,Huge R) /// A/B = C rest R */
{
    int i;
    R[0]=0;C[0]=A[0]; /// Initializam restul R si catul C
    for(i=A[0];i;i--)
    {
        Shl(R,1);
        R[1]=A[i];
        C[i]=0;
        while(Sgn(B,R)!=1) /// Cat timp R e mai mare decat impartitorul, efectuam scaderi in mod repetat
        {
            C[i]++;
            Subtract(R,B);
        }
    }
    while(!C[C[0]]&&C[0]>1) /// Elimin zerourile nesemnificative
        C[0]--;
}

void Afisare(Huge A)
{
    for(unsigned int i=A[0];i>=1;--i)
        cout<<A[i];
}

void radical(Huge ST,Huge DR) /// Cu cautare binare (intre 1 si D)
{
    Huge JUM;
    CopyValue(JUM,ST);
    Add(JUM,DR);
    Divide(JUM,2);
    Huge RADP;
    MultHuge(JUM,JUM,RADP);
    int semn=Sgn(RADP,D);
    if(semn==0)
    {
        CopyValue(RAD,JUM);
        return;
    }
    if(semn==-1)
        Add(JUM,UNU),radical(JUM,DR);
    else
        Subtract(JUM,UNU),radical(ST,JUM);
}

int main()
{
    char s[30];
    Huge n,m;
    cin>>s;
    unsigned int L=strlen(s);
    for(unsigned int i=0;i<L;++i)
        n[L-i]=s[i]-'0';
    n[0]=L;
    cin>>s;
    L=strlen(s);
    for(unsigned int i=0;i<L;++i)
        m[L-i]=s[i]-'0';
    m[0]=L;
    AtribValue(UNU,1);
    Huge p;
    CopyValue(p,n);
    Subtract(p,m); /// p=n-m
    Add(p,UNU); /// p=n-m+1
    MultHuge(p,p,D); /// D=p*p
    Huge patru;
    AtribValue(patru,4);
    Huge np;
    MultHuge(n,patru,np); /// pp=p*4
    Subtract(D,np); /// D=p*p-4*n
    radical(UNU,D);
    Subtract(p,RAD);
    Divide(p,2);
    Afisare(p);
    cout<<' ';
    Huge cat,rest;
    DivideHuge(n,p,cat,rest);
    Afisare(cat);
    cout<<'\n';
    return 0;
}