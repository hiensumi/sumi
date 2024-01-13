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
int n, q, val[base], h[base], in[base], out[base], tour[base], timedfs = 0, f[base];
vi g[base];
void dfs(int u, int p){
	in[u] = ++timedfs;
	tour[timedfs] = u;
	for(int v : g[u]) if(v != p){
		f[v] = f[u] + val[v];
		dfs(v,u);
	}
	out[u] = timedfs;
}
void inp(){
	cin >> n >> q;
	fod(i,1,n) cin >> val[i];
	fod(i,1,n-1){
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f[1] = val[1];
	dfs(1,0);
}

namespace sub1{
   	// int arr[base];
   	struct BIT{
   		int b1[base], b2[base], n;
   		void init(int x){ n = x; }
   		void add(int b[], int idx, int val){
   			while(idx <= n){
   				b[idx] += val;
   				idx += idx & -idx;
   			}
   		}
   		void add(int l, int r, int x){
   			add(b1, l, x);
   			add(b1, r + 1, -x);
   			add(b2, l, x * (l - 1));
   			add(b2, r + 1, - x * r);
   		}
   		int sum(int b[], int idx){
   			int res = 0;
   			while(idx > 0){
   				res += b[idx];
   				idx -= idx & -idx;
   			}
   			return res;
   		}
   		int getall(int idx){
   			return sum(b1, idx) * idx - sum(b2, idx);
   		}
   		int get(int l, int r){
   			return getall(r) - getall(l-1); 
   		}
   	}bit;
    void solve(){
    	// fod(i,1,n) arr[in[i]] = f[i];
    	bit.init(n);
    	fod(i,1,n) bit.add(in[i], in[i], f[i]);
    	while(q--){
    		int type; cin >> type;
    		if(type == 1){
    			int s, x; cin >> s >> x;
    			int diff = x - val[s];
    			// fod(i,in[s], out[s]) arr[i] += diff;
    			bit.add(in[s], out[s], diff);
    			val[s] = x;
    		}
    		else{
    			int s; cin >> s;
    			// cout << arr[in[s]] << el;
    			cout << bit.get(in[s], in[s]) << el;
    		}
    	}
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