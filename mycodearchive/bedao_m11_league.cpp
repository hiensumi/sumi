#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <math.h>
#include <map>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <cstring>
#include <stack>
#include <iomanip>
#include <assert.h>

#define BIT(x,pos) (((x)>>(pos)) & 1LL)
#define _(x) (1LL<<(x))
#define bitCnt(x) __builtin_popcountll(x)
#define turnOn(x,pos) ((x) = (_(pos)))
#define turnOff(x,pos) ((x) &= ~(_(pos)))
#define flipBit(x,pos) ((x) ^= (_(pos)))
#define lowBit(x) ((x) & (-x))
#define turnAll(x) (_(x)-1LL)

#define name "test"
#define nameTask ""
#define fastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 20;

struct Data
{
    int ind, Pts, GD, WinGoal;
    Data(int _ind = 0, int _Pts = 0, int _GD = 0, int _WinGoal = 0)
    {
        ind = _ind;
        Pts = _Pts;
        GD = _GD;
        WinGoal = _WinGoal;
    }
} a[N+9];

int n;
int Pts[N+9], WinGoal[N+9], LoseGoal[N+9];

bool cmp(Data x, Data y)
{
    return (x.Pts < y.Pts ||
            (x.Pts == y.Pts && x.GD < y.GD) ||
            (x.Pts == y.Pts && x.GD == y.GD && x.WinGoal < y.WinGoal));
}

int main()
{
    fastIO

    cin>>n;

    for (int i = 1;i <= n; ++i) cin>>a[i].ind;

    for (int i = 1;i <= n*(n-1); ++i)
    {
        int teamOne, teamTwo, x, y;
        cin>>teamOne>>teamTwo>>x>>y;

        if (x > y) Pts[teamOne] += 3;
        else if (x < y) Pts[teamTwo] += 3;
        else if (x == y) Pts[teamOne] += 1, Pts[teamTwo] += 1;

        WinGoal[teamOne] += x; WinGoal[teamTwo] += y;
        LoseGoal[teamOne] += y; LoseGoal[teamTwo] += x;
    }

    for (int i = 1;i <= n; ++i)
        a[i].Pts = Pts[a[i].ind],
        a[i].GD = WinGoal[a[i].ind] - LoseGoal[a[i].ind],
        a[i].WinGoal = WinGoal[a[i].ind];

    sort(a+1,a+1+n,cmp);

    int mxPts = a[n].Pts;
    int mxGD = a[n].GD;
    int mxWG = a[n].WinGoal;

    for (int i = 1;i <= n; ++i)
        if (a[i].Pts == mxPts && a[i].GD == mxGD && a[i].WinGoal == mxWG) cout<<a[i].ind<<" ";
}
