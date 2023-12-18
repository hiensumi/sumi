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
int n, c[base], k[base], lab[base];
int find(int u){
	return (lab[u] < 0) ? u : lab[u] = find(lab[u]);
}
bool join(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v) return 0;
	if(lab[u] > lab[v]) swap(u,v);
	lab[u] += lab[v];
	lab[v] = u;
	return 1;
}
point HN[base];
void inp(){
	cin >> n;
	fod(i,1,n) cin >> HN[i].x >> HN[i].y;
	fod(i,1,n) cin >> c[i];
	fod(i,1,n) cin >> k[i];
}

namespace sub1{
   	ve <edge> hn;
   	int dist(point x, point y){
   		return abs(x.x - y.x) + abs(x.y - y.y);
   	}
    void solve(){
    	memset(lab, -1, sizeof lab);
    	fod(i,1,n) hn.pb({0,i,c[i]});
    	fod(i,1,n) fod(j,i+1,n){
    		hn.pb({i,j,(k[i] + k[j]) * dist(HN[i], HN[j])});
    	}
    	
    	sort(all(hn), [&] (edge a, edge b){
    		return a.c < b.c;
    	});
    	int res = 0;
    	vi stt;
    	ve<pii> connection;
    	for(edge x : hn){
    		if(join(x.u, x.v)){
    			res += x.c;
    			if(x.u == 0) stt.pb(x.v);
    			else connection.pb(mp(x.u,x.v));
    		}
    	}
    	uni(stt);
    	uni(connection);
    	cout << res << el;
    	cout << SZ(stt) << el;
    	if(SZ(stt)){
    		for(int x : stt) cout << x << " ";
    		cout << el;
    	}
    	cout << SZ(connection) << el;
    	for(pii x : connection) cout << x.fi  << " " << x.se << el;
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