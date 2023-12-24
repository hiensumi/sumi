#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

#define SZ 100000+5
#define REP(i, n) for( int i = 0, _n = (n); i < _n; ++i )
int a[SZ], b[SZ], n;

int abs( int x ) { return x > 0 ? x : (-x); }

int bsearch( int * a, int x ) {
    if ( a[0] > x ) return a[0];
    if ( a[n-1] < x ) return a[n-1];
    int l = 0, h = n-1;
    while( l <= h ) {
        int mid = (l+h)/2;
        if ( a[mid] == x ) return a[mid];
        else if ( a[mid] < x ) l = mid + 1;
        else h = mid - 1;
    }
    if ( abs(a[l] - x) < abs(a[h] - x) ) return a[l];
    return a[h];
}

int main() {
    scanf( "%d", &n );
    REP(i, n) scanf( "%d", a+i ); REP(i, n) scanf( "%d", b+i );
    sort(b, b+n); int min = INT_MAX;
    REP(i, n) {
        int x = bsearch(b, -a[i]);
        int x2 = abs(a[i] + x);	
        if ( x2 == 0 ) { printf( "%d", 0 ); return 0; }
        if ( x2 < min ) min = x2;
    }
    printf( "%d", min );
    return 0;
}
