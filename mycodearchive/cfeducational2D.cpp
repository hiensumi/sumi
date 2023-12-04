#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define db long double
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
const db pi = acos(-1.0L);
typedef pair<int, int> ii;
struct point{
	int x, y, r;
};
struct edge{
	int u, v, c;
};
/*int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}
bool join(int u, int v) {
    int paru = find(u), parv = find(v);
    if (paru == parv) return false;
    par[parv] = paru;
    return true;
}*/	
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
point a, b;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> a.x >> a.y >> a.r;
	cin >> b.x >> b.y >> b.r;
	cout << setprecision(20);
	db d = sqrt( bpow(a.x-b.x,2) + bpow(a.y-b.y,2));
	if(d >= a.r + b.r) cout << 0;
	else if(d <= abs(a.r - b.r)){
		cout << bpow(min(a.r,b.r),2) * pi << endl;
	}
	else{
		int r1 = max(a.r, b.r), r2 = min(a.r,b.r);
		db d1 = (db) (pow(r1,2) - pow(r2,2) + pow(d,2))/(2*d);
		db d2 = (db) d - d1;
		db fp = (db) pow((db)r1,2)*acos((db)d1/r1) - d1*sqrt(pow((db)r1,2) - pow((db)d1,2));
		db sp = (db) pow((db)r2,2)*acos((db)d2/r2) - d2*sqrt(pow((db)r2,2) - pow((db)d2,2));
		cout << (db) fp + sp;
	}
	// cout << pow(2.5, 2);
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Sit down and code";
	return 0;
}
