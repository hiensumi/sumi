// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
using namespace std; 
#define            int  long long
#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     fod(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    fok(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define         all(a)  a.begin(),a.end()  
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        mask(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define pra(a,n) fod(_i,1,n)cout<<a[_i]<<el;cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<el; cout<<el; 
struct point{int x, y;};
struct edge{int u, v, c;};
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 2e6 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
vi prime; int sz = 0, np[base];
void init(){
	prime.pb(0);
	np[1] = 1;
	fod(i,2,2000000) if(np[i] == 0){
		prime.pb(i);
		for(int j = i * i; j <= 2000000; j += i) np[j] = 1;
	}
	
} // remember to reset value for multitestcase
int n, q;
map <int, int> sh;
ve <vi> g;
struct DL{
	int type, u, v, t;
}zx[base];
int h[base], par[base][21], f[base];
void dfs(int u, int p){
	for(int v : g[u]) if(v != p){
		h[v] = h[u] + 1;
		par[v][0] = u;
		fod(j,1,20){
			par[v][j] = par[par[v][j-1]][j-1];
		}
		dfs(v,u);
	}
}
int lca(int u, int v){
	if(h[u] < h[v]) swap(u,v);
	int k = h[u] - h[v];
	fod(j,0,20) if(k & mask(j)) u = par[u][j];
	if(u == v) return u;
	int d = log2(h[u]);
	fok(j,d,0) if(par[u][j] != par[v][j]) u = par[u][j], v = par[v][j];
	return par[u][0];
}
int dem = 0;
void inp(){
	cin >> n >> q;
	g.resize(n + 5);
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		if(abs(u - v) == 1) dem++;
	}
	fod(i,1,n) f[i] = 1;
	dfs(1,0);
}

namespace sub1{
   	bool check(int u, int v){
   		int x = lca(u,v);
   		int tmp = f[u];
   		while(u != x){
   			if(f[u] != tmp) return 0;
   			// cout << u << el;
   			u = par[u][0];
   		}
   		while(v != x){
   			if(f[v] != tmp) return 0;
   			// cout << v << el;
   			v = par[v][0];
   		}
   		return f[x] == tmp;
   	}
   	
    void solve(){
    	fod(i,1,q){
    		cin >> zx[i].type >> zx[i].u >> zx[i].v;
    		if(zx[i].type == 1) cin >> zx[i].t;
    	}
    	int stt = 0;
    	fod(i,1,q){
    		int u = zx[i].u, v = zx[i].v, t = zx[i].t;
    		if(zx[i].type == 1){
    			int x = lca(u,v);
    			if(sh.find(t) == sh.end()) sh[t] = prime[++stt];
    			
    			while(u != x){
    				f[u] = f[u] * sh[t] % MOD;
    				u = par[u][0];
    			}
    			
    			while(v != x){
    				f[v] = f[v] * sh[t];
    				v = par[v][0];
    			}
    			
    			f[x] = f[x] * sh[t] % MOD;
    		}
    		else{
    			 
    			cout << check(u,v) << el;
    		}
    	}
    }	
}
namespace sub2{
	struct DL{
		int val;
		bool flag;
	}st[4 * 200005];
	DL combine(DL a, DL b){
		bool fl = (a.flag and b.flag and (a.val == b.val));
		if(fl) return {a.val, fl};
		else return {a.val, fl};
	}
	void build(int i, int l, int r){
		if(l == r){
		 	st[i].val = st[i].flag = 1;
		 	return;
		}
		int mid = l + r >> 1;
		build(2*i,l,mid);
		build(2*i+1,mid+1,r);
		st[i] = combine(st[2*i], st[2*i+1]);
	}
	int lz[4 * 200005];
	void pull(int i){
		if(lz[i] > 1){
			(st[2*i].val *= lz[i]) %= MOD;
			(st[2*i+1].val *= lz[i]) %= MOD;
			(lz[2*i] *= lz[i]) %= MOD;
			(lz[2*i+1] *= lz[i]) %= MOD;
			lz[i] = 1;
		}
	}
	void upd(int i, int l, int r , int u, int v, int val){
		if(r < u or v < l) return;
		if(u <= l and r <= v){
			(st[i].val *= val) %= MOD;
			(lz[i] *= val) %= MOD ;
			return;
		}
		int mid = l + r >> 1;
		pull(i);
		upd(2*i,l,mid,u,v,val);
		upd(2*i+1,mid+1,r,u,v,val);
		
		st[i] = combine(st[2*i], st[2*i+1]);
	}
	
	DL check(int i, int l, int r, int u, int v){
		if(r < u or v < l) return {-1,1};
		if(u <= l and r<= v) return (st[i]);
		pull(i);
		int mid = l + r >> 1;
		DL getl = check(2*i,l,mid,u,v);
		DL getr = check(2*i+1,mid+1,r,u,v);
		if(getl.flag and getr.flag and (getl.val == getr.val or getl.val == -1 or getr.val == -1)){
			int new_val = 0;
			if(getl.val != -1) new_val = getl.val;
			else new_val = getr.val;
			return {new_val, 1};
		}
		else return {getl.val, 0};
	}
	void solve(){
		fod(i,1,q){
    		cin >> zx[i].type >> zx[i].u >> zx[i].v;
    		if(zx[i].type == 1) cin >> zx[i].t;
    	}
    	
    	fod(i,0,4 * 2e5) lz[i] = 1;
    	
    	build(1,1,n);
    	
    	int stt = 0;
    	fod(i,1,q){
    		int u = zx[i].u, v = zx[i].v, t = zx[i].t;
    		if(u > v) swap(u,v);
    		if(zx[i].type == 1){
    			if(sh.find(t) == sh.end()) sh[t] = prime[++stt];
    			
    			upd(1,1,n,u,v,sh[t]);
    		}
    		else{
    			cout << check(1,1,n,u,v).flag << el;
    		}
    	}
    	
	}
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); srand(time(0)); 
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test-- or endless){
        inp();
        // sub1 :: solve();
        if(dem != n - 1) sub1 :: solve();
        else sub2 :: solve();
    }
    kill();
}