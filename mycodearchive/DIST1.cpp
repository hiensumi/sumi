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
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 2e5 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
int n;
ii a[base];
void inp(){
	cin >> n;
	fod(i,1,n) cin >> a[i].fi;
	fod(i,1,n) cin >> a[i].se;
	// sort(a+1,a+n+1);
}

namespace sub_task1{
	void solve(){
		int res = 0;
		fod(i,1,n) fod(j,i+1,n){
			if(a[i].se <= a[j].se) res += (a[j].fi - a[i].fi);
		}
		cout << res << el;
	}	
	
}

namespace sub_task2{
	struct FenwickTree {
	    int b1[base], b2[base];
	    int n;
	    void init(int n){
	    	this-> n = n;
	    }
	    void add(int b[], int idx, int x){
		    while(idx <= n){
		        b[idx] += x;
		        idx += idx & -idx;
			}
		}
		void range_add(int l, int r, int x){
		    add(b1,l,x);
		    add(b1,r+1,-x);
		    add(b2,l,x*(l-1));
		    add(b2,r+1,-x*r);
		}
		int sum(int b[], int idx){
		    int res = 0;
		    while(idx){
		        res += b[idx];
		        idx -= idx & -idx;
		    }
		    return res;
		}
		int getall(int idx){
		    return sum(b1, idx) * idx - sum(b2, idx);
		}
		int get(int l, int r){
			if(l > r) return 0;
			if(l == 0 or r == 0) return 0;
			return getall(r) - getall(l-1);
		}
}sum, cnt;
	struct bg{
		int x, v, id;
	}b[base];
	int op[base];
	const int N = 1e5 + 5;
	bool cmp(bg a, bg b){
		if(a.x == b.x) return a.v < b.v;
		return a.x < b.x;
	}
	void solve(){
		fod(i,1,n){
			b[i] = {a[i].fi, a[i].se, i};	
		}
		sort(b+1,b+n+1,cmp);
		map <int,int> mp; int d = 0;
		fod(i,1,n) mp[b[i].v] = 0;
		for(ii x : mp) mp[x.fi] = ++d;
		fod(i,1,n) b[i].v = mp[b[i].v];
		sum.init((int) N);
		cnt.init((int) N);
		int res = 0;
		fok(i,n,1){
			res += sum.get(b[i].v ,N) - cnt.get(b[i].v, N) * b[i].x;
			sum.range_add(b[i].v, b[i].v, b[i].x);
			cnt.range_add(b[i].v, b[i].v, 1);
		}
		cout << res << el;
		
	}
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	int Test = 1; if(multitest) cin >> Test;
	while(Test--){
		inp();
		sub_task2 :: solve();
	}
	kill();
}