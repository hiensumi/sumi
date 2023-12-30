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
#define pra(a,n) fod(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 
struct point{int x, y;};
struct edge{int u, v, c;};

//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
//bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
#define name "abc175_d"
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, k, p[base], c[base];
void inp(){
	cin >> n >> k;
	fod(i,1,n) cin >> p[i];
	fod(i,1,n) cin >> c[i];	
}

namespace sub1{
	int low[base], cnt = 0, dd[base], num[base], stt = 0, root[base], sum[base], sz[base];
   	stack <int> st;
   	vi g[base];
   	void dfs(int u){
 		low[u] = num[u] = ++stt;
 		st.push(u);
 		for(int v : g[u]){
 			if(dd[v]) continue;
 			if(num[v]) low[u] = min(low[u], num[v]);
 			else{
 				dfs(v);
 				low[u] = min(low[u], low[v]);
 			}
 		}
 		if(low[u] == num[u]){
 			int x;
 			cnt++;
 			do{
 				x = st.top();
 				st.pop();
 				dd[x] = 1;
 				root[x] = cnt;
 				// tplt[cnt].pb(x);
 				sz[cnt]++;
 				sum[cnt] += c[x];
 			}while(x != u);
 		}
   	}
    void solve(){
    	fod(i,1,n) g[i].pb(p[i]);
    	fod(i,1,n) if(dd[i] == 0) dfs(i);
    	int res = -INF;
    	fod(i,1,n){
    		int x = root[i], ans = 0, add = -INF, cur = 0, t = k;
    		if(sum[x] >= 0) ans += (t / sz[x]) * sum[x], t %= sz[x], add = 0;
    		vi pre; pre.pb(0); int m = 0, dem = 0;
    		
    		for(int u = i; t ; u = p[u], t--){
    			if(u == i and dem == 0) dem = 1;
    			else if(u == i and dem == 1) break;
    			pre.pb(c[u]);
    			m++;
    		}
    		fod(i,1,m) pre[i] += pre[i-1], maxi(add, pre[i]); 
    		maxi(res, ans + add);
    	}
		
		fod(i,1,n){
    		int x = root[i];
    		int v = i, cnt = 0, path = 0;
    		while(true){
    			cnt++;
    			path += c[v];
    			if(cnt > k) break;
    			
    			int num = (k - cnt) / sz[x];
    			maxi(res, path + max(0ll, sum[x]) * num);
    			
				v = p[v];
				if(v == i) break;
    		}
    		
    	}
		    	
    	cout << res << el;
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
        if(endless) endless--;
    }
    kill();
}