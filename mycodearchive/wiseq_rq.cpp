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
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
namespace solution{
	int n, W, a[base];	
	void inp(){
		cin >> n >> W;
		fod(i,1,n) cin >> a[i];
	}
	// dp[i][j] là độ dài dãy con tăng dài nhất có trọng số <= j kết thúc ở i
	int dp[501][10000];
	void sub1(){
		fod(i,1,n) if(a[i] <= W) dp[i][a[i]] = 1;
		fod(i,1,n) fod(w,1,W){
			fod(j,i+1,n) if(a[j] > a[i]) dp[j][w + a[j]] = max(dp[j][w + a[j]], dp[i][w] + 1);
		}
		int res = 0;
		fod(i,1,n) fod(j,1,W) res = max(res, dp[i][j]);
		cout << res;
	}
	int st[4 * 50004];
	const int N = 5e4 + 5;
	int f[N];
	void update(int i, int l, int r, int u, int v, int val){
		if(v < l or r < u) return;
		if(u <= l and r <= v){
			st[i] = val;
			return;
		}
		int mid = (l + r)/2;
		update(2*i,l,mid, u,v,val);
		update(2*i+1,mid+1,r,u,v,val);
		st[i] = max(st[2*i],st[2*i+1]);
	}
	ll get(int i, int l, int r,int u, int v){
		if(v < l or r < u) return 0;
		if(u <= l and r <= v){
			return st[i];
		}
		int mid = (l + r)/2;
		return max(get(2*i,l,mid,u,v),get(2*i+1,mid+1,r,u,v));
	}
	void sub5(){
		fod(i,1,n) f[a[i]] = 0, update(1,1,N,a[i],a[i],f[a[i]]);
		int res = 0;
		fod(i,1,n){
			f[a[i]] = max(f[a[i]], 1 + get(1,1,N,1,a[i]-1));
			update(1,1,N,a[i],a[i],f[a[i]]);
			res = max(res, f[a[i]]);
		}
		cout << res;
	}
	void solve(){
		inp();
		if(n <= 500) sub1();
		else sub5();
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