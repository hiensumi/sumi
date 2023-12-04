// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
struct point{
	double x, y;
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
const ll INF = 1e18;
const int base = 1e6 + 5;
const bool multitest = 1;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld double
const ld esp = 1e-9;
namespace solution{
	// remember to reset value for multitestcase
	struct Cir{
		point Center;
		ld Rad;
	};
	
	Cir Sc;
	int n;
	point a[base];
	ld dist(point x, point y){
		ld s1 = (x.x - y.x);
		ld s2 = (x.y - y.y);
		return s1 * s2 + s2 * s2;
	}
	ld dist_sum(point x){
		ld res = 0;
		fod(i,1,n) res += dist(x,a[i]);
		return res;
	}
	bool cmp(point a, point b){
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
	void inp(){
		cin >> Sc.Center.x >> Sc.Center.y >> Sc.Rad;
		cin >> n;
		fod(i,1,n) cin >> a[i].x >> a[i].y;
		sort(a+1,a+n+1,cmp);
	}
	bool nt(point x){
		ld d1 = dist(x,Sc.Center);
		return d1 <= (Sc.Rad * Sc.Rad);
	}
	pair<ld, ld> findY(ld x) {
	    ld yl = -1e9, yr = 1e9;
	    fod(i,1,60){
	        ld ym1 = yl + (yr - yl)/3;
	        ld ym2 = yr - (yr - yl)/3;
	        ld d1 = dist_sum({x, ym1});
	        ld d2 = dist_sum({x, ym2});
	        if(d1 < d2) yr = ym2;
	        else yl = ym1;
	    }
	    return {yl, dist_sum({x,yl})};
	}

	point findXY(){
	    ld xl = -1e9, xr = 1e9;
	    fod(i,1,60){
	        ld xm1 = xl + (xr - xl) / 3;
	        ld xm2 = xr - (xr - xl) / 3;
	        auto [y1, d1] = findY(xm1);
	        auto [y2, d2] = findY(xm2);
	        if(d1 < d2) xr = xm2;
	        else xl = xm1;
	    }
	    return {xl, findY(xl).fi};
	}
	void sub1(){
		point res = findXY();
		int best = 0;
		cout << res.x << " " << res.y << el;
		ld bestd = dist(res,a[1]);
		fod(i,2,n){
			ld dis = dist(res,a[i]);
			if(dis < bestd){
				bestd = dis;		
			}
		}
		cout << bestd;
	}
	void solve(){
		inp();
		sub1();
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	else if(fopen(".inp", "r")){
	freopen(".inp", "r", stdin);
	  freopen(".out", "w", stdout);
	}
	int Test = 1; if(multitest) cin >> Test;
	while(Test--) solution :: solve();
	kill();
}