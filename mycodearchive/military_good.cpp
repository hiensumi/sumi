#include <iostream>
#include <algorithm>
#include <cstdio>
#define ii pair<int, int>
#define X first
#define Y second
const int N = 4004;
using namespace std;

int n, res;
ii O;
ii a[N]; int s[N];
bool chk[N];

void operator -= (ii& A, ii B) {A.X -= B.X; A.Y -= B.Y;}
bool CCW(ii A, ii B, ii C) {C -= B; B -= A; return B.X * C.Y > B.Y * C.X;}

void Hull() {
    int i, k, t;
    k = 1;
    for(i = 1; i <= n; i++) {
        while (k > 2 && CCW(a[s[k - 2]], a[s[k - 1]], a[i])) k--;
        s[k++] = i;
    }
    for(i = n, t = k + 1; i; i--) {
        while (k > t && CCW(a[s[k - 2]], a[s[k - 1]], a[i])) k--;
        s[k++] = i;
    }
    for(i = 1; i <= n; i++) chk[i] = false;
    for(i = 1; i < k; i++) chk[s[i]] = true;
    int m = 0;
    for(i = 1; i <= n ; i++) if (!chk[i])
        a[++m] = a[i];
    n = m;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &a[i].X, &a[i].Y);
    sort(a + 1, a + 1 + n);
    while (n > 2) {res++; Hull();}
    printf("%d", res);
    return 0;
}
