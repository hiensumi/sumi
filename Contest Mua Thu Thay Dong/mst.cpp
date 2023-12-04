// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
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
	int x, y;
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
const ll INF = 1e18;
const int base = 1e6 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
namespace solution{
	// remember to reset value for multitestcase
	int n, q, par[base];	
	int find(int u) {
	    if (par[u] == u) return u;
	    return par[u] = find(par[u]);
	}
	bool join(int u, int v) {
	    int paru = find(u), parv = find(v);
	    if (paru == parv) return false;
	    par[parv] = paru;
	    return true;
	}
	void inp(){
		cin >> n >> q;
	}
	int a[1005][1005];
	vector <edge> e;
	bool cmp(edge a, edge b){
		return a.c < b.c;
	}
	void sub1(){
		while(q--){
			int imin, imax, jmin, jmax, w; cin >> imin >> imax >> jmin >> jmax >> w;
			fod(i,imin,imax) fod(j,jmin,jmax) a[i][j] += w; 
		}
		fod(i,1,n) fod(j,i+1,n) e.pb({i,j,a[i][j]});
		sort(e.begin(), e.end(), cmp);
		int res = 0;
		fod(i,1,n) par[i] = i;
		for(edge x : e){
			if(join(x.u,x.v)) res += x.c;
		}
		cout << res;
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