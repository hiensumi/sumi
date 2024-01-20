// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
#include <unordered_set>
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
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << " [ .... EtnallirB AnuL ...].\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase

int n, pw[base];
const ll num = 33113;

string a;
ve <vi> g;
unordered_set <int> f[base];

void inp(){
	cin >> n >> a;
	
	a = "#" + a;
	
	g.resize(n + 1);
	
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
}
namespace sub1{
	int sz[base], vst[base], len = 0;
	
	void sub(int u, int p){
		sz[u] = 1;
		for(int v : g[u]) if(vst[v] == 0 and v != p){
			sub(v,u);
			sz[u] += sz[v];
		}
	}
	
	int cent(int u, int p, int SZ){
		for(int v : g[u]) if(vst[v] == 0 and v != p){
			if(sz[v] > SZ) return cent(v,u,SZ); 
		}
		return u;
	}
	
	int md = 0;
	ve <pii> store;
	
	bool dfs(int u, int p, int h, int up, int down){
		if(h > len) return 0;
		
		if(p) down = (down * num + (a[u] - 'a' + 1)) % MOD;
		up = (up + pw[h - 1] * (a[u] - 'a' + 1)) % MOD;
		
		int x = (up * pw[len - h] - down + MOD) % MOD;
		
		if(p == 0) f[h].insert(x);
		if(f[len-h+1].find(x) != f[len-h+1].end()) return 1;
		
		maxi(md, h);
		
		for(int v : g[u]) if(vst[v] == 0 and v != p){
			if(p == 0) store.clear();
			if(dfs(v,u,h+1,up,down)) return 1;
			if(p == 0) for(auto [x,y] : store) f[x].insert(y); 
		}
		
		store.pb(mp(h,x));
		return 0;
	}
	
	int dec(int u){
		sub(u,0);
		int c = cent(u,0,sz[u]/2);
		
		if(dfs(c,0,1,0,0)) return 1;
		
		fod(i,1,md) f[i].clear();
		vst[c] = 1;
		md = 0;
		
		for(int v : g[c]) if(vst[v] == 0){
			if(dec(v)) return 1;
		}
		return 0;	
	}
	
   	bool check(int x){
   		len = x;
   		fod(i,1,n) vst[i] = 0, f[i].clear();
 		return dec(1);  		
   	}
   	
    void solve(){
    	pw[0] = 1;
    	
    	fod(i,1,n) pw[i] = pw[i-1] * num % MOD;
    	
    	int l = 0, r = n/2, ans = 0;
    	while(l <= r){
    		int mid = l + r >> 1;
    		if(check(2 * mid + 1)) ans = 2 * mid + 1, l = mid + 1;
    		else r = mid - 1;
    	}
    	
    	l = 0, r = n/2;
    	while(l <= r){
    		int mid = l + r >> 1;
    		if(check(2 * mid)) l = mid + 1, maxi(ans, 2 * mid);
    		else r = mid - 1;
    	}
    	
    	cout << ans;
    }	
}
namespace sub2{
	
	void solve(){
	
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
        sub1 :: solve();
        sub2 :: solve();
    }
    kill();
}
