#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define DEBUG 0

#define MAXN 390000000
#define MAXNPER384 1015626 
#define NPRIME 4000000

unsigned ciur[MAXNPER384];
int n, prime[NPRIME];

static inline int getBit( int x ) {
    int i = x >> 6;
    int o = (x >> 1) & 31;
    return (ciur[i] >> o) & 1;
}

static inline void setBit( int x ) {
    int i = x >> 6;
    int o = (x >> 1) & 31;
    ciur[i] |= (((unsigned)1) << o);
}

int triprime( int x ) {
    int ntriprime, i, j, k;
    ntriprime = 0;
    i = 0;
    while ( i + 2 < n && prime[i] * prime[j = i + 1] * prime[k = i + 2] <= x ) {
        while ( prime[i] * prime[j] * prime[k] <= x )
            k++;
        k--;
        while ( k > j ) {
            ntriprime += k - j;
            j++;
            while ( k > j && prime[i] * prime[j] * prime[k] > x )
                k--;
        }
        i++;
    }
    return ntriprime;
}

int main() {
    FILE *fin, *fout;
    int a, b, c, i, d, tria, trib;
    fin = fopen( "triprime.in", "r" );
    fscanf( fin, "%d%d", &a, &b );
    fclose( fin );
    c = (b / 6) | 63;
    for ( i = 3; i * i <= c; i += 2 )
        if ( getBit( i ) == 0 )
            for ( d = i * i; d <= c; d += 2 * i )
                setBit( d );
    prime[n++] = 2;
    for ( i = 3; i <= c; i += 2 )
        if ( getBit( i ) == 0 )
            prime[n++] = i;
    prime[n] = c + 1;
    trib = triprime( b );
    tria = triprime( a - 1 );
    fout = fopen( "triprime.out", "w" );
    fprintf( fout, "%d\n", trib - tria );
    fclose( fout );
    return 0;
} 