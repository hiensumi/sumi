// hiensumi is on the sky
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<time.h>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name "CV"
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1e18 + 1 + 2 + 3 + 4 + 5 + 12345678910;
typedef pair<int, int> ii;
struct point{
	db x, y;
	point operator- (const point& a)const{
		return {(x - a.x), (y - a.y)};
	}
	int operator* (const point& a)const{
		return x * a.y - y * a.x;
	}
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
int n;
point a[base], h[base];
int ccw(point a, point b, point c){
	return (b - a) * (c - b);
}
bool cmp(point x, point y){
	if(y.y == x.y) return x.x < y.x;
	return x.y < y.y;
}
db kc(point a, point b){
	return (pow((db)a.x - b.x, 2) + pow((db)a.y - b.y, 2));
}
point p1;
bool cmp1(point x, point y){
	if(ccw(p1,x,y) == 0) return kc(p1,x) < kc(p1,y);
	return ccw(p1, x,y) > 0;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n) cin >> a[i].x >> a[i].y;
	// fod(i,1,n) cout << a[i].x << " " << a[i].y << endl;
	sort(a+1,a+n+1,cmp);
	p1 = a[1];
	a[n+1] = a[1];
	sort(a+2,a+n+1,cmp1);
	h[1] = a[1]; h[2] = a[2];
	int m = 2;
	fod(i,3,n+1){
		while(m >= 2 and ccw(h[m-1],h[m],a[i]) <= 0) m--;
		m++; h[m] = a[i];
	}
	// h[m+1] = h[1];
	db res = 0;
	fod(i,1,m-1){
		// cout << h[i].x << " " << h[i].y << endl;
 		res += sqrt(kc(h[i], h[i+1]));
	}
	// fod(i,1,m) cout << h[i].x << " " << h[i].y << endl;
	cout << setprecision(2) << fixed << res;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n";
	return 0;
}
