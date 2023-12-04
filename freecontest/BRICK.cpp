// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
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
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { int tmp = x; mul(tmp, Inv(y, mod), mod); return tmp;}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
struct point{int x, y;};
struct edge{int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 2e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, k, a[base];
struct FenwickTree{
	int n, lgn, b[base];
	void init(int _n){
		n = _n;
		lgn = log2(n);
	}
	void add(int idx, int val){
		while(idx <= n){
			b[idx] += val;
			idx += idx & -idx;
		}
	}
	int get(int idx){
		int res = 0;
		while(idx){
			res += b[idx];
			idx -= idx & -idx;
		}
		return res;
	}
	int lower_bound(int val){
		int sum = 0, pos = 0;
		fok(i,lgn,0){
			int j = pos + mask(i);
			if(j < n and sum + b[j] < val){
				sum += b[j];
				pos = j;
			}
		}
		return pos + 1;
	}
}BIT;
#define pvv pair <vector<int>, vector<int>>
pvv st[4*100005];

pvv merge(pvv b, pvv c){
	vector <int> a;
	vector <int> s;
	int res = 0;
	int n = b.fi.size(), m = c.fi.size(), i = 0, j = 0;
	s.pb(0);
	while(i < n and j < m){
		if(b.fi[i] < c.fi[j]){
			a.pb(b.fi[i]);
			s.pb(s.back() + b.fi[i]);
			i++;
		}
		else{
			a.pb(c.fi[j]);
			s.pb(s.back() + c.fi[j]);
			j++;
		}
	}
	for(; i < n; i++) a.pb(b.fi[i]), s.pb(s.back() + b.fi[i]);
	for(; j < m; j++) a.pb(c.fi[j]), s.pb(s.back() + c.fi[j]);
	return {a, s};
}
void build(int i, int l, int r){
	if(l == r){
		st[i].fi.pb(a[l]);
		st[i].se.pb(0);
		st[i].se.pb(a[l]);
		return;
	}
	int mid = l + r >> 1;
	build(2 *i, l , mid);
	build(2*i+1,mid+1,r);
	st[i] = merge(st[2*i], st[2*i+1]);	
}
ii get(int i, int l, int r, int u, int v, int val){
	if(r < u or v < l ){
		return ii(0,0);
	}
	if(u <= l and r <= v){
		int x = st[i].fi.size() - (upper_bound(all(st[i].fi), val) - st[i].fi.begin());
		int sum = 0;
		int sz = st[i].fi.size();
		if(x > 0) sum =  st[i].se[sz] - st[i].se[sz - x];
		return ii(x,sum);
	}
	int mid = l + r >> 1;
	ii getl = get(2*i,l,mid,u,v,val);
	ii getr = get(2*i+1,mid+1,r,u,v,val);
	return ii(getl.fi + getr.fi, getl.se + getr.se);
}
ii get2(int i, int l, int r, int u, int v, int val){
	if(r < u or v < l ){
		return ii(0,0);
	}
	if(u <= l and r <= v){
		int x = lower_bound(all(st[i].fi), val)  - st[i].fi.begin();
		int sum = 0;
		// cout << x << el;
		int sz = st[i].fi.size();
		if(x > 0) sum =  st[i].se[x];
		return ii(x,sum);
	}
	int mid = l + r >> 1;
	ii getl = get2(2*i,l,mid,u,v,val);
	ii getr = get2(2*i+1,mid+1,r,u,v,val);
	return ii(getl.fi + getr.fi, getl.se + getr.se);
}
int ma = -INF;
void inp(){
    cin >> n >> k;
    fod(i,1,n) cin >> a[i], a[i]++, maxi(ma, a[i]);
}
int history[base];
namespace sub_task1{
	int f[base];
    void solve(){
        BIT.init(ma);
        fod(i,1,k-1) BIT.add(a[i],1);
        int pos = k + 1 >> 1;

        fod(i,k,n){
        	BIT.add(a[i], 1);	
			int ans = BIT.lower_bound(pos);
        	f[i] = ans;
        	BIT.add(a[i-k+1], -1);
        }

		build(1,1,n);
		int res = INF;
		fod(i,k,n){
			ii valri = get(1,1,n,i-k+1,i,f[i]);
			ii valle = get2(1,1,n,i-k+1,i,f[i]);
			int ans = valle.fi * f[i] - valle.se + valri.se - f[i] * valri.fi;
			mini(res, ans);
			history[i] = ans;
		}
		fod(i,k,n){
			if(res == history[i]){
				fod(j,i-k+1,i) a[j] = f[i];
				break;
			}
		}
		cout << res << el;
		fod(i,1,n) cout << a[i] - 1 << el;
        
    }	
    
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test--){
        inp();
        sub_task1 :: solve();
    }
    kill();
}