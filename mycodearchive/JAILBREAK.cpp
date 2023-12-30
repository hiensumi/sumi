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
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 1; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, m;
char a[101][101];
ve <pii> dir = {
	mp(0, -1), mp(0, 1), mp(-1,0), mp(1,0)
};
pii P1, P2;
void inp(){
	P1 = mp(0,0);
	P2 = mp(0,0);
	cin >> n >> m;
	fod(i,1,n) fod(j,1,m){
		cin >> a[i][j];
		if(a[i][j] == '$' and !P1.fi and !P1.se) P1 = mp(i,j);
		else if(a[i][j] == '$') P2 = mp(i,j);
	}
}

namespace sub1{
   	int dis[4][105][105];
   	bool nt(int x, int y){
   		return 1 <= x and x <= n and 1 <= y and y <= m;
   	}
   	void go(int type){
   		deque <pii> dq;
   		fod(i,0,n+1) fod(j,0,m+1) dis[type][i][j] = INF;
   		if(type == 1) fod(i,1,n) fod(j,1,m) if(i == 1 or i == n or j == 1 or j == m){
    		if(a[i][j] == '#') dis[type][i][j] = 1, dq.push_front(mp(i,j));	
    		else if(a[i][j] == '.' or a[i][j] == '$') dis[type][i][j] = 0, dq.push_front(mp(i,j));
    	}
    	if(type == 2) dq.push_front(mp(P1.fi, P1.se)), dis[type][P1.fi][P1.se] = 0;
    	if(type == 3) dq.push_front(mp(P2.fi, P2.se)), dis[type][P2.fi][P2.se] = 0;
    	
    	while(!dq.empty()){
    		int u = dq.front().fi, v = dq.front().se;
    		dq.pop_front();
    		for(pii gg : dir){
    			int x = u + gg.fi, y = v + gg.se;
    			if(!nt(x,y) or a[x][y] == '*') continue;
    			int w = (a[x][y] == '#');
    			if(mini(dis[type][x][y], dis[type][u][v] + w)){
    				if(w == 1) dq.pb(mp(x,y));
    				else dq.push_front(mp(x,y));
    			}
    		}
    	}
   	}
    void solve(){
    	go(1);
    	go(2);
    	go(3);
    	int ans = INF;
    	fod(i,1,n) fod(j,1,m){
    		mini(ans, dis[1][i][j] + dis[2][i][j] + dis[3][i][j] + ( (a[i][j] == '#') ? -2 : 0 ));
    	}
    	
    	// cout << dis[1][4][5] << " " << dis[2][4][5] << " " << dis[3][4][5] << el;
    	cout << ans << el;
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