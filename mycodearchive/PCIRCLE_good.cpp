#include <cstdio>

#define FOR(i, a, b) for( int i = (a), _b = (b); i <= _b; ++i )
#define REP(i, n) for( int i = 0, _n = (n); i < _n; ++i )

int n, pr[40], res[25], ch[40];
int tp[10005][25], count;

void eratos( int n ) {
        REP(i, n+1) pr[i] = 1;
        pr[0] = pr[1] = 0;
        int i = 2;
        while ( i * i <= n ) {
                for( int j = i + i; j <= n; j += i ) pr[j] = 0;
                do ++i; while( i * i <= n && !pr[i] );
        }
}

void backtrack( int k ) {
    if ( k == 2*n ) {
        if (pr[res[k-1] + res[0]]) {
            if ( count < 10000 )
                REP(i, k) tp[count][i] = res[i];
            count++;
        }
    } else  FOR(i, 1, 2*n) if ( !ch[i] && pr[res[k-1]+i] ) {
            res[k] = i; ch[i] = 1;
            backtrack(k+1);
            ch[i] = 0;
        }
}

int main() {
    eratos(39);
    scanf( "%d", &n );
    res[0] = 1; ch[1] = 1; count = 0;
    backtrack(1);
    printf( "%d\n", count );
    REP(i, count < 10000 ? count : 10000) {
        printf( "%d", tp[i][0] );
        FOR(j, 1, 2*n-1) printf( " %d", tp[i][j] );
        putchar('\n');
    }
    return 0;
}
