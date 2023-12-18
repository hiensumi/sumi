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
const ll base = 1e6 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, in[base], a[1001][1001];
vi g[base];
int m;
int getid(int x, int y){
		return (x - 1) * m + y;
	}
void inp(){
	cin >> n;
	m = n;
	fod(i,1,n){
		fod(j,1,n-1){
			cin >> a[i][j];	
		}
		int u = getid(i,a[i][1]);
		if(a[i][1] < i) u = getid(a[i][1], i);
		
		fod(j,2,n-1){
			int v = getid(i,a[i][j]);
			if(a[i][j] < i) v = getid(a[i][j], i);
			
			g[u].pb(v);
			in[v]++;
			u = v;
		}
	}
}

namespace sub1{
	int dd[base];
   void dfs(int u){
   		if(dd[u]) return;
   		dd[u] = 1;
   		for(int v : g[u]){
   			if(dd[v] == 1){
   				cout << -1;
   				kill();
   			}
   			if(dd[v] == 2) continue;
   			dfs(v);
   		}
   		dd[u] = 2;
   }
   int dis[base];
    void solve(){
    	fod(i,1,n*n) if(dd[i] == 0) dfs(i);
    	queue <int> q;
    	fod(i,1,n * n) if(in[i] == 0) q.push(i), dis[i] = 1;
    	
    	while(!q.empty()){
    		int u = q.front(); q.pop();
    		for(int v : g[u]){
    			if(--in[v] == 0){
    				maxi(dis[v], dis[u] + 1);
    				q.push(v);
    			}
    		}
    	}
    	int res = 0;
    	fod(i,1,n * n) maxi(res, dis[i]);
    	cout << res;
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